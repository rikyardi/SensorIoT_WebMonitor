<?php 
$db = mysqli_connect('localhost', 'id16662570_root', 'mIsuhn+~p?-{Bg5n', 'id16662570_arnosensor');
    if (isset($_GET['suhu']) AND isset($_GET['kelembaban']) AND isset($_GET['sto']))
    {
        $suhu = $_GET['suhu']; 
        $kelembaban = $_GET['kelembaban'];
        $sto = $_GET['sto'];
        mysqli_query($db, "Update sensor set suhu='$suhu', kelembaban='$kelembaban' where sto='$sto'");  
    }else {
        mysqli_query($db, "Update sensor set suhu='NaN', kelembaban='NaN'");  
    }
?>