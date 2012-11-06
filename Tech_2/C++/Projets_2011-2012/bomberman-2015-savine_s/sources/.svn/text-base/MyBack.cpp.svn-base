//
// MyBack.cpp for  in /home/leo_j//Tech2/ProgC++/gitolite@89.92.92.67:bomberman.git/sources
//
// Made by jason leo
// Login   <leo_j@epitech.net>
//
// Started on  Sun Jun  3 06:00:12 2012 jason leo
// Last update Sun Jun  3 11:09:23 2012 jason leo
//

#include	"MyBack.hpp"

MyBack::MyBack(std::string text, float x, float z) : AObject(x, z, TEXT) {
  texture_name = text;
}

MyBack::MyBack(float x, float z) : AObject(x, z, TEXT) {
}

void		MyBack::setText(std::string text)
{
  (void)text;
}

void		MyBack::initialize(void) {
  texture_ = gdl::Image::load(texture_name);
}

void		MyBack::update(gdl::GameClock const& gameClock, gdl::Input& input,
		    std::deque<AObject*> &map) {
  (void)map;
  (void)gameClock;
  (void)input;
}

void		MyBack::draw() {
  switchToOrtho();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  texture_.bind();
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0); glVertex2d(0, 0);
  glTexCoord2f(0, 1); glVertex2d(0, 768);
  glTexCoord2f(1, 1); glVertex2d(1024, 768);
  glTexCoord2f(1, 0); glVertex2d(1024, 0);
  glEnd();
  glDisable(GL_BLEND);
  switchBackToPerspective();
}

void		MyBack::switchToOrtho()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MyBack::switchBackToPerspective()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
