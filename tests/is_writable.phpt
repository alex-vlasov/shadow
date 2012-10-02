--TEST--
Check is_writable on instance
--SKIPIF--
<?php if (!extension_loaded("shadow")) print "skip"; ?>
--FILE--
<?php 
require_once('setup.inc');
var_dump(is_writable("$template/unwritable.txt"));
var_dump(is_writable("$instance/unwritable.txt"));
?>
--EXPECT--
bool(true)
bool(true)
