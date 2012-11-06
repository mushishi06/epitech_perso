//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Thu Feb  9 17:24:13 2012 Emelyne
//

#ifndef			OPERANDINT16_HH
#define			OPERANDINT16_HH

#include		"AOperand.hh"

namespace		Chipset
{

class			OperandInt16	:	public AOperand
{
  short			nb_;

public:
  OperandInt16(std::string const &str = "");
  virtual		~OperandInt16();

  short			getNb() const;
  void			setNb(const short &nb);

  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;
};

}

#endif			/* OPERANDINT16_HH */
