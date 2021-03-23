#include "Mesh.h"
/*
Mesh::Mesh(std::vector<Vertex>& vertexList_, GLuint textureID_, GLuint shaderProgram_) : VAO(0), VBO(0), vertexList(std::vector<Vertex>()), 
shaderProgram(0), modelLoc(0), viewLoc(0), projectionLoc(0), textureLoc(0)
{
	vertexList = vertexList_;
	textureID = textureID_;
	shaderProgram = shaderProgram_;
	GenerateBuffers();
}
*/
Mesh::Mesh(SubMesh& subMesh_, GLuint shaderProgram_) : VAO(0), VBO(0), shaderProgram(0), modelLoc(0), viewLoc(0), projectionLoc(0), textureLoc(0),
vPos(0), lPos(0), lAmbient(0), lDiffuse(0), lSpecular(0), lColour(0)
{
	subMesh = subMesh_;
	shaderProgram = shaderProgram_;
	GenerateBuffers();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	if (subMesh.vertexList.size() > 0)
	{
		subMesh.vertexList.clear();
	}
	if (subMesh.meshIndices.size() > 0)
	{
		subMesh.meshIndices.clear();
	}
	//vertexList.clear();
}

void Mesh::Render(Camera* camera_, std::vector<glm::mat4>& instances_)
{
	glUniform1i(textureLoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, subMesh.textureID);


	// Get light uniform info using camera
	glUniform3fv(vPos, 1, glm::value_ptr(camera_->GetPosition()));
	glUniform3fv(lPos, 1, glm::value_ptr(camera_->GetLights()[0]->GetPosition()));
	glUniform1f(lAmbient, camera_->GetLights()[0]->GetAmbient());
	glUniform1f(lDiffuse, camera_->GetLights()[0]->GetDiffuse());
	glUniform1f(lSpecular, camera_->GetLights()[0]->GetSpecular());
	glUniform3fv(lColour, 1, glm::value_ptr(camera_->GetLights()[0]->GetColour()));

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetView()));
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetPerspective()));

	glBindVertexArray(VAO);

	glEnable(GL_DEPTH_TEST);
	for (int i = 0; i < instances_.size(); i++)
	{
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));
		glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Mesh::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);
	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	//TEXTURE COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinates));
	//COLOUR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	textureLoc = glGetUniformLocation(shaderProgram, "inputTexture");

	// Light
	vPos = glGetUniformLocation(shaderProgram, "viewPosition");
	lPos = glGetUniformLocation(shaderProgram, "light.position");
	lAmbient = glGetUniformLocation(shaderProgram, "light.ambient");
	lDiffuse = glGetUniformLocation(shaderProgram, "light.diffuse");
	lSpecular = glGetUniformLocation(shaderProgram, "light.specular");
	lColour = glGetUniformLocation(shaderProgram, "light.colour");
}
