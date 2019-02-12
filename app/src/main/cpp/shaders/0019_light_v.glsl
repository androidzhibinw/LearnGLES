#version 300 es
precision highp float;
layout (location = 0) in vec3 vPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
    gl_Position = projection * view * model * vec4(vPosition,1.0);
}
