#version 300 es
precision highp float;
out vec4 fragColor;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform vec3 viewPos;
uniform Material material;
uniform Light    light;

in vec3 vWorldPos;
in vec3 vNorm;



void main()
{
    //ambient
   
    vec3  abmient       = light.ambient * material.ambient;

    //diffuse
    vec3 normal     = normalize(vNorm);
    vec3 lightDir   = normalize(light.position - vWorldPos);
    float diffRatio = max(dot(normal, lightDir), 0.0);
    vec3 diffuse    = light.diffuse * (diffRatio * material.diffuse);

    //specular
    vec3 viewDir = normalize(viewPos - vWorldPos);
    vec3 reflectDir = reflect(-lightDir, vNorm);
    float value = max(dot(viewDir, reflectDir), 0.0);
    float spec = pow(value, material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    fragColor = vec4((abmient + diffuse + specular), 1.0);
}