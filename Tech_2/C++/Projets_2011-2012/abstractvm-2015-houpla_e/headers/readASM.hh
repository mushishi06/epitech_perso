//
// readASM.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 16:49:17 2012 Emelyne
// Last update Fri Feb  3 16:53:57 2012 Emelyne
//

#ifndef		READASM_HH
#define		READASM_HH

#include        <iostream>
#include	<vector>
#include        <string>
#include	"IOperand.hh"

class		ReadAsm
{
  std::vector<IOperand>	tab;

public:
  std::string     readFile(const char *str);
  std::string     readIn();
  int             checkEnd(std::string file);
  void            parsFile(std::string file);
};

#endif		/* READASM_HH */
