//
// Background.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes_gdl
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Fri May 18 14:56:29 2012 Jason Leo
// Last update Mon May 21 19:38:56 2012 Jason Leo
//

#ifndef		__BACKGROUND_HPP_
# define	__BACKGROUND_HPP_

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"AObject.hpp"
# include	"Image.hpp"

class		Accueil : public AObject
{
private:
  gdl::Image	texture_;

public:
  Accueil(float, float, e_type);
  ~Accueil(void);

  void	initialize(void);
  void	update(gdl::GameClock const&, gdl::Input &, std::deque<AObject*> &);
  void	draw(void);
};

#endif		/*!__BACKGROUND_HPP__*/
