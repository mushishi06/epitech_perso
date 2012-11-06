//
// load_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 13:12:19 2012 laurent ha-tam-dan
// Last update Tue May 22 14:36:59 2012 belia-_r
//

#include <fstream>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Generic_object.hpp"
#include "bomberman.hpp"
#include "string_to_nbr.hpp"

#include <algorithm>

void	test_map(G_obj *m_object)
{
  std::cout << m_object->getX() << "|" << m_object->getY() << "|"
	    << m_object->getZ() << "\t" << m_object->getID()
	    << "\t" << m_object->getType() << "\t"
	    << m_object->getGraph_path() << std::endl;
}

t_load_xml	load_xml[]=
  {
    {PLAYER, "<Player>", "</Player>", load_player},
    {BOT, "<Bot>", "</Bot>", load_bot},
    {BOMB, "<Bomb>", "</Bomb>", load_bomb},
    {DESTRUCTIBLE, "<Destructible>", "</Destructible>", load_destructible},
    {INDESTRUCTIBLE,"<Indestructible>", "</Indestructible>", load_indestructible},
    {INDESTRUCTIBLE, NULL, NULL, NULL}
  };

void	recup_base(G_obj *m_object, std::fstream &my_file)
{
  std::string	tmp;

  tmp = "";
  while (strncmp("</", tmp.c_str(), 2) != 0)
    {
      my_file >> tmp;
      if (strncmp("<type>", tmp.c_str(), 6) == 0)
	m_object->setType((Obj_type)string_to_nbr<int>(tmp.c_str() + 6));
      if (strncmp("<Pos_x>", tmp.c_str(), 7) == 0)
	m_object->setX(string_to_nbr<int>(tmp.c_str() + 7));
      if (strncmp("<Pos_y>", tmp.c_str(), 7) == 0)
	m_object->setY(string_to_nbr<int>(tmp.c_str() + 7));
      if (strncmp("<Pos_z>", tmp.c_str(), 7) == 0)
	m_object->setZ(string_to_nbr<int>(tmp.c_str() + 7));
      if (strncmp("<ID>", tmp.c_str(), 4) == 0)
	m_object->setID(string_to_nbr<int>(tmp.c_str() + 4));
      if (strncmp("<graph_path>", tmp.c_str(), 12) == 0)
	{
	  // A CHANGER
	  char *str = strdup(tmp.c_str() + 12);
	  str[strlen(str) - 13] = '\0';
	  tmp = str;
	  free(str);
	  m_object->setGraph_path(tmp);
	}
    }
}

void	load_player(std::deque<G_obj*> &map, std::fstream &my_file)
{
  G_obj	m_object;

  recup_base(&m_object, my_file);
  map.push_back(&m_object);
  for_each(map.begin(), map.end(), test_map);
}

void	load_bot(std::deque<G_obj*> &map, std::fstream &my_file)
{
  G_obj	m_object;

  recup_base(&m_object, my_file);
  map.push_back(&m_object);
}

void	load_bomb(std::deque<G_obj*> &map, std::fstream &my_file)
{
  G_obj	m_object;

  recup_base(&m_object, my_file);
  map.push_back(&m_object);
}

void	load_destructible(std::deque<G_obj*> &map, std::fstream &my_file)
{
  G_obj	m_object;

  recup_base(&m_object, my_file);
  map.push_back(&m_object);
}

void	load_indestructible(std::deque<G_obj*> &map, std::fstream &my_file)
{
  G_obj	m_object;

  recup_base(&m_object, my_file);
  map.push_back(&m_object);
}


bool	load_map(std::deque<G_obj*> &map, std::string &map_name)
{
  std::fstream			my_file;
  std::string			tmp;
  int	i;

  my_file.open(map_name.c_str(), std::fstream::in);
  if (!my_file.good())
    {
      if (!my_file.is_open())
	my_file.close();
      return (false);
    }
  tmp = "";
  while (tmp != "<map>")
    my_file >> tmp;
  while (tmp != "</map>")
    {
      my_file >> tmp;
      i = 0;
      while (load_xml[i].m_start != NULL)
	{
	  if (load_xml[i].m_start == tmp)
	    {
	      load_xml[i].func(map, my_file);
	      break;
	    }
	  i++;
	}
    }
  my_file.close();
  return (false);
}
