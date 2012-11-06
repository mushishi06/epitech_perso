//
// Timer.cpp<2> for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 22:06:47 2012 Sampson SAVINEL
// Last update Sun Jun  3 17:53:30 2012 jason leo
//

#ifndef		__TIMER
# define	__TIMER

# include	<sstream>
# include       "Clock.hpp"
# include	"MyText.hpp"

class		Timer : public AObject
{
  MyText	*_time;
  gdl::Clock	*_timer;
  int		time_;
public:
  Timer(int, unsigned int, unsigned int);
  ~Timer();

  void		initialize(void);
  void		update(gdl::GameClock const&, gdl::Input&, std::deque<AObject*>&);
  void		draw();
  gdl::Clock    *getClock();
};

#endif		//TIMER
