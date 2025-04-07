<?php

session_start();

if(!$_SESSION["ID"]==143)
{

      header("location:products.html");
}


?>


<html>
<head>
       <title> Login
                        </title>
</head>
<body>

Succesfully Added!
<br><br>

<a href="logout1.php">Logout</a>

</body>
</html>
