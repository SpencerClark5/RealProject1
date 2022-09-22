#version 410

uniform sampler2D FireTex;

uniform float opacity;
in vec2 fragUV;
out vec4 outCol;
void main()
{
	vec4 tex = texture(FireTex, fragUV);

	tex.r *= 0.5f;
	tex.g *= 0.55f;
	tex.b *= 0.6f;
	//tex.a *= .1f;

	outCol = tex;
}