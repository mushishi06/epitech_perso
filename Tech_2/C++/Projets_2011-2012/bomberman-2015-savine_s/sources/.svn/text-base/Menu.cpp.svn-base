//
// Menu.cpp for bomberman in /home/ss814/vanBurace/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat Jun  2 22:37:00 2012 Sampson SAVINEL
// Last update Sun Jun  3 11:11:07 2012 jason leo
//

# include	"Menu.hpp"

void		Menu::initialize(std::string const& backgroundFile) {
  this->get2D();
  this->back_ = gdl::Image::load(backgroundFile);
}

void		Menu::update() {
}

void		Menu::draw() {
  this->back_.bind();
  glPushMatrix();
  glLoadIdentity();
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f); glVertex2d(-1.0, 1.0);
  glTexCoord2f(0.0f, 1.0f); glVertex2d(-1.0, -1.0);
  glTexCoord2f(1.0f, 1.0f); glVertex2d(1.0, -1.0);
  glTexCoord2f(1.0f, 0.0f); glVertex2d(1.0, 1.0);
  glEnd();
  glPopMatrix();
}

void Menu::get2D() {
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Menu::get3D() {
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void Menu::changeBackground(std::string const& backgroundFile) {
  this->back_ = gdl::Image::load(backgroundFile);
}
