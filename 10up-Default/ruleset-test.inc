


<?php
// Errors - Squiz.WhiteSpace.SuperfluousWhitespace & Squiz.Commenting.FileComment.WrongStyle.
$hello = ''; $posts_not_in = ''; $title = ''; $ch = ''; $thing = ''; $descriptorspec = ''; $pipes = ''; $cwd = ''; $env = ''; $page_title = ''; $menu_title = ''; $capability = ''; $function = ''; $icon_url = ''; $position = ''; $wpdb = ''; $file = ''; $fp = ''; $test = ''; $post = ''; $bar = ''; $array = []; $query_args = []; $url = ''; $page_title = ''; $true = true; $data = ''; $group = ''; $stdClass = new stdClass(); $needle = ''; $some_var = ''; $blogid = 1; $text = ''; $category_id = 123; $foo = ''; $bar = ''; $var = ''; $wp_rewrite = ''; $count = 1; $loop = 1; $obj = ''; // phpcs:ignore WordPress.WP.GlobalVariablesOverride.Prohibited -- All set for VariableAnalysis checks.

// phpcs:disable Squiz.Commenting
// Errors: Generic.PHP.Syntax.PHPSyntax & WordPress.WhiteSpace.ControlStructureSpacing.NoSpaceAfterStructureOpen & WordPress.WhiteSpace.ControlStructureSpacing.NoSpaceBeforeOpenParenthesis & Squiz.ControlStructures.ControlSignature.SpaceAfterKeyword & Generic.CodeAnalysis.EmptyStatement.DetectedForeach
foreach() {
}

// Errors: Generic.PHP.NoSilencedErrors && WordPress.WhiteSpace.ControlStructureSpacing.NoSpaceAfterOpenParenthesis
// Warnings: WordPress.PHP.NoSilencedErrors.Discouraged
if (@in_array( $array, $needle, true )) {
	echo '@';
}

// Errors: WordPress.Security.EscapeOutput.OutputNotEscaped
echo $hello;
// Errors: WordPress.Security.EscapeOutput.OutputNotEscaped
echo apply_filters( 'the_title', $title );

function bar() {
	// Errors: Generic.CodeAnalysis.EmptyStatement.DetectedIf
	if ( ! isset( $_POST['test'] ) ) {
	}
}

// Errors: WordPress.Security.ValidatedSanitizedInput.MissingUnslash
if ( isset( $_POST['nonce'] ) && wp_verify_nonce( sanitize_text_field( $_POST['nonce'] ) ) ) {
	// Errors: WordPress.Security.ValidatedSanitizedInput.InputNotValidated & WordPress.Security.ValidatedSanitizedInput.MissingUnslash & WordPress.Security.ValidatedSanitizedInput.InputNotSanitized
	bar( $_POST['foo2'] );
	// Errors: WordPress.Security.ValidatedSanitizedInput.MissingUnslash
	$foo2 = isset( $_POST['foo2'] ) ?? foo( sanitize_text_field( $_POST['foo2'] ) ); // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable
}

// Errors: PEAR.Functions.FunctionCallSignature.SpaceAfterOpenBracket
// Warnings: WordPress.WP.Capabilities.Undetermined & WordPress.Security.PluginMenuSlug.Using__FILE__
add_menu_page($page_title, $menu_title, $capability, __FILE__, $function, $icon_url, $position );

// Errors: WordPress.WP.EnqueuedResources.NonEnqueuedScript & Squiz.PHP.EmbeddedPhp.ContentBeforeOpen
?> <script src="http://someurl/somefile.js"></script> <?php

// Warnings: WordPress.WP.PostsPerPage.posts_per_page_posts_per_page
$args = array( // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable
	'posts_per_page' => 999,
);

// Warnings: WordPress.WP.PostsPerPage.posts_per_page_posts_per_page
_query_posts( 'posts_per_page=999' );

// Warnings: WordPress.WP.PostsPerPage.posts_per_page_posts_per_page
$query_args['posts_per_page'] = 999;

