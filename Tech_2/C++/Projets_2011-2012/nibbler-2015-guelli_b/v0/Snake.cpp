//
// Snake.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Wed Mar 14 14:56:04 2012 igor morenosemedo
// Last update Wed Mar 28 09:40:31 2012 belia-_r
//

#include <cstdlib>
#include <iostream>
#include "Exception.hh"
#include "Snake.hh"

Snake::Snake(IDisplayModule *display)
{
  this->_display = display;
  this->setMap(MAPWIDTH, MAPHEIGH);
  this->setWall(WALLWIDTH, WALLHEIGH);
  this->_whereImGoingTo = S_RIGHT;
  this->_points = 0;
}

Snake::Snake(const Snake &oth)
{
  this->_mapWidth = oth.getMapWidth();
  this->_mapHeigh = oth.getMapHeigh();
  this->_wallWidth = oth.getWallWidth();
  this->_wallHeigh = oth.getWallHeigh();

  this->_key = oth.getKey();
  this->_snaAAAake = oth.getSnnaAAAake();
  this->_whereImGoingTo = S_RIGHT;
  this->_points = 0;
}

const Snake & Snake::operator=(const Snake & oth)
{
  if (this != &oth)
    {
      this->_mapWidth = oth.getMapWidth();
      this->_mapHeigh = oth.getMapHeigh();
      this->_wallWidth = oth.getWallWidth();
      this->_wallHeigh = oth.getWallHeigh();

      this->_key = oth.getKey();
      this->_snaAAAake = oth.getSnnaAAAake();

      this->_whereImGoingTo = oth.getWhereImGoingTo();
      this->_points = oth.getPoints();
    }
  return (*this);
}

Snake::~Snake()
{
  std::cout << "SNake?! non SnaaAAAAAaaaAaeke!!..."
  	    << std::endl;
  delete this->_display;
}

void Snake::KeyRight()
{
  this->_whereImGoingTo--;
  if (this->_whereImGoingTo < 0)
    this->_whereImGoingTo = 3;
}

void Snake::KeyLeft()
{
  this->_whereImGoingTo++;
  this->_whereImGoingTo = this->_whereImGoingTo % 4;
}

void Snake::KeyEschap()
{
  std::cout << "Mission Failed: " << std::endl
	    << this->_points << " rate..." << std::endl;
  exit (0);
}

void Snake::ChooseEvent()
{
  s_coord	head;

  head = this->_snaAAAake[0];
  switch (this->_whereImGoingTo)
    {
    case S_DOWN :
      head.y--;
      break;
    case S_UP :
      head.y++;
      break;
    case S_LEFT :
      head.x--;
      break;
    case S_RIGHT :
      head.x++;
      break;
    default :
      break;
    }
  if (!Where_is_Snake(head))
    this->KeyEschap();
  else
    if (this->Snake_nonSaaaake(head))
      this->KeyEschap();
    else
      {
	this->_snaAAAake.push_front(head);
	if (head.x == this->_key.x && head.y == this->_key.y)
	  {
	    this->KeyMove();
	    this->_points += 5 + this->_walls.size();
	    if (this->_display->GetTimeOutMouse() >  50)
	      this->_display->setTimeOutMouse(this->_display->GetTimeOutMouse() - SPEEDUP);
	  }
	else
	  this->_snaAAAake.pop_back();
      }
  this->Print();
}

void		Snake::init_snaaAAake(unsigned int size)
{
  s_coord	ready;
  unsigned int	pos;

  this->_snaAAAake.erase(this->_snaAAAake.begin(), this->_snaAAAake.end());
  ready.x = this->_mapWidth / 2 - size;
  ready.y = this->_mapHeigh / 2;
  pos = 0;
  for(pos = 0; pos < size; pos++)
    {
      this->_snaAAAake.push_front(ready);
      ready.x++;
    }
}

bool		Snake::Snake_nonSaaaake(const s_coord &oth)
{
  s_coord	co;
  std::deque<s_coord>::const_iterator it = this->_snaAAAake.begin();

  while(it != this->_snaAAAake.end())
    {
      co = *it;
      if (co.x == oth.x && co.y == oth.y)
	return (true);
      ++it;
    }
  if (this->_walls.empty())
    return (false);

  std::deque<s_coord>::const_iterator itw = this->_walls.begin();

  while(itw != this->_walls.end())
    {
      co = *itw;
      if (co.x == oth.x && co.y == oth.y)
	return (true);
      ++itw;
    }
  return (false);
}

bool Snake::Where_is_Snake(const s_coord &oth)
{
  return (oth.x < this->_mapWidth && oth.y < this->_mapHeigh);
}

void Snake::KeyMove()
{
  do
    {
      this->_key.x = random () % this->_mapWidth;
      this->_key.y = random () % this->_mapHeigh;
    } while (this->Snake_nonSaaaake(this->_key));
}

