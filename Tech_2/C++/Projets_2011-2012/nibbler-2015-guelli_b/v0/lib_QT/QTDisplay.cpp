//
// QtDisplayModule.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler/lib_QT
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Fri Mar 16 22:16:26 2012 igor morenosemedo
// Last update Sun Mar 18 02:00:42 2012 badrane guellim
//

#include <iostream>
#include <QTime>
#include <QPen>
#include <cstring>
#include <cstdlib>
#include "QTDisplay.hh"

DisplayModule::DisplayModule()
{
  this->_wallWidth = 0;
  this->_wallHeigh = 0;
  this->_time = 0;
}
void  DisplayModule::window_init(unsigned int width, unsigned int height)
{
  this->_wallWidth = width + 25;
  this->_wallHeigh = height + 25;
}

void DisplayModule:: design_wind(int x, int y,
				unsigned int size)
{
  s_qt	qt;


  qt.x = x;
  qt.y = y;
  qt.size = size;
  this->_squareStack.push(qt);
}

void  DisplayModule::design_wind(int x, int y,
				 unsigned int size,
				 unsigned int sx, unsigned int sy,
				 unsigned int ex ,unsigned int ey)
{
  s_qt	qt;

  (void)sx;
  (void)sy;
  (void)ex;
  (void)ey;
  qt.x = x;
  qt.y = y;
  qt.size = size;
  this->_squareStack.push(qt);
}

int   DisplayModule::run(IEvent &ev)
{
  int	argc = 1;
  char	**argv;

  argv = (char**)malloc(2 *sizeof(char*));
  argv[0] = strdup("./nibbler");
  argv[1] = '\0';
  this->_event = &ev;
  QApplication		apps(argc, argv);

  this->_scene = new Scene(ev, this->_time);
  this->_view = new QGraphicsView(this->_scene);
  this->_view->setFixedSize(this->_wallWidth, this->_wallHeigh);
  this->Update();
  this->_view->show();
  apps.exec();
  return (1);
}

int   DisplayModule::Update()
{
  Scene	*sc = new Scene(*this->_event, this->_time);
  QColor	cl;

  while (!this->_squareStack.empty())
    {
      cl.setRgb(255, 0 , 127);
      QPen	cali(cl);
      sc->addRect(this->_squareStack.top().x,
		     this->_squareStack.top().y,
		     this->_squareStack.top().size,
		     this->_squareStack.top().size,
		     cali, cali.brush());
      this->_squareStack.pop();
    }
  delete this->_scene;
  this->_scene = sc;
  this->_view->setScene(this->_scene);
  this->_view->setFixedSize(this->_wallWidth, this->_wallHeigh);
  this->_view->show();
  return (1);
}

void	DisplayModule::setTimeOutMouse(unsigned int t)
{
  this->_time = t;
}

unsigned int	DisplayModule::GetTimeOutMouse() const
{
  return (this->_time);
}

extern "C"
{
  IDisplayModule        *create_nibbler()
  {
    return (new DisplayModule());
  }
}
