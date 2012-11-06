//
// Memory.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractvm-2015-houpla_e
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Thu Feb  9 13:02:26 2012 Emelyne
// Last update Thu Feb  9 15:19:07 2012 Emelyne
//

#include		"Comm.hh"
#include		"Memory.hh"

namespace		Memory
{

Mem::Mem()
{
  Creates_[Chipset::Int8] = &Mem::createInt8;
  Creates_[Chipset::Int16] = &Mem::createInt16;
  Creates_[Chipset::Int32] = &Mem::createInt32;
  Creates_[Chipset::Float] = &Mem::createFloat;
  Creates_[Chipset::Double] = &Mem::createDouble;
}

Mem::~Mem()
{
}

Chipset::IOperand       *Mem::createOperand(Chipset::eOperandType type,
					     const std::string &value)
{
  std::map<Chipset::eOperandType, Mem::createPtr>::iterator    it;
  Chipset::IOperand                                             *newOperand;

  for (it = Creates_.begin(); it != Creates_.end(); it++)
    {
      if (it->first == type)
	newOperand = (this->*(it->second))(value);
    }
  return (newOperand);
}

  Chipset::IOperand       *Mem::createInt8(const std::string &value)
  {
    Chipset::IOperand     *newnb = new Chipset::OperandInt8(value);
    return (newnb);
  }

  Chipset::IOperand       *Mem::createInt16(const std::string &value)
  {
    Chipset::IOperand     *newnb = new Chipset::OperandInt16(value);
    return (newnb);
  }

  Chipset::IOperand       *Mem::createInt32(const std::string &value)
  {
    Chipset::IOperand     *newnb = new Chipset::OperandInt32(value);
    return (newnb);
  }

  Chipset::IOperand       *Mem::createFloat(const std::string &value)
  {
    Chipset::IOperand     *newnb = new Chipset::OperandFloat(value);
    return (newnb);
  }

  Chipset::IOperand       *Mem::createDouble(const std::string &value)
  {
    Chipset::IOperand     *newnb = new Chipset::OperandDouble(value);
    return (newnb);
  }


}
