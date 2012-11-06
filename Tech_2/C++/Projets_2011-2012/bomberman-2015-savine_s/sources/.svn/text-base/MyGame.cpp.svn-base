//
// MyGame.cpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Thu May 10 15:22:17 2012 Sampson SAVINEL
// Last update Sun Jun  3 23:33:57 2012 jason leo
//

#include	"Bomber.hpp"
#include	"MyGame.hpp"
#include	"Object.hpp"
#include	"Aintelligence.hpp"
#include	"SecondBomber.hpp"
#include	"Generate_map.hpp"
#include	"Save_map.hpp"
#include	"Load_map.hpp"
#include	"time.h"
#include	"MyMenu.hpp"
#include	"MyCursor.hpp"
#include	"MyBack.hpp"
#include	"string_to_nbr.hpp"
#include	<iostream>

void		MyGame::initialize(void)
{
  window_.setWidth(1024);
  window_.setHeight(768);
  window_.create();
  camera_.initialize();
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  resultat = FMOD_System_CreateSound(system, "libgdl_gl/music/bomber-intro.ogg", FMOD_SOFTWARE
  				     | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  int	i = 1;
  std::string name;
  while (i <= 202)
    {
      name = nbr_to_string<int>(i);
      name = "libgdl_gl/images/output/" + name + ".png";
      list_.push_back(name);
      i++;
    }
  for (unsigned int i = 0; i < objects_.size(); ++i)
    objects_[i]->initialize();
  timer_ = new Timer(1, 500, 50);
  game_ = 0;
  movie_ = 0;
}

void		MyGame::update(void)
{
  static int lvl = 1;

  if (movie_ == 0)
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
  if (input_.isKeyDown(gdl::Keys::Back) == true && passVid == false)
    {
      FMOD_Sound_Release(musique);
      FMOD_System_Close(system);
      FMOD_System_Release(system);
      movie_ = 201;
      passVid = true;
    }
  if (movie_ < 201)
    {
      movie_++;
      while (objects_.size() > 0)
	objects_.erase(objects_.begin());
      objects_.push_front(new MyMenu(list_[movie_], 0, 0));
      for (unsigned int i = 0; i < objects_.size(); ++i)
	objects_[i]->initialize();
    }
  else
    {
      if (movie_ == 201)
	{
	  FMOD_Sound_Release(musique);
	  FMOD_System_Close(system);
	  FMOD_System_Release(system);
	  while (objects_.size() > 0)
	    objects_.erase(objects_.begin());
	  objects_.push_front(new MyCursor(0, 0));
	  objects_.push_front(new MyMenu("libgdl_gl/images/bomber-accueil.png", 0, 0));
	  for (unsigned int i = 0; i < objects_.size(); ++i)
	    objects_[i]->initialize();
	  movie_++;
	    }
      static bool	key_F5;

      if (input_.isKeyDown(gdl::Keys::F5) == true)
	key_F5 = true;
      if (input_.isKeyDown(gdl::Keys::F5) == false && key_F5 == true)
	{
	  time_t rawtime;
	  struct tm * timeinfo;
	  char		buffer[80];
	  t_param_map           param_map;

	  time ( &rawtime );
	  timeinfo = localtime ( &rawtime );
	  strftime (buffer,80,"%Y-%d-%m-%H:%M",timeinfo);
	  std::string	name_xml = "Save_";
	  name_xml += buffer;
	  name_xml += ".xml";
	  save_map(objects_, name_xml, param_map);
	  key_F5 = false;
	}
      camera_.update(gameClock_, input_);
      if (objects_.size() > 10)
	game_ = 1;
      for (unsigned int i = 0; i < objects_.size(); ++i)
	if (objects_[i]->getType() == PLAYER)
	  game_ = 2;
      if (game_ == 2)
	for (unsigned int i = 0; i < objects_.size(); ++i)
	  if (objects_[i]->getType() == IA || objects_[i]->getType() == BOT)
	    game_ = 6;
      if (game_ == 2)
	{
	  t_param_map           param_map;
	  std::string map_name;
	  while (objects_.size() > 0)
            objects_.erase(objects_.begin());
	  lvl++;
	  if (lvl >= 2 && lvl <= 5)
	    {
	      if (lvl == 2)
		{
		  map_name = "./map/Level_2.xml";
		  objects_.push_front(new MyBack("libgdl_gl/images/bomber-cave.png", 0, 0));
		}
	      if (lvl == 3)
		{
		  map_name = "./map/Level_3.xml";
		  objects_.push_front(new MyBack("libgdl_gl/images/bomber-space.png", 0, 0));
		}
	      if (lvl == 4)
		{
		  map_name = "./map/Level_4.xml";
		  objects_.push_front(new MyBack("libgdl_gl/images/bomber-ice.png", 0, 0));
		}
	      if (lvl == 5)
		{
		  map_name = "./map/Level_5.xml";
		  objects_.push_front(new MyBack("libgdl_gl/images/bomber-lava.png", 0, 0));
		}
	      if (load_map(objects_, map_name, param_map, NULL) == false)
		std::cout << "Load_map fail." << std::endl;
	      objects_.push_back(new Timer(1, 500, 50));
	      for (unsigned int i = 0; i < objects_.size(); ++i)
		objects_[i]->initialize();
	    }
	  else
	    {
	      objects_.push_front(new MyBack("libgdl_gl/images/bomber-success.png", 0, 0));
	      for (unsigned int i = 0; i < objects_.size(); ++i)
                objects_[i]->initialize();
	    }
	}
      if (input_.isKeyDown(gdl::Keys::Escape) == true && (game_ == 0 || game_ == 4))
	{
	  while (objects_.size() > 0)
	    objects_.erase(objects_.begin());
	  objects_.push_front(new MyCursor(0, 0));
	  objects_.push_front(new MyMenu("libgdl_gl/images/bomber-accueil.png", 0, 0));
	  lvl = 1;
	  for (unsigned int i = 0; i < objects_.size(); ++i)
	    objects_[i]->initialize();
	  game_ = 0;
	}
      else if (game_ == 1)
	{
	  while (objects_.size() > 0)
	    objects_.erase(objects_.begin());
	  objects_.push_front(new MyMenu("libgdl_gl/images/bomber-gameover.png", 0, 0));
	  for (unsigned int i = 0; i < objects_.size(); ++i)
	    objects_[i]->initialize();
	  game_ = 4;
	}
      else if (game_ == 4)
	{
	  gdl::Clock time;
	  time.play();
	  while (time.getTotalElapsedTime() < 3)
	    time.update();
	  while (objects_.size() > 0)
	    objects_.erase(objects_.begin());
	  objects_.push_front(new MyCursor(0, 0));
	  objects_.push_front(new MyMenu("libgdl_gl/images/bomber-accueil.png", 0, 0));
	  lvl = 1;
	  for (unsigned int i = 0; i < objects_.size(); ++i)
	    objects_[i]->initialize();
	  game_ = 0;
	}
      for (unsigned int i = 0; i < objects_.size(); ++i)
	objects_[i]->update(gameClock_, input_, this->objects_);
    }
}

void		MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 0.95f, 1.0f);
  glClearDepth(1.0f);
  for (unsigned int i = 0; i < objects_.size(); ++i)
    objects_[i]->draw();
  window_.display();
  if (movie_ < 202)
    usleep(40000);
}

void		MyGame::unload(void)
{

}
