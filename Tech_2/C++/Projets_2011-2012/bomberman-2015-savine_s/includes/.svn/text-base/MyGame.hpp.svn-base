//
// MyGame.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Thu May 10 15:22:13 2012 Sampson SAVINEL
// Last update Sun Jun  3 23:34:29 2012 jason leo
//

#ifndef		__MY_GAME_HPP__
# define	__MY_GAME_HPP__

# include	<cstdlib>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Game.hpp"
# include	"Timer.hpp"
# include	"Camera.hpp"
# include	"FMOD/fmod.hpp"

class		MyGame : public gdl::Game
{
protected :
  Camera			camera_;
  Timer				*timer_;
  t_param_map			param_map_;
  int				game_;
  std::deque<AObject*>		objects_;
  std::deque<std::string>	list_;
  int				movie_;
  bool				passVid;
  FMOD_SYSTEM			*system;
  FMOD_SOUND			*musique;
  FMOD_RESULT			resultat;

public :
  void		initialize(void);
  void		update(void);
  void		draw(void);
  void		unload(void);
};

#endif		/*!__MYGAME_HPP__*/
