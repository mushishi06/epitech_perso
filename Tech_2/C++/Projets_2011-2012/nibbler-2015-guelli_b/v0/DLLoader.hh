//
// DLLoader.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 20:36:56 2012 igor morenosemedo
// Last update Tue Mar 13 22:20:50 2012 igor morenosemedo
//

#ifndef _DLLOADER_HH_
# define _DLLOADER_HH_

#include <string>
#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "IDisplayModule.hh"

//chargeur de lobrairie
class DLLoader
{
private:
  IDisplayModule	*(*_NibblerDaze)();//extern C
  void			*_dlhandle;

public:
  DLLoader(const std::string &); //dlopen dlsym, dlclose
  ~DLLoader(); //dlcose

public:
  IDisplayModule	*getInstance();
};

#endif
