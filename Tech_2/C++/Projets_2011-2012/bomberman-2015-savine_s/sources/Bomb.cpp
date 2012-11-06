//
// Bomb.cpp for  in /home/jason/Tech2/ProgC++/Bomberman.Git/gitolite@89.92.92.67:bomberman.git/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Fri May 25 15:38:42 2012 Jason Leo
// Last update Sun Jun  3 18:58:14 2012 guillaume francois
//

#include	"Bomb.hpp"
#include	"Bomber.hpp"
#include	"SecondBomber.hpp"

Bomb::Bomb(float x, float z, e_type type, int m_port, AObject *m_pos, int n_player)
  : AObject(x, z, type)
{
  this->time_.play();
  port = m_port;
  pos_ = m_pos;
  player_ = n_player;
  danger_ = 1;
}

Bomb::~Bomb(void)
{
}

void		Bomb::initialize(void)
{
  this->model_ = gdl::Model::load("libgdl_gl/assets/bomb.fbx");
}

void		Bomb::detect_explosion(int x, int y, int *dir, std::deque<AObject*> &map)
{
  unsigned int	i = 0;
  int		is_expl = 1;
  int		c_bonus = 0;

  while (is_expl == 1 && i < map.size())
    {
      if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	  && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	  && (map[i]->getType() == INDESTRUCTIBLE))
	{
	  *dir = 0;
	  is_expl = 0;
	}
      else if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	       && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	       && (map[i]->getType() == DESTRUCTIBLE || map[i]->getType() == PLAYER
		   || map[i]->getType() == BOT || map[i]->getType() == IA || map[i]->getType() == BONUS_SPEED
		   || map[i]->getType() == BONUS_NB_BOMB || map[i]->getType() == BONUS_PORT_BOMB|| map[i]->getType() == BOMB))
	{
	  if (map[i]->getType() == BOMB && (map[i]->getPosition().x != position_.x || map[i]->getPosition().z != position_.z))
	    {
	      Bomb* m_bomb = dynamic_cast<Bomb*>(map[i]);
	      m_bomb->explosion(map);
	    }
	  else
	    {
	      if (map[i]->getType() == DESTRUCTIBLE)
		{
		  c_bonus = rand() % 100;
		  if (c_bonus >= 1 && c_bonus <= 10)
		    {
		      int bonus_type = rand() % 3;
		      if (bonus_type == 1)
			{
			  Cube *bonus = new Cube(map[i]->getPosition().x, map[i]->getPosition().z, BONUS_SPEED_IND);
			  bonus->initialize();
			  map.push_back(bonus);
			}
		      else if (bonus_type == 2)
			{
			  Cube *bonus = new Cube(map[i]->getPosition().x, map[i]->getPosition().z, BONUS_PORT_BOMB_IND);
			  bonus->initialize();
			  map.push_back(bonus);
			}
		      else
			{
			  Cube *bonus = new Cube(map[i]->getPosition().x, map[i]->getPosition().z, BONUS_NB_BOMB_IND);
			  bonus->initialize();
			  map.push_back(bonus);
			}
		    }
		}
	      if (map[i]->getType() != BONUS_SPEED_IND && map[i]->getType() != BONUS_PORT_BOMB_IND && map[i]->getType() != BONUS_PORT_BOMB_IND)
		{
		  map.erase(map.begin() + i);
		  Cube *exp = new Cube(x, y, FIRE);
		  exp->initialize();
		  map.push_back(exp);
		}
	    }
	  *dir = 0;
	  is_expl = 0;
	}
      i += 1;
    }
}

bool		Bomb::can_expl(int x, int y, int *dir, std::deque<AObject*> &map)
{
  unsigned int	i = 0;

  while (i < map.size())
    {
      if ((map[i]->getPosition().x + 160 >= x && map[i]->getPosition().x - 160 <= x)
	  && (map[i]->getPosition().z + 160 >= y && map[i]->getPosition().z - 160 <= y)
	  && map[i]->getType() != GRASS && map[i]->getType() != DANGER && map[i]->getType() != PLAYER && map[i]->getType() != IA)
	{
	  *dir = 0;
	  return (false);
	}
      i += 1;
    }
  return (true);
}

