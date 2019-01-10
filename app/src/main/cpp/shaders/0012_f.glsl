#version 300 es
precision highp float;
out vec4 fragColor;

in vec2 texCord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main()
{
    fragColor = mix(texture(ourTexture1, texCord), texture(ourTexture2, texCord), 0.5);
}