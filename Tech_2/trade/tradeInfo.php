<?php

/**
** Controller of information
**
** Can be useful for adds some informations...
**
** @param array $a_trade trade information
**
** @return none
** @access protected
*/
function	tradeInfo($a_trade)
{
  tradeInfoMoney($a_trade);
  tradeInfoError($a_trade);
}

/**
** Fast option -o
*/
function	tradeInfoOutput($a_trade)
{
  echo '['.trim($a_trade['data'][$a_trade['currentDay']], "\n").'] -> ';
  echo trim($a_trade['action'][$a_trade['actionIndex'] - 1], "\n")."\n";
}

/**
** Fast money informations
*/
function	tradeInfoMoney($a_trade)
{
  $i_total	= $a_trade['currentMoney'] - $a_trade['money'];

  echo '['.Color::CYAN.'Money'.Color::DEFAULTCOLOR.']'."\n";
  echo "Start:\t\t".$a_trade['money']."\n";
  echo "End:\t\t".$a_trade['currentMoney']."\n";
  echo "Total:\t\t".($i_total > 0 ? Color::GREEN : Color::RED);
  echo ($i_total > 0 ? '+'.$i_total : $i_total).Color::DEFAULTCOLOR."\n";
}

/**
** Fast error
*/
function	tradeInfoError($a_trade)
{
  echo '['.Color::CYAN.'Error'.Color::DEFAULTCOLOR.'] '."\n";
  if ($a_trade['error'])
  {
    echo Color::RED.tradeError::getError($a_trade['error']).Color::DEFAULTCOLOR."\n";
  }
  else
    echo Color::GREEN."\t\t".'none'.Color::DEFAULTCOLOR."\n";
}

?>
