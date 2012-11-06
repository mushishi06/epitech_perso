//
// parsFile.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Fri Feb  3 14:18:06 2012 Emelyne
// Last update Wed Feb 15 17:54:18 2012 belia-_r
//

#include		<vector>
#include		"IO.hh"
#include		"Comm.hh"
#include		"Chipset.hh"
#include		"Memory.hh"

int			Chipset::checkEnd(const std::string file)
{
  size_t		pos;

  pos = file.find("exit");
  if (pos == std::string::npos)
    return (1);
  return (0);
}

void			Chipset::parsLine(Line &oneLine)
{
  std::string		tmp;

  oneLine.cleanComm();
  oneLine.cleanLine();
  if (oneLine.getLine().size() != 0)
    {
      oneLine.setInstr(oneLine.getInstr());
      oneLine.cleanLine();
      oneLine.setInstr(tmp);
      oneLine.cleanLine();
      oneLine.setOperand(tmp);
      oneLine.setValue(tmp);
      oneLine.checkInstr();
      if ((oneLine.getLine().size() != 0) ||
	  ((oneLine.getOperand().size() != 0) &&
	   (oneLine.getValue().size() == 0)))
	throw Error(SYNTAX);
    }
}

void			Chipset::parsFile(std::string &file, int nb, bool verbose)
{
  bool			flagEx;
  CPU::Comm		exec;
  Line			oneLine;
  size_t		pos;
  Memory::Mem		mem;

  while (file.size() > 0)
    {
      pos = file.find("\n");
      if (pos != std::string::npos)
	{
	  oneLine = file.substr(0, pos);
	  file.erase(0, pos + 1);
	}
      parsLine(oneLine);
      if (oneLine.getInstr().size() != 0)
	{
	  if (verbose)
	    std::cout << "instr = " << oneLine.getInstr() << "\t"
		      << "operand = " << oneLine.getOperand() << "\t"
		      << "value = " << oneLine.getValue() << std::endl;
	  exec.setLine(oneLine);
	  flagEx = exec.execLine(mem);
	  if (flagEx == false)
	    break;
	}
    }
  if (nb == 1)
    throw Error(EXIT);
}
