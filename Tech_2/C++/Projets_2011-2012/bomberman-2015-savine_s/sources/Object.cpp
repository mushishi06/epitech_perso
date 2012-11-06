//
// Object.cpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 19:19:18 2012 Sampson SAVINEL
// Last update Sun Jun  3 19:32:25 2012 laurent ha-tam-dan
//

#include	"Object.hpp"

Cube::Cube(float x, float z, e_type type)
  : AObject(x, z, type)
{
  time_ = 0;
  e_time_.play();
}

void		Cube::initialize()
{
t_type m_type[] =
  {
    {DESTRUCTIBLE, "libgdl_gl/images/bomber-dest.png"},
    {FIRE, "libgdl_gl/images/bomber-explo.png"},
    {BONUS_NB_BOMB_IND, "libgdl_gl/images/bomber-bomb.png"},
    {BONUS_SPEED_IND, "libgdl_gl/images/bomber-speed.png"},
    {BONUS_PORT_BOMB_IND, "libgdl_gl/images/bomber-flame.png"},
    {INDESTRUCTIBLE, "libgdl_gl/images/bomber-indes.png"}
  };

 int	i = 0;

 if (type_ != DANGER)
   {
     while (i <= 5 && m_type[i].type != type_)
       i++;
     texture_ = gdl::Image::load(m_type[i].texture_name);
   }
 while (i <= 5 && m_type[i].type != type_)
    i++;
  texture_ = gdl::Image::load(m_type[i].texture_name);
}

Cube::~Cube(void)
{
}

void		Cube::update(gdl::GameClock const & gameClock, gdl::Input & input,
			     std::deque<AObject*> &map)
{
  unsigned int  i = 0;
  int           erase = 0;

  (void)gameClock;
  (void)input;
  if (type_ == FIRE)
    {
      if (time_ >= 3)
	{
	  while (erase == 0 && i < map.size())
	    {
	      if (position_.x == map[i]->getPosition().x && position_.z == map[i]->getPosition().z && map[i]->getType() == FIRE)
		{
		  erase = 1;
		  map.erase(map.begin() + i);
		}
	      i += 1;
	    }
	}
      time_++;
    }
  else if (type_ == BONUS_NB_BOMB_IND)
    type_ = BONUS_NB_BOMB;
  else if (type_ == BONUS_SPEED_IND)
    type_ = BONUS_SPEED;
  else if (type_ == BONUS_PORT_BOMB_IND)
    type_ = BONUS_PORT_BOMB;
  else if (type_ == DANGER)
    {
      e_time_.update();
      if (e_time_.getTotalElapsedTime() > 3)
	{
	  while (erase == 0 && i < map.size())
	    {
	      if (position_.x == map[i]->getPosition().x && position_.z == map[i]->getPosition().z && map[i]->getType() == DANGER)
		{
		  erase = 1;
		  map.erase(map.begin() + i);
		}
	    i += 1;
	    }
	}
    }
}

void		Cube::draw(void)
{
  if (type_ != DANGER)
    {
      glPushMatrix();
      glLoadIdentity();
      texture_.bind();
      glTranslated(-position_.x, -position_.y, -position_.z);
      glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
      glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
      glBegin(GL_QUADS);
      {
	glTexCoord2d(0, 0); glVertex3f(-150,-150,-150);
	glTexCoord2d(0, 1); glVertex3f( 150,-150,-150);
	glTexCoord2d(1, 1); glVertex3f( 150, 150,-150);
	glTexCoord2d(1, 0); glVertex3f(-150, 150,-150);
	glEnd();
      }
      glBegin(GL_QUADS);
      {
	glTexCoord2d(0, 0); glVertex3f(-150,-150,-150);
	glTexCoord2d(0, 1); glVertex3f(-150,-150, 150);
	glTexCoord2d(1, 1); glVertex3f(-150, 150, 150);
	glTexCoord2d(1, 0); glVertex3f(-15, 150,-150);
	glEnd();
      }
      glBegin(GL_QUADS);
      {
	glTexCoord2d(0, 0); glVertex3f(150, -150, 150);
	glTexCoord2d(0, 1); glVertex3f(150, -150,-150);
	glTexCoord2d(1, 1); glVertex3f(150, 150,-150);
	glTexCoord2d(1, 0); glVertex3f(150, 150, 150);
	glEnd();
      }
      glBegin(GL_QUADS);
      {
	glTexCoord2d(0, 0);glVertex3f(-150,-150, 150);
	glTexCoord2d(0, 1);glVertex3f( 150,-150, 150);
	glTexCoord2d(1, 1);glVertex3f( 150, 150, 150);
	glTexCoord2d(1, 0);glVertex3f(-150, 150, 150);
	glEnd();
      }
      glBegin(GL_QUADS);
      {
	glTexCoord2d(0, 0);glVertex3f(-150, 150, 150);
	glTexCoord2d(0, 1);glVertex3f(-150, 150,-150);
	glTexCoord2d(1, 1);glVertex3f( 150, 150,-150);
	glTexCoord2d(1, 0);glVertex3f( 150, 150, 150);
	glEnd();
      }
      glPopMatrix();
    }
}

Carre::Carre(float x, float z, e_type type)
  : AObject(x, z, type)
{
}

void		Carre::initialize()
{
  if (this->type_ == GRASS)
    texture_ = gdl::Image::load("libgdl_gl/images/bomber-grass.png");
  else if (this->type_ == DOOR_CLOSE)
    texture_ = gdl::Image::load("libgdl_gl/images/bomber-openeddoor.png");
  else
    texture_ = gdl::Image::load("libgdl_gl/images/bomber-closeddoor.png");
}

Carre::~Carre(void)
{
}

void		Carre::update(gdl::GameClock const & gameClock, gdl::Input & input,
			     std::deque<AObject*> &map)
{
  (void)gameClock;
  (void)input;
  (void)map;
}

void		Carre::draw(void)
{
  glPushMatrix();
  glLoadIdentity();
  texture_.bind();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glBegin(GL_QUADS);
  {
    glTexCoord2d(0, 0); glVertex3f(-150,-150,-150);
    glTexCoord2d(0, 1);glVertex3f( 150,-150,-150);
    glTexCoord2d(1, 1);glVertex3f( 150,-150, 150);
    glTexCoord2d(1, 0);glVertex3f(-150,-150, 150);
    glEnd();
  }
  glPopMatrix();
}
