#version 300 es
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
out vec3 myColor;
void main()
{
    gl_Position = vec4(vPosition,1.0);
    myColor     = vColor;
}