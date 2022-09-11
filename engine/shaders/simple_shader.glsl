#version 450

#ifdef VERTEX

#pragma shader_stage(vertex)

vec2 position[3] = vec2[] (
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5, 0.5)
);

void main()
{
    gl_Position = vec4(position[gl_VertexIndex], 0.0, 1.0);
}

#else

#pragma shader_stage(fragment)

layout (location = 0) out vec4 outColor;
void main()
{
    outColor = vec4(1.0, 0.0, 0.0, 1.0);
}

#endif
