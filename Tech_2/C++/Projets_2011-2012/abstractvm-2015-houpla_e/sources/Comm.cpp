//
// Comm.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Mon Feb  6 13:09:01 2012 Emelyne
// Last update Sat Feb 11 19:21:04 2012 Emelyne
//

#include		"Comm.hh"

namespace		CPU
{

Comm::Comm()
{
  initMaps();
}

Comm::Comm(const Comm &comm)
  : line_(comm.line_)
{
  initMaps();
}

Comm			&Comm::operator=(const Comm &comm)
{
  line_ = comm.getLine();
  return (*this);
}

Comm::~Comm()
{
}

Chipset::Line		Comm::getLine(void) const
{
  return (this->line_);
}

void			Comm::setLine(const Chipset::Line &line)
{
  line_ = line;
}

void			Comm::initMaps(void)
{
  ListComm_["push"] = &Comm::push_;
  ListComm_["pop"] = &Comm::pop_;
  ListComm_["dump"] = &Comm::dump_;
  ListComm_["assert"] = &Comm::assert_;
  ListComm_["add"] = &Comm::add_;
  ListComm_["sub"] = &Comm::sub_;
  ListComm_["mul"] = &Comm::mul_;
  ListComm_["div"] = &Comm::div_;
  ListComm_["mod"] = &Comm::mod_;
  ListComm_["print"] = &Comm::print_;
  ListComm_["exit"] = &Comm::exit_;

  Types_[Chipset::Int8] = "int8";
  Types_[Chipset::Int16] = "int16";
  Types_[Chipset::Int32] = "int32";
  Types_[Chipset::Float] = "float";
  Types_[Chipset::Double] = "double";
}

bool			Comm::push_(Chipset::IOperand *nb,
					  std::vector<Chipset::IOperand*> &pile)
{
  pile.push_back(nb);
  return (true);
}

bool			Comm::pop_(Chipset::IOperand *,
					 std::vector<Chipset::IOperand*> &pile)
{
  if (pile.size() != 0)
    pile.pop_back();
  else
    throw Error(POP);
  return (true);
}

bool			Comm::dump_(Chipset::IOperand *,
				    std::vector<Chipset::IOperand*> &pile)
{
  std::vector<Chipset::IOperand *>::reverse_iterator	it;
  std::string						str;

  for (it = pile.rbegin(); it != pile.rend(); it++)
    std::cout << (*it)->toString() << std::endl;
  return (true);
}

bool			Comm::assert_(Chipset::IOperand *nb,
				      std::vector<Chipset::IOperand*> &pile)
{
  if ((pile.back()->getType() != nb->getType()) ||
      (pile.back()->toString().compare(nb->toString()) != 0))
    throw Error(ASSERT);
  return (true);
}

bool			Comm::add_(Chipset::IOperand *,
				   std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp2;
  Chipset::IOperand	*tmp1;
  Chipset::IOperand	*res;

  if (pile.size() < 2)
    throw Error(POP);
  tmp1 = pile.back();
  pile.pop_back();
  tmp2 = pile.back();
  pile.pop_back();
  res = (*tmp1) + (*tmp2);
  pile.push_back(res);
  return (true);
}

bool			Comm::sub_(Chipset::IOperand *,
				   std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp2;
  Chipset::IOperand	*tmp1;
  Chipset::IOperand	*res;

  if (pile.size() < 2)
    throw Error(POP);
  tmp1 = pile.back();
  pile.pop_back();
  tmp2 = pile.back();
  pile.pop_back();
  res = *tmp1 - *tmp2;
  pile.push_back(res);
  return (true);
}

bool			Comm::mul_(Chipset::IOperand *,
				   std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp2;
  Chipset::IOperand	*tmp1;
  Chipset::IOperand	*res;

  if (pile.size() < 2)
    throw Error(POP);
  tmp1 = pile.back();
  pile.pop_back();
  tmp2 = pile.back();
  pile.pop_back();
  res = (*tmp1) * (*tmp2);
  pile.push_back(res);
  return (true);
}

bool			Comm::div_(Chipset::IOperand *,
				   std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp2;
  Chipset::IOperand	*tmp1;
  Chipset::IOperand	*res;

  if (pile.size() < 2)
    throw Error(POP);
  tmp1 = pile.back();
  pile.pop_back();
  tmp2 = pile.back();
  pile.pop_back();
  res = *tmp1 / *tmp2;
  pile.push_back(res);
  return (true);
}

bool			Comm::mod_(Chipset::IOperand *,
				   std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp2;
  Chipset::IOperand	*tmp1;
  Chipset::IOperand	*res;

  if (pile.size() < 2)
    throw Error(POP);
  tmp1 = pile.back();
  pile.pop_back();
  tmp2 = pile.back();
  pile.pop_back();
  res = *tmp1 % *tmp2;
  pile.push_back(res);
  return (true);
}

bool			Comm::print_(Chipset::IOperand *,
				     std::vector<Chipset::IOperand*> &pile)
{
  Chipset::IOperand	*tmp;
  char			tmpnb;

  if (pile.size() < 1)
    throw Error(POP);
  if (pile.back()->getType() != Chipset::Int8)
    throw Error(ASSERT);
  tmp = pile.back();
  tmpnb = dynamic_cast<Chipset::OperandInt8*>(tmp)->getNb();
  std::cout << tmpnb << std::endl;
  return (true);
}

bool			Comm::exit_(Chipset::IOperand *,
				    std::vector<Chipset::IOperand*> &)
{
  return (false);
}

bool			Comm::execLine(Memory::Mem &memory)
{
  std::map<std::string, Comm::funcPtr>::iterator		it;
  std::map<Chipset::eOperandType, std::string>::iterator	i;
  Chipset::IOperand	*newNb;
  bool			is_flag;

  if (line_.getOperand().size() != 0)
    {
      is_flag = false;
      for (i = Types_.begin(); i != Types_.end(); i++)
	if (line_.getOperand().compare(i->second) == 0)
	  {
	    newNb = memory.createOperand(i->first, line_.getValue());
	    is_flag = true;
	  }
      if (is_flag == false)
	throw Error(SYNTAX);
    }
  for (it = ListComm_.begin(); it != ListComm_.end(); it++)
    if (line_.getInstr().compare(it->first) == 0)
      return ((this->*(it->second))(newNb, memory.pile));
  return (false);
}

}
