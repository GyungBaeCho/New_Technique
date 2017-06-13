#include "Define.fx"
#include "Function.fx"

//-------------------------------------------------------------------------------------------------------------------------------------디퓨즈 쉐이더
struct VS_DIFFUSED_INPUT
{
	float4 position : POSITION;
	float4 color : COLOR0;
};

struct VS_DIFFUSED_OUTPUT
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float4 color : COLOR0;
};


//디퓨즈 색상 정점 쉐이더
VS_DIFFUSED_OUTPUT VSDiffusedColor(VS_DIFFUSED_INPUT input)
{
    VS_DIFFUSED_OUTPUT output = (VS_DIFFUSED_OUTPUT)0;
	
	output.positionW = mul(input.position, gmtxWorld).xyz;
	output.position = mul(float4(output.positionW, 1), gmtxVP);

    output.color = input.color;
//	output.color = Fog(output.color, output.positionW);
//	output.color = GreyTone(output.color);

    return output;
}

float4 PSDiffusedColor(VS_DIFFUSED_OUTPUT input) : SV_Target
{
//	input.color = Fog(input.color, input.positionW);
	return input.color;
}

PS_MULTIPLE_RENDER_OUTPUT M_PS(VS_DIFFUSED_OUTPUT input) : SV_Target
{
	PS_MULTIPLE_RENDER_OUTPUT output = (PS_MULTIPLE_RENDER_OUTPUT) 0;
	output.color = input.color;
	output.color.a = 0;
	
	float fDepth = input.position.z / input.position.w;
	output.normal = float4(1, 1, 1, fDepth);
	float fSpecular = 1.0f;
	output.position = float4(input.positionW, fSpecular);

	return output;
}


//-------------------------------------------------------------------------------------------------------------------------------------디퓨즈 인스턴싱 쉐이더
struct VS_INSTANCED_DIFFUSED_INPUT
{
    float3 position : POSITION;
    float4 color : COLOR0;
    column_major float4x4 mtxTransform : INSTANCE_MTX;
};

struct VS_INSTANCED_DIFFUSED_OUTPUT
{
    float4 position : SV_POSITION;
    float4 color : COLOR1;
	float3 positionW : POSITION;
//시스템 생성 변수로 정점 쉐이더에 전달되는 객체 인스턴스의 ID를 픽셀 쉐이더로 전달한다.
//	float4 instanceID : INDEX0;
};

//인스턴싱을 하면서 정점이 랜덤한 색상을 갖는 경우 정점 쉐이더의 입력을 위한 구조체이다.
struct VS_MTX_FLT4{
	column_major float4x4 mtxTransform : INSTANCE_MTX;
    float4 instanceColor : INSTANCECOLOR;
};


VS_INSTANCED_DIFFUSED_OUTPUT VSInstancedDiffusedColor(VS_INSTANCED_DIFFUSED_INPUT input)
{
    VS_INSTANCED_DIFFUSED_OUTPUT output = (VS_INSTANCED_DIFFUSED_OUTPUT)1;
	
	output.positionW = mul(float4(input.position, 1), input.mtxTransform).xyz;
	output.position = mul(float4(output.positionW, 1), gmtxVP);
	output.color = input.color;
	output.color = Fog(output.color, output.positionW);
//	output.color = GreyTone(output.color);
//	output.color.a = 1;
    return output;
}

float4 PSInstancedDiffusedColor(VS_INSTANCED_DIFFUSED_OUTPUT input) : SV_Target
{
	return input.color;
}

//-------------------------------------------------------------------------------------------------------------------------------------디퓨즈 인스턴싱 랜덤 쉐이더
struct VS_INSTANCED_DIFFUSED_RANDOM_INPUT
{
    float3 position : POSITION;
    float4 color : COLOR0;
	VS_MTX_FLT4 transform_color;
//    column_major float4x4 mtxTransform : INSTANCE_MTX;
//    float4 instanceColor : INSTANCECOLOR;
};

struct VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT
{
    float4 position : SV_POSITION;
	float3 positionW : POSITION;
    float4 color : COLOR1;

};

VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT VSInstancedDiffusedRandomColor(VS_INSTANCED_DIFFUSED_RANDOM_INPUT input)
{
    VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT output = (VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT)0;
	
	output.position = mul(mul(float4(input.position, 1), input.transform_color.mtxTransform), gmtxVP);
	output.positionW = mul(float4(input.position, 1.0f), input.transform_color.mtxTransform).xyz;
	output.color = input.transform_color.instanceColor;  
//	output.color = GreyTone(output.color);
	output.color = Fog(output.color, output.positionW);

	return output;
}

float4 PSInstancedDiffusedRandomColor(VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT input) : SV_Target
{
	return input.color;

	input.color = Fog(input.color, input.positionW);

	return input.color;
}