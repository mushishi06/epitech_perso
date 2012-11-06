#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include "Bomberman.hpp"
#include "AObject.hpp"

bool	save_map(std::deque<AObject*> &map, std::string &map_name, t_param_map &map_param);
void	generate_map(std::deque<AObject*> &map, t_param_map &map_param);

struct	t_tab_enum
{
  e_type	obj;
  char		symbol;
};

t_tab_enum tab_[]=
  {
    {PLAYER, 'X'},
    {BOT, '*'},
    {BOMB, 'B'},
    {DESTRUCTIBLE, 'D'},
    {INDESTRUCTIBLE, 'W'},
    {INDESTRUCTIBLE, '\0'}
  };

void	show_map(std::deque<AObject*> &map, t_param_map &map_param)
{
  char **new_map;
  std::deque<AObject*>::iterator	it = map.begin();
  int	i;
  int	found;

  new_map = (char**)malloc((map_param.height + 1) * sizeof(char*));
  for (i = 0; i != map_param.height; i++)
    {
      new_map[i] = (char*)malloc((map_param.weight + 1) * sizeof(char));
      memset(new_map[i], ' ', map_param.weight);
      new_map[i][map_param.weight] = '\0';
    }
  new_map[i] = NULL;
  std::cout << std::endl << "map =>" << std::endl;
  for (; it != map.end(); ++it)
    {
      found = 0;
      i = 0;
      while (tab_[i].symbol != '\0')
	{
	  if (tab_[i].obj == (*it)->getType())
	    {
	      new_map[((int)(*it)->getPosition().y)][((int)(*it)->getPosition().x)] = tab_[i].symbol;
	      found = 1;
	      break;
	    }
	  i++;
	}
      if (found == 0)
	std::cout << " " << std::endl;
    }
  i = 0;
  while (new_map[i])
    {
      std::cout << new_map[i] << std::endl;
      free(new_map[i]);
      i++;
    }
  free(new_map);
  std::cout << "end map" << std::endl;
}

int	main()
{
  t_param_map	param_map =
    {2, 1, 20, 20};
  std::deque<AObject*> map;

  generate_map(map, param_map);
  show_map(map, param_map);

  std::string	map_name;
  map_name = "test.xml";
  save_map(map, map_name, param_map);

  // std::deque<G_obj*> map2;
  // load_map(map, map_name);
  // show_map(map2, param_map);

}
