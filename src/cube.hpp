/*
** cube.hpp for cube in /home/nguye_1/rendu/gdl
**
** Made by Alexandre NGUYEN
** Login   <nguye_1@epitech.net>
**
** Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
** Last update Wed May 21 11:52:24 2014 teddy fontaine
*/

#ifndef CUBE_HPP_
# define CUBE_HPP_

#include "AObject.hh"

class Cube : public AObject
{
  private:

    gdl::Texture	_texture;
    gdl::Geometry	_geometry;
    float		_speed;

  public:
    Cube()
    {
    }

    virtual ~Cube()
    {
    }

    /*
     * Initialise un cube
     * color : _geometry.setColor(glm::vec4(R, G, B, 1));
     */
    virtual bool	initialize(int x, int y, int z)
    {
      _speed = 10.0f;

      if (_texture.load("./textures/stone_wall/wall_512_1_05.tga") == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
      _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
      _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
      _geometry.pushUv(glm::vec2(0.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 0.0f));
      _geometry.pushUv(glm::vec2(1.0f, 1.0f));
      _geometry.pushUv(glm::vec2(0.0f, 1.0f));

      _geometry.build();
      return (true);
    }

    /*
     * gestion des mouvements du cube
     */
    virtual void	update(gdl::Clock const &clock, gdl::Input &input)
    {
      if (input.getKey(SDLK_UP))
	translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
      if (input.getKey(SDLK_DOWN))
	translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
      if (input.getKey(SDLK_LEFT))
	translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
      if (input.getKey(SDLK_RIGHT))
	translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    }

    /*
     * Dessine le cube
     */
    virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock)
    {
      (void)clock;
      _texture.bind();
      _geometry.draw(shader, getTransformation(), GL_QUADS);
    }
};

#endif /* !CUBE_HPP_ */
