<?php

$db = mysqli_connect('localhost', 'id16662570_root', 'mIsuhn+~p?-{Bg5n', 'id16662570_arnosensor');
$sto = $_GET['sto'];

$sql = mysqli_query($db, "Select * from sensor where sto='$sto'");
$data_1 = mysqli_fetch_array($sql);
$nilai_1 = $data_1['kelembaban'];
echo $nilai_1;

?>