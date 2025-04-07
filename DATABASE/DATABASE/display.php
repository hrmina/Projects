<html>
<head> 
<title> Records </title>
</head>

<body>

<h1> Records </h1>
<hr><br>

<table align="right" width="10%">
 <tr>
<td>
<h3 align="right"> <a href="products.html">Back</a></h3>
</td>
<td>
<h3 align="right"> <a href="logout.php">Logout</a></h3> 
</td>
</tr>
</table>


<table align="center" border=1 width="50%">

<?php

   include "connection.php";

   $sql = "select * from products";
   $records = mysqli_query($con,$sql);

        echo "<tr>";
        echo "<td>ID</td>";
        echo "<td>Name</td>";
        echo "<td>Category</td>";
        echo "<td>Price</td>";
        echo "<td>QTY</td>";
        echo "<td>Date</td>";
             echo "<td>Delete</td>";
     
        echo "</tr>";
 
   
   while($data = mysqli_fetch_array($records))
   {

        $id = $data['id'];
        $name = $data['name'];
        $cat = $data['category'];
        $pr = $data['price'];
        $qty = $data['qty'];
        $dd = $data['date_delivered'];

        echo "<tr>";
        echo "<td>".$id."</td>";
        echo "<td>".$name."</td>";
        echo "<td>".$cat."</td>";
        echo "<td>".$pr."</td>";
        echo "<td>".$qty."</td>";
        echo "<td>".$dd."</td>";
        echo "<td><a href=''>Delete </a></td>";
        echo "</tr>";




   }



?>

</table>

</body>
</html>