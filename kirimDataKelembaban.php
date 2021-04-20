<?php 
//koneksi ke db
    $db = mysqli_connect('localhost', 'root', '', 'arnosensor');

//get data from arno
    $nilai1 = $_GET['sensor'];
    mysqli_query($db, "Update sensor set kelembaban='$nilai1'");

?>