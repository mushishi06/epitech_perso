//
// Bomber.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 13:35:15 2012 Jason Leo
// Last update Mon May 21 19:39:16 2012 Jason Leo
//

#ifndef		__BOMBER_HPP__
# define	__BOMBER_HPP__

# include	<stdlib.h>
# include	<iostream>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"GameClock.hpp"
# include	"Player.hpp"
# include	"Model.hpp"

class		Bomberman : public Player
{
public:
  Bomberman(float, float, e_type);
  ~Bomberman(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
};

#endif		/*!__BOMBER_HPP__*/
