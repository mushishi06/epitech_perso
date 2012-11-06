//
// Monster.hpp for  in /home/leo_j//Tech2/ProgC++/gitolite@89.92.92.67:bomberman.git
//
// Made by jason leo
// Login   <leo_j@epitech.net>
//
// Started on  Sun Jun  3 10:53:13 2012 jason leo
// Last update Sun Jun  3 20:19:01 2012 jason leo
//

#ifndef		__MONSTER_HPP__
# define	__MONSTER_HPP__

# include	"GL/gl.h"
# include	"GL/glu.h"
# include	"Model.hpp"
# include	"AObject.hpp"

class		Monster : public AObject
{
protected:

  gdl::Model	model_;
  float		speed_;
  int		isWalk;
  void (Monster::*reverse_mov)(std::deque<AObject*> &, int);

public:
  Monster(float, float, e_type);
  ~Monster(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &);
  void	       	draw(void);
  bool		found_player(Vector3f const &, std::deque<AObject*> &map);
  bool		safe(int x, int y, std::deque<AObject*> &map, int*);
  void		go_safe_place(std::deque<AObject*> &map);
  void		right_left(float, std::deque<AObject*> &map);
  void		go_left(std::deque<AObject*> &map, int);
  void		go_right(std::deque<AObject*> &mapn, int);
  void		up_down(float, std::deque<AObject*> &map);
  void		go_up(std::deque<AObject*> &map, int);
  void		go_down(std::deque<AObject*> &map, int);
};
#endif		/*!__MONSTER_HPP__*/
