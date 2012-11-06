//
// bomberman.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 16:42:49 2012 Sampson SAVINEL
// Last update Wed May 23 19:40:38 2012 belia-_r
//

#ifndef		__BOMBERMAN_HPP__
# define	__BOMBERMAN_HPP__

#include	"AObject.hpp"
#include <deque>
/* ENUM */
typedef enum
  {
    PLAYER = 1,
    IA,
    BOT,
    BOMB,
    BONUS,
    DESTRUCTIBLE,
    INDESTRUCTIBLE,
    BACKGROUND
  }		e_type;

/* STRUCT */
typedef struct	s_param_map
{
  int		character_max;
  int		player;
  int		weight;
  int		height;
}		t_param_map;
struct	t_label_xml
{
  e_type	m_type;
  const char*	m_start;
  const char*	m_end;
  void	(*save_func)(std::deque<AObject*>::iterator &, std::fstream &);
};

struct	t_load_xml
{
  e_type	m_type;
  const char*	m_start;
  const char*	m_end;
  void	(*func)(std::deque<AObject*> &, std::fstream &);
};
#endif		/*!__BOMBERMAN_HPP__*/

