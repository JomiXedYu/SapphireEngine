#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 PROJECTION;
uniform mat4 VIEW;
uniform mat4 MODEL;

void main() {
	mat4 transform = PROJECTION * VIEW * MODEL;
	gl_Position = transform * vec4(aPos, 1.0);
}