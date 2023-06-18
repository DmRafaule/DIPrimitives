#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"

namespace DI{

  Tetrahedron::Tetrahedron(PrimitiveMaterial matType, unsigned int mode){
    materialType = matType;
    renderType = mode;
    // Set mesh
    mesh = new DI::Mesh();
    switch (matType){
      case PrimitiveMaterial::POSITION_AND_COLORS:{
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.count = 4;
        mesh->verticies.size  = mesh->verticies.count * 3;
	      mesh->verticies.data = new float[]{
          // Position         
          1.0f, 1.0f, 1.0f,     
          -1.0f, 1.0f, -1.0f,   
          1.0f, -1.0f, -1.0f,   
          -1.0f, -1.0f, 1.0f,   
        };

        mesh->elements.count = 12;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2,
          1, 2, 3,
          1, 3, 0,
          0, 2, 3,
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
      case PrimitiveMaterial::POSITION_AND_COLORS_AND_TEXTURES:{ 
        render_callback = std::bind(&DI::RendererSingleton::DrawArrays,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.count = 12;
        mesh->verticies.size  = mesh->verticies.count * 5;
	      mesh->verticies.data = new float[]{
          // Position         UV 
          1.0f, 1.0f, 1.0f,   0.5f, 1.0f,  
          -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 
          -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 
          
          1.0f, 1.0f, 1.0f,   0.5f, 1.0f, 
          -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 
          1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 

          1.0f, 1.0f, 1.0f,   0.5f, 1.0f,  
          -1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 
          1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 

          1.0f, -1.0f, -1.0f, 0.5f, 1.0f, 
          -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 
          -1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 
        };

        mesh->elements.count = 12;
        mesh->elements.data = new unsigned int[]{
          0, 1, 2,
          1, 2, 3,
          1, 3, 0,
          0, 2, 3,
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
    }
  }
  Tetrahedron::~Tetrahedron(){
  }
}


