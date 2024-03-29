#version 450 core

in vec3 Normal;
in vec2 TexCoords;
in vec3 FragPosition;

//uniform sampler2D inputTexture;
///Light
uniform vec3 cameraPosition;
uniform vec3 viewPosition;

out vec4 fColour;

struct Material {
	sampler2D diffuseMap; //newtml

	float shininess;   //Ns
	float transparency;//d

	vec3 ambient; //Ka
	vec3 diffuse; //Kd
	vec3 specular;//Ks
};

struct Light {
	vec3 position;
	float ambient;
	float diffuse;
	float specular;
	vec3 colour;
};

uniform Light light;
uniform Material material;

void main()
{
	// Ambient
	vec3 ambient = light.ambient * material.ambient * texture(material.diffuseMap,TexCoords).rgb * light.colour;

	// Diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPosition);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = (diff*material.diffuse) * texture(material.diffuseMap,TexCoords).rgb*light.colour;

	// Specular
	vec3 viewDir = normalize(viewPosition - FragPosition);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir,reflectDir),0.0), material.shininess);
	vec3 specular = (spec* material.specular) * light.colour;

	vec3 result = ambient + diffuse + specular;

	fColour = vec4(result, material.transparency);
}