// Errors: WordPress.DateTime.RestrictedFunctions.timezone_change_date_default_timezone_set)
date_default_timezone_set( 'FooBar' );

$b = function () { // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable
	global $wpdb;
	$listofthings = wp_cache_get( 'foo' );
	if ( ! $listofthings ) {
		$foo = "column = 'test'";

		// Errors: WordPress.DB.PreparedSQL.NotPrepared
		// Warnings: WordPress.DB.DirectDatabaseQuery.DirectQuery
		$listofthings = $wpdb->query( 'SELECT something FROM somewhere WHERE ' . $foo );
		wp_cache_set( 'foo', $listofthings );
	}
};

// Warnings: WordPress.DB.DirectDatabaseQuery.DirectQuery & WordPress.DB.PreparedSQLPlaceholders.UnnecessaryPrepare & WordPress.DB.DirectDatabaseQuery.NoCaching
$baz = $wpdb->get_results( $wpdb->prepare( 'SELECT X FROM Y ' ) ); // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable -- Warning x 2.

$test = [
	// Warnings: WordPress.DB.SlowDBQuery.slow_db_query_tax_query
	'tax_query' => [],
];

// Errors: PEAR.Functions.FunctionCallSignature.ContentAfterOpenBracket
new WP_Query( array(
	// Warnings: WordPress.DB.SlowDBQuery.slow_db_query_meta_query
	'meta_query' => [],
	// Warnings: WordPress.DB.SlowDBQuery.slow_db_query_meta_key & WordPress.Arrays.MultipleStatementAlignment.DoubleArrowNotAligned
	'meta_key' => 'foo',
	// Warnings: Warnings: WordPress.DB.SlowDBQuery.slow_db_query_meta_value
	'meta_value' => 'bar',
	// Errors: PEAR.Functions.FunctionCallSignature.CloseBracketLine
) );

// WordPress.WP.GlobalVariablesOverride
$GLOBALS['wpdb'] = 'test';

// Errors: Generic.CodeAnalysis.EmptyStatement.DetectedIf
// Warnings: Universal.Operators.StrictComparisons.LooseEqual
if ( true == $true ) {
}

// Errors: Generic.CodeAnalysis.EmptyStatement.DetectedIf & Squiz.PHP.DisallowMultipleAssignments.FoundInControlStructure
// Warnings: Generic.CodeAnalysis.AssignmentInCondition.Found
if ( $test = get_post( $post ) ) {
}

// Errors: Generic.CodeAnalysis.EmptyStatement.DetectedIf)
// Warnings: WordPress.PHP.StrictInArray.MissingTrueStrict
if ( true === in_array( $foo, $bar ) ) {
}

// Errors: WordPress.PHP.DontExtract.extract_extract
extract( $foobar );

// WordPress.WP.CronInterval
function my_add_weekly( $schedules ) {
	$schedules['every_6_mins'] = array(
		'interval' => 360,
		// Errors: NormalizedArrays.Arrays.CommaAfterLast.MissingMultiLine
		// Warnings: WordPress.Arrays.MultipleStatementAlignment.DoubleArrowNotAligned
		'display' => __( 'Once every 6 minutes' )
	);
	return $schedules;
}

// Errors: PEAR.Functions.FunctionCallSignature.SpaceBeforeCloseBracket
// Warnings:WordPress.WP.CronInterval.CronSchedulesInterval
add_filter( 'cron_schedules', 'my_add_weekly');

// Errors: Universal.Files.SeparateFunctionsFromOO.Mixed
class TestClass extends MyClass
// Errors: Generic.Classes.OpeningBraceSameLine.BraceOnNewLine
{
	// Errors: Squiz.Scope.MethodScope.Missing
	function __construct() {
		parent::MYCLASS();
		parent::__construct();
	}
}

