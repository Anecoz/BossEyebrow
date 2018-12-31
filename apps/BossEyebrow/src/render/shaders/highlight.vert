#version 410

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inUvs;

uniform mat4 modelMatrix;
uniform mat4 projMatrix;

void main() {
  gl_Position = projMatrix * modelMatrix * vec4(inPosition, 1.0);
}