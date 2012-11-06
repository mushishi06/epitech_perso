//
// load_map.cpp for bomberman in /home/ha-tam_l/Desktop/projet/bomberman/gitolite@89.92.92.67:bomberman.git/map
//
// Made by laurent ha-tam-dan
// Login   <ha-tam_l@epitech.net>
//
// Started on  Sat May 19 13:12:19 2012 laurent ha-tam-dan
// Last update Sun Jun  3 21:13:50 2012 belia-_r
//

#include	<iostream>
#include	<string>
#include	"string_to_nbr.hpp"
#include	"Load_map.hpp"
#include	"MyGame.hpp"
#include	"Bomber.hpp"
#include	"Object.hpp"
#include	"Aintelligence.hpp"
#include	"SecondBomber.hpp"
#include	"Bomb.hpp"
#include	"Monster.hpp"

static int nb_player = 0;

static bool	verif_inf(std::fstream &my_file, std::string &m_str)
{
  static std::string	m_verif = "";

  my_file >> m_str;
  if (m_verif == m_str)
    return (false);
  m_verif = m_str;
  return (true);
}

static void	load_player(std::deque<AObject*> &map, std::vector<int> &m_vector)
{
  std::deque<AObject*>::iterator it;

  if (nb_player == 0)
    {
      map.push_back(new Bomberman(m_vector[POSX], m_vector[POSY], PLAYER));
      nb_player = 1;
    }
  else
    map.push_back(new SecondBomberman(m_vector[POSX], m_vector[POSY], PLAYER));
  it = map.end();
  --it;
  dynamic_cast<Player*>(*it)->setNbBomb((int)m_vector[BOMB_NB]);
  dynamic_cast<Player*>(*it)->setTotBomb((int)m_vector[BOMB_MAX]);
  dynamic_cast<Player*>(*it)->setSpeed((int)m_vector[SPEED]);
  dynamic_cast<Player*>(*it)->setRange((int)m_vector[RANGE]);
}

static void	load_ia(std::deque<AObject*> &map, std::vector<int> &m_vector)
{
  std::deque<AObject*>::iterator it;

  map.push_back(new Aintelligence(m_vector[POSX], m_vector[POSY], IA));
  it = map.end();
  --it;
  dynamic_cast<Player*>(*it)->setNbBomb((int)m_vector[BOMB_NB]);
  dynamic_cast<Player*>(*it)->setTotBomb((int)m_vector[BOMB_MAX]);
  dynamic_cast<Player*>(*it)->setSpeed((int)m_vector[SPEED]);
  dynamic_cast<Player*>(*it)->setRange((int)m_vector[RANGE]);
}

static void	load_bomb(std::deque<AObject*> &map, std::vector<int> &m_vector)
{
  std::deque<AObject*>::iterator it = map.begin();
  int	find = 0;

  while (it != map.end() &&
	 m_vector[N_PLAYER] > find)
    {
      if (((m_vector[N_PLAYER] == 2 || m_vector[N_PLAYER] == 1) && (*it)->getType() == PLAYER) ||
	  (m_vector[N_PLAYER] == 3 && (*it)->getType() == IA))
	break;
      ++it;
    }
  map.push_back(new Bomb(m_vector[POSX], m_vector[POSY], BOMB ,
  			 dynamic_cast<Player*>(*it)->getRange(),
  			 (*it), m_vector[N_PLAYER]));
  it = map.end();
  --it;
  dynamic_cast<Bomb*>(*it)->setTime(m_vector[TIMER]);
}

static void	load_item(std::deque<AObject*> &map, std::vector<int> &m_vector)
{
  int	bonus = 0;

  if ((e_type)m_vector[TYPE] == BONUS_NB_BOMB ||
      (e_type)m_vector[TYPE] == BONUS_SPEED ||
      (e_type)m_vector[TYPE] == BONUS_PORT_BOMB)
    bonus = 3;
  map.push_back(new Cube(m_vector[POSX], m_vector[POSY], (e_type)(m_vector[TYPE] + bonus)));
}

static void	load_bot(std::deque<AObject*> &map, std::vector<int> &m_vector)
{
   map.push_back(new Monster(m_vector[POSX], m_vector[POSY], (e_type)m_vector[TYPE]));
}

