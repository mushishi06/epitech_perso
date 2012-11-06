//
// MyText.hpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:44 2012 Sampson SAVINEL
// Last update Sun Jun  3 10:57:13 2012 jason leo
//

#ifndef		__MY_TEXT
# define	__MY_TEXT

# include	<string>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Text.hpp"
# include       "Color.hpp"
# include	"AObject.hpp"
# include       "Image.hpp"

class		MyText : public AObject {
  gdl::Image	texture_;
  std::string	text_;
  std::string	list_;
  int		height_;

public:
  MyText(std::string text, float x, float z, int height);
  MyText(float x, float z, int height);

  void		setText(std::string text);
  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void		draw();
  void		switchToOrtho();
  void		switchBackToPerspective();
};

#endif		//MY_TEXT
