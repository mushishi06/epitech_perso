//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Fri Feb 10 10:04:41 2012 Emelyne
//

#ifndef			OPERANDINT8_HH
#define			OPERANDINT8_HH

#include		"AOperand.hh"

namespace		Chipset
{

  class			OperandInt8	:	public AOperand
  {
    char			nb_;

  public:
    OperandInt8(std::string const &str = "");
    ~OperandInt8();

    char			getNb() const;
    void			setNb(const char &nb);

    IOperand	*operator+(const IOperand &rhs) const;
    IOperand	*operator-(const IOperand &rhs) const;
    IOperand	*operator*(const IOperand &rhs) const;
    IOperand	*operator/(const IOperand &rhs) const;
    IOperand	*operator%(const IOperand &rhs) const;
  };

}

#endif			/* OPERANDINT8_HH */
