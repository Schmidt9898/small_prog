#version 400 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0

layout (location = 1) in vec3 aColor;

out vec3 ourcolor;

uniform mat4 trans;

void main() {
    gl_Position =  trans * vec4(aPos, 1.0);
	ourcolor = aColor;
}
