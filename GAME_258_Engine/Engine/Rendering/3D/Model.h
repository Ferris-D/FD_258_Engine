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
	/*
	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
	*/
private:
	glm::mat4 CreateTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_) const;
	void LoadModel();

	std::vector<Mesh*> meshes;
	GLuint shaderProgram;
	std::vector<glm::mat4> modelInstances;
	LoadOBJModel* obj;

	//glm::vec3 position;
	//float angle;
	//glm::vec3 rotation;
	//glm::vec3 scale;
	//glm::mat4 GetTransform() const;
};

#endif