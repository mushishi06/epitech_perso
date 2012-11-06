//
// Ncurses.cpp for Ncurses in /home/guelli_b//Epitech/tek2/B4/C++/Nibbler/nibbler/bco/v0/lib_ncurses/include
//
// Made by badrane guellim
// Login   <guelli_b@epitech.net>
//
// Started on  Fri Mar 16 15:27:19 2012 badrane guellim
// Last update Sun Mar 18 23:17:32 2012 igor morenosemedo
//

#include "Ncurses.hpp"

Ncurses::Ncurses() {}

Ncurses::~Ncurses() {endwin();}

void		Ncurses::window_init(unsigned int width, unsigned int height)
{
  (void)width;
  (void)height;
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

void		Ncurses::design_wind(int x, int y, unsigned int size)
{
  t_coord	coord;

  (void)size;
  coord.x = (x / 20); coord.y = (y / 20);
  _partStack.push(coord);
}

void		Ncurses::design_wind(int x, int y, unsigned int size, unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey)
{
  (void)sx;
  (void)sy;
  (void)ex;
  (void)ey;
  design_wind(x, y, size);
}

int		Ncurses::run(IEvent &eventManager)
{
  int	pb;

  Update();
  timeout(_timeout);
  while ((pb = getch()) != 'q' || pb != KEY_ESC)
    {
      switch (pb)
	{
	case KEY_LEFT :
	  {eventManager.KeyLeft(); break;}
	case KEY_RIGHT :
	  {eventManager.KeyRight(); break;}
	case KEY_ESC :
	  {eventManager.KeyEschap(); break;}
	}
      eventManager.ChooseEvent();
    }
  return (1);
}

void            Ncurses::partDisplay(t_coord coord) const
{
  mvprintw(coord.y, coord.x, "#");
}

int		Ncurses::Update()
{
  clear();
  while (!_partStack.empty())
    {partDisplay(_partStack.top()); _partStack.pop();}
  return (1);
}

void		Ncurses::setTimeOutMouse(unsigned int timeout)
{
  _timeout = static_cast<float>(timeout);
}

unsigned int	Ncurses::GetTimeOutMouse() const
{
  return (static_cast<unsigned int>(_timeout));
}

extern "C"
{
  IDisplayModule	*create_nibbler() {return new Ncurses();}
}
