/*
** main.c for  in /home/emelyne/rendu/abstractVM
**
** Made by Emelyne
** Login   <emelyne@epitech.net>
**
** Started on  Fri Feb  3 10:35:37 2012 Emelyne
// Last update Thu Feb 16 00:23:00 2012 Emelyne
*/

#include	<iostream>
#include	<string>
#include	"Chipset.hh"
#include	"IO.hh"

void		readIn(bool verbose)
{
  std::string	file;

  try
    {
      file = IO::readIn();
      Chipset::parsFile(file, Chipset::checkEnd(file), verbose);
    }
  catch(const Error &e)
    {
      std::cout << e.what() << std::endl;
    }
}

void		readOut(char *av, bool verbose)
{
  std::string	file;

  try
    {
      file = IO::readFile(av);
      Chipset::parsFile(file, Chipset::checkEnd(file), verbose);
    }
  catch(const Error &e)
    {
      std::cout << e.what() << std::endl;
    }
}

bool		check_op(int ac, char **av, bool &help)
{
  bool		verbose = false;
  int		c;
  int		i = 0;

  while (i < ac)
    {
      c = getopt(ac, av, "v?");
      if (c == -1)
	break;
      switch (c)
        {
        case 'v':
	  verbose = true;
          break;
        case '?':
	  help = true;
	  std::cout << USAGE << std::endl;
	  break;
        default:
	  std::cout << USAGE << std::endl;
        }
      i++;
    }
  return (verbose);
}

int		main(int ac, char **av)
{
  bool		help = false;
  bool		verbose = check_op(ac, av, help);

  if (!help)
    {
      if (!(optind < ac))
	readIn(verbose);
      else
	{
	  for (; optind < ac; optind += 1)
	    {
	      std::cout << "---     ---     ---     ---" << std::endl
			<< "  Debut du fichier " << av[optind] << ": "
			<< std::endl
			<< "---     ---     ---     ---" << std::endl;
	      readOut(av[optind], verbose);
	      std::cout << "---     ---     ---     ---" << std::endl
			<< "  Fin du fichier " << av[optind] << "."
			<< std::endl
			<< "---     ---     ---     ---" << std::endl;
	    }
	}
    }
  return (0);
}
