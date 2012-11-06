//
// cleanLine.cpp for  in /home/emelyne/rendu/abstractVM
//
// Made by Emelyne
// Login   <emelyne@epitech.net>
//
// Started on  Sun Feb  5 09:29:17 2012 Emelyne
// Last update Thu Feb  9 19:30:41 2012 Emelyne
//

#include	"Chipset.hh"

namespace	Chipset
{

Line::Line(std::string line)
  : line_(line)
{
  operand_.assign("");
  value_.assign("");
  instrs_.push_back("push");
  instrs_.push_back("pop");
  instrs_.push_back("dump");
  instrs_.push_back("assert");
  instrs_.push_back("add");
  instrs_.push_back("sub");
  instrs_.push_back("mul");
  instrs_.push_back("div");
  instrs_.push_back("mod");
  instrs_.push_back("print");
  instrs_.push_back("exit");
}

Line::Line(const Line &line)
  : line_(line.line_), instr_(line.instr_), operand_(line.operand_),
    value_(line.value_)
{
  instrs_.push_back("push");
  instrs_.push_back("pop");
  instrs_.push_back("dump");
  instrs_.push_back("assert");
  instrs_.push_back("add");
  instrs_.push_back("sub");
  instrs_.push_back("mul");
  instrs_.push_back("div");
  instrs_.push_back("mod");
  instrs_.push_back("print");
  instrs_.push_back("exit");
}

Line		&Line::operator=(const Line &line)
{
  line_.assign(line.line_);
  instr_.assign(line.instr_);
  operand_.assign(line.operand_);
  value_.assign(line.value_);
  return (*this);
}

Line::~Line()
{
}

std::string	Line::getLine(void) const
{
  return (line_);
}

std::string 	&Line::getInstr(void)
{
  return (instr_);
}

std::string	Line::getOperand(void) const
{
  return (operand_);
}

std::string	Line::getValue(void) const
{
  return (value_);
}

void		Line::cleanComm(void)
{
  size_t	pos;

  pos = line_.find(";");
  if (pos != std::string::npos)
    line_.erase(pos, line_.size());
}

void		Line::cleanLine(void)
{
  unsigned int	it;

  for (it = 0; ((it < line_.size()) &&
		((line_[it] == ' ') || (line_[it] == '\t'))); it += 1);
  line_.erase(0, it);
}

void		Line::setInstr(std::string &instr)
{
  unsigned int	it;

  for (it = 0; ((it < line_.size()) && (line_[it] != ' ')
		&& (line_[it] != '\t')); it += 1);
  instr = line_.substr(0, it);
  line_.erase(0, it);
}

void		Line::checkArgs()
{
  unsigned int	args;

  args = 0;
  if ((instr_.compare("assert") == 0) || (instr_.compare("push") == 0))
    args = 1;
  if ((args == 1) &&
      ((operand_.size() == 0) || (value_.size() == 0)))
    throw Error(INVARG);
  if ((args == 0) &&
      ((operand_.size() != 0) || (value_.size() != 0)))
    throw Error(INVARG);
}

void		Line::checkInstr(void)
{
  bool					is_flag;
  std::vector<std::string>::iterator	it;

  is_flag = false;
  for (it = instrs_.begin(); it != instrs_.end(); it += 1)
    {
      if (instr_.compare(*it) == 0)
	{
	  checkArgs();
	  is_flag = true;
	}
    }
  if (is_flag == false)
    throw Error(UNKNOWN);
}

void		Line::setOperand(std::string &tmp)
{
  unsigned int	it;

  for (it = 0; ((it < tmp.size()) && (tmp[it] != '(')); it += 1);
  operand_ = tmp.substr(0, it);
  tmp.erase(0, it + 1);
}

void		Line::setValue(std::string &tmp)
{
  unsigned int	it;

  if ((tmp.size() != 0) && tmp.find(")") == std::string::npos)
    throw Error(SYNTAX);
  for (it = 0; ((it < tmp.size()) && (tmp[it] != ')')); it += 1);
  value_ = tmp.substr(0, it);
  tmp.erase(0, it + 1);
}

}
