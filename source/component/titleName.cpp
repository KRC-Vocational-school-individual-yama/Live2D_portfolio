#include "titleName.h"

TitleName::TitleName(Object* obj)
	:Component(obj)
	,hFont{-1}
{}

TitleName::~TitleName(){
	DeleteFontToHandle(hFont);

}

void TitleName::Init(){
	hFont = CreateFontToHandle("",64,-1);
	assert(hFont > 0);

}

void TitleName::Update(){

}

void TitleName::Draw(){

	DrawFormatStringToHandle(200,200,0x7fbfff, hFont, u8"Title");

	DrawFormatString(300,400,0x1,"スペースキー,エンター,マウス左を押してGameScene");

}
