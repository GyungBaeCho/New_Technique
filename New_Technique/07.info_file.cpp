#include "stdafx.h"

//using std::cout;
//using std::endl;
using namespace std;
//std::ofstream file;

auto BuildShader(){
	ID3D11InputLayout* pd3dInputLayout = nullptr;
	ID3D11VertexShader* pd3dVS = nullptr;
	ID3D11PixelShader* pd3dPS = nullptr;
	ID3D11ComputeShader* pd3dCS = nullptr;
	ID3D11GeometryShader* pd3dGS = nullptr;
	ID3D11DomainShader* pd3dDS = nullptr;
	ID3D11HullShader* pd3dHS = nullptr;

	return pd3dInputLayout;
}

enum class COMMAND{
	SET_TYPE,
	ADD_INGRE,
	FILE_NAME,
	FUNC_NAME,
	BEGIN,
	END,
};

enum class SHADER{
	VERTEX_SHADER,
	PIXEL_SHADER,
	COMPUTE_SHADER,
	GEOMETRY_SHADER,
	DOMAIN_SHADER,
	HULL_SHADER,
};

enum class INGREDIENT{
	POSITION,
	TEXCOORD,
	TANGENT,
	BITANGENT,
	NORMAL,
	COLOR,
};

int main(){
//	ofstream Write("../Data/Text.info");
//	Write.close();

	map<string, COMMAND> mCommand;
	mCommand["SET_TYPE"] =			COMMAND::SET_TYPE;
	mCommand["ADD_INGRE"] =			COMMAND::ADD_INGRE;
	mCommand["FILE_NAME"] =			COMMAND::FILE_NAME;
	mCommand["FUNC_NAME"] =			COMMAND::FUNC_NAME;
	mCommand["BEGIN"] =				COMMAND::BEGIN;
	mCommand["END"] =				COMMAND::END;
	
	map<string, SHADER> mShader;
	mShader["VERTEX_SHADER"] =		SHADER::VERTEX_SHADER;
	mShader["PIXEL_SHADER"] =		SHADER::PIXEL_SHADER;
	mShader["COMPUTE_SHADER"] =		SHADER::COMPUTE_SHADER;
	mShader["GEOMETRY_SHADER"] =	SHADER::GEOMETRY_SHADER;
	mShader["DOMAIN_SHADER"] =		SHADER::DOMAIN_SHADER;
	mShader["HULL_SHADER"] =		SHADER::HULL_SHADER;

	map<string, INGREDIENT> mIngredient;
	mIngredient["POSITION"] =		INGREDIENT::POSITION;
	mIngredient["TEXCOORD"] =		INGREDIENT::TEXCOORD;
	mIngredient["TANGENT"] =		INGREDIENT::TANGENT;
	mIngredient["BITANGENT"] =		INGREDIENT::BITANGENT;
	mIngredient["NORMAL"] =			INGREDIENT::NORMAL;
	mIngredient["COLOR"] =			INGREDIENT::COLOR;

	ifstream ReadFile("../Data/Text.info");
	if(ReadFile.fail()) exit(-1);

	LPCSTR sVSShaderName = NULL;
	LPCSTR sShaderModel = NULL;
	LPCWSTR pFileName = NULL;
	vector<D3D11_INPUT_ELEMENT_DESC> vpInputElement;
	UINT nSlot = 0;

	wstring wContext;
	string sContext;
	bool bQuitFlag = false;
	ReadFile >> sContext;
	while(!bQuitFlag){
		//명령어
		if(ReadFile.peek() == '#'){
			ReadFile.get();
			ReadFile >> sContext;

			switch(mCommand[sContext])
			{
			case COMMAND::SET_TYPE:
				ReadFile >> sContext;
				cout << "SET_TYPE : " << sContext << endl;
				switch(mShader[sContext]){
				case SHADER::VERTEX_SHADER:
					sShaderModel = "vs_5_0";
					break;
				case SHADER::PIXEL_SHADER:
					sShaderModel = "ps_5_0";
					break;
				case SHADER::COMPUTE_SHADER:
					sShaderModel = "cs_5_0";
					break;
				case SHADER::GEOMETRY_SHADER:
					sShaderModel = "gs_5_0";
					break;
				case SHADER::DOMAIN_SHADER:
					sShaderModel = "ds_5_0";
					break;
				case SHADER::HULL_SHADER:
					sShaderModel = "hs_5_0";
					break;
				}
				break;
			case COMMAND::ADD_INGRE:
				ReadFile >> sContext;
				switch(mIngredient[sContext]){
				case INGREDIENT::POSITION:
					cout << "POSITION" << endl;
					vpInputElement.push_back({"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0});
					break;
				case INGREDIENT::TEXCOORD:
					cout << "TEXCOORD" << endl;
					vpInputElement.push_back({"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0});
					break;
				case INGREDIENT::TANGENT:
					cout << "TANGENT" << endl;
					vpInputElement.push_back({"TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0});
					break;
				case INGREDIENT::BITANGENT:
					cout << "BITANGENT" << endl;
					vpInputElement.push_back({"BITANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0});
					break;
				case INGREDIENT::NORMAL:
					cout << "NORMAL" << endl;
					vpInputElement.push_back({"NORMAL", 0,DXGI_FORMAT_R32G32B32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 });
					break;
				case INGREDIENT::COLOR:
					cout << "COLOR" << endl;
					vpInputElement.push_back({"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, nSlot++, 0, D3D11_INPUT_PER_VERTEX_DATA, 0});
					break;
				}
				break;
			case COMMAND::FILE_NAME:
				ReadFile >> sContext;
			//	cout << sContext << endl;
				wcout << wContext << endl;
				wContext.assign(sContext.begin(), sContext.end());
				pFileName = wContext.c_str();
				break;
			case COMMAND::FUNC_NAME:
				ReadFile >> sContext;
				cout << sContext << endl;
				sVSShaderName = sContext.c_str();
				break;
			case COMMAND::END:
				cout << "Successively Imported Shader Data" << endl;
				bQuitFlag = true;
				break;
			default:
				cout << "Unknown Command!" << endl;
				bQuitFlag = true;
			}
		}
		else{
			while(ReadFile.peek() == ' ')
				ReadFile.get();
			while(ReadFile.peek() == '\n')
					ReadFile.get();
		}
	}
	ReadFile.close();

	ID3DBlob *pd3dShaderBlob = nullptr;
	ID3DBlob *pd3dErrorBlob = nullptr;

	ID3D11Device* pd3dDevice = nullptr;
	ID3D11DeviceContext* pd3dDeviceContext = nullptr;

	ID3D11InputLayout* pd3dInputLayout = nullptr;
	ID3D11VertexShader* pd3dVS = nullptr;
	ID3D11PixelShader* pd3dPS = nullptr;
	ID3D11ComputeShader* pd3dCS = nullptr;
	ID3D11GeometryShader* pd3dGS = nullptr;
	ID3D11DomainShader* pd3dDS = nullptr;
	ID3D11HullShader* pd3dHS = nullptr;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(DEBUG) || defined(_DEBUG)
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif
	HRESULT hResult = D3DX11CompileFromFile(pFileName, NULL, NULL, "VSDiffusedColor", sShaderModel, dwShaderFlags, 0, NULL, &pd3dShaderBlob, &pd3dErrorBlob, NULL);
	if(FAILED(hResult)){
	//	cout << static_cast<char*>(pd3dErrorBlob->GetBufferPointer()) << endl;
	//	pd3dErrorBlob->Release();
	//	HR(hResult);

		DXTraceA(__FILE__, (DWORD)__LINE__, hResult, NULL, true); 
		exit(-1);										   
	}

	switch(mShader[sContext]){
	case SHADER::VERTEX_SHADER:
		pd3dDevice->CreateInputLayout(vpInputElement.data(),vpInputElement.size(),pd3dShaderBlob->GetBufferPointer(),pd3dShaderBlob->GetBufferSize(), &pd3dInputLayout);
		pd3dDevice->CreateVertexShader(pd3dShaderBlob->GetBufferPointer(), pd3dShaderBlob->GetBufferSize(), NULL, &pd3dVS);
		break;
	case SHADER::PIXEL_SHADER:
		pd3dDevice->CreatePixelShader(pd3dShaderBlob->GetBufferPointer(), pd3dShaderBlob->GetBufferSize(), NULL, &pd3dPS);
		break;
	case SHADER::COMPUTE_SHADER:
		pd3dDevice->CreateComputeShader(pd3dShaderBlob ->GetBufferPointer(), pd3dShaderBlob->GetBufferSize(), NULL, &pd3dCS);
		break;
	case SHADER::GEOMETRY_SHADER:
		break;
	case SHADER::DOMAIN_SHADER:
		pd3dDevice->CreateDomainShader(pd3dShaderBlob->GetBufferPointer(), pd3dShaderBlob->GetBufferSize(), NULL, &pd3dDS);
		break;
	case SHADER::HULL_SHADER:
		pd3dDevice->CreateHullShader(pd3dShaderBlob->GetBufferPointer(), pd3dShaderBlob->GetBufferSize(), NULL, &pd3dHS);
		break;
	}

	pd3dShaderBlob->Release();
		


//	Read.ignore();
//	Read.getline(char*, int);	/**/
//	Read.gcount();				/**/
//	Read.peek();				/**/
//	Read.get();					/*가져온 하나의 문자의 Asccii 코드를 반환함*/




}