static bool	get_param(t_param_map &map_param, std::fstream &my_file)
{
  std::string	tmp;

  tmp = "";
  while (tmp != "<Parameter>")
    if (verif_inf(my_file, tmp) == false)
      return (false);
  while (tmp != "</Parameter>")
    {
      if (verif_inf(my_file, tmp) == false)
	return (false);
      if (tmp.compare(0, 10, "<Max_Char>") == 0)
	map_param.character_max = string_to_nbr<int>(tmp.c_str() + 10);
      if (tmp.compare(0, 8, "<Player>") == 0)
	map_param.player = string_to_nbr<int>(tmp.c_str() + 8);
      if (tmp.compare(0, 8, "<Height>") == 0)
	  map_param.height = string_to_nbr<int>(tmp.c_str() + 8);
      if (tmp.compare(0, 8, "<Weight>") == 0)
	  map_param.weight = string_to_nbr<int>(tmp.c_str() + 8);
    }
  return (true);
}

static bool	get_object(std::deque<AObject*> &map, std::fstream &my_file, AObject *m_player)
{
  std::string		tmp = "";
  std::vector<int>	res;
  int			i;
  Vector3f	pos(0, 0, 0);
  t_load_xml	load_xml[]=
    {
      {PLAYER, load_player},
      {IA, load_ia},
      {BOT, load_bot},
      {BOMB, load_bomb},
      {BONUS_NB_BOMB, load_item},
      {BONUS_SPEED, load_item},
      {BONUS_PORT_BOMB, load_item},
      {DESTRUCTIBLE, load_item},
      {INDESTRUCTIBLE, load_item},
      {GRASS, NULL}
    };
  t_parse_vec	parse_vec[] =
    {
      {"<Type>", TYPE},
      {"<Pos_x>", POSX},
      {"<Pos_y>", POSY},
      {"<Bomb_Max>", BOMB_MAX},
      {"<Bomb_Nb>", BOMB_NB},
      {"<Speed>", SPEED},
      {"<Range>", RANGE},
      {"<N_Player>", N_PLAYER},
      {"<Timer>", TIMER},
      {"", 0}
    };

  i = 0;
  for (; i < 7; ++i)
    res.push_back(0);
  while (tmp != "</Object>")
    {
      if (verif_inf(my_file, tmp) == false)
	return (false);
      for (i = 0; parse_vec[i].m_str != ""; ++i)
	{
	  if (tmp.compare(0, parse_vec[i].m_str.size(), parse_vec[i].m_str) == 0)
	    res[parse_vec[i].type] = string_to_nbr<int>(tmp.c_str() + parse_vec[i].m_str.size());
	}
    }
  for (i = 0; load_xml[i].func != NULL; ++i)
    if ((e_type)res[TYPE] == load_xml[i].type)
      {
	if ((e_type)res[TYPE] == PLAYER && m_player != NULL)
	  {
	    pos.x = res[POSX];
	    pos.y = res[POSY];
	    m_player->setPosition(pos);
	  }
	else
	  load_xml[i].func(map, res);
      }
  return (true);
}

static bool	get_item(std::deque<AObject*> &map, std::fstream &my_file, AObject *m_player)
{
  std::string		tmp = "";

  while (tmp != "<Item>")
    if (verif_inf(my_file, tmp) == false)
      return (false);
  while (tmp != "</Item>")
    {
      if (verif_inf(my_file, tmp) == false)
	return (false);
      if (tmp == "<Object>")
	if (get_object(map, my_file, m_player) == false)
	  return (false);
    }
  std::cout <<  "END" << std::endl;
  return (true);
}

static void	generate_Grass(std::deque<AObject*> &map, t_param_map &map_param)
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
                 (*it)->getType() == DOOR_OPEN ||
		 (*it)->getType() == DOOR_CLOSE) &&
                (*it)->getPosition().x == x * 300 &&
                (*it)->getPosition().z == y * 300)
	      find = true;
	  }
	if (find == false)
	  map.push_back(new Carre(x * 300, y * 300, GRASS));
      }
}

bool		load_map(std::deque<AObject*> &map, std::string &map_name,
			 t_param_map &map_param, AObject *m_player)
{
  std::fstream	my_file;

  my_file.open(map_name.c_str(), std::fstream::in);
  if (!my_file.good())
    {
      if (!my_file.is_open())
	my_file.close();
      return (false);
    }
  if (get_param(map_param, my_file) == false ||
      get_item(map, my_file, m_player) == false)
    {
      nb_player = 0;
      my_file.close();
      return (false);
    }
  nb_player = 0;
  generate_Grass(map, map_param);
  my_file.close();
  return (true);
}
