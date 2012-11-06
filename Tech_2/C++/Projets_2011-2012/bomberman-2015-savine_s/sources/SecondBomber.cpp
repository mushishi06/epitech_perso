//
// SecondBomber.cpp for  in /home/jason/Tech2/ProgC++/Bomberman.Git/gitolite@89.92.92.67:bomberman.git/sources
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 20:46:05 2012 Jason Leo
// Last update Thu May 31 11:00:57 2012 cedric santarelli
//

#include	"SecondBomber.hpp"
#include	"Bomb.hpp"

SecondBomberman::SecondBomberman(float x, float z, e_type type)
  : Player(x, z, type)
{
  port = 2;
  posed_ = false;
}

void		SecondBomberman::initialize(void)
{
  this->model_ = gdl::Model::load("libgdl_gl/assets/marvin.fbx");
  this->speed_ = 20;
  this->nb_bomb_ = 1;
  this->tot_bomb_ = 3;
}

SecondBomberman::~SecondBomberman(void)
{
}

void		SecondBomberman::left(std::deque<AObject*> &map)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB)) &&
	  (map[i]->getPosition().x >= position_.x + speed_ && map[i]->getPosition().x <= position_.x + speed_ + 300) &&
	  (map[i]->getPosition().z + 160 >= position_.z && map[i]->getPosition().z - 160 <= position_.z))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      position_.x += speed_;
      this->model_.play("Marche");
      this->rotation_.y = -90;
      isWalk = 0;
    }
}

void		SecondBomberman::right(std::deque<AObject*> & map)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB)) &&
	  (map[i]->getPosition().x >= position_.x - speed_ - 300 && map[i]->getPosition().x <= position_.x - speed_) &&
	  (map[i]->getPosition().z + 160 >= position_.z && map[i]->getPosition().z - 160 <= position_.z))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      position_.x -= speed_;
      this->model_.play("Marche");
      this->rotation_.y = 90;
      isWalk = 0;
    }
}

void		SecondBomberman::up(std::deque<AObject*> & map)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB)) &&
	  (map[i]->getPosition().z <= position_.z + speed_ + 300 && map[i]->getPosition().z >= position_.z + speed_) &&
	  (map[i]->getPosition().x + 160 >= position_.x && map[i]->getPosition().x - 160 <= position_.x))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      position_.z += speed_;
      this->model_.play("Marche");
      this->rotation_.y = 180;
      isWalk = 0;
    }
}

void		SecondBomberman::down(std::deque<AObject*> & map)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB)) &&
	  (map[i]->getPosition().z <= position_.z - speed_ && map[i]->getPosition().z >= position_.z - speed_ - 300) &&
	  (map[i]->getPosition().x + 160 >= position_.x && map[i]->getPosition().x - 160 <= position_.x))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      position_.z -= speed_;
      this->model_.play("Marche");
      this->rotation_.y = 0;
      isWalk = 0;
    }
}

void		SecondBomberman::update(gdl::GameClock const & gameClock, gdl::Input & input,
					std::deque<AObject*> &map)
{
  SecondBomberman::t_move m_move [] =
    {
      {gdl::Keys::A, &SecondBomberman::left},
      {gdl::Keys::D, &SecondBomberman::right},
      {gdl::Keys::W, &SecondBomberman::up},
      {gdl::Keys::S, &SecondBomberman::down},
      {gdl::Keys::F1, NULL}
    };

  gdl::Color c(0, 0, 255, 255);
  this->model_.set_default_model_color(c);
  if (input.isKeyDown(gdl::Keys::Space) == true && nb_bomb_ > 0)
    posed_ = true;
  if (input.isKeyDown(gdl::Keys::Space) == false && posed_ == true)
    pos_bomb(map);
  this->model_.cut_animation(this->model_,"Take 001", 30, 60,"Marche");
  this->model_.cut_animation(this->model_,"Take 001", 50, 150,"Arret");
  this->model_.cut_animation(this->model_,"Take 001", 0, 10,"Stop");
  this->model_.set_anim_speed("Marche", 2);
  isWalk = 1;
  int i = 0;
  while (m_move[i].func != NULL && input.isKeyDown(m_move[i].input) != 1)
    i++;
  if (m_move[i].func != NULL)
    ((*this).*m_move[i].func)(map);
  if (isWalk == 0)
    {
      this->model_.play("Arret");
      isWalk = 1;
    }
  take_bonus(position_.x, position_.z, map);
   this->model_.update(gameClock);
}

void		SecondBomberman::draw(void)
{
  glLoadIdentity();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  this->model_.draw();
}

void            SecondBomberman::inc_bomb()
{
  nb_bomb_++;
}

void		SecondBomberman::take_bonus(int x, int y, std::deque<AObject*> &map)
{
  unsigned int	i = 0;

  while (i < map.size())
    {
      if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	  && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	  && (map[i]->getType() == BONUS_SPEED))
	{
	  if (speed_ < 40)
	    speed_ += 5;
	  map.erase(map.begin() + i);
	}
      else if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	       && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	       && (map[i]->getType() == BONUS_PORT_BOMB))
	{
	  port++;
	  map.erase(map.begin() + i);
	}
      else if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	       && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	       && (map[i]->getType() == BONUS_NB_BOMB))
	{
	  if (nb_bomb_ < tot_bomb_)
	    nb_bomb_++;
	  map.erase(map.begin() + i);
	}
      i += 1;
    }
}

void		SecondBomberman::pos_bomb(std::deque<AObject*> &map)
{
  int		already_here = 0;
  unsigned int	i = 0;
  while (already_here == 0 && i < map.size())
    {
      if (map[i]->getType() == BOMB && map[i]->getPosition().x >= position_.x - 30 && map[i]->getPosition().x <= position_.x + 30 &&
	  map[i]->getPosition().z >= position_.z - 30 && map[i]->getPosition().z <= position_.z + 30)
	already_here = 1;
      i++;
    }
  if (already_here == 0)
    {
      nb_bomb_--;
      Bomb	*b = new Bomb(this->position_.x, this->position_.z, BOMB, port, this, 2);
      b->initialize();
      map.push_back(b);
    }
  posed_ = false;
}
