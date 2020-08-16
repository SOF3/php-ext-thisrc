--TEST--
thisuniq() should clone correctly
--SKIPIF--
<?php
if (!extension_loaded('thisrc')) {
    echo 'skip';
}
?>
--FILE--
<?php
class Foo {
    public $bar = 2;
    public $qux;

    public function bar() {
        $uniq = thisuniq();
        var_dump($uniq);
        var_dump($uniq === $this);
        var_dump($uniq->bar);
        var_dump($uniq->qux);
        var_dump($uniq->corge);
        return new Foo;
    }
}

$foo = new Foo;
$foo->bar = 3;
$foo->qux = 4;
$fox->corge = 5;
$foo->bar()->bar()->bar();

// check that the original object is unmodified
// $foo->bar();
?>
--EXPECT--
bool(false)
int(3)
int(4)
int(5)
bool(true)
int(3)
int(4)
int(5)
int(true)
int(3)
int(4)
int(5)
bool(false)
int(3)
int(4)
int(5)
