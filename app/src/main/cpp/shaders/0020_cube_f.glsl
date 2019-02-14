#version 300 es
precision highp float;
out vec4 fragColor;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float     shininess;
};

struct Light
{
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform vec3 viewPos;
uniform Material material;
uniform Light    light;

in vec3 vWorldPos;
in vec3 vNorm;
in vec2 vTex;

void main()
{
    //ambient
   
    vec3  abmient       = light.ambient * texture(material.diffuse, vTex).rgb;

    //diffuse
    vec3 normal     = normalize(vNorm);
    vec3 lightDir   = normalize(-light.direction);
    float diffRatio = max(dot(normal, lightDir), 0.0);
    vec3 diffuse    = light.diffuse * (diffRatio * texture(material.diffuse, vTex).rgb);

    //specular
    vec3 viewDir = normalize(viewPos - vWorldPos);
    vec3 reflectDir = reflect(-lightDir, vNorm);
    float value = max(dot(viewDir, reflectDir), 0.0);
    float spec = pow(value, 64.0f);//material.shininess not work on MI 5
    vec3 specular = light.specular * (spec * vec3(texture(material.specular, vTex).rgb));

    fragColor = vec4((abmient + diffuse + specular), 1.0);
}