//
// string_to_nbr.hpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 14:12:18 2012 laurent ha-tam-dan
// Last update Sun Jun  3 12:26:31 2012 cedric santarelli
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

template<typename T>
std::string	nbr_to_string(T nb)
{
  std::stringstream	tmp;

  tmp << nb;
  return (tmp.str());
}


#endif	/* !__STRING_TO_NBR_HPP__ */
