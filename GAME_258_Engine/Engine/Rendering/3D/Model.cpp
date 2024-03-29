#include "Model.h"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

Model::Model(const std::string& objPath_, const std::string& matPath_, GLuint shaderProgram_) : meshes(std::vector<Mesh*>()), shaderProgram(0), modelInstances(std::vector<glm::mat4>())
{
	shaderProgram = shaderProgram_;
	meshes.reserve(10);
	modelInstances.reserve(5);
	obj = new LoadOBJModel();
	obj->LoadModel(objPath_, matPath_);
	LoadModel();
}

Model::~Model()
{
	if (meshes.size() > 0)
	{
		for (auto m : meshes)
		{
			delete m;
			m = nullptr;
		}
		meshes.clear();
	}

	if (modelInstances.size() > 0)
	{
		modelInstances.clear();
	}
}

void Model::Render(Camera* camera_)
{
	glUseProgram(shaderProgram);
	for (auto m : meshes)
	{
		m->Render(camera_, modelInstances);
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	meshes.push_back(mesh_);
}

unsigned int Model::CreateInstance(glm::vec3 position_, float angle_, Quaternion rotation_, glm::vec3 scale_)
{
	modelInstances.push_back(CreateTransform(position_, angle_, rotation_, scale_));
	return modelInstances.size() - 1;
}

void Model::UpdateInstance(unsigned int index_, glm::vec3 position_, float angle_, Quaternion rotation_, glm::vec3 scale_)
{
	modelInstances[index_] = CreateTransform(position_, angle_, rotation_, scale_);
}

glm::mat4 Model::GetTransform(unsigned int index_) const
{
	return modelInstances[index_];
}

GLuint Model::GetShaderProgram() const
{
	return shaderProgram;
}

BoundingBox Model::GetBoundingBox() const
{
	return boundingBox;
}

glm::mat4 Model::CreateTransform(glm::vec3 position_, float angle_, Quaternion rotation_, glm::vec3 scale_) const
{
	glm::mat4 model;
	model = glm::translate(model, position_);
	glm::quat qq(rotation_.v.w, rotation_.v.x, rotation_.v.y, rotation_.v.z);
	//model *= glm::toMat4(glm::quat(rotation_.v.w, rotation_.v.x, rotation_.v.y, rotation_.v.z));
	float angle = glm::angle(qq);
	glm::vec3 axis = glm::axis(qq);
	model = glm::rotate(model, angle, axis);
	model = glm::scale(model, scale_);
	//model = glm::rotate(model, rotation_.CQAA(rotation_).angle_, rotation_.CQAA(rotation_).rotation_);
	//model = glm::rotate(model, rotation_.CQAA().angle_, rotation_.CQAA().rotation_);
	//model = glm::rotate(model, angle_, (glm::quat(rotation_.v.w, rotation_.v.x, rotation_.v.y, rotation_.v.z)));
	return model;
}

void Model::LoadModel()
{
	for (int i = 0; i < obj->GetSubMeshes().size(); i++)
	{
		meshes.push_back(new Mesh(obj->GetSubMeshes()[i], shaderProgram));
	}

	boundingBox = obj->GetBoundingBox();

	delete obj;
	obj = nullptr;
}