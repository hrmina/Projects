<?php

session_start();
$pname = $_POST['pn'];
$cat = $_POST['category'];
$price= $_POST['p'];
$qty= $_POST['qty'];


$con = mysqli_connect("localhost","root","");

mysqli_select_db($con,"htagle301a2019");

$sql = "insert into products(name,category,price,qty)values('$pname','$cat','$price','$qty')";

$record = mysqli_query($con,$sql);

if($record==1)
{
        $_SESSION[ID]="143";
        header ("location: display.php");

}

?>