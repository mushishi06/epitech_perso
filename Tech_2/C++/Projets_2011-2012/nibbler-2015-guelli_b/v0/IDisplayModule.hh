//
// IDisplayModule.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 15:47:49 2012 igor morenosemedo
// Last update Sat Mar 17 15:41:28 2012 igor morenosemedo
//

#ifndef  _IDISPLAYMODULE_HH_
# define _IDISPLAYMODULE_HH_

#include <deque>
#include <string>
#include "IEvent.hh"

struct	s_coord
{
  unsigned int x;
  unsigned int y;
};

class IDisplayModule
{
public:
  virtual	~IDisplayModule() {};

public:

  // initialiation de fenetre
  virtual	void window_init(unsigned int, unsigned int) = 0;

  virtual	void design_wind(int, int, unsigned int) = 0;
  virtual	void design_wind(int, int, unsigned int, unsigned int, unsigned int,
  				 unsigned int, unsigned int) = 0;

  // evenement souris dans la fenetre - ????
  virtual	void setTimeOutMouse(unsigned int) = 0;
  virtual	unsigned int GetTimeOutMouse() const = 0;

public:
  //pour la lib graphique mmmh

  virtual	int run(IEvent &) = 0;
  virtual	int Update() = 0;
};

#endif
