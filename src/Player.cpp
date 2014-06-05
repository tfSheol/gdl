/*
** Player.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Thu Jun  5 14:28:44 2014 teddy fontaine
*/

#include "Player.hh"

Player::Player(std::string path)
{
  _modelPath = "./assets/marvin.fbx";
  _textureMod = path;
}

Player::~Player()
{
}

bool	Player::initialize(__attribute__((unused)) float x,
			__attribute__((unused)) float y,
			__attribute__((unused)) float z)
{
  _speed = 5.0f;
  _x = x;
  _y = y;
  _z = z;
  _rX = 0;
  _rY = 0;
  _rZ = 0;
  _model = new gdl::Model();
  _model->load(_modelPath);
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(0, 1, 0)),
				  0.0f,
				  glm::vec3(_x, _y, _z)),
		      glm::vec3(0.001f, 0.001f, 0.001f));

  _model->createSubAnim(0, "RESET", 0, 0);
  _model->createSubAnim(0, "START", 0, 36);
  _model->createSubAnim(0, "RUN", 36, 53);
  _model->createSubAnim(0, "END", 53, 120);

  _model->setCurrentSubAnim("START");

  return (true);
}

void	Player::update(__attribute__((unused)) gdl::Clock const &clock,
		    __attribute__((unused)) gdl::Input &input)
{
  if (input.getKey(SDLK_UP))
  {
    _anim = "START";
    _z -= clock.getElapsed() * _speed;
    _rX = 180.0f;
  }
  if (input.getKey(SDLK_DOWN))
  {
    _anim = "RUN";
    _z += clock.getElapsed() * _speed;
    _rX = 0.0f;
  }
  if (input.getKey(SDLK_LEFT))
  {
    _anim = "RUN";
    _x -= clock.getElapsed() * _speed;
    _rX = 270.0f;
  }
  if (input.getKey(SDLK_RIGHT))
  {
    _anim = "RUN";
    _x += clock.getElapsed() * _speed;
    _rX = 90.0f;
  }
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(_x, _y, _z)),
				  _rX,
				  glm::vec3(0, 1, 0)),
		      glm::vec3(0.001f, 0.001f, 0.001f));
  if (_model->getAnimationFrameNumber(0) == 121)
    _model->setCurrentSubAnim(_anim, true);
  std::cout << _model->getAnimationFrameNumber(0) << std::endl;
}

void	Player::draw(__attribute__((unused)) gdl::AShader &shader,
		  __attribute__((unused)) gdl::Clock const &clock)
{
  _model->draw(shader, _trans, clock.getElapsed());
}
