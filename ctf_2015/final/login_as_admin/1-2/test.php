<?php
$username = 'admin';
$password = '123';
$hmac_key = '123';
$a = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa';
$salt = hash("sha512", $a);
$hmac = hash_hmac("sha512", $username.$salt.$password, $hmac_key)."\n";
$auth = array(
    'username' => $username,
    'password' => $password,
    'hmac' => $hmac,
    'hmac_salt' => $salt
);
$data = base64_encode(serialize($auth));
echo $data."\n";
?>
