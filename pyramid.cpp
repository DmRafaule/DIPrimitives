#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"

namespace DI{

  Pyramid::Pyramid(PrimitiveMaterial matType, unsigned int mode){
    materialType = matType;
    renderType = mode;
    // Set mesh
    mesh = new DI::Mesh();
    switch (matType){
      case PrimitiveMaterial::POSITION_AND_COLORS:{
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.count = 5;
        mesh->verticies.size  = mesh->verticies.count * 3;
	      mesh->verticies.data = new float[]{
          // Position         
          0.0f, 1.0f, 0.0f,     
          -1.0f, -1.0f, -1.0f,  
          1.0f, -1.0f, -1.0f,   
          1.0f, -1.0f, 1.0f,    
          -1.0f, -1.0f, 1.0f,   
        };

        mesh->elements.count = 18;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2,
          0, 2, 3,
          0, 3, 4,
          0, 4, 1,
          2, 3, 4,
          1, 2, 4,
        };

        DI::MeshHandler::Set(*mesh);
        // Set shaders
        shader = new DI::Shader();
        DI::ShaderHandler::Set(*shader,"assets/shaders/pPosCol.vert","assets/shaders/pPosCol.frag");
        // Create material
        material = new DI::Material();
        DI::MaterialHandler::SetShader(*material,*shader);
        DI::LayoutHandler::Set("assets/shaders/pPosCol.vert");
        material->uniforms["uMatModel"].first = &mesh->model_matrix;
        material->uniforms["uMatView"].first =  new glm::mat4(1.0f);
        material->uniforms["uMatProj"].first =  new glm::mat4(1.0f);
        material->uniforms["uPointSize"].first = new float(1.0f);
        material->uniforms["uCol"].first = new glm::vec4(1.0f);

        break;
      }
      case PrimitiveMaterial::POSITION_AND_COLORS_AND_TEXTURES:{ 
        render_callback = std::bind(&DI::RendererSingleton::DrawArrays,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.count = 18;
        mesh->verticies.size  = mesh->verticies.count * 5;
	      mesh->verticies.data = new float[]{
          // Position         
          0.0f, 1.0f, 0.0f,     0.5f, 1.0f,  
          -1.0f, -1.0f, -1.0f,  1.0f, 0.0f,
          -1.0f, -1.0f, 1.0f,   0.0f, 0.0f, 

          0.0f, 1.0f, 0.0f,     0.5f, 1.0f,
          -1.0f, -1.0f, 1.0f,   1.0f, 0.0f,
          1.0f, -1.0f, 1.0f,    0.0f, 0.0f,

          0.0f, 1.0f, 0.0f,     0.5f, 1.0f, 
          1.0f, -1.0f, 1.0f,    1.0f, 0.0f,
          1.0f, -1.0f, -1.0f,   0.0f, 0.0f,

          0.0f, 1.0f, 0.0f,     0.5f, 1.0f,
          1.0f, -1.0f, -1.0f,   1.0f, 0.0f,
          -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,

          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,   
          1.0f, -1.0f, -1.0f,   1.0f, 1.0f,
          1.0f, -1.0f, 1.0f,    1.0f, 0.0f, 
          1.0f, -1.0f, 1.0f,    1.0f, 0.0f,
          -1.0f, -1.0f, 1.0f,   0.0f, 0.0f,    
          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f, 
        };

        mesh->elements.count = 18;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2,
          0, 2, 3,
          0, 3, 4,
          0, 4, 1,
          2, 3, 4,
          1, 2, 4,
        };

        DI::MeshHandler::Set(*mesh);
        // Set shaders
        shader = new DI::Shader();
        DI::ShaderHandler::Set(*shader,"assets/shaders/pPosColTex.vert","assets/shaders/pPosColTex.frag");
        // Create material
        material = new DI::Material();
        DI::MaterialHandler::SetShader(*material,*shader);
        DI::LayoutHandler::Set("assets/shaders/pPosColTex.vert");
        material->uniforms["uMatModel"].first = &mesh->model_matrix;
        material->uniforms["uMatView"].first =  new glm::mat4(1.0f);
        material->uniforms["uMatProj"].first =  new glm::mat4(1.0f);
        material->uniforms["uPointSize"].first = new float(1.0f);
        material->uniforms["uCol"].first = new glm::vec4(1.0f);
        break;
      }
    }
  }
  Pyramid::~Pyramid(){
  }
  
}