void		Bomb::explosion(std::deque<AObject*> &map)
{
  int left = 1;
  int right = 1;
  int up = 1;
  int down = 1;
  int i = 0;

  if (player_ == 1)
    {
      Bomberman *player = dynamic_cast<Bomberman*>(pos_);
      player->inc_bomb();
    }
  else if (player_ == 2)
    {
      SecondBomberman *player = dynamic_cast<SecondBomberman*>(pos_);
      player->inc_bomb();
    }
  else
    {
      Aintelligence *player = dynamic_cast<Aintelligence*>(pos_);
      player->inc_bomb();
    }
  while (i <= (unsigned int)port)
    {
      if (i == 0)
	{
	  Cube *exp = new Cube(position_.x, position_.z, FIRE);
	  exp->initialize();
	  map.push_back(exp);
	}
      else
	{
	  if (left == 1 && can_expl(position_.x + (300 * i), position_.z, &left, map) == true)
	    {
	      Cube *exp = new Cube((position_.x + (300 * i)), position_.z, FIRE);
	      exp->initialize();
	      map.push_back(exp);
	    }
	  if (right == 1 && can_expl((position_.x - (300 * i)), position_.z, &right, map) == true)
	    {
	      Cube *exp = new Cube((position_.x - (300 * i)), position_.z, FIRE);
              exp->initialize();
              map.push_back(exp);
	    }
	  if (up == 1 && can_expl(position_.x, (position_.z + (300 * i)), &up, map) == true)
	    {
	      Cube *exp = new Cube(position_.x, position_.z + (300 * i), FIRE);
              exp->initialize();
              map.push_back(exp);
	    }
	  if (down == 1 && can_expl(position_.x, (position_.z - (300 * i)), &down, map) == true)
	    {
	      Cube *exp = new Cube(position_.x, position_.z - (300 * i), FIRE);
              exp->initialize();
              map.push_back(exp);
	    }
	}
      i++;
    }
  i = 0;
  right = left = up = down = 1;
  detect_explosion(position_.x + (300 * i), position_.z, &left, map);
  left = 1;
  i = 0;
  while (i <= port)
    {
      if (left == 1)
	detect_explosion(position_.x + (300 * i), position_.z, &left, map);
      if (right == 1)
	detect_explosion((position_.x - (300 * i)), position_.z, &right, map);
      if (up == 1)
	detect_explosion(position_.x, (position_.z + (300 * i)), &up, map);
      if (down == 1)
	detect_explosion(position_.x, (position_.z - (300 * i)), &down, map);
      i++;
    }
}

void		Bomb::update(gdl::GameClock const &gameClock, gdl::Input &input,
			     std::deque<AObject*> &map)
{
  int left = 1;
  int right = 1;
  int up = 1;
  int down = 1;
  int i = 1;

  (void)input;
  this->time_.update();
  if (danger_ == 1)
    {
      while (i <= port)
	{
	  if (left == 1 && can_expl(position_.x + (300 * i), position_.z, &left, map) == true)
	    {
	      Cube *exp = new Cube((position_.x + (300 * i)), position_.z, DANGER);
	      map.push_back(exp);
	    }
	  if (right == 1 && can_expl((position_.x - (300 * i)), position_.z, &right, map) == true)
	    {
	      Cube *exp = new Cube((position_.x - (300 * i)), position_.z, DANGER);
	      map.push_back(exp);
	    }
	  if (up == 1 && can_expl(position_.x, (position_.z + (300 * i)), &up, map) == true)
	    {
	      Cube *exp = new Cube(position_.x, position_.z + (300 * i), DANGER);
	      map.push_back(exp);
	    }
	  if (down == 1 && can_expl(position_.x, (position_.z - (300 * i)), &down, map) == true)
	    {
	      Cube *exp = new Cube(position_.x, position_.z - (300 * i), DANGER);
	      map.push_back(exp);
	    }
	  danger_ = 0;
	  i++;
	}
    }
  if (this->time_.getTotalElapsedTime() > 3)
    this->explosion(map);
  this->model_.update(gameClock);
}

void		Bomb::draw(void)
{
  glLoadIdentity();
  glTranslated(-position_.x, -position_.y, -position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0);
  glRotatef(this->rotation_.x, 1.0f, 0.0f, 0);
  glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
  this->model_.draw();
}

int		Bomb::getPlayer(void)const
{
  return (this->player_);
}

void		Bomb::setPlayer(int player)
{
  this->player_ = player;
}

float		Bomb::getTime(void)const
{
  return (this->time_.getElapsedTime());
}

void		Bomb::setTime(float time)
{
  (void)time;
}
