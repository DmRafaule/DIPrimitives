#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"

namespace DI{

  Reqtangle::Reqtangle(PrimitiveMaterial matType, unsigned int mode){
    renderType = mode;
    materialType = matType;
    // Set mesh
    mesh = new DI::Mesh();
    mesh->verticies.count = 4;
    switch (matType){
      case PrimitiveMaterial::POSITION_AND_COLORS:{
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.size  = mesh->verticies.count * 3;
	      mesh->verticies.data = new float[]{
          // Position         
          1.f, 1.f, 0.f,   
          1.f, -1.f, 0.f,  
          -1.f, -1.f, 0.f, 
          -1.f, 1.f, 0.f,  
        };

        mesh->elements.count = 6;
        mesh->elements.data = new unsigned int[]{
          0, 1, 3,
          3, 2, 1,
        };
        DI::MeshHandler::Set(*mesh);
        break;
      }
      case PrimitiveMaterial::POSITION_AND_COLORS_AND_TEXTURES:{ 
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.size  = mesh->verticies.count * 5;
	      mesh->verticies.data = new float[]{
          // Position        // Tex coord 
          1.f, 1.f, 0.f,   1.f, 1.f, 
          1.f, -1.f, 0.f,  1.f, 0.f,
          -1.f, -1.f, 0.f, 0.f, 0.f,
          -1.f, 1.f, 0.f,  0.f, 1.f,
        };

        mesh->elements.count = 6;
        mesh->elements.data = new unsigned int[]{
          0, 1, 3,
          3, 2, 1,
        };
        DI::MeshHandler::Set(*mesh);
        break;
      }
    }
  }
  Reqtangle::~Reqtangle(){
  }
}
