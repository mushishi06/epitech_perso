// master class of player and mosters

#ifndef _CHARACTERS_HH_
# define _CHARACTERS_HH_

#include	"Generic_object.hpp"

class	A_Character : virtual public G_obj
{
 protected:

  int		nb_lives;
  int		speed;
  bool		live_;

public:

  A_Character();
  virtual ~A_Character();

  bool		alive();
  void		move();
};

#endif /*!_CHARACTERS_HH_*/
