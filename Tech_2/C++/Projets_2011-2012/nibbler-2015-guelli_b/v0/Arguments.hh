//
// Arguments.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Sun Mar 18 00:51:02 2012 igor morenosemedo
// Last update Sun Mar 18 01:15:47 2012 badrane guellim
//

#ifndef _ARGUMENTS_HH_
# define  _ARGUMENTS_HH_

#  include	<string>
#  include	<sstream>
#  include	<iostream>

#  include	"Snake.hh"

namespace ArgErr
{
  bool		isGood(const std::string &);
  unsigned int	getValue(const std::string &);
}

#endif
