/*
** mod.hh for mod in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:37:28 2014 teddy fontaine
** Last update Wed Jun 11 16:05:22 2014 teddy fontaine
*/

#include <Model.hh>
#include "AObject.hh"
#include "Joystick.hh"

#ifndef PLAYER_HH_
# define PLAYER_HH_

class Player : public AObject
{
  public:
    Player(int, int);
    ~Player();
    bool			initialize(float, float, float);
    void			update(gdl::Clock const &, gdl::Input &);
    void			draw(gdl::AShader &, gdl::Clock const &);

    std::vector<int>		getObjs() const;
    void			setObjs(int);

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
    float		_angle;
    int			_idJoy;
    int			_frame;
    bool		_anim;
    std::string		_modelPath;
    float		_speed;
    gdl::Model		_model;
    Joystick		_joystick;
    glm::mat4		_trans;
    void		updateObjs(int);
    void		rezObjs();
};

#endif /* !PLAYER_HH_ */
