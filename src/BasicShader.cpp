/*
** BasicShader.cpp for gdl in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <sheol@epitech.net>
**
** Started on  Wed May 21 11:36:46 2014 teddy fontaine
** Last update Wed May 21 11:37:05 2014 teddy fontaine
*/

#include <BasicShader.hh>

namespace	gdl
{
  BasicShader::BasicShader()
  {
  }


  BasicShader::~BasicShader()
  {
  }

  bool	BasicShader::build()
  {
    bool	ret;
    _build();
    _bindAttribLocation(0, "vPosition");
    _bindAttribLocation(1, "vColor");
    _bindAttribLocation(2, "vNormal");
    _bindAttribLocation(3, "vTexCoord");
    ret = _linkProgram();
    if (ret)
      _bindTextureUnit(0, "fTexture0");
    return (ret);
  }
}
