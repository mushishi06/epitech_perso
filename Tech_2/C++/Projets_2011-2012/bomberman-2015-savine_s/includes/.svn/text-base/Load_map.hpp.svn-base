//
// Load_map.hpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/git_bomber/includes
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Thu May 24 16:13:47 2012 laurent ha-tam-dan
// Last update Sun Jun  3 18:39:52 2012 laurent ha-tam-dan
//

#ifndef		__LOAD_MAP_HPP__
# define	__LOAD_MAP_HPP__

# include	<vector>
# include	<fstream>
# include	"AObject.hpp"

# define	TYPE 0
# define	POSX 1
# define	POSY 2
# define	BOMB_MAX 3
# define	BOMB_NB 4
# define	SPEED 5
# define	RANGE 6
# define	N_PLAYER 3
# define	TIMER 4

struct		t_parse_vec
{
  std::string	m_str;
  int		type;
};

struct		t_load_xml
{
  e_type	type;
  void		(*func)(std::deque<AObject*> &map, std::vector<int> &m_vector);
};

bool		load_map(std::deque<AObject*> &map, std::string &map_name, t_param_map &map_param, AObject *m_player);

#endif		/* !__LOAD_MAP_HPP__ */
