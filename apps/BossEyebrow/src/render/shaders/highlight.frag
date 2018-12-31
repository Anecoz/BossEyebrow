#version 410

out vec4 outColor;

uniform vec4 highlightColor;

void main() {
  outColor = highlightColor;
}