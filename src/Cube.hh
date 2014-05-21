/*
** Cube.hh for cube in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
** Last update Wed May 21 13:51:58 2014 teddy fontaine
*/

#ifndef CUBE_HH_
# define CUBE_HH_

#include "AObject.hh"

class Cube : public AObject
{
  private:

    gdl::Texture	_texture;
    gdl::Geometry	_geometry;
    float		_speed;

  public:
    Cube();
    virtual ~Cube();
    virtual bool	initialize(int x, int y, int z);
    virtual void	update(gdl::Clock const &clock, gdl::Input &input);
    virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !CUBE_HH_ */
