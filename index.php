<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/css/style.css">
	<link rel="stylesheet" href="assets/css/bootstrap.css">
    <script src="assets/js/bootstrap.min.js"></script>
    <script src="assets/js/jquery.min.js"></script>
    <script src="assets/js/Chart.js"></script>

    <script>
    $(document).ready(function(){
        setInterval(function(){
            $("#sensor").load('cekSensorSuhu.php');
        }, 1000);
    });
    </script>
    <script>
    $(document).ready(function(){
        setInterval(function(){
            $("#sensor_1").load('cekSensorKelembaban.php');
        }, 1000);
    });
    </script>
     <script>
    $(document).ready(function(){
        $("#waktu").load('waktu.php');
        setInterval(function(){
            $("#waktu").load('waktu.php');
        }, 1000);
    });
    </script>
</head>
<body>
    <div class="container-fluid">
        <div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h3 style="text-align:center; color:CornflowerBlue; font-family:Segoe UI" class="tebel">Sensor Suhu dan Kelembaban</h3></center>
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
		</div>
		<div class="row">
			<div class="col-md-8 col-md-offset-2">
				<center><h5 style="text-align:center; color:#8FBC8F; font-family:Segoe UI" class="tebel">Data Sensor dengan Arduino IDE, NodeMCU ESP8266, dan DHT11</h5></center>
				<hr style="margin-top: 0px; margin-bottom:0px">
			</div>
			<div class="col-md-2">
				&nbsp;
			</div>
            </div>
		</div>
        <br>
        <div class="container" style="margin-right:100px">
        <div class="col-md-5" style="margin-top:117px">
				<table class="table table-bordered" style="margin-top:5px; margin-left:10px;">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Suhu (&degC)</p></center></td>
					</thead>
					<tr class="success">
						
						<td><center><img style="width:100px" src="assets/img/suhu.png"><h1><p class="tebel" style="margin-top:5px"><span id="sensor">0</span> &#8451</p></h1></center></td>
					</tr>
				</table>
			</div>
			<div class="col-md-5">
				<table class="table table-bordered style=" style="margin-top:5px; margin-right:10px">
					<thead>
						<td><center><p class="tebel" style="margin-top:0px; margin-bottom:0px; font-size:18px">Relative Humidity (%)</p></center></td>
					</thead>
					<tr class="info">
						<td><center><img style="width:100px" src="assets/img/humidity.png" alt=""><h1><p class="tebel" style="margin-top:5px"><span id="sensor_1">0</span>% RH</p></h1></center></td>
					</tr>
                    <div class="ml-auto text-right" style="margin-bottom: 50px"><h3 id="waktu">waktu</h3></div>
                </table>
            </div>
			</div>
            
	</div>
    <blockquote class="blockquote tengah">
        <p class="mb-0">&copy DAFI MUMAMMAR ZULFIKAR & RIKY ARDIANSYAH</p>
        <footer class="blockquote-footer">GitHub : dafimz | rikyardi 
        <cite title="Source Title">Special Thanks To Allah SWT</cite>
        </footer>
    </blockquote>
</body>
</html>