//
// Operand.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 15:22:42 2012 Emelyne
// Last update Wed Feb 15 15:01:33 2012 Emelyne
//

#include		<cfloat>
#include		<limits>
#include		"Memory.hh"
#include		"OperandFloat.hh"

namespace		Chipset
{

OperandFloat::OperandFloat(std::string const &str)
  : AOperand(str)
{
  std::istringstream	iss(str);

  iss >> nb_;
  if ((nb_ < (std::numeric_limits<float>::min())) ||
      (nb_ > std::numeric_limits<float>::max()))
    throw Error(OUTRANG);
  this->setPrecision(3);
  this->setType(Float);
}

OperandFloat::~OperandFloat()
{
}

float			OperandFloat::getNb() const
{
  return (this->nb_);
}

void			OperandFloat::setNb(const float &nb)
{
  std::ostringstream    oss;

  oss << nb;
  this->setString(oss.str());
  this->nb_ = nb;
}

IOperand		*OperandFloat::operator+(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  float			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() + tmp));
  return (res);
}

IOperand                *OperandFloat::operator-(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  float			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() - tmp));
  return (res);
}

IOperand                *OperandFloat::operator*(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  float			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() * tmp));
  return (res);
}

IOperand		*OperandFloat::operator/(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  float                  tmp;

  iss >> tmp;
  if (tmp == 0)
    throw Error(DOMDIV);
  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() / tmp));
  return (res);
}

IOperand                *OperandFloat::operator%(const IOperand &) const
{
  throw Error(DOMMODF);
}

}
