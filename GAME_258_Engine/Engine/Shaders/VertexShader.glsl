#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec3 Normal;
out vec2 TexCoords;
out vec3 FragPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	//Colour = colour;
	TexCoords = vec2(texCoords.x, 1.0 - texCoords.y);
	/// Inverse and transpose model then multiply by normal which is now a vec4 then cast to vec3
	Normal = vec3(transpose(inverse(model)) * vec4(normal, 1.0f));
	/// Multiply model by position which is now a vec4 then cast to vec3
	FragPosition = vec3(model * vec4(position, 1.0f));
}