#ifndef _ITEM_HH_
# define _ITEM_HH_

#include	"Generic_object.hpp"

typedef enum
  {
    NONE = 1,
    ADD_BOMB,
    SPEED_HACK,
    MORE_BOMB
  } Bonus_type;

class	Item : virtual public G_obj
{
public:
  Item();
  virtual ~Item();
};

class	Bonus_item : virtual public Item
{
public:
  Bonus_item();
  virtual ~Item();
};

class	Bomb : virtual public Item
{
protected:

  time_t	before_expl;

public:
  Bomb();
  virtual ~Bomb();

  time_t	explosition();
};

#endif /*!_ITEM_HH_*/
