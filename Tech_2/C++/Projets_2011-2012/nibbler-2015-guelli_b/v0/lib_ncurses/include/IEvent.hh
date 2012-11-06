//
// IEvent.hh for  in /home/moreno_i//afs/renduLocal/projets/nibbler
//
// Made by igor morenosemedo
// Login   <moreno_i@epitech.net>
//
// Started on  Tue Mar 13 19:36:00 2012 igor morenosemedo
// Last update Sat Mar 17 02:14:53 2012 igor morenosemedo
//

#ifndef _IEVENT_HH_
# define _IEVENT_HH_

class IEvent
{
public:
  virtual	~IEvent() {};

public:
  virtual	void KeyRight() = 0;
  virtual	void KeyLeft() = 0;
  virtual	void KeyEschap() = 0;
  virtual	void ChooseEvent() = 0;
};

#endif
