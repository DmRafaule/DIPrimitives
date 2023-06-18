#include "primitives.hpp"
#include "DIRenderer/renderer.hpp"


namespace DI{

  Line::Line(){
    glLineWidth(3.0f);
    materialType = POSITION_AND_COLORS;
    renderType = GL_LINES;
    render_callback = std::bind(&DI::RendererSingleton::DrawElements,std::placeholders::_1,std::placeholders::_2);
    // Set mesh
    mesh = new DI::Mesh();
    mesh->verticies.count = 2;
    mesh->verticies.size  = mesh->verticies.count * 3;
	  mesh->verticies.data = new float[]{ 
      // Position     
      -1.0f, -1.0f, -1.0f,
      1.0f, 1.0f, 1.0f,
    };


    mesh->elements.count = 2;
    mesh->elements.data = new unsigned int[]{
      0, 1
    };

    DI::MeshHandler::Set(*mesh);
  }
  Line::~Line(){
  }
}
