#version 300 es
precision highp float;
out vec4 fragColor;

uniform vec3 lightPos;
uniform vec3 viewPos;
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

    //specular
    float specStrangth = 0.5;
    vec3 viewDir = normalize(viewPos - vWorldPos);
    vec3 reflectDir = reflect(-lightDir, vNorm);
    float value = max(dot(viewDir, reflectDir), 0.0);
    float spec = pow(value, 32.0f);
    vec3 specular = specStrangth * spec * lightColor;

    fragColor = vec4((diffuse + abmient + specular) * cubeColor, 1.0);
}