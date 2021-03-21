<?php
	if (!empty($_GET)) {
         $db_config = array(
        "host" => "localhost",
        "name" => "arduino",
        "login" => "root",
        "pass" => ""
         );

        $curr_date = date('d/m/Y G:i:s');
        $conn = new mysqli($db_config['host'], $db_config['login'], $db_config['pass'],$db_config['name']) or die("Connect failed: %s\n". $conn -> error);
        $conn->query("INSERT INTO sensor_level(result, date)  VALUES ({$_GET['dat1']}, '{$curr_date}')");
        $conn->query("INSERT INTO sensor_temp(result, date)  VALUES ({$_GET['dat2']}, '{$curr_date}')");
        $conn->query("INSERT INTO sensor_ph(result, date)  VALUES ({$_GET['dat3']}, '{$curr_date}')");
        print_r("OK");
    } else {
        print_r("NO");
    }
    
?>