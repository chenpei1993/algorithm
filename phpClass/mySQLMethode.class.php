<?php
	//	MySQL 工具类
	// 	作者 陈沛 时间 2016/11/23 
	//	功能作用	 
	//		实现 数据库连接
	//	
	//
	
	Class mySQLMethode{
		private $Username;
		private $Password;
		private $Serveraddress;
		private $conn;
		private $Databasename;
		
		//设置用户名
		public function setUsername($username){
			$this->Username=$username;		
		}
		//设置密码
		public function setPassword($password){
			$this->Password=$password;		
		}
		//设置 地址
		public function setServeraddress($serveraddress){
			$this->Serveraddress=$serveraddress;		
		}
		//设置数据库名字
		public function setDatabaseName($databasename){
			$this->Databasename=$databasename;
		}
		
		//函数mySQLConnect 数据库链接   		
		public function mySQLConnect(){
			$this->conn=mysqli_connect($this->Serveraddress,$this->Username,$this->Password);
			if(!$this->conn){
				die("failed connect with database".mysqli_error());			
			} 
			//设置字体为utf-8
			mysqli_query($this->conn,"set names utf8");
			//选择数据库
			mysqli_select_db($this->conn,$this->dbname);
		}

		//
		public function execute_dql($sql){
			$arr=array();
			$res=mysqli_query($this->conn,$sql) or die(mysqli_error());
			while($row=mysqli_fetch_assoc($res)){
				$arr[]=$row;
			}
			mysqli_free_result($res);
			return $arr;
		}
		

		public function closeConnect(){
			if(empty($this->conn)){
				mysqli_close($this->conn);			
			}
		}
			
		

	

	}




?>
