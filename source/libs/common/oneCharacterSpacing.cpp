#include "oneCharacterSpacing.h"

namespace {
	const int FirstDispSpeed = 5;//秒間何文字
}

OneCharacterSpacing::OneCharacterSpacing()
	:myWStr{L""}
	,count{0}
	,dispSpeed{FirstDispSpeed}
	,hFont{-1}
{
}
//
//OneCharacterSpacing::~OneCharacterSpacing(){
//
//}
//
//void OneCharacterSpacing::Init(){
//
//}

void OneCharacterSpacing::Update(){
	if(count<GetSize())
	count += dispSpeed;

}

void OneCharacterSpacing::Draw(float x,float y,int color){
	std::string disp = WStringToString(myWStr.substr(0, static_cast<unsigned int>(count)));
	if (hFont > 0)
		DrawStringFToHandle(x, y, disp.c_str(), color, hFont);
	else
		DrawStringF(x,y,disp.c_str(),color);
}

void OneCharacterSpacing::SetStr(std::string str){
	count = 0;
	myWStr= StringToWString(str);
}

int OneCharacterSpacing::GetSize(){
	
	return myWStr.size();
}

bool OneCharacterSpacing::GetAllDisp(){
	return myWStr.size()<=count;
}

void OneCharacterSpacing::AllDisp(){
	count= static_cast<float>(myWStr.size());
}



std::string OneCharacterSpacing::WStringToString(std::wstring oWString)
{
	// wstring → SJIS
	int iBufferSize = WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str()
		, -1, (char*)NULL, 0, NULL, NULL);
	// バッファの取得
	CHAR* cpMultiByte = new CHAR[iBufferSize];
	// wstring → SJIS
	WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str(), -1, cpMultiByte
		, iBufferSize, NULL, NULL);
	// stringの生成
	std::string oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);
	// バッファの破棄
	delete[] cpMultiByte;
	// 変換結果を返す
	return(oRet);
}
std::wstring OneCharacterSpacing::StringToWString(std::string oString)
{
	//  SJIS→wstring
	std::wstring ws;
	int iBufferSize = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, oString.c_str()
		, -1, (wchar_t*)NULL, 0);

	// バッファの取得
	wchar_t* cpMultiByte = new wchar_t[iBufferSize];
	// wstring → SJIS
	MultiByteToWideChar(CP_ACP, 0, oString.c_str(), -1, cpMultiByte
		, iBufferSize);
	// wstringの生成
	std::wstring oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);
	// バッファの破棄
	delete[] cpMultiByte;
	// 変換結果を返す
	return(oRet);
}