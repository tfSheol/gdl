/*
** model.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Tue Jun  3 15:02:22 2014 teddy fontaine
*/

#include "Mod.hh"

Mod::Mod(std::string path)
{
  _modelPath = path;
}

Mod::~Mod()
{
}

bool	Mod::initialize(__attribute__((unused)) float x,
			__attribute__((unused)) float y,
			__attribute__((unused)) float z)
{
  _speed = 10.0f;
  _x = x;
  _y = y;
  _z = z;
  _rX = 0;
  _rY = 0;
  _rZ = 0;
  this->_model = new gdl::Model();
  this->_model->load(_modelPath);
  _trans = glm::scale(glm::translate(glm::rotate(
				       glm::mat4(1),
				       90.0f,
				       glm::vec3(_rX, _rY + 1, _rZ)),
				     glm::vec3(_x, _y, _z)),
		      glm::vec3(0.001f, 0.001f, 0.001f));
  return (true);
}

void	Mod::update(__attribute__((unused)) gdl::Clock const &clock,
		    __attribute__((unused)) gdl::Input &input)
{
}

void	Mod::draw(__attribute__((unused)) gdl::AShader &shader,
		  __attribute__((unused)) gdl::Clock const &clock)
{
  this->_model->draw(shader, _trans, clock.getElapsed());
}
