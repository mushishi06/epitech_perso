//
// MyText.cpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:52 2012 Sampson SAVINEL
// Last update Sun Jun  3 11:06:10 2012 jason leo
//

#include	"MyText.hpp"

MyText::MyText(std::string text, float x, float z, int height) : AObject(x, z, TEXT) {
  height_ = height;
  text_ = text;
  list_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:-/";
}

MyText::MyText(float x, float z, int height) : AObject(x, z, TEXT) {
  height_ = height;
  text_ = "";
  list_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:-/";
}

void		MyText::setText(std::string text)
{
  text_ = text;
}

void		MyText::initialize(void) {
  texture_ = gdl::Image::load("libgdl_gl/images/bomber-font.png");
}

void		MyText::update(gdl::GameClock const& gameClock, gdl::Input& input,
		    std::deque<AObject*> &map) {
  (void)map;
  (void)gameClock;
  (void)input;
}

void		MyText::draw() {
  int i = 0;
  int a = 0;
  switchToOrtho();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  texture_.bind();
  while (text_.c_str()[a] != '\0')
    {
      while(list_.c_str()[i] != text_.c_str()[a] && list_.c_str()[i] != '\0')
      i++;
      glBegin(GL_QUADS);
      glTexCoord2f(0, .02565 * i); glVertex2d((20 * height_ * a) + position_.x, 0 + position_.z);
      glTexCoord2f(0, .02565 * (i+1)); glVertex2d((20 * height_ * a) + position_.x, (20 * height_) + position_.z);
      glTexCoord2f(1, .02565 * (i+1)); glVertex2d((20 * height_ *(a+1)) + position_.x, (20 * height_) + position_.z);
      glTexCoord2f(1, .02565 * i); glVertex2d((20 * height_ * (a+1)) + position_.x, 0 + position_.z);
      glEnd();
      i = 0;
      a++;
}
  glDisable(GL_BLEND);
  switchBackToPerspective();
}

void		MyText::switchToOrtho()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MyText::switchBackToPerspective()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
