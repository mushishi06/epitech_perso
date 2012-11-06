//
// MyText.cpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:52 2012 Sampson SAVINEL
// Last update Sun Jun  3 11:06:14 2012 jason leo
//

#include	"MyMenu.hpp"

MyMenu::MyMenu(std::string text, float x, float z) : AObject(x, z, TEXT) {
  texture_name = text;
}

MyMenu::MyMenu(float x, float z) : AObject(x, z, TEXT) {
}

void		MyMenu::setText(std::string text)
{
  (void)text;
}

void		MyMenu::initialize(void) {
  texture_ = gdl::Image::load(texture_name);
}

void		MyMenu::update(gdl::GameClock const& gameClock, gdl::Input& input,
		    std::deque<AObject*> &map) {
  (void)map;
  (void)gameClock;
  (void)input;
}

void		MyMenu::draw() {
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

void		MyMenu::switchToOrtho()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MyMenu::switchBackToPerspective()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
