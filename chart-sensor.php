<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<div style="width: 790px;margin: 0px auto;">
	<canvas id="barChart"></canvas>
</div>

<?php

    $db = mysqli_connect('localhost', 'root', '', 'arnosensor');
    $sql = mysqli_query($db, 'Select * from sensor');
    $data = mysqli_fetch_array($sql);

    $a[0] = "Suhu";
    $a[1] = "Kelembaban"; 
    
    $b[0] = $data['suhu'];
    $b[1] = $data['kelembaban'];
?>
<script>
		var ctx = document.getElementById("barChart").getContext('2d');
		var myChart = new Chart(ctx,config1);
		var config1 = {
			type: 'bar',
			data: {
				labels: <?php echo json_encode($a); ?>,
				datasets: [{
					label: 'Grafik Analisis',
					data: <?php echo json_encode($b); ?>,
					backgroundColor: ['rgba(255, 99, 132, 0.2)','rgba(54, 162, 235, 0.2)','rgba(255, 130, 120, 0.1)'],
					borderColor: 'rgba(255,99,132,1)',
					borderWidth: 1
				}]
			},
			options: {
				scales: {
					yAxes: [{
						ticks: {
							beginAtZero:true
						}
					}]
				}
			}
		};
	</script>

    
</body>
</html>