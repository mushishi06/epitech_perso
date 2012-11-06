 //
// Operand.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 15:22:42 2012 Emelyne
// Last update Wed Feb 15 15:19:42 2012 Emelyne
//

#include		<limits>
#include		"Memory.hh"
#include		"OperandInt32.hh"

namespace		Chipset
{

OperandInt32::OperandInt32(std::string const &str)
  : AOperand(str)
{
  std::istringstream	iss(str);

  if ((atoi(str.c_str()) < (std::numeric_limits<int>::min())) ||
      (atoi(str.c_str()) > std::numeric_limits<int>::max()))
    throw Error(OUTRANG);
  iss >> nb_;
  this->setPrecision(2);
  this->setType(Int32);
}

OperandInt32::~OperandInt32()
{
}

int			OperandInt32::getNb() const
{
  return (this->nb_);
}

void			OperandInt32::setNb(const int &nb)
{
  std::ostringstream    oss;
  oss << nb;
  this->setString(oss.str());
  this->nb_ = nb;
}

IOperand		*OperandInt32::operator+(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  int			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  if (((tmp + this->getNb()) < (-32767)) || ((tmp + this->getNb()) > 32767))
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() + tmp));
  return (res);
}

IOperand                *OperandInt32::operator-(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  int			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  if (((tmp - this->getNb()) < (-32767)) || ((tmp - this->getNb()) > 32767))
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() - tmp));
  return (res);
}

IOperand                *OperandInt32::operator*(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  int			tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  if (((tmp * this->getNb()) < (-32767)) || ((tmp * this->getNb()) > 32767))
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() * tmp));
  return (res);
}

IOperand		*OperandInt32::operator/(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  int                  tmp;

  iss >> tmp;
  if (tmp == 0)
    throw Error(DOMDIV);
  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  if (((tmp / this->getNb()) < (-32767)) || ((tmp / this->getNb()) > 32767))
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() / tmp));
  return (res);
}

IOperand                *OperandInt32::operator%(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  int                   tmp;

  iss >> tmp;
  if (tmp == 0)
    throw Error(DOMMOD);
  if ((this->getType() == Float) || (this->getType() == Double))
    throw Error(DOMMODF);
  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  if (((tmp % this->getNb()) < (-32767)) || ((tmp % this->getNb()) > 32767))
    throw Error(OUTRANG);
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() % tmp));
  return (res);
}

}
