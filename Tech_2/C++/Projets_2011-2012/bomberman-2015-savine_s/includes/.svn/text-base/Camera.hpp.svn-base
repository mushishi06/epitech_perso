//
// Camera.hpp for bomberman in /home/ss814/Documents/Epitech/git/bomberman
//
// Made by Sampson SAVINEL
// Login   <ss814@epitech.net>
//
// Started on  Fri May 11 18:32:32 2012 Sampson SAVINEL
// Last update Mon May 21 17:45:24 2012 Jason Leo
//

#ifndef		__CAMERA_HPP__
# define	__CAMERA_HPP__

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	"Input.hpp"
# include	"GameClock.hpp"
# include	"Vector3f.hpp"

class		Camera
{
 public :
  Camera(void);
  ~Camera(void);

  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
  Vector3f	getPosition(void)const;
  Vector3f	getRotation(void)const;
  void		setPosition(Vector3f);
  void		setRotation(Vector3f);

 private :
  Vector3f	position_;
  Vector3f	rotation_;
};

#endif		/*!__CAMERA_HPP__*/

