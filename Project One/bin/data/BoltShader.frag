#version 410

uniform sampler2D BoltText;

uniform float opacity;
in vec2 fragUV;
out vec4 outCol;
void main()
{
	vec4 tex = texture(BoltText, fragUV) * (opacity * 1.4);

	tex.r *= 0.7f;
	tex.g *= 0.5f;
	tex.b *= 1.0f;

	outCol = tex;
}