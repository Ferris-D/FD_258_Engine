#ifndef SIMPLEX_H
#define SIMPLEX_H

#include<glm/glm.hpp>
#include<vector>

class Simplex
{
public:
	Simplex(glm::vec3 v1_, glm::vec3 v2_, glm::vec3 v3_, glm::vec3 v4_) : 
		v1(glm::vec3(0.0f,0.0f,0.0f)), v2(glm::vec3(0.0f, 0.0f, 0.0f)), v3(glm::vec3(0.0f, 0.0f, 0.0f)), v4(glm::vec3(0.0f, 0.0f, 0.0f))
	{
		v1 = v1_;
		v2 = v2_;
		v3 = v3_;
		v4 = v4_;
	}
	~Simplex() {}
	// Functions for updating specific points
	Simplex UpdateV1(glm::vec3 v1_)
	{
		v1 = v1_;
	}
	Simplex UpdateV2(glm::vec3 v2_)
	{
		v2 = v2_;
	}
	Simplex UpdateV3(glm::vec3 v3_)
	{
		v3 = v3_;
	}
	Simplex UpdateV4(glm::vec3 v4_)
	{
		v4 = v4_;
	}
private:
	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 v3;
	glm::vec3 v4;
};

#endif