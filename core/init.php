<?php 
	session_start();

	if (!function_exists('stats_standard_deviation')) {
    /**
     * This user-land implementation follows the implementation quite strictly;
     * it does not attempt to improve the code or algorithm in any way. It will
     * raise a warning if you have fewer than 2 values in your array, just like
     * the extension does (although as an E_USER_WARNING, not E_WARNING).
     * 
     * @param array $a 
     * @param bool $sample [optional] Defaults to false
     * @return float|bool The standard deviation or false on error.
     */
    function stats_standard_deviation(array $a, $sample = false) {
        $n = count($a);
        if ($n === 0) {
            trigger_error("The array has zero elements", E_USER_WARNING);
            return false;
        }
        if ($sample && $n === 1) {
            trigger_error("The array has only 1 element", E_USER_WARNING);
            return false;
        }
        $mean = array_sum($a) / $n;
        $carry = 0.0;
        foreach ($a as $val) {
            $d = ((double) $val) - $mean;
            $carry += $d * $d;
        };
        if ($sample) {
           --$n;
        }
        return sqrt($carry / $n);
    }
}


	$GLOBALS['config'] = array(
		'mysql' => array(
			'host' => '127.0.0.1',
			'username' => 'amisuser',
			'password' => 'inC7!ogr&aKKUTzh5',
			'db' => 'ram'
		),
		'remember' => array(
			'cookie_name' => 'hash',
			'cookie_expiry' => 86400 // 24hrs
		),
		'session' => array(
			'session_name' => 'user',
			'token_name' =>'token'
		)
	);
	function getrootfolder($filename){
		$x = 0;
		$filnameArray = explode('\\', $filename);
		//var_dump($filnameArray);
		//echo(count($filnameArray));
		for($i = (count($filnameArray) - 1); $i > 0; $i--){
			if($filnameArray[$i] === 'AMIS'){
				break;
			}else{
				$x++;
			}
		}
		$path = '';
		for($y = 1; $y <= $x; $y++){
			$path .= '../'; 
		}

		return $path;
	}
	function	nullval($var){
		return Input::get($var) == ""? null: Input::get($var) ;
	}
	function yesno($val){
		return $val == 1 ? "Yes":"No" ;
	}
	function ghanadate($date){
		return  date_format(date_create($date), "d M Y");
	}
	function ghanadatetime($date){
		return  date_format(date_create($date), "dmYHis");
	}
	spl_autoload_register(function($class){
		$page = getrootfolder(getcwd());
		require_once "{$page}classes/".$class.".php";
	});
	/*$numlev = getrootfolder(getcwd());
	//echo ($numlev);
	$path = '';
	for($y = 0; $y < $numlev; $y++){
		$path .= '../'; 
	} */
	$pth = (getrootfolder(getcwd()) );
	require_once "{$pth}functions/sanitize.php";



 ?>