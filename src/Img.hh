/*
** Img.hh for gdl in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <sheol@epitech.net>
**
** Started on  Sat May 24 21:07:44 2014 teddy fontaine
** Last update Tue Jun  3 12:46:42 2014 teddy fontaine
*/

#ifndef IMG_HH_
# define IMG_HH_

#include "AObject.hh"

class Img : public AObject
{
  protected:
    SDL_Window		*_window;
    SDL_Surface		*_img;

  private:
    float		_x;
    float		_y;
    float		_z;
    std::string		_filepath;
//    GLuint		_texture;
    gdl::Texture	_texture;
    gdl::Geometry	_geometry;
    SDL_Surface		*loadImage();
    void		applySurface();

  public:
    Img(SDL_Window *window, std::string path);
    virtual ~Img();
    virtual bool	initialize(float x, float y, float z);
    virtual void	update(gdl::Clock const &clock, gdl::Input &input);
    virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* !IMG_HH_ */
