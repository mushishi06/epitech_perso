//
// Object.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 19:15:55 2012 Sampson SAVINEL
// Last update Mon May 21 19:40:13 2012 Jason Leo
//

#ifndef		__OBJECT_HPP_
# define	__OBJECT_HPP_

# include	"Input.hpp"
# include	"GameClock.hpp"
# include	"AObject.hpp"
# include	"Image.hpp"
# include	<GL/gl.h>
# include	<GL/glu.h>

class		Cube : public AObject
{
protected:
  gdl::Image	texture_;

public:
  Cube(float, float, e_type);
  ~Cube(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
};

#endif		/*!__OBJECT_HPP__*/

