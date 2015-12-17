--TEST--
Scalar type hint names cannot be used as class, trait or interface names (4) - class_alias
--FILE--
<?php

class foobar {}
class_alias("foobar", "string");
--EXPECTF--
Fatal error: Cannot use 'string' as class name as it is reserved in %s on line %d
