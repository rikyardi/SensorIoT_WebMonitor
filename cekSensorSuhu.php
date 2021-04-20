<?php

$db = mysqli_connect('localhost', 'root', '', 'arnosensor');

$sql = mysqli_query($db, 'Select * from sensor');
$data = mysqli_fetch_array($sql);
$nilai = $data['suhu'];
echo $nilai;

?>