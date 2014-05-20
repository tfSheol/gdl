/*
** AObject.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 16:02:49 2014 Alexandre NGUYEN
** Last update Tue May 20 15:18:31 2014 teddy fontaine
*/

#ifndef AOBJECT_HPP_
# define AOBJECT_HPP_

#include <SdlContext.hh>
#include <AShader.hh>
#include <Texture.hh>
#include <Geometry.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

// La classe abstraite representant un objet avec sa position, sa rotation et son echelle

class AObject
{
  public:
    AObject() : _position(0, 0, 0),
		_rotation(0, 0, 0),
		_scale(1, 1, 1)
    {
    }

    virtual ~AObject()
    {
    }

    /*
     * Initialize l'objet
     */
    virtual bool		initialize(__attribute__((unused))int x, __attribute__((unused))int y, __attribute__((unused))int z)
    {
      return (true);
    }

    /*
     * Gere le comportement de l'objet
     */
    virtual void		update(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input)
    {
    }

    /*
     * Dessine l'objet
     */
    virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;

    /*
     * Translate l'object ???
     */
    void			translate(glm::vec3 const &v)
    {
      _position += v;
    }

    /*
     *
     */
    void			rotate(glm::vec3 const& axis, float angle)
    {
      _rotation += axis * angle;
    }

    /*
     *
     */
    void			scale(glm::vec3 const& scale)
    {
      _scale *= scale;
    }

    /*
     *
     */
    glm::mat4			getTransformation()
    {
      glm::mat4			transform(1);

      transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
      transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
      transform = glm::translate(transform, _position);
      transform = glm::scale(transform, _scale);

      return (transform);
    }

  protected:
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
};

#endif
