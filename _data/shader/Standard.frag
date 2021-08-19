#version 330 core
in vec4 vertexColor;
in vec2 texCoord;
in vec3 normal;
in vec3 fragPos;

out vec4 FragColor;

uniform mat4 view;

uniform sampler2D ourTexture;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
//	FragColor =  texture(ourTexture, texCoord);
	vec3 _lightColor = lightColor.xyz;
	vec3 ambient = 0.1 * _lightColor;
	
	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(lightPos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * _lightColor;
	
	float specularStrength = 0.6;
	vec3 viewDir = normalize(viewPos - fragPos);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(viewDir, reflectDir) ,0.0), 256);
	vec3 specular = specularStrength * spec * _lightColor;

	vec3 result = (ambient + diffuse + specular) * vertexColor.xyz;
	FragColor = vec4(result, 1);
}