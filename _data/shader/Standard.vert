#version 330 core
layout(location = 0) in vec3 aPos;
//layout(location = 1) in vec4 aColor;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

//out vec4 vertexColor;
out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;

uniform mat4 PROJECTION;
uniform mat4 VIEW;
uniform mat4 MODEL;

void main() {
	
	mat4 transform = PROJECTION * VIEW * MODEL;

	gl_Position = transform * vec4(aPos, 1.0);

//	vertexColor = aColor;
	texCoord = aTexCoord;
	normal = mat3(transpose(inverse(MODEL))) * aNormal;
	//normal = aNormal;
	// fragPos = vec3(model * vec4(aPos, 1.0)); 
    fragPos = vec3(MODEL * vec4(aPos, 1.0));
}