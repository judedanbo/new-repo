<?php 

	 class Validate {
	 	private $_passed = false,
	 			$_errors = array(),
	 			$_db = null;

	 	public function __construct(){
	 		$this->_db = DB::getInstance();
	 	}

	 	Public function check($source, $items = array()){
	 		//var_dump($source);
	 		//echo("<br>");
	 		//var_dump($items);
	 		foreach ($items as $item => $rules) {
	 			foreach ($rules as $rule => $rule_value) {
	 				$value = trim($source[$item]);
	 				$item = escape($item);
	 				
	 				//var_dump(empty($value));
	 				
	 				//var_dump($rule === 'required');
	 				//echo " <br> ";
	 				if($rule === 'required' && empty($value) ){
	 					//var_dump($value );
	 					$this->addError("{$item} is Required " );
	 				}else if(!empty($value)){
	 					switch ($rule) {
	 						case 'min':
	 							if(strlen($value) < $rule_value){
	 								$this->addError("{$item} must be a minimum of {$rule_value} characters.");
	 							}
	 							break;
	 						case 'max':
	 							if(strlen($value) > $rule_value){
	 								$this->addError("{$item} must not be more than {$rule_value} characters.");
	 							}
	 							break;
	 						case 'matches':
	 							if($value != $source[$rule_value]){
	 								$this-> addError("{$rule_value} must match {$item}");
	 							}
	 							break;
	 						case 'unique':
	 							//echo "$item";
	 							$check = $this->_db->get($rule_value, array($item, '=', $value));
	 							// 	$user = DB::getInstance()->get("wta_user", array('username','=','Alex'));

	 							//var_dump($check);
	 							if ($check->count()) {
	 								$this->addError("{$item} already exists");	 							}
	 							break;
	 					}
	 				}
	 			}
	 		}
	 		if(empty($this->_errors)){
	 			$this->_passed = true;
	 		}

	 		return $this;
	 	}

	 	private function addError($error){
	 		$this->_errors[] = $error ;
	 	}

	 	public function errors(){
	 		return $this->_errors;
	 	}
	 	public function passed(){
	 		//return "passed returned";
	 		return $this->_passed;
	 	}
	 }
 ?>