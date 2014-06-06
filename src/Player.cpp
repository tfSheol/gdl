/*
** Player.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Fri Jun  6 05:18:15 2014 teddy fontaine
*/

#include "Player.hh"

/*

//////////////  POUR MENU  deplacement souris plus manette ///////////////////


  glm::ivec2                    pos;
  glm::ivec2                    temp_pos;
  glm::ivec2                    comp_pos;


  if (this->Joy.Joystick_check() > 0 &&
      this->Joy.Joystick_for_menu(this->pos) > 0)
    this->pos = this->Joy.Joystick_new_pos();
  this->comp_pos = input.getMousePosition();
  if (this->temp_pos[0] != this->comp_pos[0] &&
      this->temp_pos[1] != this->comp_pos[1])
    {
      this->pos = input.getMousePosition();
      this->temp_pos = input.getMousePosition();
    }

*/


/*
//////////////  POUR JEU  deplacement clavier plus manette ///////////////////

  Sint16        x_move = 0;
  Sint16        y_move = 0;
  unsigned int  bombe = 0;
  unsigned int  pause = 0;
  signed short  hat = 0;

  Sint16        x_move_p2 = 0;
  Sint16        y_move_p2 = 0;
  unsigned int  bombe_p2 = 0;
  unsigned int  pause_p2 = 0;
  signed short  hat_p2 = 0;


  if (this->Joy.Joystick_for_game() > 0)
    {
      SDL_JoystickUpdate();
      bombe = SDL_JoystickGetButton(this->Joy.getJoy1(), 0);
      pause = SDL_JoystickGetButton(this->Joy.getJoy1(), 7);
      hat = SDL_JoystickGetHat(this->Joy.getJoy1(), 0);
      x_move = SDL_JoystickGetAxis(this->Joy.getJoy1(),0);
      y_move = SDL_JoystickGetAxis(this->Joy.getJoy1(),1);
      if (this->Joy.Joystick_for_game() > 1)
        {
          bombe_p2 = SDL_JoystickGetButton(this->Joy.getJoy2(), 0);
          pause_p2 = SDL_JoystickGetButton(this->Joy.getJoy2(), 7);
          hat_p2 = SDL_JoystickGetHat(this->Joy.getJoy2(), 0);
          x_move_p2 = SDL_JoystickGetAxis(this->Joy.getJoy2(),0);
          y_move_p2 = SDL_JoystickGetAxis(this->Joy.getJoy2(),1);
        }
    }

  if (input.getKey(SDLK_ESCAPE) || pause != 0 || pause_p2 != 0)
    optionInGame = true;
  if (player2 == false)
    {
      if (input.getKey(SDLK_UP) || y_move > 10000 || hat == 4)
        top = true;
      if (input.getKey(SDLK_DOWN) || y_move < -10000 || hat == 1)
        bot = true;
      if (input.getKey(SDLK_RIGHT) || x_move < -10000 || hat == 8)
        right = true;
      if (input.getKey(SDLK_LEFT) || x_move > 10000 || hat == 2)
        left = true;
      if (input.getKey(SDLK_SPACE) || bombe != 0)
        bombe1 = true;
    }
  else
    {
      if (input.getKey(SDLK_z) || y_move > 10000 || hat == 4)
        top = true;
      if (input.getKey(SDLK_s) || y_move < -10000 || hat == 1)
        bot = true;
      if (input.getKey(SDLK_d) || x_move < -10000 || hat == 8)
        right = true;
      if (input.getKey(SDLK_q) || x_move > 10000 || hat == 2)
        left = true;
      if (input.getKey(SDLK_LSHIFT) || bombe != 0)
        bombe1 = true;
      if (input.getKey(SDLK_o) || input.getKey(SDLK_KP_8) || y_move_p2 > 10000 || hat_p2 == 4)
        top2 = true;
      if (input.getKey(SDLK_l) || input.getKey(SDLK_KP_5) || y_move_p2 < -10000 || hat_p2 == 1)
        bot2 = true;
      if (input.getKey(SDLK_m) || input.getKey(SDLK_KP_6) || x_move_p2 < -10000 || hat_p2 == 8)
        right2 = true;
      if (input.getKey(SDLK_k) || input.getKey(SDLK_KP_4) || x_move_p2 > 10000 || hat_p2 == 2)
        left2 = true;
      if (input.getKey(SDLK_RSHIFT) || input.getKey(SDLK_KP_ENTER) || bombe_p2 != 0)
        bombe2 = true;
    }
 */



