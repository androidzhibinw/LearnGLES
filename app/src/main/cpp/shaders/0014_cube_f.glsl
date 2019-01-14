#version 300 es
precision highp float;
out vec4 fragColor;

uniform vec3 lightColor;
uniform vec3 cubeColor;

void main()
{
    fragColor = vec4(lightColor * cubeColor, 1.0);
}