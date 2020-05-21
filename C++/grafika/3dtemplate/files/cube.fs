#version 400 core

out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D texture;
//uniform sampler2D texture2;

void main() {
    FragColor =  texture(texture, TexCoord);
}