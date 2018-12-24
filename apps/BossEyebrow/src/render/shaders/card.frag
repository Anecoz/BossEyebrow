#version 410

uniform sampler2D tex;

in vec2 f_uvs;
out vec4 outColor;

void main() {
  outColor = texture(tex, f_uvs);
}