<?php 
	class Config{ // test for invalid enteries
		public static function get($path = null){
			if($path){
				$config = $GLOBALS['config'];
				$path = explode('/', $path);

				foreach ($path as $bit) {
					if (isset($config[$bit])) {
						$config = $config[$bit]; // assign value if found
					}
				}
				return $config; 
			}
			return false;
		}
	}

 ?>