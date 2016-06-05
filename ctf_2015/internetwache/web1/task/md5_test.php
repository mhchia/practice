<?php


$admin_pw = clean_hash("0e408306536730731920197920342119");

$str = 1;
while (true) {
    $str_hash = myhash($str);
    if ($str_hash[0] == '0' && $str_hash[1] == 'e' && $str_hash[2] == '1') {
        echo $str."\n";
        echo $str_hash."\n";
        if ($admin_pw == "0e1cd") { echo "fuck!\n";}
        break;
    }
    $str += 1;
}



function clean_hash($hash) {
            return preg_replace("/[^0-9a-f]/","",$hash);
}

function myhash($str) {
            return clean_hash(md5(md5($str) . "SALT"));
}

?>
