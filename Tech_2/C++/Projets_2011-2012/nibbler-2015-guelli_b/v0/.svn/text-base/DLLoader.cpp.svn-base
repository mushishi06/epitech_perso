//
// DLLoader.cpp for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 21:27:37 2012 igor morenosemedo
// Last update Sun Mar 18 00:29:38 2012 igor morenosemedo
//

#include "Exception.hh"
#include "DLLoader.hh"

DLLoader::DLLoader(const std::string &name)
{
  this->_dlhandle = dlopen(name.c_str(), RTLD_NOW);
  if (this->_dlhandle == NULL)
    throw DynLinkError();
  this->_NibblerDaze = reinterpret_cast<IDisplayModule* (*)()>
    (dlsym(_dlhandle, "create_nibbler"));
  if (this->_NibblerDaze == NULL)
    {
      std::cerr<< dlerror() << std::endl;
      dlclose(this->_dlhandle);
      exit (1);
    }
}

DLLoader::~DLLoader()
{
  dlclose(this->_dlhandle);
}

IDisplayModule *DLLoader::getInstance()
{
  return ((*this->_NibblerDaze)());
}
