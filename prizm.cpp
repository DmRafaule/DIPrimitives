#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"


namespace DI{

  Prizm::Prizm(PrimitiveMaterial matType, unsigned int mode){
    renderType = mode;
    materialType = matType;
    // Set mesh
    mesh = new DI::Mesh();
    mesh->verticies.count = 8;
    switch (matType){
      case PrimitiveMaterial::POSITION_AND_COLORS:{
        render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.size  = mesh->verticies.count * 3 ;
	      mesh->verticies.data = new float[]{
          // Position         
          -1.0f, 1.0f, -1.0f,   
          1.0f, 1.0f, -1.0f,    
          1.0f, 1.0f, 1.0f,     
          -1.0f, 1.0f, 1.0f,    
          -1.0f, -1.0f, -1.0f,  
          1.0f, -1.0f, -1.0f,   
          1.0f, -1.0f, 1.0f,    
          -1.0f, -1.0f, 1.0f,   
        };

        mesh->elements.count = 36;
        mesh->elements.data = new unsigned int[]{
          0, 1, 4,
          1, 4, 5,
          0, 1, 3,
          1, 2, 3,
          0, 4, 7,
          0, 3, 7,
          6, 2, 1,
          6, 5, 1,
          6, 2, 3,
          6, 7, 3,
          6, 5, 7,
          4, 5, 7,
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
      case PrimitiveMaterial::POSITION_AND_COLORS_AND_TEXTURES:{ 
        render_callback = std::bind(&DI::RendererSingleton::DrawArrays,std::placeholders::_1,std::placeholders::_2);
        mesh->verticies.count = 36;
        mesh->verticies.size  = mesh->verticies.count * 5 ;
	      mesh->verticies.data = new float[]{
          // Position           // UV         
          -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
           1.0f, -1.0f, -1.0f,  1.0f, 0.0f,
           1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
           1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
          -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
          -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,

          -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
           1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
           1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
           1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
          -1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
          -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,

          -1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
          -1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
          -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
          -1.0f,  1.0f,  1.0f,  1.0f, 0.0f,

           1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
           1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
           1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
           1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
           1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
           1.0f,  1.0f,  1.0f,  1.0f, 0.0f,

          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
           1.0f, -1.0f, -1.0f,  1.0f, 1.0f,
           1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
           1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
          -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
          -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,

          -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
           1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
           1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
           1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
          -1.0f,  1.0f,  1.0f,  0.0f, 0.0f,
          -1.0f,  1.0f, -1.0f,  0.0f, 1.0f
        };

        mesh->elements.count = 36;
        mesh->elements.data = new unsigned int[]{
          0, 1, 4,
          1, 4, 5,
          0, 1, 3,
          1, 2, 3,
          0, 4, 7,
          0, 3, 7,
          6, 2, 1,
          6, 5, 1,
          6, 2, 3,
          6, 7, 3,
          6, 5, 7,
          4, 5, 7,
        };

        DI::MeshHandler::Set(*mesh);
        break;
      }
    }
  }
  Prizm::~Prizm(){
  }
}
