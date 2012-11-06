//
// Model.cpp for  in /home/jason/Tech2/ProgC++/Bomberman/gitolite@89.92.92.67:bt/sources
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 14 15:50:08 2012 Jason Leo
// Last update Sun Jun  3 11:15:35 2012 jason leo
//

#include	"Bomber.hpp"
#include	"Bomb.hpp"

Bomberman::Bomberman(float x, float z, e_type type)
  : Player(x, z, type)
{
  port = 2;
  posed_ = false;
}

void		Bomberman::initialize(void)
{
  this->model_ = gdl::Model::load("libgdl_gl/assets/marvin.fbx");
  this->speed_ = 20;
  this->nb_bomb_ = 1;
  this->tot_bomb_ = 3;
}

Bomberman::~Bomberman(void)
{
}

void		Bomberman::left(std::deque<AObject*> &map)
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
      this->model_.play("Marche");
      position_.x += speed_;
      this->rotation_.y = -90;
    }
}

void		Bomberman::right(std::deque<AObject*> & map)
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
      this->model_.play("Marche");
      position_.x -= speed_;
      this->rotation_.y = 90;
    }
}

void		Bomberman::up(std::deque<AObject*> & map)
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
      this->model_.play("Marche");
      position_.z += speed_;
      this->rotation_.y = 180;
    }
}

void	Bomberman::down(std::deque<AObject*> & map)
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
      this->model_.play("Marche");
      position_.z -= speed_;
      this->rotation_.y = 0;
    }
}

void		Bomberman::pos_bomb(std::deque<AObject*> &map)
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
      Bomb	*b = new Bomb(this->position_.x, this->position_.z, BOMB, port, this, 1);
      b->initialize();
      map.push_back(b);
    }
  posed_ = false;
}

void		Bomberman::update(gdl::GameClock const & gameClock, gdl::Input & input,
				  std::deque<AObject*> &map)
{
  Bomberman::t_move m_move [] =
  {
    {gdl::Keys::Left, &Bomberman::left},
    {gdl::Keys::Right, &Bomberman::right},
    {gdl::Keys::Up, &Bomberman::up},
    {gdl::Keys::Down, &Bomberman::down},
    {gdl::Keys::F1, NULL}
  };

  gdl::Color c(255, 0, 0, 255);
  this->model_.set_default_model_color(c);
  if (input.isKeyDown(gdl::Keys::Numpad0) == true && nb_bomb_ > 0)
    posed_ = true;
  if (input.isKeyDown(gdl::Keys::Numpad0) == false && posed_ == true)
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
    {
      ((*this).*m_move[i].func)(map);
      run_ = true;
    }
  else
    isWalk = 0;
  if (run_ == true && isWalk == 0)
    {
      this->model_.play("Arret");
      isWalk = 1;
      run_ = false;
    }
  take_bonus(position_.x, position_.z, map);
  this->model_.update(gameClock);
}

void		Bomberman::draw(void)
{
  glLoadIdentity();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  this->model_.draw();
}

void            Bomberman::inc_bomb()
{
  if (nb_bomb_ < tot_bomb_)
    nb_bomb_++;
}

void		Bomberman::take_bonus(int x, int y, std::deque<AObject*> &map)
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
