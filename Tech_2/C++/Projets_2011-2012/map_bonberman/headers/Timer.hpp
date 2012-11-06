//
// Timer.cpp<2> for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 22:06:47 2012 Sampson SAVINEL
// Last update Mon May 21 19:40:55 2012 Jason Leo
//

#ifndef		__TIMER
# define	__TIMER

# include	<stdio.h>

# include	<list>
# include	<string>
# include	<sstream>

# include	"Text.hpp"
# include       "Color.hpp"
# include	"Input.hpp"
# include	"AObject.hpp"
# include	"GameClock.hpp"

class Timer : public AObject {
public:
  Timer(std::string, std::string, gdl::Color, int, unsigned int, unsigned int);

  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*> &);
  void draw();

  gdl::Text _time;
  gdl::GameClock _timer;
};

#endif		//TIMER
