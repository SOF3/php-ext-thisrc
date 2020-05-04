# php-ext-thisrc
PHP extension to get refcount of `$this`.

This extension only adds one new function `thisrc() : int`.
It returns the refcount of `$this` when called from a class.

## Why require `$this` instead of arbitrary argument?
When the parameter is passed to another function,
the refcount increases.
This might cause confusing behaviour.
Calling the function without passing any references is more reliable.

## When is refcount information useful?
Consider an immutable value class with methods that return a modified version:
```php
class Foo {
	private $inner;

	public function __construct(int $inner) {
		$this->inner = $inner;
	}

	public function plus(int $value) : Foo {
		return new Foo($this->inner + $value);
	}

	public function times(int $value) : Foo {
		return new Foo($this->inner - $value);
	}
}

$three = new Foo(3);
$sixteen = $three->plus(5)->times(2);
```

This creases an intermediate object `Foo(8)` in the call chain.
If used in hot code,
this allocation could be optimized away:

```php
public function plus(int $value) : Foo {
	if(thisrc() === 1) {
		$this->inner += $value;
		return $this;
	} else {
		return new Foo($this->inner + $value;)
	}
}
```

Then only one new `Foo` object is created in the call chain that creates `$sixteen`,
avoiding the allocation for the intermediate `Foo(8)`.
