//
// Primitive.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 18:42:00 2012 Sampson SAVINEL
// Last update Thu May 17 16:24:45 2012 Sampson SAVINEL
//

#ifndef			__PRIMITIVE
# define		__PRIMITIVE

# include		<GL/gl.h>
# include		<GL/glu.h>

# include		"Input.hpp"
# include		"GameClock.hpp"

# include		"AObject.hpp"

namespace	Primitive
{
  class		Triangle : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const&, gdl::Input &);
    void	draw(void);
  };

  class		Rectangle : public AObject
  {
    void	initialize(void);
    void	update(gdl::GameClock const&, gdl::Input &);
    void	draw(void);
  };
}

#endif			//PRIMITIVE
