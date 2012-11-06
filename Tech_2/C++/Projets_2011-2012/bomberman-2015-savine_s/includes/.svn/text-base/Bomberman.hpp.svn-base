//
// bomberman.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 16:42:49 2012 Sampson SAVINEL
// Last update Sun Jun  3 21:31:44 2012 cedric santarelli
//

#ifndef		__BOMBERMAN_HPP__
# define	__BOMBERMAN_HPP__

# include <string>

/* ENUM */
typedef enum
  {
    PLAYER = 1,
    IA,
    BOT,
    BOMB,
    BONUS_NB_BOMB,
    BONUS_SPEED,
    BONUS_PORT_BOMB,
    BONUS_NB_BOMB_IND,
    BONUS_SPEED_IND,
    BONUS_PORT_BOMB_IND,
    DESTRUCTIBLE,
    INDESTRUCTIBLE,
    GRASS,
    DOOR_CLOSE,
    DOOR_OPEN,
    FIRE,
    TEXT,
    DANGER,
    TIMER
  }		e_type;

/* STRUCT */
typedef struct	s_param_map
{
  int		character_max;
  int		player;
  int		weight;
  int		height;
}		t_param_map;

typedef struct s_expl
{
  int dir;
  int height;
}t_expl;

typedef struct s_type
{
  e_type type;
  std::string texture_name;
}t_type;

#endif		/*!__BOMBERMAN_HPP__*/

