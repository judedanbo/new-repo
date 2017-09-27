<?php 
	/**
	* Token class to prevent cross site request
	*/
	class Token{
		public static function generate(){
			return  Session::put(Config::get('session/token_name'), md5(uniqid()));
		}

		public static function check($token){
			$tokenName = Config::get('session/token_name');
			
			if (Session::exists($tokenName) && $token === Session::get($tokenName)){
				echo("in if");
				Session::delete($tokenName);
				return true;
			}
			return false; 
		}
	}

 ?>