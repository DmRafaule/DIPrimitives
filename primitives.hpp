#pragma once 

#include "DIRenderer/texture.hpp"
#include "DIRenderer/mesh.hpp"
#include "DIRenderer/shader.hpp"
#include "DIRenderer/material.hpp"
#include "DIRenderer/layout.hpp"
#include "DIRenderer/camera.hpp"
#include "DIRenderer/drawable.hpp"
#include <functional>

namespace DI{

  enum PrimitiveMaterial{
    POSITION_AND_COLORS,
    POSITION_AND_COLORS_AND_TEXTURES,
  };
  struct Collider;

  class Primitive : public Drawable{
    public:
      // Constructors/Destructor
      Primitive();
      ~Primitive();
      // Set position, scale and rotation to 0;
      void ResetModelMatrix();
      // How to draw an Primitive
      void Draw() override;
      void SetCamera( Camera& camera );
      void SetShader(Shader* shader);
      void SetRenderMode(unsigned int mode);
      void SetMesh(Mesh* mesh);
      void SetColor(glm::vec4 color);
      void SetTexture(Texture* texture);
      void SetPosition(glm::vec3 pos);
      void SetRotation(float angle, glm::vec3 offset);
      void SetScale(glm::vec3 offset);
      inline const glm::vec3& GetPosition() { return position; }
      inline const glm::vec3& GetScale() { return scale; }
      inline const glm::vec3& GetAngleOffset() { return angleOffset; }
      inline const glm::vec4& GetColor() { return color; }
      inline const Shader& GetShader() { return *shader; }
      inline const Mesh& GetMesh() { return *mesh; }
      inline const Material& GetMaterial() { return *material; }
      inline const Texture& GetTexture() { return *texture; }
    protected:
      std::function<void(Mesh&,unsigned int)> render_callback;
      unsigned int renderType;
      PrimitiveMaterial materialType;
      float angle;
      glm::vec3 angleOffset;
      glm::vec3 position;
      glm::vec3 scale;
      glm::vec4 color;
      Texture* texture;
      Mesh* mesh;
      Shader* shader;
      Material* material;
  };
  class Dot : public Primitive {
    public:
      Dot();
      ~Dot();
  };
  class Line : public Primitive{
    public:
      Line();
      ~Line();
  };
  class Triangle : public Primitive{
    public:
      Triangle(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Triangle();
  };
  class Reqtangle : public Primitive{
    public:
      Reqtangle(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Reqtangle();
  };
  class Circle : public Primitive{
    public:
      Circle(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Circle();
  };
  class Tetrahedron : public Primitive{
    public:
      Tetrahedron(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Tetrahedron();
  };
  class Pyramid : public Primitive{
    public:
      Pyramid(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Pyramid();
  };
  class Prizm : public Primitive{
    public:
      Prizm(PrimitiveMaterial material  = POSITION_AND_COLORS, unsigned int mode = GL_TRIANGLES);
      ~Prizm();
  };
}
