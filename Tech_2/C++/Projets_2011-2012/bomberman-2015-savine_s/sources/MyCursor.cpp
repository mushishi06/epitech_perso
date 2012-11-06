//
// MyText.cpp for bomberman in /home/ss814/Epitech/bomberman-2015-savine_s
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Sat May 19 18:39:52 2012 Sampson SAVINEL
// Last update Sun Jun  3 23:36:45 2012 jason leo
//

#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	"MyCursor.hpp"
#include	"MyBack.hpp"
#include	"MultCursor.hpp"
#include	"MyMenu.hpp"
#include        "Generate_map.hpp"
#include	"Timer.hpp"
#include	"Load_map.hpp"
#include	"Save_map.hpp"

MyCursor::MyCursor(float x, float z) : AObject(x, z, TEXT) {
  i_ = 1;
  pos_ = 255;
  isDown_down = false;
  isDown_up = false;
}

void		MyCursor::setText(std::string text)
{
  (void)text;
}

void		MyCursor::initialize(void) {
  texture_ = gdl::Image::load("libgdl_gl/images/bomber-head.png");
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  resultat = FMOD_System_CreateSound(system, "libgdl_gl/music/bomber-battle.ogg", FMOD_SOFTWARE
  				     | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  FMOD_Sound_SetLoopCount(musique, -1);
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
}

void		MyCursor::update(gdl::GameClock const& gameClock, gdl::Input& input,
		    std::deque<AObject*> &map) {
  (void)map;
  (void)gameClock;
  int i = 0;


  t_expl t_pos [] =
  {
    {1, 230},
    {2, 305},
    {3, 375},
    {4, 450},
    {5, 595},
  };
  if (input.isKeyDown(gdl::Keys::Down) == 1)
    isDown_down = true;
  if (isDown_down == true && input.isKeyDown(gdl::Keys::Down) == 0)
    {
      if (i_ == 5)
	i_ = 1;
      else
	i_ += 1;
      isDown_down = false;
    }
  if (input.isKeyDown(gdl::Keys::Up) == 1)
    isDown_up = true;
  if (isDown_up == true && input.isKeyDown(gdl::Keys::Up) == 0)
    {
      if (i_ == 1)
	i_ = 5;
      else
	i_ -= 1;
      isDown_up = false;
    }
  if (i_ == 1 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      t_param_map           param_map;

      while (map.size() > 0)
        map.erase(map.begin());
      std::string	map_name = "./map/Level_1.xml";
      map.push_front(new MyBack("libgdl_gl/images/bomber-ground.png", 0, 0));
      if (load_map(map, map_name, param_map, NULL) == false)
	std::cout << "Load_map fail." << std::endl;

      // generate_map(map, param_map);
      map.push_back(new Timer(1, 500, 50));
      for (unsigned int i = 0; i < map.size(); ++i)
	map[i]->initialize();
    }
  if (i_ == 3 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      while (map.size() > 0)
        map.erase(map.begin());
      map.push_front(new MultCursor(0, 0));
      map.push_front(new MyMenu("libgdl_gl/images/bomber-multi.png", 0, 0));
      for (unsigned int i = 0; i < map.size(); ++i)
        map[i]->initialize();
    }
  else if (i_ == 4 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      while (map.size() > 0)
        map.erase(map.begin());
      map.push_front(new MyMenu("libgdl_gl/images/bomber-scores.png", 0, 0));
      for (unsigned int i = 0; i < map.size(); ++i)
	map[i]->initialize();
    }
  else if (i_ == 5 && input.isKeyDown(gdl::Keys::Return) == 1)
    {
      FMOD_Sound_Release(musique);
      FMOD_System_Close(system);
      FMOD_System_Release(system);
      while (map.size() > 0)
        map.erase(map.begin());
      exit(EXIT_SUCCESS);
    }
  while (t_pos[i].dir != i_)
    i++;
  pos_ = t_pos[i].height;
}

void		MyCursor::draw() {
  switchToOrtho();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  texture_.bind();
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0); glVertex2d(500, 0 + pos_);
  glTexCoord2f(0, 1); glVertex2d(500, 50 + pos_);
  glTexCoord2f(1, 1); glVertex2d(400, 50 + pos_);
  glTexCoord2f(1, 0); glVertex2d(400, 0 + pos_);
  glEnd();
  glDisable(GL_BLEND);
  switchBackToPerspective();
}

void		MyCursor::switchToOrtho()
{
  glDisable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, 1024, 768, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MyCursor::switchBackToPerspective()
{
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}
