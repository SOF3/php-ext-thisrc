--TEST--
Check if thisrc is loaded
--SKIPIF--
<?php
if (!extension_loaded('thisrc')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "thisrc" is available';
?>
--EXPECT--
The extension "thisrc" is available
