#include "scenechanger.h"

#include<Windows.h>
//#include<cassert>

#include"../../scene/bootScene.h"
#include"../../scene/titlescene.h"
#include"../../scene/gamescene.h"


Scene* SceneChanger::Changer(std::string scene) {
	if		(scene == "boot")		return new BootScene()		;//デバッグ用
	else if	(scene == "Title")		return new TitleScene()		;//タイトル
	else if (scene == "Game")		return new GameScene()		;//ゲーム
	else {
		MessageBox(NULL, ("次のシーンはありません\n" + scene+"\n"+"無視を押すと続行できます").c_str(), "SceneFactory", MB_ICONERROR | MB_OK);
		//assert(false);
		return nullptr;
	}

}
