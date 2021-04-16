<?php 
    //koneksi ke db
    $db = mysqli_connect('localhost', 'root', '', 'arnosensor');

    //get data from arno
    $nilai = $_GET['sensor']; //sensor dari variabel di arno

    mysqli_query($db, "Update sensor set data_sensor='$nilai'");
    
?>