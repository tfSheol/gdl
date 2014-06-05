/*
** model.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Thu Jun  5 14:53:26 2014 teddy fontaine
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
  _model.load(_modelPath);
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(0, 1, 0)),
				  0.0f,
				  glm::vec3(_x, _y + 1, _z)),
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
  _model.draw(shader, _trans, clock.getElapsed());
}
