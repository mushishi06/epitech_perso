//
// abstactVM.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 12:05:06 2012 Emelyne
// Last update Wed Feb 15 17:59:41 2012 belia-_r
//

#ifndef			CHIPSET_HH
#define			CHIPSET_HH

#include		<iostream>
#include		<vector>
#include		<string>
#include		"Error.hh"
#include		"OperandInt8.hh"
#include		"OperandInt16.hh"
#include		"OperandInt32.hh"
#include		"OperandFloat.hh"
#include		"OperandDouble.hh"

namespace		Chipset
{
  class			Line
  {
    std::string		line_;
    std::string		instr_;
    std::string		operand_;
    std::string		value_;
    std::vector<std::string>	instrs_;

  public:
    Line(std::string line = "");
    Line(const Line &line);
    Line		&operator=(const Line &line);
    ~Line();

    std::string		getLine() const;
    std::string		&getInstr();
    std::string		getOperand() const;
    std::string		getValue() const;

    void		cleanComm();
    void		cleanLine();
    void		setInstr(std::string &instr);
    void		checkInstr();
    void		checkArgs();
    void		setOperand(std::string &tmp);
    void		setValue(std::string &tmp);
  };

  int			checkEnd(const std::string file);
  void			parsFile(std::string &file, int nb, bool verbose);
  void			parsLine(Line &oneLine);
}

#endif		/* CHIPSET_HH */
