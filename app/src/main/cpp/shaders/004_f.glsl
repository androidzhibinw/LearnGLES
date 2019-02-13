#version 300 es
in vec3 myColor;
out vec4 fragColor;
void main()
{
    fragColor = vec4(myColor, 1.0);
}