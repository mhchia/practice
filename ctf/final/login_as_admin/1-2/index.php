<?php
// Flag_1: CTF{sucks_robots!!Backup_file_is_dangerous}

include 'auth.php';

if (isset($_GET['logout'])) {
    setcookie('auth', null);
    header('Location: /~b99902063');
    exit();
}

$user = check_auth();

if (isset($_POST['user']) && isset($_POST['pass'])) {
    $username = (string)$_POST['user'];
    $password = (string)$_POST['pass'];

    if (find_user_pass($username, $password)) {
        set_auth($username, $password);
        header("Location: /");
        exit();
    } else {
        exit("Login Failure.");
    }
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <meta name="description" content="">
    <meta name="author" content="">

    <title>Login as admin 1</title>

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="css/custom.css" rel="stylesheet">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>

  <body>

    <nav class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="/">Login as admin 1</a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
          <?php if ($user === false) : ?>
            <form class="navbar-form navbar-right" method="post">
              <div class="form-group">
                <input type="text" name="user" placeholder="Username" class="form-control">
              </div>
              <div class="form-group">
                <input type="password" name="pass" placeholder="Password" class="form-control">
              </div>
              <button type="submit" class="btn btn-success">Sign in</button>
            </form>
          <?php else : ?>
            <ul class="nav navbar-nav navbar-right">
              <li><a href="#"><?php print $user ?></a></li>
              <li><a href="?logout=true">Logout</a></li>
            </ul>
          <?php endif; ?>
          
        </div><!--/.navbar-collapse -->
      </div>
    </nav>
    <div class="container">
      <div>
          <h1>Snoopy Login System</h1>
          <img src="https://scontent.xx.fbcdn.net/hphotos-xat1/t39.1997-6/p160x160/12057056_1390600251241456_1148022415_n.png">
          <p class="lead">
              Welcome to Snoopy Login System!<br>
              Can you login as <code>admin</code>?<br>
              Guests can login with <code>guest</code>/<code>guest</code>.
          </p>
          <?php if ($user) {
                  print "<p class='lead'>Hi ${auth['username']}! You're logined.<br>";
                  if ($user === "admin") {
                      include 'flag.php';
                      print "Flag_2 is: <code>$flag_2</code><br>";
                  }
                  else {
                      print "Try to login as <code>admin</code>!!!!!<br>";
                  }
                  print "</p>";
              }
          ?>
      </div>
    </div><!-- /.container -->

    <!-- Bootstrap core JavaScript
    ================================================== -->
    <!-- Placed at the end of the document so the pages load faster -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>