Player::Player(int idJoy, std::string path)
{
  _modelPath = "./assets/marvin.fbx";
  _textureMod = path;
  _idJoy = idJoy;
}

Player::~Player()
{
}

bool	Player::initialize(__attribute__((unused)) float x,
			   __attribute__((unused)) float y,
			   __attribute__((unused)) float z)
{
  _speed = 5.0f;
  _angle = 0.0f;
  _x = x;
  _y = y;
  _z = z;
  _type = 5;
  _objs.push_back(_type);
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
  _model.createSubAnim(0, "END", 53, 120);

  _model.setCurrentSubAnim("START");

  return (true);
}

void	Player::update(__attribute__((unused)) gdl::Clock const &clock,
		       __attribute__((unused)) gdl::Input &input)
{
  float	z;
  float	x;
  int	a;
  int	pause;

  rezVector();
  if (_joystick.joystickForGame(_idJoy) > 0)
  {
    SDL_JoystickUpdate();
    x = SDL_JoystickGetAxis(_joystick.getJoy(), 0);
    z = SDL_JoystickGetAxis(_joystick.getJoy(), 1);
    a = SDL_JoystickGetButton(_joystick.getJoy(), 0);
    pause = SDL_JoystickGetButton(_joystick.getJoy(), 7);
  }
  if (input.getKey(SDLK_UP) || z < -10000)
  {
    _anim = "START";
    _z -= clock.getElapsed() * _speed;
    _angle = 180.0f;
    updateVector(1);
  }
  if (input.getKey(SDLK_DOWN) || z > 10000)
  {
    _anim = "RUN";
    _z += clock.getElapsed() * _speed;
    _angle = 0.0f;
    updateVector(2);
  }
  if (input.getKey(SDLK_LEFT) || x < -10000)
  {
    _anim = "RUN";
    _x -= clock.getElapsed() * _speed;
    _angle = 270.0f;
    updateVector(3);
  }
  if (input.getKey(SDLK_RIGHT) || x > 10000)
  {
    _anim = "RUN";
    _x += clock.getElapsed() * _speed;
    _angle = 90.0f;
    updateVector(4);
  }
  if (input.getKey(SDLK_SPACE) || a < 0)
    updateVector(5);
  if (input.getKey(SDLK_m) || pause < 0)
    updateVector(6);
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(_x, _y, _z)),
				  _angle,
				  glm::vec3(0, 1, 0)),
		      glm::vec3(0.001f, 0.001f, 0.001f));
  if (_model.getAnimationFrameNumber(0) == 121)
    _model.setCurrentSubAnim(_anim, true);
//  std::cout << _model.getAnimationFrameNumber(0) << std::endl;
}

void	Player::draw(__attribute__((unused)) gdl::AShader &shader,
		     __attribute__((unused)) gdl::Clock const &clock)
{
  _model.draw(shader, _trans, clock.getElapsed());
}

std::vector<int>	Player::getObjs()
{
  return (_objs);
}

void			Player::setObjs(__attribute__((unused)) std::vector<int> objs)
{

}

void			Player::updateVector(int type)
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    if (type == (int)i)
      _objs[i] = !(_objs[i]);
  }
}

void			Player::rezVector()
{
  size_t		i;

  i = -1;
  while (++i < _objs.size())
  {
    _objs[i] = (int)false;
  }
}

/*int	Player::getType()
{
  return (_type);
}

int	Player::getTop()
{
  return (_top);
}

int	Player::getBot()
{
  return (_bot);
}

int	Player::getRight()
{
  return (_right);
}

int	Player::getLeft()
{
  return (_left);
}

int	Player::getBombe()
{
  return (_bombe);
}

int	Player::getPause()
{
  return (
}
*/
