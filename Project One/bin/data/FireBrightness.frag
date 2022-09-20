#version 410

uniform sampler2D fireTex;

in vec2 fragUV;
out vec4 outCol;

void main() {
	vec4 tex = texture(fireTex, fragUV);
}