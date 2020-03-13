#version 400 core
out vec4 FragColor;
uniform vec3 unicolor;

void main() {
    FragColor = vec4(unicolor, 1.0);
}
