//
// Comm.hh for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Mon Feb  6 12:45:07 2012 Emelyne
// Last update Sat Feb 11 16:48:06 2012 Emelyne
//

#ifndef			COMM_HH
#define			COMM_HH

#include		<string>
#include		<map>
#include		<vector>
#include		"Chipset.hh"
#include		"Memory.hh"

namespace		CPU
{

class			Comm
{
  typedef bool		(Comm::*funcPtr)(Chipset::IOperand *,
					 std::vector<Chipset::IOperand*>&);

  Chipset::Line		line_;
  std::map<Chipset::eOperandType, std::string>		Types_;
  std::map<std::string, Comm::funcPtr>			ListComm_;

public:
  Comm();
  Comm(const Comm &comm);
  Comm			&operator=(const Comm &comm);
  ~Comm();

  void			initMaps(void);
  bool			execLine(Memory::Mem &memory);
  void			setLine(const Chipset::Line &line);
  Chipset::Line		getLine(void) const;

  bool			push_(Chipset::IOperand *,
			      std::vector<Chipset::IOperand*> &);
  bool			pop_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			dump_(Chipset::IOperand *,
			      std::vector<Chipset::IOperand*> &);
  bool			assert_(Chipset::IOperand *,
				std::vector<Chipset::IOperand*> &);
  bool			add_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			sub_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			mul_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			div_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			mod_(Chipset::IOperand *,
			     std::vector<Chipset::IOperand*> &);
  bool			print_(Chipset::IOperand *,
			       std::vector<Chipset::IOperand*> &);
  bool			exit_(Chipset::IOperand *,
			      std::vector<Chipset::IOperand*> &);
};

}

#endif			/* COMM_HH */
