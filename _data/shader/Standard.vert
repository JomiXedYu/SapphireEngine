#version 330 core
layout(location = 0) in vec3 aPos;
//layout(location = 1) in vec4 aColor;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

//out vec4 vertexColor;
out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
	
	mat4 transform = projection * view * model;

	gl_Position = transform * vec4(aPos, 1.0);

//	vertexColor = aColor;
	texCoord = aTexCoord;
	normal = mat3(transpose(inverse(model))) * aNormal;
	//normal = aNormal;
	// fragPos = vec3(model * vec4(aPos, 1.0)); 
    fragPos = vec3(model * vec4(aPos, 1.0));
}