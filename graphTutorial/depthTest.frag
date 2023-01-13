#version 330 core
out vec4 FragColor;

in vec3 Position;
in vec3 Normal;

void main()
{    
    FragColor = vec4(252/255f, 218/255f, 252/255f, 0.5f); 
}