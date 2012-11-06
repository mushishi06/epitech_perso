//
// main.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Thu Mar 15 19:55:15 2012 igor morenosemedo
// Last update Sun Mar 18 01:08:29 2012 igor morenosemedo
//

#include <cstdlib>
#include <dlfcn.h>
#include <exception>
#include <iostream>
#include <sstream>

#include "Exception.hh"
#include "Arguments.hh"
#include "DLLoader.hh"
#include "IDisplayModule.hh"
#include "Snake.hh"

int		Nibbler_Daze(IDisplayModule *module, char **av)
{
  Snake		snake(module);

  snake.setMap(ArgErr::getValue(av[1]), ArgErr::getValue(av[2]));
  srandom(time(NULL));
  return (snake.run());
}

int		main(int ac, char **av)
{
  if (ac <= 3)
    std::cout << USAGE << std::endl;
  else
    if (!ArgErr::isGood(av[1]) || !ArgErr::isGood(av[2]))
      std::cout << USAGE << std::endl;
    else
      {
	try
	  {
	    DLLoader	loader(av[3]);
	    IDisplayModule	*module = loader.getInstance();

	    if (module == NULL)
	      throw Error("Error on GetInstance");
	    Nibbler_Daze(module, av);
	  }
	catch (const std::exception & e)
	  {
	    std::cerr << e.what() << std::endl;
	  }
      }
  return (0);
}
