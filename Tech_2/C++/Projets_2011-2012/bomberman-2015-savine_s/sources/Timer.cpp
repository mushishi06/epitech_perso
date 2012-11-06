//
// Timer.cpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 22:06:34 2012 Sampson SAVINEL
// Last update Sun Jun  3 22:15:08 2012 cedric santarelli
//

#include	"Timer.hpp"
#include	"MyMenu.hpp"
#include	"MyCursor.hpp"
#include <iostream>

Timer::Timer(int size, unsigned int x, unsigned int y)
  : AObject(0, 0, TIMER)
{
  this->_time = new MyText(x, y, size);
  this->_timer = new gdl::Clock();
  this->initialize();
  time_ = 120;
}

void		Timer::initialize(void) {
  this->_timer->play();
  this->_time->initialize();
}

Timer::~Timer()
{
}

void		Timer::update(gdl::GameClock const& gameClock, gdl::Input& input, std::deque<AObject*>& map)
{
  (void)gameClock;
  (void)input;
  (void)map;
  this->_timer->update();

  float		elapsedTime = (this->_timer->getTotalElapsedTime());
  float		eltm = _timer->getElapsedTime();
  std::stringstream	tmp;

  if (123 - elapsedTime < 0)
    {
      while (map.size() > 0)
	if (map[0]->getType() != TIMER)
	  map.erase(map.begin());
	else
	  map.erase(map.begin() + 1);
      map.push_front(new MyCursor(0, 0));
      map.push_front(new MyMenu("libgdl_gl/images/bomber-accueil.png", 0, 0));
      for (unsigned int i = 0; i < map.size(); ++i)
	map[i]->initialize();
    }
  else if (120 - elapsedTime < 0 && 123 - elapsedTime >= 2)
    {
      while (map.size() > 0)
	map.erase(map.begin());
      map.push_front(new MyMenu("libgdl_gl/images/bomber-gameover.png", 0, 0));
      for (unsigned int i = 0; i < map.size(); ++i)
	map[i]->initialize();
    }
  else
    {
      if (eltm < 0.0333)
	usleep((int)((0.0333 - eltm) * 1000000));
      tmp << (120 - (int)elapsedTime);
      _time->setText(tmp.str());
    }
}

void		Timer::draw() {
  this->_time->draw();
}

gdl::Clock	*Timer::getClock()
{
  return (_timer);
}
