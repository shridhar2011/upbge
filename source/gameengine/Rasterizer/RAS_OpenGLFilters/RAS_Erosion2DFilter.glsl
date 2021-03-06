uniform sampler2D bgl_RenderedTexture;
uniform vec2 bgl_TextureCoordinateOffset[9];
in vec4 bgl_TexCoord;
out vec4 fragColor;

void main(void)
{
  vec4 sample[9];
  vec4 minValue = vec4(1.0);

  for (int i = 0; i < 9; i++) {
    sample[i] = texture(bgl_RenderedTexture, bgl_TexCoord.xy + bgl_TextureCoordinateOffset[i]);
    minValue = min(sample[i], minValue);
  }

  fragColor = minValue;
}
