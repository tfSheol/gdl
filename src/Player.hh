/*
** mod.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
** Last update Wed Jun  4 16:54:22 2014 teddy fontaine
*/

#include <Model.hh>
#include "AObject.hh"

#ifndef PLAYER_HH_
# define PLAYER_HH_

class Player : public AObject
{
  public:
    Player(std::string);
    ~Player();
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
    std::string	_anim;
    std::string	_modelPath;
    std::string	_textureMod;
    float	_speed;
    gdl::Model	*_model;
    glm::mat4	_trans;
};

#endif /* !PLAYER_HH_ */
