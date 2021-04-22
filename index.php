<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
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

</head>
<body>
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <a class="navbar-brand" href="#!">Punten Suhu</a>
    </nav>

    <div class="container-fluid">
        <div class="row">
            <div class="col-4 text-center mt-5" style="border-right:1px solid ">
                <h3>Suhu</h3>
                <div class="card">
                    <div class="card-body p-1">
                        <h1 class="card-title"><span id="sensor">100</span> &#8451</h1>
                    </div>
                    
                </div>
                <h3>Kelembaban</h3>
                <div class="card">
                    <div class="card-body p-1">
                <h1 class="card-title"><span id="sensor_1">50</span>% RH</h1>
                </div>
                    
                </div>
         
            </div>
            <div class="col-8 mt-5 bg-dark">
                
            </div>
        </div>
    </div>
</body>
</html>