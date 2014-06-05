/*
** Bonus.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
** Last update Thu Jun  5 14:32:05 2014 teddy fontaine
*/

#include <Model.hh>
#include "AObject.hh"

#ifndef BONUS_HH_
# define BONUS_HH_

class Bonus : public AObject
{
  public:
    Bonus(std::string);
    ~Bonus();
    bool	initialize(float, float, float);
    void	update(gdl::Clock const &, gdl::Input &);
    void	draw(gdl::AShader &, gdl::Clock const &);

  private:
    float	_x;
    float	_y;
    float	_z;
    float	_rX;
    float	_rY;
    float	_rZ;
    std::string	_modelPath;
    float	_speed;
    gdl::Model	*_model;
    glm::mat4	_trans;
};

#endif /* !BONUS_HH_ */
