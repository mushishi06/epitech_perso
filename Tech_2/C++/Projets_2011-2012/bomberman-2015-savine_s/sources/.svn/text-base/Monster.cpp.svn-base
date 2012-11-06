//
// Monster.cpp for BOMBERMAN in /home/franco_g/School/Tek2/Git_repo/gitolite@89.92.92.67:bomberman.git
//
// Made by guillaume francois
// Login   <franco_g@epitech.net>
//
// Started on  Mon May 28 12:53:44 2012 guillaume francois
// Last update Sun Jun  3 20:52:01 2012 jason leo
//

#include	"Monster.hpp"

#define	ABS(x)	(x < 0) ? (-x) : (x)

Monster::Monster(float x, float z, e_type type)
  : AObject(x, z, type)
{
}

Monster::~Monster(void)
{
}

void		Monster::initialize(void)
{
  this->model_ = gdl::Model::load("libgdl_gl/assets/marvin.fbx");
  this->speed_ = 20;
}

void		Monster::update(gdl::GameClock const &gameClock, gdl::Input &input,
				std::deque<AObject*> &map)
{
  std::deque<AObject*>::iterator	it;
  std::deque<AObject*>::iterator	plk;
  Vector3f				p_pos;
  bool					stop = false;


  (void)input;
  this->model_.update(gameClock);
  this->model_.cut_animation(this->model_,"Take 001", 30, 60,"Marche");
  this->model_.cut_animation(this->model_,"Take 001", 50, 150,"Arret");
  this->model_.cut_animation(this->model_,"Take 001", 0, 10,"Stop");
  this->model_.set_anim_speed("Marche", 2);
  if (map.size() > 1)
    it = map.begin();
  while (it != map.end() && stop == false)
    {
      if ((*it)->getType() == PLAYER)
	{
	  plk = it;
	  p_pos = (*it)->getPosition();
	  stop = true;
	  if (this->found_player(p_pos, map) == true)
	    map.erase(plk);
	}
      *it++;
    }
  go_safe_place(map);
  if (this->isWalk == 0)
     {
       this->model_.play("Arret");
       this->isWalk = 1;
     }
}

void		Monster::draw(void)
{
  glLoadIdentity();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  this->model_.draw();
}

bool		Monster::found_player(Vector3f const &p_pos, std::deque<AObject*> &map)
{
  float		a;
  float		b;

  a = this->position_.x - p_pos.x;
  b = this->position_.z - p_pos.z;

  if ((a >= -80 && a <= 80) &&
      (b >= -80 && b <= 80))
    {
      go_safe_place(map);
      ((*this).*reverse_mov)(map, 1);
      return true;
    }
  else
    {
      if (ABS(b) > ABS(a))
	this->up_down(b, map);
      if (ABS(b) < ABS(a))
	this->right_left(a, map);
      else
	this->up_down(b, map);
    }
  return false;
}

void		Monster::right_left(float a, std::deque<AObject*> &map)
{
  if (a > 0) // RIGHT
    go_right(map, 1);
  else if (a < 0) // LEFT
    go_left(map, 1);
}

void		Monster::go_right(std::deque<AObject*> &map, int forced)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB) || ((map[i]->getType() == DANGER) && forced == 1)) &&
	  (map[i]->getPosition().x >= position_.x - speed_ - 300 && map[i]->getPosition().x <= position_.x - speed_) &&
	  (map[i]->getPosition().z + 160 >= position_.z && map[i]->getPosition().z - 160 <= position_.z))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      reverse_mov = &Monster::go_left;
      position_.x -= speed_;
      this->model_.play("Marche");
      this->rotation_.y = 90;
      isWalk = 0;
    }
}

void		Monster::go_left(std::deque<AObject*> &map, int forced)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB) || ((map[i]->getType() == DANGER) && forced == 1)) &&
	  (map[i]->getPosition().x >= position_.x + speed_ && map[i]->getPosition().x <= position_.x + speed_ + 300) &&
	  (map[i]->getPosition().z + 160 >= position_.z && map[i]->getPosition().z - 160 <= position_.z))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      reverse_mov = &Monster::go_right;
      position_.x += speed_;
      this->model_.play("Marche");
      this->rotation_.y = -90;
      isWalk = 0;
    }
}

