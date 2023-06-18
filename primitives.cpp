#include "primitives.hpp"
#include "DIDebuger/debuger.hpp"
#include "DIDebuger/log.hpp"



namespace DI{

  extern DebugData* eg_debugData;

  Primitive::Primitive(){
    DI_LOG_DEBUG("Create a primitive");
    mesh = nullptr;
    material = nullptr;
  }

  Primitive::~Primitive(){
    DI_LOG_DEBUG("Remove a primitive");
    delete this->material;
    delete this->mesh;
  }

  void Primitive::Draw(){
    DI::MaterialHandler::UseMaterial(*material,*shader);
    render_callback(*mesh,renderType);
    eg_debugData->counterDIVerticies_inUse += mesh->verticies.count;
    eg_debugData->counterDIElements_inUse += mesh->elements.count;
    eg_debugData->counterDICalls++;
  }

  void Primitive::SetCamera( Camera& camera){
    material->uniforms["uMatView"].first =  &camera.GetEye();
    material->uniforms["uMatProj"].first =  &camera.GetProjection();
  }

  void Primitive::SetShader(Shader* shader){
    // Create material
    this->shader = shader;
    if (material != nullptr)
      delete material;
    material = new DI::Material();
    DI::MaterialHandler::SetShader(*material,*shader);
    DI::LayoutHandler::Set(shader->layout);
    material->uniforms["uMatModel"].first = &mesh->model_matrix;
  }
  void Primitive::SetRenderMode( unsigned int mode){
    renderType = mode;
  }
  void Primitive::SetColor( glm::vec4 col){
    color = col;
    material->uniforms["uCol"].first = new glm::vec4(color); 
  }  
  void Primitive::SetTexture( Texture* tex){
    texture = tex;
    MaterialHandler::SetSampler(*material,*texture); 
  }
  void Primitive::SetPosition( glm::vec3 pos){
    position = pos;
    MeshHandler::Translate(*mesh,position); 
  }  
  void Primitive::SetRotation( float angl, glm::vec3 offset){
    angle = angl;
    angleOffset = offset;
    MeshHandler::Rotate(*mesh,angle,offset); 
  }  
  void Primitive::SetScale( glm::vec3 offset){
    scale = offset;
    MeshHandler::Scale(*mesh,offset); 
  }  
  void Primitive::SetMesh(Mesh* msh){
    if (mesh != nullptr)
      delete mesh;
    mesh = msh;
    DI::MeshHandler::Set(*mesh);
  }
  void Primitive::ResetModelMatrix(){
    mesh->model_matrix = glm::mat4(1.0f); 
  }
}
