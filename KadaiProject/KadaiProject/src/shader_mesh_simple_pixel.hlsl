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
    return input.color;
}
