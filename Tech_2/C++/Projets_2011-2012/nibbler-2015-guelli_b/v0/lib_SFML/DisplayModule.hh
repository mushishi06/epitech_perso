//
// DisplayModule.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler/lib_SFML
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Thu Mar 15 11:51:48 2012 igor morenosemedo
// Last update Sun Mar 18 00:41:23 2012 igor morenosemedo
//

#ifndef		_DISPLAYMODULE_HH__
# define	_DISPLAYMODULE_HH__

#  include <SFML/System.hpp>
#  include <SFML/Window.hpp>
#  include <SFML/Graphics.hpp>
#  include <string>
#  include <iostream>
#  include <stack>
#  include "IDisplayModule.hh"
#  include "IEvent.hh"
#  include "Exception.hh"

class	DisplayModule: public IDisplayModule
{
private:
  unsigned int                  _wWidth;
  unsigned int                  _wHeight;
  unsigned int                  _mapWidth;
  unsigned int                  _mapHeight;

  std::stack<sf::Drawable*>     _squareStack;
  std::map<std::string, sf::Image*>             _imagesMap;

  sf::RenderWindow              *_window;
  float                         _timeout;

public:
  DisplayModule();
  virtual	~DisplayModule();

public:

  // initialiation de fenetre
  virtual	void window_init(unsigned int, unsigned int);

  virtual	void design_wind(int, int, unsigned int);
  virtual	void design_wind(int, int, unsigned int, unsigned int ,
				 unsigned int, unsigned int, unsigned int);

  // evenement time
  virtual	void setTimeOutMouse(unsigned int);
  virtual	unsigned int GetTimeOutMouse() const;

public:
  //graphique
  virtual	int run(IEvent &);
  virtual	int Update();
};

#endif
