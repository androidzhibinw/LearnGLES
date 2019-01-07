#version 300 es
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vTexCord;

out vec3 ourColor;
out vec2 texCord;
void main()
{
    gl_Position = vec4(vPosition,1.0);
    ourColor = vColor;
    texCord  = vTexCord;
}