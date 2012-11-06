//
// string_to_nbr.hpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 14:12:18 2012 laurent ha-tam-dan
// Last update Sat May 19 14:17:56 2012 laurent ha-tam-dan
//

#ifndef		__STRING_TO_NBR_HPP__
# define	__STRING_TO_NBR_HPP__

# include	<sstream>

template<typename T>
T	string_to_nbr(const char *str)
{
  std::stringstream	tmp(str);
  T	nbr;

  tmp >> nbr;
  return (nbr);
}

#endif	/* !__STRING_TO_NBR_HPP__ */
