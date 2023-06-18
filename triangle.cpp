#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"


namespace DI{

  Triangle::Triangle(PrimitiveMaterial matType, unsigned int mode){
    materialType = matType;
    renderType = mode;
    // Set mesh
    mesh = new DI::Mesh();
    mesh->verticies.count = 3;
    switch (matType){
      case PrimitiveMaterial::POSITION_AND_COLORS:{
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.size  = mesh->verticies.count * 3;
	      mesh->verticies.data = new float[]{ 
          // Position         
          -1.0f, -1.0f, 0.0f, 
          1.0f, -1.0f, 0.0f,  
          0.0f, 1.0f, 0.0f,   
        };


        mesh->elements.count = 3;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
      case PrimitiveMaterial::POSITION_AND_COLORS_AND_TEXTURES:{ 
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.size  = mesh->verticies.count * 5;
	      mesh->verticies.data = new float[]{ 
          // Position         
          -1.0f, -1.0f, 0.0f,  0.f, 0.f,
          1.0f, -1.0f, 0.0f,  1.f, 0.f,
          0.0f, 1.0f, 0.0f,   0.5f, 1.f,
        };

        mesh->elements.count = 3;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
    }
  }
  Triangle::~Triangle(){
  }
}

