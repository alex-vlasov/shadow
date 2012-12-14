--TEST--
Check globs
--SKIPIF--
<?php if (!extension_loaded("shadow")) print "skip"; ?>
--FILE--
<?php 
require_once('setup.inc');
$w = getcwd();
chdir($template);
$res = glob("txt/*.txt");
sort($res);
var_dump($res);
chdir($w);
chdir($instance);
$res = glob("txt/*.txt");
sort($res);
var_dump($res);
$res = glob("templdir/*");
var_dump($res);
$res = glob("instdir/*");
var_dump($res);
$res = glob("cache/*");
var_dump($res);
?>
--EXPECT--
array(3) {
  [0]=>
  string(13) "txt/ifile.txt"
  [1]=>
  string(16) "txt/override.txt"
  [2]=>
  string(13) "txt/tfile.txt"
}
array(3) {
  [0]=>
  string(13) "txt/ifile.txt"
  [1]=>
  string(16) "txt/override.txt"
  [2]=>
  string(13) "txt/tfile.txt"
}
array(1) {
  [0]=>
  string(14) "templdir/t.txt"
}
array(1) {
  [0]=>
  string(13) "instdir/t.txt"
}
array(1) {
  [0]=>
  string(15) "cache/cache.txt"
}