// Errors: Generic.Files.OneObjectStructurePerFile.MultipleFound
class OldClass
// Errors: Generic.Classes.OpeningBraceSameLine.BraceOnNewLine
{

	// Errors: Squiz.Scope.MethodScope.Missing
	function OldClass()
	// Errors: (Generic.Functions.OpeningFunctionBraceKernighanRitchie.BraceOnNewLine
	{
	}
}

// Errors: Generic.Files.OneObjectStructurePerFile.MultipleFound
// Warnings: Generic.Classes.DuplicateClassName.Found
class TestClass extends MyClass {

	// Errors: Squiz.Scope.MethodScope.Missing
	function TestClass() {
		parent::MyClass();
		parent::__construct();
	}
}

// Errors: Squiz.PHP.EmbeddedPhp.ContentAfterEnd & Generic.PHP.DisallowShortOpenTag.EchoFound
?> <?= esc_html( $var );

// Warnings: (Squiz.PHP.CommentedOutCode.Found <!-- Warning. -->
// if (empty($this)) {echo 'This is will not work';}

// Errors: PEAR.Functions.FunctionCallSignature.SpaceAfterOpenBracket & Squiz.PHP.Eval.Discouraged
eval('$var = 4;'); // Error + Message.

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.obfuscation_base64_decode
base64_decode( 'VGhpcyBpcyBhbiBlbmNvZGVkIHN0cmluZw==' );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.obfuscation_base64_decode
base64_encode( 'This is an encoded string' );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.obfuscation_convert_uudecode
convert_uudecode( "+22!L;W9E(%!(4\"$`\n`" );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.obfuscation_convert_uudecode
convert_uuencode( "test\ntext text\r\n" );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.obfuscation_str_rot13
str_rot13( 'The quick brown fox jumps over the lazy dog.' );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.serialize_serialize
serialize();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.serialize_unserialize
unserialize();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.urlencode_urlencode
urlencode();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_passthru
passthru( 'cat myfile.zip', $err );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_proc_open
$process = proc_open( 'php', $descriptorspec, $pipes, $cwd, $env );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_system
$last_line = system( 'ls', $retval );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_popen
$handle = popen( '/bin/ls', 'r' );

// Warnings: WordPress.PHP.DevelopmentFunctions.prevent_path_disclosure_error_reporting & WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_error_reporting
error_reporting();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_ini_restore
ini_restore();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_apache_setenv
apache_setenv();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_putenv
putenv();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_set_include_path
set_include_path();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_restore_include_path && PHPCompatibility.FunctionUse.RemovedFunctions.restore_include_pathDeprecated
restore_include_path();

// Errors: PHPCompatibility.FunctionUse.RemovedFunctions.magic_quotes_runtimeDeprecatedRemoved
// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_magic_quotes_runtime
magic_quotes_runtime();

// Errors: PHPCompatibility.FunctionUse.RemovedFunctions.set_magic_quotes_runtimeDeprecatedRemoved
// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_set_magic_quotes_runtime
set_magic_quotes_runtime();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.runtime_configuration_dl & PHPCompatibility.FunctionUse.RemovedFunctions.dlDeprecated
dl();

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_exec
exec( 'whoami' );

// Warnings: WordPress.PHP.DiscouragedPHPFunctions.system_calls_shell_exec
$output = shell_exec( 'ls -lart' ); // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable -- Error.

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_var_dump
var_dump();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_var_export
var_export();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_print_r
print_r();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_trigger_error
trigger_error( 'message' );

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_set_error_handler
set_error_handler();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_debug_backtrace
debug_backtrace();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_debug_print_backtrace
debug_print_backtrace();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_wp_debug_backtrace_summary
wp_debug_backtrace_summary();

// Warnings: WordPress.PHP.DevelopmentFunctions.prevent_path_disclosure_phpinfo
phpinfo();

// Warnings: WordPress.PHP.DevelopmentFunctions.error_log_error_log
error_log();

// OK to set
ini_set( 'auto_detect_line_endings', true );

