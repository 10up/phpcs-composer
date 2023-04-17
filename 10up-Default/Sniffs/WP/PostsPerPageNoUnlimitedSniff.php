<?php
/**
 * TenUpDefault Coding Standard.
 *
 * @package PhpcsComposer
 * @link    https://github.com/10up/phpcs-composer
 * @license https://opensource.org/licenses/MIT MIT
 */

namespace PhpcsComposer\TenUpDefault\WordPress\Sniffs\WP;

use WordPressCS\WordPress\AbstractArrayAssignmentRestrictionsSniff;

/**
 * Flag returning infinite posts_per_page.
 *
 * @package WPCS\WordPressCodingStandards
 *
 * @since   0.13.0 Class name changed: this class is now namespaced.
 * @since   0.14.0 Added the posts_per_page property.
 * @since   1.0.0  This sniff has been split into two, with the check for high pagination
 *                 limit being part of the WP category, and the check for pagination
 *                 disabling being part of the VIP category.
 */
class PostsPerPageNoUnlimitedSniff extends AbstractArrayAssignmentRestrictionsSniff {

	/**
	 * Posts per page property
	 *
	 * @var string
	 */
	public $posts_per_page = '-1';

	/**
	 * Groups of variables to restrict.
	 *
	 * @return array
	 */
	public function getGroups() {
		return array(
			'posts_per_page' => array(
				'type' => 'warning',
				'keys' => array(
					'posts_per_page',
					'numberposts',
				),
			),
		);
	}

	/**
	 * Callback to process each confirmed key, to check value.
	 *
	 * @param  string $key   Array index / key.
	 * @param  mixed  $val   Assigned value.
	 * @param  int    $line  Token line.
	 * @param  array  $group Group definition.
	 * @return mixed         FALSE if no match, TRUE if matches, STRING if matches
	 *                       with custom error message passed to ->process().
	 */
	public function callback( $key, $val, $line, $group ) {
		$this->posts_per_page = (int) $this->posts_per_page;

		if ( strval( $val ) === '-1' ) {
			return 'Detected unlimited pagination, `%s` is set to `%s`';
		}

		return false;
	}

}
