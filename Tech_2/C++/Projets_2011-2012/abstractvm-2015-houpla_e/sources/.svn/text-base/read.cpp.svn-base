//
// read.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 12:02:42 2012 Emelyne
// Last update Thu Feb  9 11:04:27 2012 Emelyne
//

#include		<fstream>
#include		<iostream>
#include		<string>
#include		"IO.hh"

std::string		IO::readIn()
{
  std::string		buff;
  std::string		line;

  std::getline(std::cin, line);
  buff.append(line);
  buff.append("\n");
  while (line.find(";;") == std::string::npos)
    {
      std::getline(std::cin, line);
      buff.append(line);
      buff.append("\n");
      if (line.find(";;") != std::string::npos)
	buff.replace(buff.find(";;"), 2,"");
    }
  return (buff);
}

std::string		IO::readFile(const char *str)
{
  std::string		buff;
  std::string		line;
  std::ifstream		fd(str);

  try
    {
      if (fd == NULL)
	throw "Wrong file, file does not exist";
      while (std::getline(fd, line))
	{
	  buff.append(line);
	  buff.append("\n");
	}
    }
  catch (const char *e)
    {
      std::cerr  << e << std::endl;
    }
  fd.close();
  return (buff);
}
