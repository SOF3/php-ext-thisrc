--TEST--
thisrc() should return refcount correctly
--SKIPIF--
<?php
if (!extension_loaded('thisrc')) {
    echo 'skip';
}
?>
--FILE--
<?php
class Foo {
    public function bar() {
        var_dump(thisrc());
        return new Foo;
    }
}

$foo = new Foo;
$foo->bar()->bar()->bar();
?>
--EXPECT--
int(2)
int(1)
int(1)
