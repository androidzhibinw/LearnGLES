#version 300 es
out vec4 fragColor;

in vec3 ourColor;
in vec2 texCord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
uniform float     mixRatio;

void main()
{
    fragColor = mix(texture(ourTexture1, texCord), texture(ourTexture2, texCord), mixRatio);
}