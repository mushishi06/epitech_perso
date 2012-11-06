//
// Background.cpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Fri May 18 14:55:48 2012 Jason Leo
// Last update Wed May 30 15:23:57 2012 guillaume francois
//

#include	"Background.hpp"

Accueil::Accueil(float x, float z, e_type type)
  : AObject(x, z, type)
{
}

void		Accueil::initialize(void)
{
  this->texture_ = gdl::Image::load("libgdl_gl/images/bomber_accueil.tga");
  this->texture_.bind();
}

Accueil::~Accueil(void)
{
}

void		Accueil::update(gdl::GameClock const & gameClock, gdl::Input & input,
				std::deque<AObject*> &map)
{
  (void)map;
  (void)gameClock;
  (void)input;
}

void		Accueil::draw(void)
{
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(150.0f, 100.0f, 0.0f);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(150.0f, -100.0f, 0.0f);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-150.0f, -100.0f, 0.0f);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-150.0f, 100.0f, 0.0f);
  glEnd();
}