// Errors: PHPCompatibility.IniDirectives.RemovedIniDirectives.highlight_bgDeprecatedRemoved
ini_set( 'highlight.bg', '#000000' );

// OK to set
ini_set( 'highlight.comment', '#000000' );

// OK to set
ini_set( 'highlight.default', '#000000' );

// OK to set
ini_set( 'highlight.html', '#000000' );

// OK to set
ini_set( 'highlight.keyword', '#000000' );

// OK to set
ini_set( 'highlight.string', '#000000' );

// OK to set
ini_set( 'short_open_tag', 1 );

// Errors: WordPress.PHP.IniSet.bcmath_scale_Disallowed
ini_set( 'bcmath.scale', 1 );

// Errors: WordPress.PHP.IniSet.display_errors_Disallowed
ini_set( 'display_errors', 1 );

// Errors: WordPress.PHP.IniSet.error_reporting_Disallowed
ini_set( 'error_reporting', 1 );

// Errors: WordPress.PHP.IniSet.filter_default_Disallowed
ini_set( 'filter.default', 1 );

// Errors: WordPress.PHP.IniSet.filter_default_flags_Disallowed
ini_set( 'filter.default_flags', 1 );

// Errors: WordPress.PHP.IniSet.iconv_input_encoding_Disallowed
// Warnings: PHPCompatibility.IniDirectives.RemovedIniDirectives.iconv_input_encodingDeprecated
ini_set( 'iconv.input_encoding', 1 );

// Errors: WordPress.PHP.IniSet.iconv_internal_encoding_Disallowed
// Warnings: PHPCompatibility.IniDirectives.RemovedIniDirectives.iconv_internal_encodingDeprecated
ini_set( 'iconv.internal_encoding', 1 );

// Errors: WordPress.PHP.IniSet.iconv_output_encoding_Disallowed
// Warnings: PHPCompatibility.IniDirectives.RemovedIniDirectives.iconv_output_encodingDeprecated
ini_set( 'iconv.output_encoding', 1 );

// Errors: WordPress.PHP.IniSet.ignore_user_abort_Disallowed
ini_set( 'ignore_user_abort', 1 );

// Errors: WordPress.PHP.IniSet.log_errors_Disallowed
ini_set( 'log_errors', 1 );

// Errors: WordPress.PHP.IniSet.max_execution_time_Disallowed
ini_set( 'max_execution_time', 1 );

// Errors: WordPress.PHP.IniSet.memory_limit_Disallowed
ini_set( 'memory_limit', 1 );

// Errors: WordPress.PHP.IniSet.short_open_tag_Disallowed
ini_set( 'short_open_tag', 'off' );

// Warnings: WordPress.PHP.IniSet.Risky
ini_set( 'foo', true );

// OK to set
ini_alter( 'auto_detect_line_endings', true );

// OK to set
ini_alter( 'highlight.bg', '#000000' );

// OK to set
ini_alter( 'highlight.comment', '#000000' );

// OK to set
ini_alter( 'highlight.default', '#000000' );

// OK to set
ini_alter( 'highlight.html', '#000000' );

// OK to set
ini_alter( 'highlight.keyword', '#000000' );

// OK to set
ini_alter( 'highlight.string', '#000000' );

// OK to set
ini_alter( 'short_open_tag', 1 );

// Errors: WordPress.PHP.IniSet.bcmath_scale_Disallowed
ini_alter( 'bcmath.scale', 1 );

// Errors: WordPress.PHP.IniSet.display_errors_Disallowed
ini_alter( 'display_errors', 1 );

// Errors: WordPress.PHP.IniSet.error_reporting_Disallowed
ini_alter( 'error_reporting', 1 );

// Errors: WordPress.PHP.IniSet.filter_default_Disallowed
ini_alter( 'filter.default', 1 );

// Errors: WordPress.PHP.IniSet.filter_default_flags_Disallowed
ini_alter( 'filter.default_flags', 1 );

