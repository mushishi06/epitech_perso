
//
// generate_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Wed May 16 16:29:21 2012 laurent ha-tam-dan
// Last update Wed May 23 11:54:51 2012 belia-_r
//

#include <cstdlib>
#include <deque>
#include <string>
#include <iostream>
#include "Generic_object.hpp"
#include "Bomberman.hpp"

static bool	verif_not_used(std::deque<G_obj*> &map, int x, int y)
{
  std::deque<G_obj*>::iterator	it = map.begin();
  int	count = 0;

  for (; it != map.end(); ++it)
    {
      if ((*it)->getType() == PLAYER)
	{
	  count = 0;
	  if ((x == (*it)->getX() + 1 && y == (*it)->getY())
	      || (x == (*it)->getX() - 1 && y == (*it)->getY())
	      || (x == (*it)->getX() && y == (*it)->getY() + 1)
	      || (x == (*it)->getX() && y == (*it)->getY() - 1))
	    count++;
	}
      if (count > 0 || (x == (*it)->getX() && y == (*it)->getY()))
	return false;
    }
  return true;
}

static void	generate_contour(std::deque<G_obj*> &map, t_param_map &map_param, int *id)
{
  int	x;
  int	y;

  for (y = 0; map_param.height > y; ++y)
    {
      if (y == 0 || y == (map_param.height - 1))
	for (x = 0; map_param.weight > x; ++x)
	  {
	    map.push_back(new G_obj(INDESTRUCTIBLE, *id,
				    x, y, 0, PATH_INDESTRUCTIBLE));
	    *id += 1;
	  }
      else
	{
	  map.push_back(new G_obj(INDESTRUCTIBLE, *id,
				  0, y, 0, PATH_INDESTRUCTIBLE));
	  *id += 1;
	  map.push_back(new G_obj(INDESTRUCTIBLE, *id,
				  map_param.weight - 1, y, 0, PATH_INDESTRUCTIBLE));
	  *id += 1;
	}
    }
}

static void	generate_indestructible(std::deque<G_obj*> &map, t_param_map &map_param, int *id)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  y = 2;
  while (map_param.height > y)
    {
      x = (rand() % 2) + 2;
      while (map_param.weight > x)
	{
	  map.push_back(new G_obj(INDESTRUCTIBLE, *id,
				  x, y, 0, PATH_INDESTRUCTIBLE));
	  *id += 1;
	  x += (rand() % 2) + 2;
	}
      y += (rand() % 2) + 2;
    }
}

static void	generate_player(std::deque<G_obj*> &map, t_param_map &map_param, int *id)
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
	  map.push_back(new G_obj(PLAYER, *id, x, y, 0, PATH_PLAYER));
	  *id += 1;
	  ++i;
	}
    }
}

static void	generate_mob(std::deque<G_obj*> &map, t_param_map &map_param, int *id)
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
	  map.push_back(new G_obj(BOT, *id, x, y, 0, PATH_BOT));
	  *id += 1;
	  ++i;
	}
    }
}

static void	generate_destructible(std::deque<G_obj*> &map, t_param_map &map_param, int *id)
{
  int	x;
  int	y;
  int	limit;

  limit = (map_param.height - 1) * (map_param.weight - 1) +
    map_param.character_max + map_param.player * 4;
  while (*id < limit)
    {
      x = (rand() % (map_param.weight - 2)) + 1;
      y = (rand() % (map_param.height - 2)) + 1;
      if (verif_not_used(map, x, y) == true)
	{
	  map.push_back(new G_obj(DESTRUCTIBLE, *id, x, y, 0, PATH_DESTRUCTIBLE));
	  *id += 1;
	}
    }
}

void	generate_map(std::deque<G_obj*> &map, t_param_map &map_param)
{
  int	id;

  id = 0;
  srand(time(NULL));
  generate_contour(map, map_param, &id);
  std::cout << "contour generated." << std::endl;
  generate_indestructible(map, map_param, &id);
  std::cout << "wall indestructible generated." << std::endl;
  generate_player(map, map_param, &id);
  std::cout << "players generated." << std::endl;
  generate_mob(map, map_param, &id);
  std::cout << "mob generated." << std::endl;
  generate_destructible(map, map_param, &id);
  std::cout << "wall destructible generated." << std::endl
	    << "Map generated." << std::endl;
}
