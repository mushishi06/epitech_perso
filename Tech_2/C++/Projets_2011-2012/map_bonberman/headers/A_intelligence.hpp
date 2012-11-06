//
// A_intelligence.hh for BOMBERMAN in /home/franco_g/School/Tek2/Git_repo/gitolite@89.92.92.67:bomberman.git
//
// Made by guillaume francois
// Login   <franco_g@epitech.net>
//
// Started on  Mon May 14 11:15:08 2012 guillaume francois
// Last update Wed May 16 16:03:30 2012 guillaume francois
//

#ifndef _A_INTELLIGENCE_HH_
# define _A_INTELLIGENCE_HH_

#include	"Characters.hpp"

typedef enum
  {
    Oiseau = 1,
    Robot,
    Champignon
  } AI_type;

class	A_Intelligence : virtual public A_Character
{
private:

  AI_type	my_type;

public:

  A_Intelligence();
  virtual ~A_Intelligence();

  bool			attack();
  bool			spec_attack(); // defini selon my_type
  void			type(AI_type); // set le type
  AI_type		type(void); // renvoie le type de l'AI
};
#endif /*!_A_INTELLIGENCE_HH_*/