int	Snake::run()
{
  this->init_snaaAAake(SIZESNAKE);
  this->_display->window_init(this->_wallWidth, this->_wallHeigh);
  this->_display->setTimeOutMouse(SPEEDSTART);
  this->_sizeSnake = this->getSnakeSize();
  this->KeyMove();
  this->_display->run(*this);
  return (0);
}

void Snake::Print()
{
  std::deque<s_coord>::const_iterator	it = this->_snaAAAake.begin();
  s_coord				p;
  int		i;

  i = -1;
  while (i <= static_cast<int>(this->_mapWidth))
    {
      if (this->_texture != "")
  	{
  	  this->_display->design_wind(this->_sizeSnake * i, this->_sizeSnake * -1, this->_sizeSnake,
  				      this->_textDim.x / 2, 0, this->_textDim.x, this->_textDim.y / 2);
  	  this->_display->design_wind(this->_sizeSnake * i, this->_sizeSnake * this->_mapHeigh,	this->_sizeSnake,
  				      this->_textDim.x / 2, 0, this->_textDim.x, this->_textDim.y / 2);
  	}
      else
      	{
      	  this->_display->design_wind(this->_sizeSnake * i, this->_sizeSnake * -1,this->_sizeSnake  );
      	  this->_display->design_wind(this->_sizeSnake * i, this->_sizeSnake * this->_mapHeigh,	this->_sizeSnake);
      	}
      i++;
    }
  i = -1;
  while (i <= static_cast<int>(this->_mapHeigh))
    {
      if (this->_texture != "")
  	{
  	  this->_display->design_wind(this->_sizeSnake * -1, this->_sizeSnake * i, this->_sizeSnake,
  				      this->_textDim.x / 2, 0, this->_textDim.x, this->_textDim.y / 2);
  	  this->_display->design_wind(this->_sizeSnake * this->_mapWidth,	this->_sizeSnake * i, this->_sizeSnake,
  				      this->_textDim.x / 2, 0, this->_textDim.x, this->_textDim.y / 2);
  	}
      else
      	{
      	  this->_display->design_wind(this->_sizeSnake * -1, this->_sizeSnake * i, this->_sizeSnake);
      	  this->_display->design_wind(this->_sizeSnake * this->_mapWidth, this->_sizeSnake * i,	this->_sizeSnake);
      	}
      i++;
    }

  while (it < this->_snaAAAake.end())
    {
      p.x = (*it).x;
      p.y = (*it).y;
      if (p.x == this->_snaAAAake[0].x
  	  && p.y == this->_snaAAAake[0].y)
  	{
  	  if (this->_texture != "")
  	    this->_display->design_wind(this->_sizeSnake * p.x, this->_sizeSnake * p.y, this->_sizeSnake, 0, 0, this->_textDim.x / 2, this->_textDim.y / 2);
  	  else
  	    this->_display->design_wind(this->_sizeSnake * p.x, this->_sizeSnake * p.y, this->_sizeSnake);
  	}
      else
  	if (this->_texture != "")
  	  this->_display->design_wind(this->_sizeSnake * p.x, this->_sizeSnake * p.y, this->_sizeSnake, 0, this->_textDim.y / 2, this->_textDim.x / 2, this->_textDim.y);
  	else
  	  this->_display->design_wind(this->_sizeSnake * p.x, this->_sizeSnake * p.y, this->_sizeSnake);
      ++it;
    }

  if (this->_texture != "")
    this->_display->design_wind(this->_sizeSnake * this->_key.x, this->_sizeSnake * this->_key.y, this->_sizeSnake,
				this->_textDim.x / 2, this->_textDim.y / 2, this->_textDim.x, this->_textDim.y);
  else
    this->_display->design_wind(this->_sizeSnake * this->_key.x, this->_sizeSnake * this->_key.y, this->_sizeSnake);
  this->_display->Update();
}

void Snake::setMap(unsigned int x, unsigned int y)
{
  this->_mapWidth = x;
  this->_mapHeigh = y;
}

void Snake::setWall(unsigned int x, unsigned int y)
{
  this->_wallWidth = x;
  this->_wallHeigh = y;
}

const IDisplayModule *Snake::getDisplay() const
{
  return (this->_display);
}

unsigned int Snake::getMapWidth() const
{
  return (this->_mapWidth);
}

unsigned int Snake::getMapHeigh() const
{
  return (this->_mapHeigh);
}

unsigned int Snake::getWallWidth() const
{
  return (this->_wallWidth);
}

unsigned int Snake::getWallHeigh() const
{
  return (this->_wallHeigh);
}

unsigned int Snake::getSnakeSize() const
{
  return (this->_wallWidth / this->_mapWidth > this->_wallHeigh / this->_mapHeigh ?
	  this->_wallHeigh / this->_mapHeigh :
	  this->_wallWidth / this->_mapWidth);
}

unsigned int Snake::getPoints() const
{
  return (this->_points);
}

const s_coord &Snake::getKey() const
{
  return (this->_key);
}

const   std::deque<s_coord> &Snake::getSnnaAAAake() const
{
  return(this->_snaAAAake);
}

char	Snake::getWhereImGoingTo() const
{
  return (this->_whereImGoingTo);
}

