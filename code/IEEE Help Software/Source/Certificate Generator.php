<?php

/*  
This piece of code is used to automatically generate certificates. 
*/

$database = mysqli_connect("localhost","root","9606740404","ieee_proj");

$query = "select * from event_attendance";
$result = $database->query($query);

?>

<table border="1" cellspacing="0" cellpadding="10">
  <tr>
    <th>S.N</th>
  </tr>
<?php
if ($result->num_rows > 0) {
  $sn=1;
  while($data = $result->fetch_assoc()) {
 ?>
 <tr>
   <td><?php echo $sn; ?> </td>
   <td><?php echo $data['name']; ?> </td>
 <tr>
 <?php
  $sn++;}} else { ?>
    <tr>
     <td colspan="8">No data found</td>
    </tr>
 <?php } ?>
  </table>