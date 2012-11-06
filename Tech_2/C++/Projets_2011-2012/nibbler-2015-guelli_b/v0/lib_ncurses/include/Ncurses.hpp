//
// Ncurses.hpp for nibbler in /home/guelli_b//Epitech/tek2/B4/C++/Nibbler/nibbler/bco/v0/lib_ncurses/include
// 
// Made by badrane guellim
// Login   <guelli_b@epitech.net>
// 
// Started on  Fri Mar 16 15:24:52 2012 badrane guellim
// Last update Sat Mar 17 19:17:13 2012 badrane guellim
//

#ifndef		_NCURSES_HPP_
# define	_NCURSES_HPP_

#  include	<iostream>
#  include	<cstdlib>
#  include	<stack>
#  include	<string>

#  include	<curses.h>

#  include	"IDisplayModule.hh"
#  include	"IEvent.hh"

#  define	KEY_ESC		27

class		Ncurses : public IDisplayModule
{
  typedef struct s_coord
  {
    int	x;
    int	y;
  }		t_coord;

  std::stack<t_coord>	_partStack;
  int			_timeout;

  void			partDisplay(t_coord) const;
public:

  Ncurses();

  virtual void			window_init(unsigned int, unsigned int);
  virtual void			design_wind(int, int, unsigned int);
  virtual void			design_wind(int, int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
  virtual int			run(IEvent &eventManager);
  virtual int			Update();
  virtual void			setTimeOutMouse(unsigned int);
  virtual unsigned int		GetTimeOutMouse() const;

  virtual ~Ncurses();
};

#endif		// _NCURSES_HPP_
