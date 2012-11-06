//
// ParamChecker.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Thu Mar 15 20:45:30 2012 igor morenosemedo
// Last update Fri Mar 16 00:50:05 2012 igor morenosemedo
//
//

#ifndef _PARAMCHECKER_HH_
# define _PARAMCHECKER_HH_

#  include	<string>
#  include	<sstream>
#  include	<iostream>
#  include	"Snake.hh"

class		ParamChecker
{
public:
  static bool		isGood(const std::string &param)
  {
    unsigned int	nb;

    for (unsigned int i = 0; i < param.length(); i++)
      if (param[i] < '0' || param[i] > '9')
	return (false);
    nb = ParamChecker::getValue(param);
    if (nb < MAPWIDTH || nb > WALLWIDTH)
      return (false);
    return (true);
  }

  static unsigned int	getValue(const std::string &param)
  {
    std::istringstream	iss(param);
    unsigned int	tmp;

    iss>>tmp;
    return (tmp);
  }
};

#endif
