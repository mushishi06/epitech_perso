//
// Operand.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 21:49:44 2012 Emelyne
// Last update Wed Feb 15 15:02:41 2012 Emelyne
//

#include	<sstream>
#include	"OperandInt8.hh"
#include	"OperandInt16.hh"
#include	"OperandInt32.hh"
#include	"OperandFloat.hh"
#include	"OperandDouble.hh"
#include	"AOperand.hh"

namespace	Chipset
{

AOperand::AOperand(std::string const &str)
  : str_(str)
{
}

AOperand::~AOperand()
{
}

std::string const		&AOperand::toString() const
{
  return (this->str_);
}

int				AOperand::getPrecision() const
{
  return (this->prec_);
}

eOperandType			AOperand::getType() const
{
  return (this->type_);
}

void				AOperand::setPrecision(int pre)
{
  this->prec_ = pre;
}

void				AOperand::setType(eOperandType pre)
{
  this->type_ = pre;
}

void				AOperand::setString(const std::string &str)
{
  this->str_.assign(str);
}

void				AOperand::dynamicCast(IOperand *rhs, double nb)
{
  OperandInt8 *int8 = dynamic_cast<OperandInt8*>(rhs);
  if (int8 == 0)
    {
      OperandInt16 *int16 = dynamic_cast<OperandInt16*>(rhs);
      if (int16 == 0)
	{
	  OperandInt32 *int32 = dynamic_cast<OperandInt32*>(rhs);
	  if (int32 == 0)
	    {
	      OperandFloat *floatnb = dynamic_cast<OperandFloat*>(rhs);
	      if (floatnb == 0)
		dynamic_cast<OperandDouble*>(rhs)->setNb(nb);
	      else
		dynamic_cast<OperandFloat*>(rhs)->setNb(nb);
	    }
	  else
	    dynamic_cast<OperandInt32*>(rhs)->setNb(nb);
	}
      else
	dynamic_cast<OperandInt16*>(rhs)->setNb(nb);
    }
  else
  dynamic_cast<OperandInt8*>(rhs)->setNb(nb);
}


}
