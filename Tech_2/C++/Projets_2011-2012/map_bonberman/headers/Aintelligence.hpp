//
// Aintelligence.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s/includes
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Mon May 21 13:53:39 2012 Jason Leo
// Last update Tue May 22 17:59:24 2012 guillaume francois
//

#ifndef		__AINTELLIGENCE_HPP__
# define	__AINTELLIGENCE_HPP__

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Player.hpp"
# include	"Model.hpp"

class		Aintelligence : public Player
{
public:
  Aintelligence(float, float, e_type);
  ~Aintelligence(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void		draw(void);

  void		found_player(Vector3f const &);
  void		right_left(float);
  void		up_down(float);
};

#endif		/*!_AINTELLIGENCE_HH_*/
