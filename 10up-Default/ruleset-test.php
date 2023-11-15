<?php
/**
 * Ruleset test for the TenUpDefault ruleset
 *
 * The expected errors, warnings, and messages listed here, should match what is expected to be reported
 * when ruleset-test.inc is run against PHP_CodeSniffer and the TenUpDefault standard.
 *
 * @package PhpcsComposer\TenUpDefault
 */

namespace PhpcsComposer\TenUpDefault;

// Expected values.
$expected = [
	'errors'   => [
		4   => 1,
		5   => 1,
		6   => 41,
		10  => 5,
		15  => 2,
		20  => 1,
		22  => 1,
		26  => 1,
		31  => 1,
		33  => 3,
		35  => 1,
		40  => 1,
		43  => 2,
		57  => 1,
		67  => 1,
		81  => 1,
		89  => 1,
		96  => 1,
		101 => 2,
		106 => 1,
		110 => 1,
		118 => 1,
		125 => 1,
		128 => 1,
		130 => 1,
		132 => 1,
		139 => 1,
		141 => 1,
		144 => 1,
		146 => 1,
		152 => 1,
		155 => 1,
		162 => 2,
		168 => 3,
		222 => 1,
		226 => 1,
		230 => 1,
		275 => 1,
		296 => 1,
		299 => 1,
		302 => 1,
		305 => 1,
		308 => 1,
		312 => 1,
		316 => 1,
		320 => 1,
		323 => 1,
		326 => 1,
		329 => 1,
		332 => 1,
		335 => 1,
		365 => 1,
		368 => 1,
		371 => 1,
		374 => 1,
		377 => 1,
		380 => 1,
		383 => 1,
		386 => 1,
		389 => 1,
		392 => 1,
		395 => 1,
		398 => 1,
		401 => 1,
		452 => 1,
		455 => 1,
		457 => 1,
		463 => 1,
		468 => 1,
		475 => 1,
		478 => 1,
		483 => 4,
		486 => 1,
	],
	'warnings' => [
		15  => 1,
		40  => 2,
		47  => 1,
		51  => 1,
		54  => 1,
		67  => 1,
		73  => 3,
		77  => 1,
		83  => 1,
		85  => 2,
		87  => 1,
		96  => 1,
		101 => 1,
		106 => 1,
		118 => 1,
		125 => 1,
		152 => 1,
		171 => 1,
		174 => 1,
		177 => 1,
		180 => 1,
		183 => 1,
		186 => 1,
		189 => 1,
		192 => 1,
		195 => 1,
		198 => 1,
		201 => 1,
		204 => 1,
		207 => 2,
		210 => 1,
		213 => 1,
		216 => 1,
		219 => 1,
		222 => 1,
		226 => 1,
		230 => 1,
		233 => 2,
		236 => 1,
		239 => 1,
		242 => 1,
		245 => 1,
		248 => 1,
		251 => 1,
		254 => 1,
		257 => 1,
		260 => 1,
		263 => 1,
		266 => 1,
		269 => 1,
		272 => 1,
		305 => 1,
		312 => 1,
		316 => 1,
		320 => 1,
		338 => 1,
		404 => 1,
		407 => 1,
		410 => 1,
		413 => 1,
		416 => 1,
		419 => 1,
		422 => 1,
		425 => 1,
		428 => 1,
		431 => 1,
		434 => 1,
		437 => 1,
		440 => 1,
		443 => 1,
		446 => 1,
		449 => 1,
		475 => 1,
		486 => 1,
	],
	'messages' => [],
];

// If we're running on PHP 7.4, we need to account for the error thrown because `restore_include_path()` is deprecated.
// See https://www.php.net/manual/en/function.restore-include-path.php
if ( version_compare( PHP_VERSION, '7.4.0', '>=' ) && version_compare( PHP_VERSION, '8.0.0', '<' ) ) {
	$expected['errors'][ 222 ] = 2;
}

// We have some specific errors that are only thrown on PHP 8.2+.
if ( version_compare( PHP_VERSION, '8.2.0', '<' ) ) {
	$expected['errors'][ 486 ] = 0;
}

if ( version_compare( PHP_VERSION, '7.2', '<' ) ) {
	$expected['errors'][ 483 ] = 4;
	$expected['warnings'][ 1 ] = 1;
}

require __DIR__ . '/../tests/RulesetTest.php';

// Run the tests!
$test = new \PhpcsComposer\RulesetTest( 'TenUpDefault', $expected );
if ( $test->passes() ) {
	printf( 'All TenUpDefault tests passed!' . PHP_EOL );
	exit( 0 );
}

exit( 1 );
