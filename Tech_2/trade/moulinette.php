#!/usr/bin/php
<?php

require_once('tradeError.php');
require_once('tradeCheck.php');
require_once('tradeInfo.php');
require_once('tradeColor.php');

define('ENDFILE', "--end--\n");
define('EXEC', './');
define('BUY', 'buy');
define('SELL', 'sell');
define('PASS', 'passe');

define('IN', 0);
define('OUT', 1);
define('SPREAD', 0.15);

/**
** Initialisation of the trade structure.
**
** Can be useful (and used) for some checks and calculations...
**
** @param array &$a_trade trade information
** @param array &$a_opt option information
**
** @return none
** @access protected
*/
function			init(&$a_trade,
				     &$a_opt)
{
  $i_sum			= 0;
  $a_trade['money']		= 0;
  $a_trade['action']		= array();
  $a_trade['actionIndex']	= 0;
  $a_trade['currentDay']	= 0;
  $a_trade['share']		= 0;
  $a_trade['error']		= 0;
  $a_trade['program']		= NULL;

  $a_trade['data'] = file($a_opt['f']);
  for ($i_i = 0; isset($a_trade['data'][$i_i + 2]); ++$i_i)
  {
    if (!strcmp($a_trade['data'][$i_i + 2], ENDFILE))
      break ;
    $i_sum += $a_trade['data'][$i_i + 2];
  }
  $a_trade['money'] = $a_opt['m'];
  $a_trade['currentMoney'] = $a_trade['money'];
  $a_trade['day'] = count($a_trade['data']) - 1;
  if (strncmp($a_opt['p'], EXEC, 2))
    $a_trade['program'] = EXEC;
  $a_trade['program'] .= $a_opt['p'];
}

/**
** Execute the command.
**
** Execute the command. Model.
**
** @param array &$a_trade trade information
** @param string $s_cmd Command string
** @param int $i_number Share number
**
** @return none
** @access protected
**
** addendum by Nikola Cebovic cebovi_n on february 2012:
** add of the market spread of define(SPREAD) per s_cmd
*/
function	execCmd(&$a_trade,
			$s_cmd,
			$i_number)
{
  if ($s_cmd == BUY)
  {
    $a_trade['currentMoney'] -= $i_number * intval(@$a_trade['data'][$a_trade['currentDay']]);
    $a_trade['share'] += $i_number;
    $a_trade['currentMoney'] -= ceil(($i_number * intval($a_trade['data'][$a_trade['currentDay']]) * SPREAD) /100);

 }
  else if ($s_cmd == SELL)
  {
    $a_trade['currentMoney'] += $i_number * intval(@$a_trade['data'][$a_trade['currentDay']]);
    $a_trade['share'] -= $i_number;
    $a_trade['currentMoney'] -= ceil(($i_number * intval($a_trade['data'][$a_trade['currentDay']]) * SPREAD) /100);
  }
}

/**
** Check if the command is valid.
**
** Check if the command is valid. If not, a var is set with an error
** code.
**
** @param array &$a_trade trade information
** @param string $s_cmd Command string
** @param array $a_argument Command argument
**
** @return boolean Return false is an error occured. Else true.
** @access protected
*/
function	cmdIsValid(&$a_trade,
			   $s_cmd,
			   $a_argument)
{
  $i_number	= 0;

  if (count($a_argument) != 2)
  {
    $a_trade['error'] = tradeError::BADARGUMENT;
    return (false);
  }
  if (!is_numeric($a_argument[1]))
  {
    $a_trade['error'] = tradeError::ARGNOTNUMERIC;
    return (false);
  }
  $i_number = intval($a_argument[1]);
  if ($i_number < 0)
  {
    $a_trade['error'] = tradeError::BADARGUMENT;
    return (false);
  }
  if ($s_cmd == BUY)
  {
    if (($i_number * intval(@$a_trade['data'][$a_trade['currentDay']]) >
	 $a_trade['currentMoney']))
    {
      $a_trade['error'] = tradeError::CANTBUY;
      return (false);
    }
    if ($a_trade['day'] == $a_trade['currentDay'])
    {
      $a_trade['error'] = tradeError::CANTBUYLASTDAY;
      return (false);
    }
  }
  if ($s_cmd == SELL)
  {
    if ($i_number > $a_trade['share'])
    {
      $a_trade['error'] = tradeError::CANTSELL;
      return (false);
    }
  }
  execCmd($a_trade, $s_cmd, $i_number);
  return (true);
}

