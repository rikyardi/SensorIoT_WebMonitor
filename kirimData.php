<?php 
    //koneksi ke db
    $db = mysqli_connect('localhost', 'root', '', 'arnosensor');

    //get data from arno
    $suhu = $_GET['suhu']; //sensor dari variabel di arno
    $kelembaban = $_GET['kelembaban'];
    mysqli_query($db, "Update sensor set suhu='$suhu', kelembaban='$kelembaban'");    
    
?>
