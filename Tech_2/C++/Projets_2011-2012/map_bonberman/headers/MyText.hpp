//
// MyText.hpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:44 2012 Sampson SAVINEL
// Last update Mon May 21 19:39:57 2012 Jason Leo
//

#ifndef		__MY_TEXT
# define	__MY_TEXT

# include	<list>
# include	<string>

# include	"Text.hpp"
# include       "Color.hpp"
# include	"Input.hpp"
# include	"AObject.hpp"
# include	"GameClock.hpp"

class MyText : public AObject {
public:
  MyText(std::string, std::string, gdl::Color, int, unsigned int, unsigned int);

  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void draw();

  gdl::Text _text;
};

#endif		//MY_TEXT
