//
// AObject.hpp for  in /home/jason/Tech2/ProgC++/bomberman-2015-savine_s
//
// Made by Jason Leo
// Login   <jason@epitech.net>
//
// Started on  Sat May 19 16:51:24 2012 Jason Leo
// Last update Mon May 21 19:41:14 2012 Jason Leo
//

#ifndef		__AOBJECT_HPP__
# define	__AOBJECT_HPP__

# include	<deque>
# include	"Bomberman.hpp"
# include	"Vector3f.hpp"
# include	"GameClock.hpp"
# include	"Input.hpp"

class		AObject
{
protected :
  Vector3f	position_;
  Vector3f	rotation_;
  e_type	type_;

public :
  AObject(float x, float z, e_type type)
    : position_(x, 0.0f, z), rotation_(0.0f, 0.0f, 0.0f), type_(type)
  {
  }
  virtual void	initialize(void) = 0;
  virtual void	update(gdl::GameClock const &, gdl::Input &, std::deque<AObject*> &) = 0;
  virtual void	draw(void) = 0;
  e_type	getType(void)const {
    return (this->type_);
  }
  Vector3f      getPosition(void)const {
    return (this->position_);
  }
  Vector3f      getRotation(void)const {
    return (this->rotation_);
  }
  void          setPosition(Vector3f pos) {
    position_.x = pos.x;
    position_.y = pos.y;
    position_.z = pos.z;
  }
  void          setRotation(Vector3f rot) {
    rotation_.x = rot.x;
    rotation_.y = rot.y;
    rotation_.z = rot.z;
  }
};

#endif		/*!__AOBJECT_HPP__*/

