//
// Camera.cpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 18:29:11 2012 Sampson SAVINEL
// Last update Wed May 23 16:54:21 2012 cedric santarelli
//

#include	"Camera.hpp"

Camera::Camera(void)
  : position_(-2850.0f, 5000.0f, 200.0f), rotation_(0.0f, 0.0f, 0.0f)
{
}

Camera::~Camera(void)
{
}

void		Camera::initialize(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, 1024.0f/768.0f, 2.0f, 10000.0f);
  gluLookAt(position_.x, position_.y, position_.z,
	    -2850.0f, -1000.0f, -3000.0f,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update(gdl::GameClock const &gameClock, gdl::Input &input)
{
  (void)gameClock;
  (void)input;
}

Vector3f	Camera::getPosition(void)const
{
  return (this->position_);
}

Vector3f	Camera::getRotation(void)const
{
  return (this->rotation_);
}

void		Camera::setPosition(Vector3f pos)
{
  position_.x = pos.x;
  position_.y = pos.y;
  position_.z = pos.z;
}

void		Camera::setRotation(Vector3f rot)
{
  rotation_.x = rot.x;
  rotation_.y = rot.y;
  rotation_.z = rot.z;
}
