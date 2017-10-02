<?php
	require_once("mySQLMethode.class.php")
	
	$mysqlmethode=new mySQLMethode();
	$mysqlmethode->setUsername("root");
	$mysqlmethode->setPassword("root");
	$mysqlmethode->setDatabaseName("");

	
	$mysqlmethode->mySQLConnect();
	$sql=""
	$mysqlmethode->closeConnect();


?>
