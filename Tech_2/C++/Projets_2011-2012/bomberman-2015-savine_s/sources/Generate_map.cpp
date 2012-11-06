//
// generate_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Wed May 16 16:29:21 2012 laurent ha-tam-dan
// Last update Sun Jun  3 23:17:30 2012 jason leo
//

#include	<string>
#include	"MyGame.hpp"
#include	"Bomber.hpp"
#include        "SecondBomber.hpp"
#include	"Aintelligence.hpp"
#include	"Object.hpp"
#include	"Monster.hpp"
#include	"Generate_map.hpp"
#include	"MyBack.hpp"

static bool	verif_not_used(std::deque<AObject*> &map, int x, int y)
{
  std::deque<AObject*>::iterator	it = map.begin();
  int	count = 0;

  for (; it != map.end(); ++it)
    {
      if ((*it)->getType() == PLAYER ||
	  (*it)->getType() == IA ||
	  (*it)->getType() == BOT)
	{
	  count = 0;
	  if ((x * 300 == (*it)->getPosition().x + 300 && y * 300 == (*it)->getPosition().z)
	      || (x * 300 == (*it)->getPosition().x - 300 && y * 300 == (*it)->getPosition().z)
	      || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z + 300)
	      || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z - 300))
	    {
	      count++;
	    }
	}
      if (count > 0 || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z))
	return false;
    }
  return (true);
}

static bool	verif_player(std::deque<AObject*> &map, int x, int y)
{
  std::deque<AObject*>::iterator	it = map.begin();
  int	count = 0;

  for (; it != map.end(); ++it)
    {
      count = 0;
      if (x * 300 == (*it)->getPosition().x + 300 && y * 300 == (*it)->getPosition().z)
	count++;
      if (x * 300 == (*it)->getPosition().x - 300 && y * 300 == (*it)->getPosition().z)
	count++;
      if (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z + 300)
	count++;
      if (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z - 300)
	count++;
      if (count > 1 || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().z))
	return false;
    }
  return (true);
}

static void	generate_border(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	x;
  int	y;

  y = 0;
  x = 0;
  for (; map_param.height > y; ++y)
    {
      if (y == 0 || y == (map_param.height - 1))
	for (x = 0; map_param.weight > x; ++x)
	  map.push_back(new Cube(x * 300, y * 300, INDESTRUCTIBLE));
      else
	{
	  map.push_back(new Cube(0, y * 300, INDESTRUCTIBLE));
	  map.push_back(new Cube((map_param.weight - 1) * 300, y * 300, INDESTRUCTIBLE));
	}
    }
}

static void	generate_indestructible(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	x;
  int	y;

  y = 2;
  while (map_param.height > y)
    {
      x = (rand() % 2) + 2;
      while (map_param.weight > x)
	{
	  map.push_back(new Cube(x * 300, y * 300, INDESTRUCTIBLE));
	  x += (rand() % 2) + 2;
	}
      y += (rand() % 2) + 2;
    }
}

static void	generate_player(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < map_param.player)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true && verif_player(map, x, y) == true)
	{
	  if (i == 0)
	    map.push_back(new Bomberman(x * 300, y * 300, PLAYER));
	  else
	    map.push_back(new SecondBomberman(x * 300, y * 300, PLAYER));
	  ++i;
	}
    }
}

static void	generate_ia(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < map_param.character_max - map_param.player)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true && verif_player(map, x, y) == true)
	{
	  map.push_back(new Aintelligence(x * 300, y * 300, IA));
	  ++i;
	}
    }
}

static void	generate_destructible(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	x;
  int	y;
  unsigned int	limit;
  unsigned int	i;

  i = 0;
  limit = (((map_param.height - 1) * (map_param.weight - 1) / 2)
	   - (map_param.character_max * 5));
  while (i < limit)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true)
	{
	  map.push_back(new Cube(x * 300, y * 300, DESTRUCTIBLE));
	  i++;
	}
    }
}

static void	generate_grass(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	x;
  int	y;
  bool	find;
  std::deque<AObject*>::iterator it = map.begin();

  for (y = 1; y < map_param.height - 1; ++y)
    for (x = 1; x < map_param.weight - 1; ++x)
      {
	find = false;
	for (it = map.begin(); it != map.end(); ++it)
	  {
            if (((*it)->getType() == INDESTRUCTIBLE ||
                 (*it)->getType() == DOOR_CLOSE ||
		(*it)->getType() == DOOR_OPEN) &&
	      (*it)->getPosition().x == x * 300 &&
                (*it)->getPosition().z == y * 300)
	      find = true;
	  }
	if (find == false)
	  map.push_back(new Carre(x * 300, y * 300, GRASS));
      }
}

void	generate_map(std::deque<AObject*> &map, t_param_map &map_param)
{
  srand(time(NULL));
  generate_border(map, map_param);
  generate_indestructible(map, map_param);
  generate_player(map, map_param);
  generate_ia(map, map_param);
  generate_destructible(map, map_param);
  generate_grass(map, map_param);
  map.push_front(new MyBack("libgdl_gl/images/bomber-sky.png", 0, 0));
}
