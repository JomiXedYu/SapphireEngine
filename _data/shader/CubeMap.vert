#version 330 core
layout(location = 0) in vec3 aPos;

out vec3 texCoord;

uniform mat4 PROJECTION;
uniform mat4 VIEW;
uniform mat4 MODEL;

void main()
{
    texCoord = aPos;
    gl_Position = PROJECTION * VIEW * vec4(aPos, 1);
}