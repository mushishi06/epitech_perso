//
// Operand.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 15:22:42 2012 Emelyne
// Last update Wed Feb 15 15:18:57 2012 Emelyne
//

#include		<limits>
#include		"Memory.hh"
#include		"OperandInt8.hh"

namespace		Chipset
{

OperandInt8::OperandInt8(std::string const &str)
  : AOperand(str)
{
  int	min = std::numeric_limits<char>::min();
  int	max = std::numeric_limits<char>::max();

  if ((atoi(str.c_str()) < min) || (atoi(str.c_str()) > max))
    throw Error(OUTRANG);
  this->nb_ = atoi(str.c_str());
  this->setPrecision(0);
  this->setType(Int8);
}

OperandInt8::~OperandInt8()
{
}


char			OperandInt8::getNb() const
{
  return (this->nb_);
}

void			OperandInt8::setNb(const char &nb)
{
  std::ostringstream    oss;

  oss << (nb + 0);
  this->setString(oss.str());
  this->nb_ = nb;
}

IOperand		*OperandInt8::operator+(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem		mem;
  char			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  tmp = atoi(rhs.toString().c_str());
  if (((tmp + this->getNb()) < (-127)) || (tmp + this->getNb()) > 127)
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (tmp + this->getNb()));
  return (res);
}

IOperand                *OperandInt8::operator-(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem		mem;
  char			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  tmp = atoi(rhs.toString().c_str());
  if (((tmp - this->getNb()) < (-127)) || (tmp - this->getNb()) > 127)
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() - tmp));
  return (res);
}

IOperand                *OperandInt8::operator*(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem		mem;
  char			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  tmp = atoi(rhs.toString().c_str());
  if (((tmp * this->getNb()) < (-127)) || (tmp * this->getNb()) > 127)
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() * tmp));
  return (res);
}

IOperand		*OperandInt8::operator/(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem		mem;
  char                  tmp;

  tmp = atoi(rhs.toString().c_str());
  if (tmp == 0)
    throw Error(DOMDIV);
  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  if (((tmp / this->getNb()) < (-127)) || (tmp / this->getNb()) > 127)
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() / tmp));
  return (res);
}

IOperand                *OperandInt8::operator%(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem		mem;
  char                  tmp;

  tmp = atoi(rhs.toString().c_str());
  if (tmp == 0)
    throw Error(DOMMOD);
  if ((this->getType() == Float) || (this->getType() == Double))
    throw Error(DOMMODF);
  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  if (((tmp % this->getNb()) < (-127)) || (tmp % this->getNb()) > 127)
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() % tmp));
  return (res);
}

}
