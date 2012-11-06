<?php

function	usage($s_name)
{
  echo "Usage: php ".$s_name." -p prog -f file -m money [-o]\n";
}

/**
** Checks Parameters.
**
** Checks the number of arguments
**
** @param array $a_param Parameters
**
** @return boolean True if parameter exists.
** @access public
*/
function	checkParam($i_argc,
			   $a_argv)
{
  if ($i_argc >= 7)
    return (true);
  usage($a_argv[0]);
  return (false);
}


/**
** Check option
**
** @param array $a_opt Options
**
** @return boolean True if require option exists.
** @access public
*/
function	checkOpt($a_opt)
{
  $a_requireOpt	= array("p", "f", "m");
  $s_value	= NULL;

  foreach ($a_requireOpt as $s_value)
    if (array_key_exists($s_value, $a_opt) === false)
    {
      echo "Error: Missing option [".$s_value."]\n";
      return (false);
    }
  return (true);
}

/**
** Checks the file.
**
** @param string $s_file File
**
** @return boolean True if the file is correct
**
*/
function	checkFile($s_file)
{
  if (!file_exists($s_file))
  {
    echo "Error: \"".$s_file."\" doesn't exists.\n";
    return (false);
  }
  if (count(file($s_file)) < 3)
  {
    echo "Error: \"".$s_file."\" is not valid.\n";
    return (false);
  }
  return (true);
}

?>
