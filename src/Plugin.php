<?php

/**
* Sets default ruleset for PHPCS.
*/

namespace TenUp\PHPCS_Composer;

use Composer\Plugin\PluginInterface;
use Composer\Composer;
use Composer\IO\IOInterface;

use Symfony\Component\Process\ProcessBuilder;

class Plugin implements PluginInterface {

	const RULESET_FILE             = 'default-ruleset.xml';
	const PHP_DEFAULT_VERSION      = '7.0-';
	const PHP_VERSION_ENV_KEY      = 'PHPCS_PHP_VERSIONS';
	const DEFAULT_RULESET          = '10up-Default';
	const PHPCS_CONFIG_DEFAULT_KEY = 'default_standard';
	const PHPCS_CONFIG_VERSION_KEY = 'testVersion';

	/**
	 * @var Composer
	 */
	private $composer;

	/**
	 * @var IOInterface
	 */
	private $io;

	/**
	 * @var ProcessBuilder
	 */
	private $process_builder;

	/**
	 * @var array
	 */
	private $settings;

	/**
	 * {@inheritDoc}
	 *
	 * @throws \RuntimeException
	 * @throws LogicException
	 * @throws RuntimeException
	 * @throws ProcessFailedException
	 */
	public function activate( Composer $composer, IOInterface $io ) {
		$this->composer = $composer;
		$this->io       = $io;

		$this->process_builder = new ProcessBuilder();
		$this->process_builder->setPrefix( $this->composer->getConfig()->get( 'bin-dir' ) . DIRECTORY_SEPARATOR . 'phpcs' );

		$php_version = getenv( self::PHP_VERSION_ENV_KEY );
		if ( ! $php_version ) {
			$php_version = self::PHP_DEFAULT_VERSION;
		}

		$updated_default = $this->set_default( self::PHPCS_CONFIG_DEFAULT_KEY, self::DEFAULT_RULESET );
		$updated_version = $this->set_default( self::PHPCS_CONFIG_VERSION_KEY, $php_version );

		if ( ! $updated_default && ! $updated_version ) {
			$this->io->write( '<info>Nothing to install or update.</info>' );
		}
	}

	/**
	 * Sets the default ruleset.
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
	 * Checks if the default path is set.
	 * @param string $key          The key to look for.
	 * @param string $expected_val The expected value.
	 * @return bool                False if setting does not match expected value.
	 */
	protected function is_default_set( $key, $expected_val ) {
		if ( ! $this->settings ) {
			$output = $this->process_builder
			->setArguments( array( '--config-show', $key ) )
			->getProcess()
			->mustRun()
			->getOutput();

			$settings       = explode( PHP_EOL, $output );
			$this->settings = $settings;
		} else {
			$settings = $this->settings;
		}

		foreach ( $settings as $line ) {
			if ( 0 === strpos( $line, $key ) ) {
				$found_val = str_replace( "$key: ", '', $line );
				return $expected_val === $found_val;
			}
		}
		return false;
	}
}
