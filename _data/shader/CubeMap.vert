#version 330 core
layout(location = 0) in vec3 aPos;

out vec3 texCoord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    texCoord = aPos;
    gl_Position = projection * view * vec4(aPos, 1);
}