/**
** Check the current action.
**
** Check the current action. If an error happens, a var is set
** with the error code.
**
** @param array &$a_trade trade information
** @param string $s_buffer Command string
**
** @return boolean Return false is an error occured. Else true.
** @access protected
*/
function	actionIsValid(&$a_trade,
			      $s_buffer)
{
  $a_cmd	= array(BUY, SELL, PASS);
  $a_data	= array();

  $a_trade['action'][$a_trade['actionIndex']] = $s_buffer;
  ++$a_trade['actionIndex'];
  $s_buffer = trim($s_buffer, "\n");
  $a_data = explode(' ', $s_buffer);
  $s_cmd = $a_data[0];
  if (!in_array($s_cmd, $a_cmd))
  {
    $a_trade['error'] = tradeError::INVALIDCMD;
    return (false);
  }
  if ($s_cmd != PASS && !cmdIsValid($a_trade, $s_cmd, $a_data))
    return (false);
  return (true);
}

/**
** Core trade.
**
** Call a process. Send information to this process.
**
** @param array &$a_trade trade information
** @param array $a_opt trade option
**
** @return none
** @access protected
*/
function	trade(&$a_trade,
		      $a_opt)
{
  $r_fd		= NULL;
  $s_buffer	= NULL;
  $b_start	= false;
  $a_descriptor	= array(0 => array('pipe', 'r'),
			1 => array('pipe', 'w'),
			2 => array('file', 'error.file', 'w'));
  $a_pipes	= array();

  $r_fd = proc_open($a_trade['program'], $a_descriptor, $a_pipes);
  if (is_resource($r_fd))
  {
    while (true)
    {
      if ($b_start === false && ($b_start = true))
      {
	fwrite($a_pipes[IN], $a_trade['money']."\n");
	fwrite($a_pipes[IN], $a_trade['day']."\n");
	fwrite($a_pipes[IN], $a_trade['data'][$a_trade['currentDay']]);
      }
      $s_buffer = fgets($a_pipes[OUT]);
      if ($s_buffer === false || @$a_trade['data'][$a_trade['currentDay']] == ENDFILE)
	break ;
      if (!actionIsValid($a_trade, $s_buffer))
	break ;
      if (isset($a_opt['o']))
	tradeInfoOutput($a_trade);
      fwrite($a_pipes[IN], @$a_trade['data'][++$a_trade['currentDay']]);
    }
    if ($a_trade['share'])
      $a_trade['error'] = tradeError::SELLISMANDATORY;
    proc_close($r_fd);
  }
}

/**
** Main function
**
** @param int $i_argc Number of arguments
** @param array $a_argv Arguments
**
** @return none
** @access public
*/
function	main($i_argc,
		     $a_argv)
{
  $a_shortOpt	= "of:p:m:";
  $a_longOpt	= array();
  $a_opt	= array();
  $a_trade	= array();

  $a_opt = getopt($a_shortOpt, $a_longOpt);
  if (checkParam($i_argc, $a_argv) === false)
    return ;
  if (checkOpt($a_opt) === false)
    return ;
  if (checkFile($a_opt['f']) === false)
    return ;
  init($a_trade, $a_opt);
  trade($a_trade, $a_opt);
  tradeInfo($a_trade);
}

main($argc, $argv);

?>
