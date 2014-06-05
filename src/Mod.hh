/*
** mod.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
** Last update Thu Jun  5 16:09:37 2014 teddy fontaine
*/

#include <Model.hh>
#include "AObject.hh"

#ifndef MOD_HH_
# define MOD_HH_

class Mod : public AObject
{
  public:
    Mod(std::string);
    ~Mod();
    bool	initialize(float, float, float);
    void	update(gdl::Clock const &, gdl::Input &);
    void	draw(gdl::AShader &, gdl::Clock const &);

  private:
    float	_x;
    float	_y;
    float	_z;
    float	_angle;
    std::string	_modelPath;
    float	_speed;
    gdl::Model	_model;
    glm::mat4	_trans;
};

#endif /* !MOD_HH_ */
