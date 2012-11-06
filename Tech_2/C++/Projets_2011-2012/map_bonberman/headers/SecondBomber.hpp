//
// SecondBomber.hpp for  in /home/jason/Tech2/ProgC++/Bomberman.Git/gitolite@89.92.92.67:bomberman.git/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 20:51:42 2012 Jason Leo
// Last update Mon May 21 20:52:09 2012 Jason Leo
//

#ifndef		__SECONDBOMBER_HPP__
# define	__SECONDBOMBER_HPP__

# include	<stdlib.h>
# include	<iostream>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"GameClock.hpp"
# include	"Player.hpp"
# include	"Model.hpp"

class		SecondBomberman : public Player
{
public:
  SecondBomberman(float, float, e_type);
  ~SecondBomberman(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
};

#endif		/*!__SECONDBOMBER_HPP__*/
