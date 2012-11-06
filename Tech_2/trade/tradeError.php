<?php

class				tradeError
{
  const	INVALIDCMD		= 1;
  const	BADARGUMENT		= 2;
  const ARGNOTNUMERIC		= 4;
  const	CANTBUY			= 8;
  const CANTSELL		= 16;
  const	CANTBUYLASTDAY		= 32;
  const	SELLISMANDATORY		= 64;

  static private $a_error	= array(self::INVALIDCMD => 'Invalid command',
					self::BADARGUMENT => 'Bad argument for this command',
					self::ARGNOTNUMERIC => 'Argument is not numeric',
					self::CANTBUY => 'You can not buy',
					self::CANTBUYLASTDAY => 'You can not buy the last day',
					self::CANTSELL => 'You can not sell',
					self::SELLISMANDATORY => 'You should sell your shares the last day');

  static public function	getError($i_errorNum)
  {
    if (array_key_exists($i_errorNum, self::$a_error))
      return (self::$a_error[$i_errorNum]);
    return (NULL);
  }
}

?>
