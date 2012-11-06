//
// save_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/bomberman-2015-savine_s/sources/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 10:35:11 2012 laurent ha-tam-dan
// Last update Sun Jun  3 17:16:34 2012 laurent ha-tam-dan
//

#include	<fstream>
#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cstring>
#include	"Bomb.hpp"
#include	"Save_map.hpp"
#include	"Player.hpp"

void		put_base(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  my_file << "      <Type>" << (*it)->getType() << "</Type>\n"
	  << "      <Pos_x>" << (*it)->getPosition().x << "</Pos_x>\n"
	  << "      <Pos_y>" << (*it)->getPosition().z << "</Pos_y>\n";
}

void		save_player(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "      <Bomb_Max>" << dynamic_cast<Player*>(*it)->getTotBomb() << "</Bomb_Max>\n"
	  << "      <Bomb_Nb>" << dynamic_cast<Player*>(*it)->getNbBomb() << "</Bomb_Nb>\n"
	  << "      <Speed>" << dynamic_cast<Player*>(*it)->getSpeed() << "</Speed>\n"
	  << "      <Range>" << dynamic_cast<Player*>(*it)->getRange() << "</Range>\n";
}

void		save_bot(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
}

void		save_bomb(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
  my_file << "      <N_Player>" << dynamic_cast<Bomb*>(*it)->getPlayer() << "</N_Player>\n"
	  << "      <Time>" << dynamic_cast<Bomb*>(*it)->getTime() << "</Time>\n";
}

void		save_item(std::deque<AObject*>::iterator &it, std::fstream &my_file)
{
  put_base(it, my_file);
}

void		init_xml(t_param_map &map_param, std::fstream &my_file)
{
  my_file << "<?xml version=\"1.0\"?>\n"
	  << "<!-- Save_auto -->\n"
	  << "<Map>\n"
	  << "  <Game>\n"
	  << "    <Parameter>\n"
	  << "      <Max_Char>" << map_param.character_max << "</Max_Char>\n"
	  << "      <Player>" << map_param.player << "</Player>\n"
	  << "      <Height>" << map_param.height << "</Height>\n"
	  << "      <Weight>" << map_param.weight << "</Weight>\n"
	  << "    </Parameter>\n"
	  << "  </Game>\n"
	  << "  <Item>\n";
}

bool		save_map(std::deque<AObject*> &map, std::string &map_name,
			 t_param_map &map_param)
{
  std::deque<AObject*>::iterator	it = map.begin();
  std::fstream				my_file;
  int					i;
  t_label_xml	label_xml[]=
    {
      {PLAYER, save_player},
      {IA, save_player},
      {BOT, save_bot},
      {BOMB, save_bomb},
      {BONUS_NB_BOMB, save_item},
      {BONUS_SPEED, save_item},
      {BONUS_PORT_BOMB, save_item},
      {DOOR_OPEN, save_item},
      {DOOR_CLOSE, save_item},
      {DESTRUCTIBLE, save_item},
      {INDESTRUCTIBLE, save_item},
      //    {DANGER, save_Danger},
      {GRASS, NULL}
    };

  my_file.open(map_name.c_str(), std::fstream::out);
  if (!my_file.good())
    {
      if (!my_file.is_open())
	my_file.close();
      return (false);
    }
  init_xml(map_param, my_file);
  for (; it != map.end(); ++it)
    {
      i = 0;
      while (label_xml[i].save_func != NULL)
	{
	  if (label_xml[i].m_type == (*it)->getType())
	    {
	      my_file << "    <Object>\n";
	      label_xml[i].save_func(it, my_file);
	      my_file << "    </Object>\n";
	      break;
	    }
	  i++;
	}
    }
  my_file << "  </Item>\n"
	  << "</Map>\n";
  my_file.close();
  return (true);
}
