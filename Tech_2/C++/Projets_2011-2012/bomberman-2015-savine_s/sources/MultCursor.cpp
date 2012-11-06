//
// MyText.cpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:52 2012 Sampson SAVINEL
// Last update Sun Jun  3 11:09:51 2012 jason leo
//

#include	"MultCursor.hpp"
#include	"MyMenu.hpp"
#include        "Generate_map.hpp"
#include	<iostream>
#include	<stdlib.h>

MultCursor::MultCursor(float x, float z) : AObject(x, z, TEXT) {
  i_ = 1;
  pos_ = 255;
  isDown_down = false;
  isDown_up = false;
}

void		MultCursor::setText(std::string text)
{
  (void)text;
}

void		MultCursor::initialize(void) {
  texture_ = gdl::Image::load("libgdl_gl/images/bomber-head.png");
}

void		MultCursor::update(gdl::GameClock const& gameClock, gdl::Input& input,
		    std::deque<AObject*> &map) {
  (void)map;
  (void)gameClock;
  int i = 0;
  t_expl t_pos [] =
    {
      {1, 0},
      {2, 200},
    };

  if (input.isKeyDown(gdl::Keys::Right) == 1)
    isDown_down = true;
  if (isDown_down == true && input.isKeyDown(gdl::Keys::Right) == 0)
    {
      if (i_ == 2)
	i_ = 1;
      else
	i_ += 1;
      isDown_down = false;
    }
  if (input.isKeyDown(gdl::Keys::Left) == 1)
    isDown_up = true;
  if (isDown_up == true && input.isKeyDown(gdl::Keys::Left) == 0)
    {
      if (i_ == 1)
	i_ = 2;
      else
	i_ -= 1;
      isDown_up = false;
    }
  if (i_ == 1 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      t_param_map           param_map;

      param_map.character_max = 4;
      param_map.player = 1;
      param_map.weight = 20;
      param_map.height = 20;
      while (map.size() > 0)
        map.erase(map.begin());
      generate_map(map, param_map);
      for (unsigned int i = 0; i < map.size(); ++i)
        map[i]->initialize();
    }
  if (i_ == 2 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      t_param_map           param_map;

      param_map.character_max = 4;
      param_map.player = 2;
      param_map.weight = 20;
      param_map.height = 20;
      while (map.size() > 0)
        map.erase(map.begin());
      generate_map(map, param_map);
      for (unsigned int i = 0; i < map.size(); ++i)
        map[i]->initialize();
    }
  while (t_pos[i].dir != i_)
    i++;
  pos_ = t_pos[i].height;
}

void		MultCursor::draw() {
  switchToOrtho();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  texture_.bind();
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0); glVertex2d(650 + pos_, 0 + 300);
  glTexCoord2f(0, 1); glVertex2d(650 + pos_, 50 + 300);
  glTexCoord2f(1, 1); glVertex2d(550 + pos_, 50 + 300);
  glTexCoord2f(1, 0); glVertex2d(550 + pos_, 0 + 300);
  glEnd();
  glDisable(GL_BLEND);
  switchBackToPerspective();
}

void		MultCursor::switchToOrtho()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MultCursor::switchBackToPerspective()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
