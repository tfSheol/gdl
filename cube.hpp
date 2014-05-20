//
// cube.hpp for cube in /home/nguye_1/rendu/gdl
//
// Made by Alexandre NGUYEN
// Login   <nguye_1@epitech.net>
//
// Started on  Tue May 20 10:45:19 2014 Alexandre NGUYEN
// Last update Tue May 20 11:04:45 2014 Alexandre NGUYEN
//

#ifndef CUBE_HPP_
# define CUBE_HPP_

#include "AObject.hpp"

class Cube : public AObject
{
private:

  // La texture utilisee pour le cube
  gdl::Texture _texture;

  // La geometrie du cube
  gdl::Geometry _geometry;

  // La vitesse de deplacement du cube
  float _speed;

public:

  Cube() { }
  virtual ~Cube() { }
  virtual bool initialize(int x, int y, int z)
  {
    _speed = 10.0f;

    // On charge la texture qui sera affichee sur chaque face du cube
    if (_texture.load("./textures/stone_wall/wall_512_1_05.tga") == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

    // on set la color d'une premiere face
    //    _geometry.setColor(glm::vec4(1, 0, 0, 1));

    // tout les pushVertex qui suivent seront de cette couleur
    // On y push les vertices d une premiere face

    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
    // Les UVs d'une premiere face
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // ETC ETC
    // _geometry.setColor(glm::vec4(1, 1, 0, 1));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // _geometry.setColor(glm::vec4(0, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // _geometry.setColor(glm::vec4(1, 0, 1, 1));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // _geometry.setColor(glm::vec4(0, 1, 0, 1));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + 0.5, z + 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // _geometry.setColor(glm::vec4(0, 0, 1, 1));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + -0.5));
    _geometry.pushVertex(glm::vec3(x + 0.5, y + -0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + 0.5));
    _geometry.pushVertex(glm::vec3(x + -0.5, y + -0.5, z + -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    // Tres important, on n'oublie pas de build la geometrie pour envoyer ses informations a la carte graphique
    _geometry.build();
    return (true);
  }
  // Ici le cube bougera avec les fleches du clavier
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    // On multiplie par le temps ecoule depuis la derniere image pour que la vitesse ne depende pas de la puissance de l'ordinateur
    if (input.getKey(SDLK_UP))
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_DOWN))
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_LEFT))
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_RIGHT))
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  }

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    (void)clock;
    // On bind la texture pour dire que l'on veux l'utiliser
    _texture.bind();
    // Et on dessine notre cube
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