void		Monster::up_down(float b, std::deque<AObject*> &map)
{
  if (b > 0) // DOWN
    go_down(map, 1);
  else if (b < 0) // UP
    go_up(map, 1);
}
void		Monster::go_up(std::deque<AObject*> &map, int forced)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB) || ((map[i]->getType() == DANGER) && forced == 1)) &&
	  (map[i]->getPosition().z <= position_.z + speed_ + 300 && map[i]->getPosition().z >= position_.z + speed_) &&
	  (map[i]->getPosition().x + 160 >= position_.x && map[i]->getPosition().x - 160 <= position_.x))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      reverse_mov = &Monster::go_down;
      position_.z += speed_;
      this->model_.play("Marche");
      this->rotation_.y = 180;
      isWalk = 0;
    }
}

void		Monster::go_down(std::deque<AObject*> &map, int forced)
{
  unsigned int i = 0;
  int wall = 0;

  while (wall != 1 && map.size() > i)
    {
      if (((map[i]->getType() == DESTRUCTIBLE) || (map[i]->getType() == INDESTRUCTIBLE) || (map[i]->getType() == BOMB) || ((map[i]->getType() == DANGER) && forced == 1)) &&
	  (map[i]->getPosition().z <= position_.z - speed_ && map[i]->getPosition().z >= position_.z - speed_ - 300) &&
	  (map[i]->getPosition().x + 160 >= position_.x && map[i]->getPosition().x - 160 <= position_.x))
	wall = 1;
      i++;
    }
  if (wall != 1)
    {
      reverse_mov = &Monster::go_up;
      position_.z -= speed_;
      this->model_.play("Marche");
      this->rotation_.y = 0;
      isWalk = 0;
    }
}

bool		Monster::safe(int x, int y, std::deque<AObject*> &map, int *dir)
{
  unsigned int				i = 0;
  bool					is_safe = 0;

  while (i < map.size())
    {
      if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x) &&
	  (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y) &&
	  map[i]->getType() == GRASS)
	is_safe = true;
      if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x) &&
	  (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y) &&
	  (map[i]->getType() == BOMB || map[i]->getType() == DANGER || map[i]->getType() == DESTRUCTIBLE || map[i]->getType() == INDESTRUCTIBLE))
	{
	  if (map[i]->getType() == BOMB || map[i]->getType() == DESTRUCTIBLE || map[i]->getType() == INDESTRUCTIBLE)
	    *dir = 0;
	  return (false);
	}
      i++;
    }
  return (is_safe);
}

void		Monster::go_safe_place(std::deque<AObject*> &map)
{
  unsigned int	i = 0;
  bool		is_safe = false;
  int		left = 1, right = 1, up = 1, down = 1;

  while (is_safe == false && i < map.size())
    {
      if ((map[i]->getType() == DANGER || map[i]->getType() == BOMB) &&
	  map[i]->getPosition().x + 160 >= position_.x && map[i]->getPosition().x - 160 <= position_.x &&
	  map[i]->getPosition().z + 160 >= position_.z && map[i]->getPosition().z - 160 <= position_.z)
	{
	  if ((safe(position_.x + (300 * i), position_.z, map, &left) == true) || (safe(position_.x - (300 * i), position_.z, map, &right) == true))
	    {
	      if (left == 1)
		{
		  go_left(map, 0);
		  is_safe = true;
		}
	      else if (right == 1)
		{
		  go_right(map, 0);
		  is_safe = true;
		}
	    }
	  else
	    {
	      if (up == 1)
		{
		  go_up(map, 0);
		  is_safe = true;
		}
	      else if (down == 1)
		{
		  go_down(map, 0);
		  is_safe = true;
		}
	    }
	  i++;
	}
      i++;
    }
}
