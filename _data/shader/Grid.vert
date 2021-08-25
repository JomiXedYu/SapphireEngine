#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 vertexColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
	
	mat4 transform = projection * view * model;

	gl_Position = transform * vec4(aPos, 1.0);

	vertexColor = aColor;
}