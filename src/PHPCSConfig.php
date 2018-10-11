<?php
/**
 * Sets default ruleset and versioning for PHPCS.
 *
 * This class interacts with Composer and PHPCS to read
 * environment variables and configure PHPCS to use a
 * default ruleset and PHP version. By default it relies
 * on the provide 10up-Default ruleset and PHP 7.0+.
 *
 * See: https://getcomposer.org/doc/articles/plugins.md
 *
 * @package TenUp\PHPCS_Composer
 */

namespace TenUp\PHPCS_Composer;

use Composer\Plugin\PluginInterface;
use Composer\EventDispatcher\EventSubscriberInterface;
use Composer\Composer;
use Composer\IO\IOInterface;
use Composer\Script\Event;
use Composer\Script\ScriptEvents;

use Symfony\Component\Process\ProcessBuilder;

/**
 * PHPCS Configuration class.
 */
class PHPCSConfig implements PluginInterface, EventSubscriberInterface {

	/**
	 * Name of environment variable to override PHP Compatibility version default.
	 *
	 * @var string
	 */
	const PHP_VERSION_ENV_KEY = 'PHPCS_PHP_VERSION';

	/**
	 * Default version for PHP Compatibility.
	 *
	 * @var string
	 */
	const PHP_DEFAULT_VERSION = '7.0-';

	/**
	 * Name of PHPCS config key to control tested PHP Compatibility version.
	 *
	 * @var string
	 */
	const PHPCS_CONFIG_VERSION_KEY = 'testVersion';

	/**
	 * Name of default ruleset PHPCS is configured with.
	 *
	 * @var string
	 */
	const DEFAULT_RULESET = '10up-Default';

	/**
	 * Name of PHPCS config key to control default standard.
	 *
	 * @var string
	 */
	const PHPCS_CONFIG_DEFAULT_KEY = 'default_standard';

	/**
	 * Name of the PHPCS config key to control installed paths.
	 *
	 * @var string
	 */
	const PHPCS_CONFIG_PATH_KEY = 'installed_paths';

	/**
	 * Relative path to ruleset.
	 *
	 * @var string
	 */
	const PHPCS_CONFIG_PATH = 'vendor/10up/phpcs-composer/10up-Default,vendor/wp-coding-standards/wpcs,vendor/phpcompatibility/php-compatibility,vendor/phpcompatibility/phpcompatibility-paragonie,vendor/phpcompatibility/phpcompatibility-wp';

	/**
	 * Reference to Composer class.
	 *
	 * @var Composer
	 */
	private $composer;

	/**
	 * IO interface to write output.
	 *
	 * @var IOInterface
	 */
	private $io;

	/**
	 * Instance of the Symfony Process Builder class.
	 *
	 * @var ProcessBuilder
	 */
	private $process_builder;

	/**
	 * PHP version to set.
	 *
	 * @var string
	 */
	private $php_version;

	/**
	 * Array of settings from PHPCS configuration.
	 *
	 * @var array
	 */
	private $settings;

	/**
	 * Test method. Triggers the configuration update via manual command.
	 *
	 * @param Event $event Composer event.
	 * @return void
	 */
	public static function run( Event $event ) {
		$instance = new static();

		$instance->composer = $event->getComposer();
		$instance->io       = $event->getIO();

		$instance->init();
		$instance->triggerUpdates();

	}

	/**
	 * Runs plugin activation logic.
	 *
	 * @param Composer    $composer Reference to Composer class.
	 * @param IOInterface $io       IO output read/write class.
	 * @return void
	 */
	public function activate( Composer $composer, IOInterface $io ) {
		$this->composer = $composer;
		$this->io       = $io;

		$this->init();
	}

	/**
	 * Returns an array of events that the plugin hooks into.
	 *
	 * @return array
	 */
	public static function getSubscribedEvents() {
		return array(
			ScriptEvents::POST_INSTALL_CMD => array(
				array( 'triggerUpdates', 0 ),
			),
			ScriptEvents::POST_UPDATE_CMD  => array(
				array( 'triggerUpdates', 0 ),
			),
		);
	}


	/**
	 * Triggers PHPCS configuration updates.
	 *
	 * @return void
	 */
	public function triggerUpdates() {
		$updated_default = $this->set_default( self::PHPCS_CONFIG_DEFAULT_KEY, self::DEFAULT_RULESET );
		$updated_version = $this->set_default( self::PHPCS_CONFIG_VERSION_KEY, $this->php_version );
		$updated_paths   = $this->set_default( self::PHPCS_CONFIG_PATH_KEY, self::PHPCS_CONFIG_PATH );

		if ( ! $updated_default && ! $updated_version && ! $updated_paths ) {
			$this->io->write( '<info>Nothing to install or update.</info>' );
		}
	}

	/**
	 * Initializes the plugin.
	 *
	 * @return void
	 */
	protected function init() {
		$this->process_builder = new ProcessBuilder();
		$this->process_builder->setPrefix( $this->composer->getConfig()->get( 'bin-dir' ) . DIRECTORY_SEPARATOR . 'phpcs' );

		$php_version = getenv( self::PHP_VERSION_ENV_KEY );
		if ( ! $php_version ) {
			$php_version = self::PHP_DEFAULT_VERSION;
		}
		$this->php_version = $php_version;
	}

	/**
	 * Sets a PHPCS configuration value.
	 *
	 * @param string $key The key to set.
	 * @param string $val The values to be set in the config.
	 * @return bool       True on updated.
	 */
	protected function set_default( $key, $val ) {
		if ( $this->is_default_set( $key, $val ) ) {
			return false;
		}
		$output = $this->process_builder
		->setArguments( array( '--config-set', $key, $val ) )
		->getProcess()
		->mustRun()
		->getOutput();

		$update_message = sprintf(
			'PHP CodeSniffer Config <info>%s</info> <comment>set to</comment> <info>%s</info>',
			$key,
			$val
		);
		$this->io->write( $update_message );
		return true;
	}

	/**
	 * Parses PHPCS configuration output to check if desired config key is set.
	 *
	 * @param string $key          The key to look for.
	 * @param string $expected_val The expected value.
	 * @return bool                False if setting does not match expected value.
	 */
	protected function is_default_set( $key, $expected_val ) {
		// If the PHPCS settings are not already saved, get them.
		if ( ! $this->settings ) {
			// Runs phpcs --config-show $key.
			$output = $this->process_builder
			->setArguments( array( '--config-show', $key ) )
			->getProcess()
			->mustRun()
			->getOutput();

			// Parse the results
			$this->settings = array_filter( explode( PHP_EOL, $output ) );
		}

		foreach ( $this->settings as $line ) {
			if ( 0 === strpos( $line, $key ) ) {
				$found_val = trim( str_replace( "$key:", '', $line ) );
				return $expected_val === $found_val;
			}
		}
		return false;
	}
}
