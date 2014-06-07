/*
** AObject.hpp for partie graphique bomberman in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Thu May 15 16:02:49 2014 Alexandre NGUYEN
** Last update Sat Jun  7 15:28:07 2014 teddy fontaine
*/

#include <SdlContext.hh>
#include <AShader.hh>
#include <Texture.hh>
#include <Geometry.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#ifndef AOBJECT_HH_
# define AOBJECT_HH_

class AObject
{
  public:
    AObject();
    virtual ~AObject();
    virtual bool		initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z);
    virtual bool		initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z,
					   __attribute__((unused))float size_x, __attribute__((unused))float size_y, __attribute__((unused))float size_z);
    virtual bool		initialize(__attribute__((unused))float x, __attribute__((unused))float y, __attribute__((unused))float z,
					   __attribute__((unused))float size_x, __attribute__((unused))float size_y, __attribute__((unused))float size_z,
					   __attribute__((unused))std::string texture_name);
    virtual void		update(__attribute__((unused))gdl::Clock const &clock, __attribute__((unused))gdl::Input &input);
    virtual void		draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
    virtual float		getCamZ();
    virtual std::vector<int>	getObjs();
    virtual void		setObjs(__attribute__((unused)) int objs);
    void			translate(glm::vec3 const &v);
    void			rotate(glm::vec3 const& axis, float angle);
    void			scale(glm::vec3 const& scale);
    glm::mat4			getTransformation();

  protected:
    glm::vec3		_position;
    glm::vec3		_rotation;
    glm::vec3		_scale;
};

#endif /* !AOBJECT_HH_ */
