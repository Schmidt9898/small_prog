#version 400 core
out vec4 FragColor;
in vec3 ourcolor;
uniform vec3 unicolor;

void main() {
    FragColor = vec4(ourcolor-unicolor, 1.0);
}
