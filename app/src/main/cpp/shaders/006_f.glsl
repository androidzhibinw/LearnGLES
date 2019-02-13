#version 300 es
out vec4 fragColor;
in vec3 fragmentColor;
void main()
{
    fragColor = fragmentColor;
}