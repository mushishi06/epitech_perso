//
// QTDisplay.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler/lib_QT
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Fri Mar 16 22:58:46 2012 igor morenosemedo
// Last update Sat Mar 17 15:22:50 2012 igor morenosemedo
//

#ifndef		__DISPLAYMODULE_HH__
# define	__DISPLAYMODULE_HH__

#include <QApplication>
#include <QtGui>
#include <stack>
#include <string>
#include <iostream>
#include "IDisplayModule.hh"
#include "Scene.hh"

struct		s_qt
{
  int		x;
  int		y;
  int		size;
};

class	DisplayModule : public IDisplayModule
{
private :
  Scene				*_scene;

  unsigned int                  _wallWidth;
  unsigned int                  _wallHeigh;

  IEvent			*_event;
  std::stack<s_qt>		_squareStack;
  unsigned int			_time;
  QGraphicsView			*_view;

public :
  DisplayModule();
  virtual ~DisplayModule() {}

  virtual	void window_init(unsigned int, unsigned int);

  virtual	void design_wind(int, int, unsigned int);
  virtual	void design_wind(int, int, unsigned int,unsigned int ,
				 unsigned int, unsigned int, unsigned int);

  virtual	void setTimeOutMouse(unsigned int);
  virtual	unsigned int GetTimeOutMouse() const;

public:
  //pour la lib graphique mmmh
  virtual	int run(IEvent &);
  virtual	int Update();

};

#endif
