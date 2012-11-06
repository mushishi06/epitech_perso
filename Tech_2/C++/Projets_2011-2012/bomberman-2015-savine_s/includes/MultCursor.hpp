//
// MyText.hpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:44 2012 Sampson SAVINEL
// Last update Sun Jun  3 10:52:55 2012 jason leo
//

#ifndef		__MY_MULTCURSOR
# define	__MY_MULTCURSOR

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"AObject.hpp"
# include       "Image.hpp"

class		MultCursor : public AObject {
  gdl::Image	texture_;
  int		i_;
  int		pos_;
  bool		isDown_up;
  bool		isDown_down;

public:
  MultCursor(float x, float z);

  void		setText(std::string text);
  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void		draw();
  void		unload(void);
  void		switchToOrtho();
  void		switchBackToPerspective();
};

#endif		//MY_MENU
