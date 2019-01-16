#version 300 es
precision highp float;
out vec4 fragColor;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 cubeColor;

in vec3 vWorldPos;
in vec3 vNorm;

void main()
{
    //ambient
    float ambientLength = 0.1;
    vec3  abmient       = ambientLength * lightColor;

    //diffuse
    vec3 normal     = normalize(vNorm);
    vec3 lightDir   = normalize(lightPos - vWorldPos);
    float diffRatio = max(dot(normal, lightDir), 0.0);
    vec3 diffuse    = diffRatio * lightColor;

    fragColor = vec4((diffuse + abmient) * cubeColor, 1.0);
}