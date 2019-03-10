//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

struct PSInput
{
    float4 position    : SV_POSITION;
	float4 color : COLOR;
};

Texture2D        g_txDiffuse : register(t0);
SamplerState    g_sampler : register(s0);

float4 PSMain(PSInput input) : SV_TARGET
{
    //float3 color = g_txDiffuse.Sample(g_sampler, input.uv).rgb;

    // Reduce R and B contributions to the output color.
    float4 filter = float4(0.25f, 1.0f, 0.25f, 1.0f);

	return input.color * filter;
}
