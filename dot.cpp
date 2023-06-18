#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"



namespace DI{

  Dot::Dot(){
    renderType = GL_POINTS;
    materialType = PrimitiveMaterial::POSITION_AND_COLORS;
    render_callback = std::bind(&DI::RendererSingleton::DrawArrays,std::placeholders::_1,std::placeholders::_2);
    // Set mesh
    mesh = new DI::Mesh();
    mesh->verticies.count = 1;
    mesh->verticies.size  = mesh->verticies.count * 3;
	  mesh->verticies.data = new float[]{ 
      // Position      
      0.0f, 0.0f, 0.0f,
    };  
    mesh->elements.count = 1;
    mesh->elements.data = new unsigned int[]{
      0
    };


    DI::MeshHandler::Set(*mesh);
  }
  Dot::~Dot(){

  }
}
