<?php

$db = mysqli_connect('localhost', 'root', '', 'arnosensor');

$sql = mysqli_query($db, 'Select * from sensor');
$data_1 = mysqli_fetch_array($sql);
$nilai_1 = $data_1['kelembaban'];
echo $nilai_1;

?>