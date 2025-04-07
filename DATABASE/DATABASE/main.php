<?php

session_start();

if(!$_SESSION["ID"]==143)
{

      header("location:login.html");
}


?>


<html>
<head>
       <title> Login
                        </title>
</head>
<body>

hello word
<br><br>

<a href="logout.php">Logout</a>

</body>
</html>
