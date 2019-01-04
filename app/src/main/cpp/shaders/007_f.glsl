#version 300 es
out vec4 fragColor;

in vec3 ourColor;
in vec2 texCord;

uniform sampler2D ourTexture;
void main()
{
    fragColor = texture(ourTexture, texCord);
}