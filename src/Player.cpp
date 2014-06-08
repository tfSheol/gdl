/*
** Player.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Sun Jun  8 10:28:33 2014 teddy fontaine
*/

#include "Player.hh"

Player::Player(int idJoy, std::string path)
{
  _modelPath = "./assets/marvin.fbx";
  _textureMod = path;
  _idJoy = idJoy;
}

Player::~Player()
{
  _objs.clear();
}

bool	Player::initialize(__attribute__((unused)) float x,
			   __attribute__((unused)) float y,
			   __attribute__((unused)) float z)
{
  _speed = 5.0f;
  _angle = 0.0f;
  _frame = 0;
  _anim = false;
  _x = x;
  _y = y;
  _z = z;
  _type = 5;
  _objs.push_back(_type);
  _objs.push_back(_idJoy);
  _objs.push_back(_joystick.joystickCheck());
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _objs.push_back((int)false);
  _model.load(_modelPath);
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(_x, _y, _z)),
				  _angle,
				  glm::vec3(0, 1, 0)),
		      glm::vec3(0.001f, 0.001f, 0.001f));

  _model.createSubAnim(0, "RESET", 0, 0);
  _model.createSubAnim(0, "START", 0, 36);
  _model.createSubAnim(0, "RUN", 36, 53);
  _model.createSubAnim(0, "END", 53, 121);

//  _model.setCurrentSubAnim("START");

  return (true);
}

void	Player::update(__attribute__((unused)) gdl::Clock const &clock,
		       __attribute__((unused)) gdl::Input &input)
{
  float	z;
  float	x;
  int	a;
  int	pause;

  _anim = false;
  if ((_idJoy < _joystick.joystickCheck()) || (_idJoy == 0))
  {
    rezObjs();
    if (_joystick.joystickForGame(_idJoy) > 0)
    {
      SDL_JoystickUpdate();
      x = SDL_JoystickGetAxis(_joystick.getJoy(), 0);
      z = SDL_JoystickGetAxis(_joystick.getJoy(), 1);
      a = SDL_JoystickGetButton(_joystick.getJoy(), 0);
      pause = SDL_JoystickGetButton(_joystick.getJoy(), 7);
    }
    if ((input.getKey(SDLK_UP) && _idJoy == 0) || z < -10000)
    {
      _anim = true;
      _z -= clock.getElapsed() * _speed;
      _angle = 180.0f;
      setObjs(3);
    }
    if ((input.getKey(SDLK_DOWN) && _idJoy == 0) || z > 10000)
    {
      _anim = true;
      _z += clock.getElapsed() * _speed;
      _angle = 0.0f;
      setObjs(4);
    }
    if ((input.getKey(SDLK_LEFT) && _idJoy == 0) || x < -10000)
    {
      _anim = true;
      _x -= clock.getElapsed() * _speed;
      _angle = 270.0f;
      setObjs(5);
    }
    if ((input.getKey(SDLK_RIGHT) && _idJoy == 0) || x > 10000)
    {
      _anim = true;
      _x += clock.getElapsed() * _speed;
      _angle = 90.0f;
      setObjs(6);
    }
    if ((input.getKey(SDLK_SPACE) && _idJoy == 0) || a > 0)
      setObjs(7);
    if (input.getKey(SDLK_m) || pause > 0)
      setObjs(8);
    _trans = glm::scale(glm::rotate(glm::translate(
				      glm::mat4(1),
				      glm::vec3(_x, _y, _z)),
				    _angle,
				    glm::vec3(0, 1, 0)),
			glm::vec3(0.001f, 0.001f, 0.001f));
    if (_anim == true)
    {
      if (_frame == 1)
	_model.setCurrentSubAnim("RUN");
    }
    if (_anim == false)
    {
      _model.setCurrentSubAnim("RESET");
      _frame = 0;
    }
    if (_anim == true)
      _frame += 1;
    std::cout << "<<>>" << std::endl;
    std::cout << _frame << std::endl;
    std::cout << _anim << std::endl;
    std::cout << "<<>>" << std::endl;
  }
}

void	Player::draw(__attribute__((unused)) gdl::AShader &shader,
		     __attribute__((unused)) gdl::Clock const &clock)
{
  if ((_idJoy < _joystick.joystickCheck()) || (_idJoy == 0))
    _model.draw(shader, _trans, clock.getElapsed());
}

std::vector<int>	Player::getObjs()
{
  return (_objs);
}

void			Player::setObjs(int type)
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    if (type == (int)i)
      _objs[i] = !(_objs[i]);
  }
}

void			Player::rezObjs()
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    if (i == 2)
      _objs[i] = _joystick.joystickCheck();
    else if (i != 0 && i != 1)
      _objs[i] = (int)false;
  }
}
