<?php 
	/**
	* WITAMA 	
	* Database class
	*/
	class DB  
	{
		// using singleton partern
		private static $_instance = null;
		private $_pdo, 
				$_query, 
				$_error = false, 
				$_result, 
				$_count = 0 ;

		private function __construct(){
			try{
				// pdo call new PDO()
				$this->_pdo = new PDO('mysql:host='. Config::get('mysql/host') . ';dbname=' . Config::get('mysql/db'),Config::get('mysql/username'),Config::get('mysql/password'));
				// $this->_pdo = new PDO('mysql:host=' . Config::get('mysql/host'). ';dbname=' .config::get('mysql/db'),. )

				//echo "Connected";
			}catch(PDOException $e) {
				die($e->getMessage());
			}
		}

		public static function getInstance(){
			// method to instantiate database if its not set to prevent redundant initiation
			if(!isset(self::$_instance)){
				self::$_instance = new DB();
			}
			return self::$_instance;
		}
		public function query($sql, $params = array()){
			$this->_error = false;
			$this->_pdo->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_WARNING );
			if ($this->_query = $this->_pdo->prepare($sql)){
				$x = 1;
				if (count($params)) {
					foreach ($params as $param) {
						$this->_query->bindValue($x, $param);
						$x++;
						//echo(" $param ");
					}
				}
				//var_dump($this->_query);
				if($this->_query->execute()){
					$this->_result = $this->_query->fetchAll(PDO::FETCH_OBJ);
					$this->_count = $this->_query->rowCount();
				}else{
					$this->_error = true;
					//echo "Could not Execute the query";
				}
			}
			return $this;
		}
		public function action($action, $table, $where = array()){
			if(count($where) === 3){
				$operators = array('=','>','<','>=','<=', '<>');
				$field   	= $where[0];
				$operator 	= $where[1];
				$value 		= $where[2];
				if (in_array($operator, $operators)){
					$sql = " {$action} FROM {$table} WHERE {$field} {$operator} ?";
					if(!$this->query($sql, array($value))->error() ){
						return $this;
					}
				}
			}elseif (empty($where)) {
				$sql = " {$action} FROM {$table}";
				if(!$this->query($sql)->error() ){
					return $this;
				}
			}
			return false;
		}

		public function get($table, $where = array()){
			return $this->action('SELECT *', $table, $where);
		}
		public function delete($table, $where){
			return $this->action('DELETE', $table, $where);
		}
		 public function insert($table, $fields =array()){
		 	if (count($fields)){  
		 		$keys = array_keys($fields);
		 		$values = '';
		 		$x = 1;
		 		foreach ($fields as $field) {
		 			$values .= '?';
		 			if($x < count($fields)){
		 				$values .= ', ';
		 			}
		 			$x++;
		 		}

		 		$sql = "INSERT INTO {$table} (`". implode('`, `', $keys) ."`) VALUES ({$values} )" ;
		 		//echo($sql);
		 		//var_dump($fields);
		 		if (!$this->query($sql, $fields)->error()){
		 			return true; 
		 		}
		 	}
		 	return false; 
		 }
		public function update($table, $ids = array(), $fields = array()){
			$set = $where ='';
			$x = $y =  1;
			foreach ($fields as $name => $value) {
				$set .= "{$name} = ? ";
				if($x < count($fields) ){
					$set .= ', ';
				}
				$x++;
			}
			foreach ($ids as $key => $value) {
				$where .= " {$key } = '$value' ";
				if ($y < count($ids)){
					$where .= ' AND ';
				}
				$y++;
			}
			$sql = "UPDATE {$table}  SET {$set} WHERE {$where} ";

			if(!$this->query($sql, $fields)->error() ){
				return true;
			}
			return false;
		}
		public function results(){
			return $this->_result;
		}

		public function error(){
			return $this->_error;
		}

		public function count(){
			return $this->_count;
		}

		public function first(){
			return $this->results()[0];
		}
	}

 ?>