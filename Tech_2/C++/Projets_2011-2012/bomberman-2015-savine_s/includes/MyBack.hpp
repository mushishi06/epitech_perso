//
// MyBack.hpp for  in /home/leo_j//Tech2/ProgC++/gitolite@89.92.92.67:bomberman.git/includes
//
// Made by jason leo
// Login   <leo_j@epitech.net>
//
// Started on  Sun Jun  3 06:01:15 2012 jason leo
// Last update Sun Jun  3 11:00:13 2012 jason leo
//

#ifndef		__MY_BACK
# define	__MY_BACK

# include	<string>
# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Text.hpp"
# include       "Color.hpp"
# include	"AObject.hpp"
# include       "Image.hpp"

class		MyBack : public AObject {
  gdl::Image	texture_;
  std::string	texture_name;

public:
  MyBack(std::string text, float x, float z);
  MyBack(float x, float z);

  void		setText(std::string text);
  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void		draw();
  void		switchToOrtho();
  void		switchBackToPerspective();
};

#endif		//MY_BACK
