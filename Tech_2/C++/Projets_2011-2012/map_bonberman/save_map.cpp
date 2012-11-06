//
// save_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/bomberman-2015-savine_s/sources/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 10:35:11 2012 laurent ha-tam-dan
// Last update Wed May 23 19:43:01 2012 belia-_r
//

#include <fstream>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "AObject.hpp"
#include "Bomberman.hpp"

t_label_xml	label_xml[]=
  {
    {PLAYER, "<Player>\n", "</Player>\n", save_player},
    {BOT, "<Bot>\n", "</Bot>\n", save_bot},
    {BOMB, "<Bomb>\n", "</Bomb>\n", save_bomb},
    {DESTRUCTIBLE, "<Destructible>\n", "</Destructible>\n", save_destructible},
    {INDESTRUCTIBLE,"<Indestructible>\n", "</Indestructible>\n", save_indestructible},
    {INDESTRUCTIBLE, NULL, NULL, NULL}
  };

void	put_base(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  my_file << "<Object>\n";
  // my_file << "<graph_path>" << (*it)->getGraph_path() << "</graph_path>\n";
  my_file << "<Type>" << (*it)->getType() << "</Type>\n";
  // my_file << "<ID>" << (*it)->getID() << "</ID>\n";
  my_file << "<Pos_x>" << (*it)->getPosition().x << "</Pos_x>\n";
  my_file << "<Pos_y>" << (*it)->getPosition().y << "</Pos_y>\n";

  // my_file << "<Pos_z>" << (*it)->getZ() << "</Pos_z>\n";
}

void	save_player(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "</Object>\n";
}

void	save_bot(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "</Object>\n";
}

void	save_bomb(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "</Object>\n";
}

void	save_destructible(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "</Object>\n";
}

void	save_indestructible(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "</Object>\n";
}

bool	save_map(std::deque<AObject*> &map, std::string &map_name, t_param_map &map_param)
// manque la structure avec le temps rentant etc...
{
  std::deque<AObject*>::iterator  it = map.begin();
  std::fstream			my_file;
  int				i;

  my_file.open(map_name.c_str(), std::fstream::out);
  if (!my_file.good())
    {
      if (!my_file.is_open())
	my_file.close();
      return (false);
    }
  my_file << "<?xml version=\"1.0\"?>\n\n";
  my_file << "<Game>\n";
  my_file << "<Size>\n";
  my_file << "<Height>" << t_param_map.height << "</Height>\n";
  my_file << "<Weight>" << t_param_map.weight << "</Weight>\n";
  my_file << "</Size>\n";
  my_file << "</Game>\n";
  //j'ai passer le debut (temps restant etc..)
  my_file << "<list_item>\n";
  for (; it != map.end(); ++it)
    {
      i = 0;
      while (label_xml[i].m_start != NULL)
	{
	  if (label_xml[i].m_type == (*it)->getType())
	    {
	      // my_file << label_xml[i].m_start;
	      label_xml[i].save_func(it, my_file);
	      // my_file << label_xml[i].m_end;
	      break;
	    }
	  i++;
	}
    }
  my_file << "</list_item>\n";
  my_file.close();
  return (true);
}
