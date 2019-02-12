#version 300 es
precision highp float;
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoords;

out vec3 vWorldPos;
out vec3 vNorm;
out vec2 vTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
    vNorm = (model * vec4(vNormal, 1.0)).xyz;
    vWorldPos = (model * vec4(vPosition, 1.0)).xyz;
    vTex = vTexCoords;
    gl_Position = projection * view * vec4(vWorldPos,1.0);
}
