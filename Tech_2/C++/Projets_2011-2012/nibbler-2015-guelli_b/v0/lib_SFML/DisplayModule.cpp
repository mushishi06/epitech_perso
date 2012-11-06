//
// DisplayModule.cpp for  in /home/moreno_i//afs/renduLocal/tek1/rush/nib_15/libnibbler_SFML
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 16:05:03 2012 igor morenosemedo
// Last update Sun Mar 18 00:32:19 2012 igor morenosemedo
//

#include		<SFML/Window.hpp>
#include		<SFML/Graphics.hpp>
#include		<SFML/System/Clock.hpp>
#include		<string>
#include		<iostream>
#include		"DisplayModule.hh"

DisplayModule::DisplayModule()
{
  this->_wWidth = 0;
  this->_wHeight = 0;
  this->_mapWidth = 0;
  this->_mapHeight = 0;
}

DisplayModule::~DisplayModule()
{
  while (!this->_squareStack.empty())
    {
      delete this->_squareStack.top();
      this->_squareStack.pop();
    }
  this->_imagesMap.clear();
}

void			DisplayModule::window_init(unsigned int width,
						   unsigned int height)
{
  sf::RenderWindow	*Win = new sf::RenderWindow(sf::VideoMode(width, height), "Nibbler using SFML");

  this->_wWidth = width + 50;
  this->_wHeight = height + 50;
  this->_window = Win;

}

void			DisplayModule::design_wind(int x, int y, unsigned int size)
{
  sf::Shape		*Square = new sf::Shape;

  Square->AddPoint(x, y, sf::Color::Green);
  Square->AddPoint(x, y + size, sf::Color::Yellow);
  Square->AddPoint(x + size, y + size, sf::Color::Magenta);
  Square->AddPoint(x + size, y, sf::Color::Blue);
  this->_squareStack.push(Square);
}

void	DisplayModule::design_wind(int x, int y, unsigned int size,
				   unsigned int sx, unsigned int sy,
				   unsigned int ex, unsigned int ey)
{
  sf::Sprite		*Sprite = new sf::Sprite();
  float			scalex = static_cast<float>(size) / static_cast<float>(ex - sx);
  float			scaley = static_cast<float>(size) / static_cast<float>(ey - sy);

  Sprite->SetSubRect(sf::IntRect(static_cast<int>(sx), static_cast<int>(sy),
  				 static_cast<int>(ex), static_cast<int>(ey)));
  Sprite->SetPosition(sf::Vector2f(x, y));
  Sprite->Scale(scalex, scaley);
  this->_squareStack.push(Sprite);
}

int			DisplayModule::run(IEvent &ev)
{
  sf::Clock		Clock;
  sf::Event		Event;

  if (this->_window == NULL)
    throw ImageError("Window init Fail");
  this->Update();
  while (this->_window->IsOpened())
    {
      while (this->_window->GetEvent(Event))
	{
	  if (Event.Type == sf::Event::KeyPressed
	      && Event.Key.Code == sf::Key::Left)
	    ev.KeyLeft();
	  else if (Event.Type == sf::Event::KeyPressed
		   && Event.Key.Code == sf::Key::Right)
	    ev.KeyRight();
	  else if (Event.Type == sf::Event::KeyPressed
		   && Event.Key.Code == sf::Key::Space)
	    sf::Sleep(1);
	  else if (Event.Type == sf::Event::KeyPressed
		   && Event.Key.Code == sf::Key::Escape)
	    ev.KeyEschap();
	}
      if (Clock.GetElapsedTime() > this->_timeout)
	    {
	      ev.ChooseEvent();
	      Clock.Reset();
	    }
    }
  return (1);
}

int			DisplayModule::Update()
{
  this->_window->Clear();
  while (!this->_squareStack.empty())
    {
      this->_window->Draw(*(this->_squareStack.top()));
      this->_squareStack.pop();
    }
  this->_window->Display();
  return (1);
}

void			DisplayModule::setTimeOutMouse(unsigned int timeout)
{
  this->_timeout = static_cast<float>(timeout) / 1000.0;
}

unsigned int		DisplayModule::GetTimeOutMouse() const
{
  return (static_cast<unsigned int>(this->_timeout * 1000.0));
}
extern "C"
{
  IDisplayModule	*create_nibbler()
  {
    return (new DisplayModule());
  }
}
