<?php

include "config.php";

$con = mysqli_connect($host,$user,$password);

mysqli_select_db($con,$db_name);

?>