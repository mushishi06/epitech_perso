//
// MyText.hpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:44 2012 Sampson SAVINEL
// Last update Sun Jun  3 10:58:38 2012 jason leo
//

#ifndef		__MY_MENU
# define	__MY_MENU

# include	<string>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Text.hpp"
# include       "Color.hpp"
# include	"AObject.hpp"
# include       "Image.hpp"

class		MyMenu : public AObject {
  gdl::Image	texture_;
  std::string	texture_name;

public:
  MyMenu(std::string text, float x, float z);
  MyMenu(float x, float z);

  void		setText(std::string text);
  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void		draw();
  void		unload(void);
  void		switchToOrtho();
  void		switchBackToPerspective();
};

#endif		//MY_MENU
