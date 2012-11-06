//
// MyGame.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Thu May 10 15:22:13 2012 Sampson SAVINEL
// Last update Mon May 21 17:57:37 2012 Jason Leo
//

#ifndef		__MY_GAME_HPP__
# define	__MY_GAME_HPP__

# include	<cstdlib>
# include	<deque>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Game.hpp"
# include	"Image.hpp"
# include	"Camera.hpp"
# include	"AObject.hpp"
# include	"Background.hpp"

class		MyGame : public gdl::Game
{
protected :
  Camera		camera_;
  std::deque<AObject*>	objects_;

public :
  void		initialize(void);
  void		update(void);
  void		draw(void);
  void		unload(void);
};

#endif		/*!__MYGAME_HPP__*/
