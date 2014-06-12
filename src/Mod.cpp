/*
** model.cpp for model in /home/sheol/my_git/gdl
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Fri May 30 11:35:33 2014 teddy fontaine
** Last update Thu Jun 12 15:32:05 2014 teddy fontaine
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
  _angle = 0.0f;
  _x = x;
  _y = y;
  _z = z;
  _model.load(_modelPath);
  _trans = glm::scale(glm::rotate(glm::translate(
				       glm::mat4(1),
				       glm::vec3(_x, _y, _z)),
				  _angle,
				  glm::vec3(0, 1, 0)),
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
  shader.setUniform("color", glm::vec4(0, 0, 0, 1));
  _model.draw(shader, _trans, clock.getElapsed());
}
