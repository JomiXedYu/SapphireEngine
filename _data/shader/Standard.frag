#version 330 core
in vec4 vertexColor;
in vec2 texCoord;
in vec3 normal;
in vec3 fragPos;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

struct Material
{
	
    vec3 ambient;
    vec3 specular;
    float shininess;
}; 

uniform Material material;
uniform sampler2D diffuse2d;

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform Light light;

void main()
{
//	FragColor =  texture(ourTexture, texCoord);
//	FragColor = vec4( material.ambient , 1);
//	return;

	vec3 ambient = light.ambient * material.ambient;
	
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * light.diffuse * vec3(texture(diffuse2d, texCoord));

	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir) ,0.0), material.shininess);
	vec3 specular = material.specular * spec * light.specular;

	vec3 result = (ambient + diffuse + specular) * vertexColor.xyz;
	FragColor = vec4(result, 1);
}