//
// Generic_object.cpp for  in /home/santar_c//Desktop/tech2/projet_en_cour/bomberman_git/gitolite@89.92.92.67:bomberman.git/claas_file
//
// Made by cedric santarelli
// Login   <santar_c@epitech.net>
//
// Started on  Wed May 16 17:08:42 2012 cedric santarelli
// Last update Sat May 19 14:45:28 2012 laurent ha-tam-dan
//

#include "Generic_object.hpp"

G_obj::G_obj() : type(PLAYER), ID_(0), x_(0), y_(0), z_(0), graph_path("")
{
}

G_obj::G_obj(Obj_type m_type, int r_id, int r_x, int r_y, int r_z, std::string model_path)
  : type(m_type), ID_(r_id), x_(r_x), y_(r_y), z_(r_z), graph_path(model_path)
{
}

G_obj::~G_obj()
{

}

const std::string &   G_obj::serialise()
{

}

void    G_obj::up()
{
}

void    G_obj::down()
{
}

void    G_obj::left()
{
}

void    G_obj::right()
{
}

int G_obj::getX() const
{
  return (x_);
}

int G_obj::getY() const
{
  return (y_);
}

int G_obj::getZ() const
{
  return (z_);
}

Obj_type G_obj::getType() const
{
  return (type);
}

std::string	G_obj::getGraph_path() const
{
  return (graph_path);
}

int	G_obj::getID() const
{
  return (ID_);
}

void	G_obj::setX(int	x)
{
  this->x_ = x;
}

void	G_obj::setY(int y)
{
  this->y_ = y;
}

void	G_obj::setZ(int z)
{
  this->z_ = z;
}

void	G_obj::setType(Obj_type type)
{
  this->type = type;
}

void	G_obj::setGraph_path(std::string &path)
{
  this->graph_path = path;
}

void	G_obj::setID(int id)
{
  this->ID_ = id;
}
