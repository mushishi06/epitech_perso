//
// Operand.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 10:14:00 2012 Emelyne
// Last update Wed Feb  8 10:16:51 2012 Emelyne
//

#ifndef			OPERAND_HH
#define			OPERAND_HH

#include		<iostream>
#include		"Error.hh"
#include		"IOperand.hh"

template<typename T>
class			Operand	:	public	IOperand
{
  std::string		str_;
  T			nb_;
  int			prec_;
  eOperandType		type_;

public:
  virtual std::string const 	&toString() const;
  T				getNb() const;

  virtual int		getPrecision() const;
  virtual eOperandType	getType() const;
  void			setNb(const T &nb);
  void			setPrecision(int);
  void			setType(eOperandType);

  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;

  Operand(std::string const &str = "");
  Operand(const Operand<T> &);
  virtual		~Operand();
};

#endif			/* OPERAND_HH */
