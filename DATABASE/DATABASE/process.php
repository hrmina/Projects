<?php

session_start();
$name = $_POST['uname'];
$un = $_POST['user'];
$pass = $_POST['password'];


$con = mysqli_connect("localhost","root","");

mysqli_select_db($con,"htagle301a2019");

$sql = "insert into user_account(name,username,password)values('$name','$un','$pass')";

$record = mysqli_query($con,$sql);

if($record==1)
{
        $_SESSION[ID]="143";
        header ("location: login.html");

}



?>