#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include <sstream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <glew.h>
#include "../Core/Debug.h"

class ShaderHandler
{
public:
	ShaderHandler(const ShaderHandler&) = delete;
	ShaderHandler(ShaderHandler&&) = delete;
	ShaderHandler& operator=(const ShaderHandler&) = delete;
	ShaderHandler& operator=(ShaderHandler&&) = delete;

	static ShaderHandler* GetInstance();

	// 
	void CreateProgram(const std::string& shaderName_, const std::string& vertexShaderFileName_, const std::string& fragmentShaderFileName_);
	GLuint GetShader(const std::string& shaderName_);
	void OnDestroy();

private:
	ShaderHandler();
	~ShaderHandler();

	static std::unique_ptr<ShaderHandler> shaderInstance;
	friend std::default_delete<ShaderHandler>;

	// Reads shader file returns a string of what is in the file
	std::string ReadShader(const std::string& filePath_);
	// Create the actual shader using the string
	GLuint CreateShader(GLenum shaderType_, const std::string& source_, const std::string& shaderName_);

	// Keeps track of all shaders created
	static std::unordered_map<std::string, GLuint> programs;
};

#endif SHADERHANDLER_H