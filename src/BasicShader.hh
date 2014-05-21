/*
** BasicShader.hh for gdl in /home/sheol/my_git/gdl/src
**
** Made by teddy fontaine
** Login   <sheol@epitech.net>
**
** Started on  Wed May 21 11:35:38 2014 teddy fontaine
** Last update Wed May 21 11:36:36 2014 teddy fontaine
*/

#ifndef BASICSHADER_HH_
# define BASICSHADER_HH_

#include <AShader.hh>

namespace	gdl
{
  // Class used to compile the shaders basic.fp and basic.vp
  class BasicShader : public AShader
  {
    public:
      BasicShader();
      ~BasicShader();

      // Function used to build the shaders once they are loaded
      virtual bool build();
  };
}

#endif /* !BASICSHADER_HH_ */
