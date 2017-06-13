#include "stdafx.h"
#include "Function_Tool.h"
#include <bitset>

#define BIT_SIZE(x)	sizeof(x) * 8
#define _I(x)	static_cast<UINT>(x)

enum EShader {
	Illuminated = 1,
};

enum class EDpthStnclState : unsigned int{
	NONE,
	NO_DEPTH_TEST,
	NO_WRITE,
	GRT_EQUAL,
	TEST,
};

enum class ERstrzrState : unsigned int {
	NONE,
	WIRE_NONE,
	WIRE_B_CULL,
	WIRE_F_CULL,
	SOLID_NONE,
	SOLID_B_CULL,
	SOLID_F_CULL,
	A,
	B,
};

enum class EBlndState : unsigned int {
	NONE,
	ONE_BLEND,
	SRC_BLEND,
	SRC_BLEND2,
	ENABLE_BLEND_ALPHA,
	ALPHA_COVERAGE,
	ALPHA_COVARAGE_ALPHA_BLENDING,
};

class CShader {
public:

	void SetToDevice() {}
};

class CModelHomo;



typedef pair<CModelHomo*, XMFLOAT4X4> RenderData;

class CRenderer {
public:
	UINT					m_tRenderer;

	CShader					*m_pShader;
	ID3D11RasterizerState	*m_pRstrzrState;
	ID3D11DepthStencilState *m_pDpthStnclState;
	ID3D11BlendState		*m_pBlndState;

	vector<RenderData>		m_vecRenderData;

	void Render() {
		if(m_pShader)
			m_pShader->SetToDevice();
		if(m_pRstrzrState)
			m_pRstrzrState;
		if(m_pDpthStnclState)
			m_pDpthStnclState;
		if (m_pBlndState)
			m_pBlndState;;

		const auto &end = m_vecRenderData.end();
		for (auto pivot = m_vecRenderData.begin() ; pivot!=end ; ++pivot) {
			pivot->first;
			pivot->second;
		}
	}
};

class CModel {
public:
	EShader				m_eShader;
	EDpthStnclState		m_eDpthStnclStt;
	ERstrzrState		m_eRstrzrStt;
	EBlndState			m_eBlndStt;

	bool			m_bBlend = false;
	bool			m_bShadow = false;

	UINT			m_tRenderer = 0;

	void CalRendererType() {
		m_tRenderer = 0;

		__int64 nPlaceValue = 1;

		m_tRenderer += _I(m_eShader) * nPlaceValue;
		nPlaceValue *= 1000;

		m_tRenderer += _I(m_eDpthStnclStt) * nPlaceValue;
		nPlaceValue *= 100;

		m_tRenderer += _I(m_eRstrzrStt) * nPlaceValue;
		nPlaceValue *= 100;

		m_tRenderer += _I(m_eBlndStt) * nPlaceValue;
		nPlaceValue *= 10;

		m_tRenderer += _I(m_bBlend) * nPlaceValue;
		nPlaceValue *= 10;

		m_tRenderer += _I(m_bShadow) * nPlaceValue;
		nPlaceValue *= 10;

		//m_tRenderer <<= 1;
		//m_tRenderer += _I(m_eDpthStnclStt);
		//m_tRenderer <<= 2;
		//m_tRenderer += _I(m_eRstrzrStt);
		//m_tRenderer <<= 3;
		//m_tRenderer += _I(m_eBlndStt);
		//m_tRenderer <<= 4;
		//m_tRenderer += _I(m_bBlend);
		//m_tRenderer <<= 5;
		//m_tRenderer += _I(m_bShadow);
	}
};

//template<class T>
//struct COMPARE : public binary_function<T, T, bool> {
//	bool operator()(const T& data1, const T& data2)const {
//		return data1->m_tRenderer < data2->m_tRenderer;
//	}
//};
//
//typedef set<CModelHomo*, COMPARE<CModel*>> SSet;

class CModelHomo {
public:
	UINT				m_tRenderer;
	CRenderer			*m_pRenderer;
	vector<CModel*>		m_vpHomoModel;

	void Release() {
		delete this;
	}

	void AddModel(CModel* pModel) {
		m_vpHomoModel.push_back(pModel);
	}

	void Render() {
		const auto &end = m_vpHomoModel.end();
		for (auto& pivot = m_vpHomoModel.begin(); pivot != end; ++pivot) {
			(*pivot);
		}
	}
};

class CModelAssembly {
public:
	vector<CModel*>			m_lpModel;
	vector<CModelHomo*>		m_lpModelHomo;

