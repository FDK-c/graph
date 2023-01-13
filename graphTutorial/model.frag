#version 330 core
out vec4 FragColor;

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_height1;
uniform samplerCube skyBox;
uniform float currentFrame;
uniform vec3 cameraPos;

void main()
{    
    vec3 I = normalize(Position - cameraPos);
    vec3 R = refract(I, normalize(Normal), 0.658);
//  FragColor = vec4(texture(texture_diffuse2, R).rgb, 1.0);
//  FragColor = vec4(texture(texture_diffuse1, TexCoords));
    float value = abs(sin(currentFrame));
    FragColor = mix(texture(skyBox, R), texture(texture_diffuse1, TexCoords), 1);  
}