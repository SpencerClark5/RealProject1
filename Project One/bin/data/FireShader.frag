#version 410

uniform sampler2D FireTex;


in vec2 fragUV;
out vec4 outCol;
void main()
{
	outCol = texture(FireTex, fragUV);
}