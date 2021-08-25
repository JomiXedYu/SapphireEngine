#version 330 core

in vec4 vertexColor;
out vec3 FragColor;

void main()
{
	FragColor = vertexColor.xyz;
}