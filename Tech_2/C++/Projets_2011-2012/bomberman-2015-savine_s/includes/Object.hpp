//
// Object.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 19:15:55 2012 Sampson SAVINEL
// Last update Sun Jun  3 10:58:21 2012 jason leo
//

#ifndef		__OBJECT_HPP_
# define	__OBJECT_HPP_

# include	"AObject.hpp"
# include	"Image.hpp"
# include	<GL/gl.h>
# include	<GL/glu.h>

class		Cube : public AObject
{
protected:
  gdl::Image	texture_;
  int		time_;
  gdl::Clock    e_time_;

public:
  Cube(float, float, e_type);
  ~Cube(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
};

class		Carre : public AObject
{
protected:
  gdl::Image	texture_;

public:
  Carre(float, float, e_type);
  ~Carre(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);
};

#endif		/*!__OBJECT_HPP__*/

