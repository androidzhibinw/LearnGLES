#version 300 es
precision highp float;
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec2 vTexCord;

out vec2 texCord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
    gl_Position = projection * view * model * vec4(vPosition,1.0);
    texCord  = vTexCord;
}