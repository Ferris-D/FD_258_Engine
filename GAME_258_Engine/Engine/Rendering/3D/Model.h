#ifndef MODEL_H
#define MODEL_H

#include "LoadOBJModel.h"
//#include <glm/gtc/matrix_transform.inl>
#include <string>

class Model
{
public:
	Model(const std::string& objPath_, const std::string& matPath_, GLuint shaderProgram_);
	//Model(GLuint shaderProgram_, glm::vec3 position_ = glm::vec3(), float angle_ = 0.0f, glm::vec3 rotation_ = glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3 scale_ = glm::vec3(1.0f));
	~Model();

	void Render(Camera* camera_);
	void AddMesh(Mesh* mesh_);
	unsigned int CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
	void UpdateInstance(unsigned int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
	glm::mat4 GetTransform(unsigned int index_) const;
	GLuint GetShaderProgram() const;
	BoundingBox GetBoundingBox() const;
	
private:
	glm::mat4 CreateTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const;
	void LoadModel();

	std::vector<Mesh*> meshes;
	GLuint shaderProgram;
	std::vector<glm::mat4> modelInstances;
	LoadOBJModel* obj;

	BoundingBox boundingBox;
};

#endif