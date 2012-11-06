//
// Memory.hh for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Thu Feb  9 10:22:31 2012 Emelyne
// Last update Thu Feb  9 15:24:25 2012 Emelyne
//

#ifndef				MEMORY_HH
#define				MEMORY_HH

#include			<string>
#include			<map>
#include			<vector>
#include			"Chipset.hh"
#include			"IOperand.hh"

namespace      			Memory
{
  class				Mem
  {
    typedef Chipset::IOperand	*(Mem::*createPtr)(const std::string &value);
    std::map<Chipset::eOperandType, Mem::createPtr>	Creates_;

  public:
    Mem();
    ~Mem();

    std::vector<Chipset::IOperand*>			pile;

    Chipset::IOperand		*createOperand(Chipset::eOperandType type,
					       const std::string &value);
    Chipset::IOperand		*createInt8(const std::string &value);
    Chipset::IOperand		*createInt16(const std::string &value);
    Chipset::IOperand		*createInt32(const std::string &value);
    Chipset::IOperand		*createFloat(const std::string &value);
    Chipset::IOperand		*createDouble(const std::string &value);
  };
}

#endif				/* MEMORY_HH */
