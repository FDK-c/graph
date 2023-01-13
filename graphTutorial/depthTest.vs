#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (std140) uniform Matrices
{
    mat4 projection;
    mat4 view;
};
uniform mat4 model;

out vec3 Position;

void main()
{
    vec4 pos = projection * view * model * vec4(aPos, 1.0);
    gl_Position = pos;
    Position = vec3(model * vec4(aPos, 1.0));
    gl_PointSize = gl_Position.z;
}