//
// Save_map.hpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/git_bomber
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Wed May 23 19:43:18 2012 laurent ha-tam-dan
// Last update Sun Jun  3 10:57:55 2012 jason leo
//

#ifndef		__SAVE_MAP_HPP__
# define	__SAVE_MAP_HPP__

# include	<fstream>
# include	"AObject.hpp"

struct		t_label_xml
{
  e_type	m_type;
  void	(*save_func)(std::deque<AObject*>::iterator &, std::fstream &);
};

bool	save_map(std::deque<AObject*> &map, std::string &map_name, t_param_map &map_param);

#endif	/* !__SAVE_MAP_HPP__ */
