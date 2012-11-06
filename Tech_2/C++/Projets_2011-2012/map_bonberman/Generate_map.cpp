//
// generate_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Wed May 16 16:29:21 2012 laurent ha-tam-dan
// Last update Wed May 23 19:26:40 2012 belia-_r
//

#include	<cstdlib>
#include	<deque>
#include	<string>
#include	<iostream>
#include	"MyGame.hpp"
#include	"Bomberman.hpp"
#include	"Bomber.hpp"
#include	"Object.hpp"
#include	"Aintelligence.hpp"
#include	"Generate_map.hpp"

static bool	verif_not_used(std::deque<AObject*> &map, int x, int y)
{
  std::deque<AObject*>::iterator	it = map.begin();
  int	count = 0;

  for (; it != map.end(); ++it)
    {
      if ((*it)->getType() == PLAYER)
	{
	  count = 0;
	  if ((x * 300 == (*it)->getPosition().x + 1 && y * 300 == (*it)->getPosition().y)
	      || (x * 300 == (*it)->getPosition().x - 1 && y * 300 == (*it)->getPosition().y)
	      || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().y + 1)
	      || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().y - 1))
	    count++;
	}
      if (count > 0 || (x * 300 == (*it)->getPosition().x && y * 300 == (*it)->getPosition().y))
	return false;
    }
  return true;
}

static void	generate_contour(std::deque<AObject*> &map, t_param_map &map_param)
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
      if (verif_not_used(map, x, y) == true)
	{
	  map.push_back(new Bomberman(x * 300, y * 300, PLAYER));
	  ++i;
	}
    }
}

static void	generate_mob(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < map_param.character_max - map_param.player)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true)
	{
	  map.push_back(new Aintelligence(x * 300, y * 300, PLAYER));
	  ++i;
	}
    }
}

static void	generate_destructible(std::deque<AObject*> &map, t_param_map &map_param)
{
  int	x;
  int	y;
  unsigned int	limit;

  limit = (map_param.height - 1) * (map_param.weight - 1) +
    map_param.character_max + map_param.player * 4;
  while (map.size() < limit)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true)
	map.push_back(new Cube(x * 300, y * 300, DESTRUCTIBLE));
    }
}

void	generate_map(std::deque<AObject*> &map, t_param_map &map_param)
{
  srand(time(NULL));
  generate_contour(map, map_param);
  generate_indestructible(map, map_param);
  generate_player(map, map_param);
  generate_mob(map, map_param);
  generate_destructible(map, map_param);
  std::cout << "Map generated." << std::endl;
}
