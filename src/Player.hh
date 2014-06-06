/*
** mod.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
** Last update Fri Jun  6 05:15:09 2014 teddy fontaine
*/

#include <Model.hh>
#include "AObject.hh"
#include "Joystick.hh"

#ifndef PLAYER_HH_
# define PLAYER_HH_

class Player : public AObject
{
  public:
    Player(int, std::string);
    ~Player();
    bool	initialize(float, float, float);
    void	update(gdl::Clock const &, gdl::Input &);
    void	draw(gdl::AShader &, gdl::Clock const &);

    std::vector<int>		getObjs();
    void			setObjs(std::vector<int>);

/*    int		getType();
    int		getTop();
    int		getBot();
    int		getRight();
    int		getLeft();
    int		getBombe();
    int		getPause();

    void	setTop();
    void	setBot();
    void	setRight();
    void	setLeft();
    void	setBombe();
    void	setPause();*/

  private:
    std::vector<int>	_objs;
    int			_type;
    float		_x;
    float		_y;
    float		_z;
    float		_angle;
    int			_idJoy;
    std::string		_anim;
    std::string		_modelPath;
    std::string		_textureMod;
    float		_speed;
    gdl::Model		_model;
    Joystick		_joystick;
    glm::mat4		_trans;
    void		updateVector(int);
    void		rezVector();
};

#endif /* !PLAYER_HH_ */
