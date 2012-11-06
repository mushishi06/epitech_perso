//
// Arguments.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Sun Mar 18 00:47:28 2012 igor morenosemedo
// Last update Sun Mar 18 01:07:21 2012 igor morenosemedo
//

#include "Arguments.hh"

unsigned int ArgErr::getValue(const std::string &param)
{
  std::istringstream	iss(param);
  unsigned int	tmp;

  iss >> tmp;
  return (tmp);
}

bool ArgErr::isGood(const std::string &param)
{
  unsigned int	nb;
  unsigned int	i;

  for (i = 0; i < param.length(); i++)
    if (param[i] < '0' || param[i] > '9')
      return (false);
  nb = getValue(param);
  if (nb < MAPWIDTH || nb > WALLWIDTH)
    return (false);
  return (true);
}

