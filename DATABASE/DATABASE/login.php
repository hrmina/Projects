<?php

include "connection.php";
session_start();
$uname = $_POST['name'];
$upass = $_POST['password'];

$sql="select * from user_account where username='$uname' and password='$upass'";

$record = mysqli_query($con,$sql);
$count = mysqli_num_rows($record);

if($count==1)
{
        $_SESSION[ID]="143";
        header ("location: products.html");

}
else
{
        echo "RECORD NOT FOUND";

}


?>