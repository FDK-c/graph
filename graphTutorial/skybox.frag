#version 330 core
out vec4 FragColor;

in vec3 TexCoords;
in vec3 Normal;

uniform samplerCube skybox;

void main()
{    
    
    FragColor = texture(skybox, TexCoords);
}