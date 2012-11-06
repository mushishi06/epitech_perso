//
// Exception.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 21:41:10 2012 igor morenosemedo
// Last update Sun Mar 18 00:56:24 2012 igor morenosemedo
//

#include <unistd.h>
#include <cstdlib>
#include <dlfcn.h>
#include <stdexcept>
#include <string>
#include <iostream>

class DynLinkError: public std::exception
{
public:
  DynLinkError() throw()
  {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }
  virtual ~DynLinkError() throw() {};
};

class ImageError : public std::runtime_error
{
public:
  ImageError(std::string const &str):runtime_error(str) {}
  virtual ~ImageError() throw() {};
};

class Error : public std::runtime_error
{
public:
  Error(std::string const &str):runtime_error(str) {}
  virtual ~Error() throw() {};
};
