#include "bootTestObject.h"

#include"../libs/frameWork/scenemanager.h"

BootTestObject::BootTestObject(Scene* sc)
	:Object		(sc)
	,hFont{-1}
{}
BootTestObject::~BootTestObject(){
	DeleteFontToHandle(hFont);
}
void BootTestObject::Init(){
	FillMaskScreen(0);

	hFont= CreateFontToHandle("",96,-1);
	assert(hFont > 0);
}
void BootTestObject::Update(){
	
	SceneChangeKey();
}
void BootTestObject::Draw() {
	//上の説明
	std::string explanation = "";
	explanation += "今は Debug Scene \n";
	explanation += "「Space key」 で TitleScene\n";
	explanation += "「Space と LeftShift key で GameScene」\n";
	DrawFormatString(100, 50, 0xff66ff,explanation.c_str());

	//編集用の主張
	std::string str = "デバッグ用シーン";

	DrawFormatStringToHandle(400 - str.size()*GetFontSizeToHandle(hFont), 600-128, 0xffffff, hFont, str.c_str());
}

void BootTestObject::SceneChangeKey() {
	bool spaceKey	= CheckHitKey(KEY_INPUT_SPACE)||(GetMouseInput()&MOUSE_INPUT_LEFT)||CheckHitKey(KEY_INPUT_RETURN);
	bool lShiftKey	= CheckHitKey(KEY_INPUT_LSHIFT);
	
	if (spaceKey&& !lShiftKey) 
		SceneManager::SceneChange("Title");

	if (spaceKey&& lShiftKey) 
		SceneManager::SceneChange("Game");
}
