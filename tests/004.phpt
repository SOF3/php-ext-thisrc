--TEST--
thisuniq() should throw error when there is no class context
--SKIPIF--
<?php
if (!extension_loaded('thisrc')) {
    echo 'skip';
}
?>
--FILE--
<?php
$ret = thisuniq();

var_dump($ret);
?>
--EXPECTF--
Fatal error: Uncaught Error: thisuniq() must be called from within a class in %s:%d
Stack trace:
#0 %s(%d): thisuniq()
#1 {main}
  thrown in %s on line %d
