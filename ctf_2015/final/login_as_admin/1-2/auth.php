<?php

function check_auth() {
    if (!isset($_COOKIE['auth']))
        return false;

    $auth = $_COOKIE['auth'];
    $auth = unserialize(base64_decode($auth));

    if (!is_array($auth))
        return false;
    
    // $hmac_key, $database
    include 'config.php';

    $auth['hmac_salt'] = hash_hmac("sha512", $auth['username'].$auth['hmac_salt'].$auth['password'], $hmac_key);

    if ($auth['hmac_salt'] !== $auth['hmac'])
        return false;

    return find_user_pass($auth['username'], $auth['password']);
}


function find_user_pass($user, $pass) {
    // $database
    include 'config.php';
    foreach ($database as $row) {
        if ($row['username'] == $user && $row['password'] == $pass)
            return $row['username'];
    }
    return false;
}


function set_auth($user, $pass) {
    // $hmac_key
    include 'config.php';

    $salt = hash("sha512", openssl_random_pseudo_bytes(32));
    $hmac = hash_hmac("sha512", $user.$salt.$pass, $hmac_key);
    $auth = array(
        'username' => $user,
        'password' => $pass,
        'hmac' => $hmac,
        'hmac_salt' => $salt
    );
    $data = base64_encode(serialize($auth));
    setcookie('auth', $data);
}
