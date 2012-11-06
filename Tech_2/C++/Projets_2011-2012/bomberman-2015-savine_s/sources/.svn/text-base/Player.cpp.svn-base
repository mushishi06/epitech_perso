//
// Player.cpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/sources
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 13:28:29 2012 Jason Leo
// Last update Sun Jun  3 11:05:44 2012 jason leo
//

#include	"Player.hpp"

Player::Player(float x, float z, e_type type)
  : AObject(x, z, type)
{
}

void		Player::initialize(void)
{
  this->model_ = gdl::Model::load("libgdl_gl/assets/marvin.fbx");
}

Player::~Player(void)
{
}

void		Player::update(gdl::GameClock const & gameClock, gdl::Input & input,
			       std::deque<AObject*> &map)
{
  (void)map;
  (void)gameClock;
  (void)input;
}

void		Player::draw(void)
{
  glLoadIdentity();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  this->model_.draw();
}

int		Player::getNbBomb(void)const
{
  return (this->nb_bomb_);
}

void		Player::setNbBomb(int nbBomb)
{
  this->nb_bomb_ = nbBomb;
}

int		Player::getTotBomb(void)const
{
  return (this->tot_bomb_);
}

void		Player::setTotBomb(int totBomb)
{
  this->tot_bomb_ = totBomb;
}

float		Player::getSpeed(void)const
{
  return (this->speed_);
}

void		Player::setSpeed(int speed)
{
  this->speed_ = speed;
}

int		Player::getRange(void)const
{
  return (this->port);
}

void		Player::setRange(int range)
{
  this->port = range;
}

