//
// MyText.hpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:44 2012 Sampson SAVINEL
// Last update Sun Jun  3 23:34:41 2012 jason leo
//

#ifndef		__MY_MYCURSOR
# define	__MY_MYCURSOR

# include	<string>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Text.hpp"
# include       "Color.hpp"
# include	"AObject.hpp"
# include       "Image.hpp"
# include	"FMOD/fmod.h"

class		MyCursor : public AObject {
  gdl::Image	texture_;
  int		i_;
  int		pos_;
  bool		isDown_up;
  bool		isDown_down;
  FMOD_SYSTEM			*system;
  FMOD_SOUND			*musique;
  FMOD_RESULT			resultat;
public:
  MyCursor(float x, float z);

  void		setText(std::string text);
  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void		draw();
  void		switchToOrtho();
  void		switchBackToPerspective();
};

#endif		//MY_MENU
