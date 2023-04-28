#include "titleSceneChange.h"

#include"../libs/frameWork/scenemanager.h"
#include"../libs/common/keyManager.h"

namespace {
	KeyManager* keys=nullptr;
}

TitleSceneChange::TitleSceneChange(Object* obj)
	:Component(obj)
	,keystop{true}
	,mouseInput{false}
{
}

TitleSceneChange::~TitleSceneChange()
{
}

void TitleSceneChange::Init()
{
	keys = new KeyManager();
	std::vector<int>keyNumberList;
	keyNumberList.reserve(10);
	keyNumberList.emplace_back(KEY_INPUT_SPACE);
	keyNumberList.emplace_back(KEY_INPUT_RETURN);
	keyNumberList.emplace_back(KEY_INPUT_TAB);
	keyNumberList.emplace_back(KEY_INPUT_ESCAPE);
	keyNumberList.shrink_to_fit();
	keys->SetKey(keyNumberList);

}

void TitleSceneChange::Update(){
	bool mouse = GetMouseInput() & MOUSE_INPUT_LEFT;
	mouseInput = mouse && !keystop;
	keystop = mouse;

	if (mouseInput || keys->Down(KEY_INPUT_SPACE)) {
		SceneManager::SceneChange("Game");
	}

}

void TitleSceneChange::Draw()
{
}

bool TitleSceneChange::TitleGameEnd(){
	return keys->Down(KEY_INPUT_ESCAPE);
}
