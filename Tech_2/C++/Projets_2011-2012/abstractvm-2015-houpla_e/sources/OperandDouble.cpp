//
// Operand.cpp for  in /home/emelyne/rendu/projet_abstractVM/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Wed Feb  8 15:22:42 2012 Emelyne
// Last update Wed Feb 15 15:20:26 2012 Emelyne
//

#include		<cfloat>
#include		<limits>
#include		"Memory.hh"
#include		"OperandDouble.hh"

namespace		Chipset
{

OperandDouble::OperandDouble(std::string const &str)
  : AOperand(str)
{
  std::istringstream	iss(str);

  iss >> nb_;
  if ((nb_ < (std::numeric_limits<double>::min())) ||
      nb_ > std::numeric_limits<double>::max())
    throw Error(OUTRANG);
  this->setPrecision(4);
  this->setType(Double);
}

OperandDouble::~OperandDouble()
{
}

double			OperandDouble::getNb() const
{
  return (this->nb_);
}

void			OperandDouble::setNb(const double &nb)
{
  std::ostringstream    oss;

  oss << nb;
  this->setString(oss.str());
  this->nb_ = nb;
}

IOperand		*OperandDouble::operator+(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  double		tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() + tmp));
  return (res);
}

IOperand                *OperandDouble::operator-(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  double		tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() - tmp));
  return (res);
}

IOperand                *OperandDouble::operator*(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  double		tmp;

  if (this->getPrecision() > rhs.getPrecision())
    res = mem.createOperand(this->getType(), "1");
  else
    res = mem.createOperand(rhs.getType(), "1");
  iss >> tmp;
  dynamic_cast<AOperand*>(res)->dynamicCast((res), (this->getNb() * tmp));
  return (res);
}

IOperand		*OperandDouble::operator/(const IOperand &rhs) const
{
  IOperand              *res;
  Memory::Mem           mem;
  std::istringstream    iss(rhs.toString());
  double                tmp;

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

IOperand                *OperandDouble::operator%(const IOperand &) const
{
  throw Error(DOMMODF);
}

}