// Errors: WordPress.PHP.IniSet.iconv_input_encoding_Disallowed
ini_alter( 'iconv.input_encoding', 1 );

// Errors: WordPress.PHP.IniSet.iconv_internal_encoding_Disallowed
ini_alter( 'iconv.internal_encoding', 1 );

// Errors: WordPress.PHP.IniSet.iconv_output_encoding_Disallowed
ini_alter( 'iconv.output_encoding', 1 );

// Errors: WordPress.PHP.IniSet.ignore_user_abort_Disallowed
ini_alter( 'ignore_user_abort', 1 );

// Errors: WordPress.PHP.IniSet.log_errors_Disallowed
ini_alter( 'log_errors', 1 );

// Errors: WordPress.PHP.IniSet.max_execution_time_Disallowed
ini_alter( 'max_execution_time', 1 );

// Errors: WordPress.PHP.IniSet.memory_limit_Disallowed
ini_alter( 'memory_limit', 1 );

// Errors: WordPress.PHP.IniSet.short_open_tag_Disallowed
ini_alter( 'short_open_tag', 'off' );

// Warnings: WordPress.PHP.IniSet.Risky
ini_alter( 'foo', true );

// Warnings: WordPress.WP.AlternativeFunctions.curl_curl_init
curl_init();

// Warnings: WordPress.WP.AlternativeFunctions.curl_curl_close
curl_close( $ch );

// Warnings: WordPress.WP.AlternativeFunctions.curl_curl_getinfo
CURL_getinfo();

// Warnings: WordPress.WP.AlternativeFunctions.parse_url_parse_url
parse_url( 'http://example.com/' );

// Warnings: WordPress.WP.AlternativeFunctions.json_encode_json_encode
$json = json_encode( $thing ); // phpcs:ignore VariableAnalysis.CodeAnalysis.VariableAnalysis.UnusedVariable -- Warning.

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_readfile
readfile();

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_fclose
fclose();

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_fopen
fopen();

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_fread
fread();

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_fsockopen
fsockopen();

// Warnings: WordPress.WP.AlternativeFunctions.file_system_operations_pfsockopen
pfsockopen();

// Warnings: WordPress.WP.AlternativeFunctions.rand_seeding_srand
srand();

// Warnings: WordPress.WP.AlternativeFunctions.rand_seeding_mt_srand
mt_srand();

// Warnings: WordPress.WP.AlternativeFunctions.rand_rand
rand();

// Warnings: WordPress.WP.AlternativeFunctions.rand_mt_rand
mt_rand();

// Errors: Generic.Files.OneObjectStructurePerFile.MultipleFound
class MyClass {

	// Errors: Squiz.Scope.MethodScope.Missing
	function my_function() {
		// Errors: Squiz.Functions.MultiLineFunctionDeclaration.SpaceAfterFunction
		return function() {
			$this->my_callback(); // OK - new VariableAnalysis doesn't flag $this as undefined in closure.
		};
	}

	// Errors: Squiz.Scope.MethodScope.Missing
	function my_callback() {}
}

// Errors: Generic.VersionControl.GitMergeConflict.OpenerFound
?>
<<<<<<< HEAD

>>>>>>>
<?php

// Errors: Squiz.PHP.DisallowMultipleAssignments.Found
// Warnings: WordPress.CodeAnalysis.AssignmentInTernaryCondition.FoundInTernaryCondition
$var = ( $test = get_post( $post ) ) ? $test : '';

// Errors: Squiz.PHP.EmbeddedPhp.ContentBeforeEnd & Squiz.WhiteSpace.SuperfluousWhitespace.EndFile
// Error. ?>


<?php
// MCrypt is deprecated in PHP 7.1 and removed in PHP 7.2.
$secret = mcrypt_encrypt( MCRYPT_3DES, '12345678abcdefgh', 'test', MCRYPT_MODE_CBC, '12345678' );

// Function utf8_encode() is deprecated since PHP 8.2;
utf8_encode( 'test' );
