#version 330 core

out vec3 FragColor;

uniform vec3 gridColor;

void main()
{
	FragColor = gridColor;
}