	void AddModel(CModel* pModel) {
		m_lpModel.push_back(pModel);
	}

	void CreateModelHomo() {
		ReleaseModelHomo();

		for (CModel *pModel : m_lpModel) {
			bool bFlag = false;
			for (CModelHomo* pModelHomo : m_lpModelHomo) {
				if (pModelHomo->m_tRenderer == pModel->m_tRenderer) {
					pModelHomo->AddModel(pModel);
					bFlag = true;
					break;
				}
			}
			if (bFlag == false) {
				CModelHomo* pModelHomo = new CModelHomo;
				pModelHomo->AddModel(pModel);
				pModelHomo->m_tRenderer = pModel->m_tRenderer;

				//여기서 Renderer를 검색하여 ModelHomo에 추가해주는 작업이 필요하고
				//만일 없다면 생성해야 한다.
				pModelHomo->m_pRenderer;
				m_lpModelHomo.push_back(pModelHomo);
			}
		}
	}

	void ReleaseModelHomo() {
		for (CModelHomo *pModelHomo : m_lpModelHomo) {
			if(pModelHomo) pModelHomo->Release();
		}
		m_lpModelHomo.clear();
	}

	void PrintInfo() {
		cout << "Model List" << endl;
		for (CModel *pModel : m_lpModel)
			cout << pModel->m_tRenderer << endl;
		cout << endl;

		cout << "ModelHomo List" << endl;
		for (CModelHomo* pModelHomo : m_lpModelHomo) {
			cout << pModelHomo->m_tRenderer << " : " << pModelHomo->m_vpHomoModel.size() << endl;
		}
	}
};

int main() {
	map<string, int> mapNum;
	try {
		mapNum.at("zzz");
	}
	catch (runtime_error) {
		cout << "runtime_error" << endl;
	}
	catch (out_of_range){
		cout << "out_of_range" << endl;
	}
	catch (...) {
		cout << "..." << endl;
	}

	int num = 12345;
	int nPlaceValue = 1;

	cout << "1의 자리 : " << (num % (nPlaceValue * 10)) / nPlaceValue << endl;

	nPlaceValue *= 10;
	cout << "10의 자리 : " << (num % (nPlaceValue * 10)) / nPlaceValue << endl;

	nPlaceValue *= 10;
	cout << "100의 자리 : " << (num % (nPlaceValue * 10)) / nPlaceValue << endl;

	nPlaceValue *= 10;
	cout << "1000의 자리 : " << (num % (nPlaceValue * 10)) / nPlaceValue << endl;

	nPlaceValue *= 10;
	cout << "10000의 자리 : " << (num % (nPlaceValue * 10)) / nPlaceValue << endl;


	nPlaceValue = 1;
	cout << "1, 2 : " << (num % (nPlaceValue * 100)) / nPlaceValue << endl;

	nPlaceValue *= 100;
	cout << "3, 4 : " << (num % (nPlaceValue * 100)) / nPlaceValue << endl;

	nPlaceValue *= 100;
	cout << "5, 6 : " << (num % (nPlaceValue * 100)) / nPlaceValue << endl;


	CModelAssembly modelAssmbly;

	CModel *pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::TEST;
	pModel->m_eRstrzrStt = ERstrzrState::SOLID_NONE;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = false;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	//-------------------------------------------------------
	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::SOLID_NONE;
	pModel->m_eBlndStt = EBlndState::ENABLE_BLEND_ALPHA;
	pModel->m_bBlend = false;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	//-------------------------------------------------------
	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = false;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = false;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = false;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	//-------------------------------------------------------
	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = false;
	pModel->m_bShadow = false;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	//-------------------------------------------------------
	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = true;
	pModel->m_bShadow = false;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = true;
	pModel->m_bShadow = false;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = true;
	pModel->m_bShadow = false;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	//-------------------------------------------------------
	pModel = new CModel;
	pModel->m_eShader = EShader::Illuminated;
	pModel->m_eDpthStnclStt = EDpthStnclState::NO_WRITE;
	pModel->m_eRstrzrStt = ERstrzrState::B;
	pModel->m_eBlndStt = EBlndState::ALPHA_COVERAGE;
	pModel->m_bBlend = true;
	pModel->m_bShadow = true;
	pModel->CalRendererType();
	modelAssmbly.AddModel(pModel);

	modelAssmbly.CreateModelHomo();
	modelAssmbly.PrintInfo();
}
