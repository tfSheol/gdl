/*
** AObject.cpp for AObject in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <fontai_d@epitech.eu>
**
** Started on  Tue May 20 17:34:37 2014 teddy fontaine
** Last update Tue May 20 17:48:45 2014 teddy fontaine
*/

#include "AObject.hh"

AObject::AObject() : _position(0, 0, 0),
		     _rotation(0, 0, 0),
		     _scale(1, 1, 1)
{
}

AObject::~AObject()
{
}

/*
 * Initialize l'objet
 */
bool		AObject::initialize(__attribute__((unused))int x, __attribute__((unused))int y, __attribute__((unused))int z)
{
  return (true);
}

/*
 * Gere le comportement de l'objet
 */
void		AObject::update(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
{
}

/*
 * Translate l'object ???
 */
void		AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

/*
 *
 */
void		AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

/*
 *
 */
void		AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

/*
 *
 */
glm::mat4	AObject::getTransformation()
{
  glm::mat4			transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);

  return (transform);
}
