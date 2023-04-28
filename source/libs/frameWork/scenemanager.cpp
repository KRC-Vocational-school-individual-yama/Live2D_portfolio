#include"scenemanager.h"

#include"scenechanger.h"
#include"../../object/titleobject.h"

namespace {
	std::string scene		;//現在シーン名
	std::string nextScene	;//次のシーン名
	
	SceneChanger* changer	;//シーン切り替え

	Scene* game				;//現在のシーン
	Scene* commonGame		;//保存用シーン

	int frameCount			;//カウンター
	bool gameEndflag		;//ゲーム終了のフラグ
}

namespace SceneManager {

	void Init() {
		changer		= new SceneChanger();
		game		= nullptr;
		commonGame	= new Scene();
		scene		= "";
		frameCount	= 0;
		gameEndflag = false;
#ifdef _DEBUG
		nextScene	= "boot";
#else 
		nextScene	= "Title";
#endif 
	}

	void Update() {
		frameCount++;

		//シーンの入れ替え
		if (nextScene != scene) {
			if(game!=nullptr)
			delete game;
			game = dynamic_cast<Scene*>(changer->Changer(nextScene));
			scene = nextScene;
		}

		//それぞれの更新
		game->Update();
		commonGame->Update();
	}

	void Draw() {
		game->Draw();
		commonGame->Draw();
	}

	void Delete() {
		delete game;
		delete changer;
		delete commonGame;
	}



	void SceneChange(std::string sceneName){
		nextScene = sceneName;
	}

	int GetFrame() {
		return frameCount;
	}

	bool GameEnd() {
		if (gameEndflag)
			return true;

		if (scene == "Title") {
			TitleObject* titleObject= game->Invoke<TitleObject>();
			if (titleObject == nullptr)
				return false;

			if (titleObject->EndKeyInput())
				return true;
		}
		return false;
	}
	void SetGameEnd() {
		gameEndflag = true;
	}
	Scene* GetCommonScene() {
		return commonGame;
	}
	Scene* GetCurrentScene(){
		return game;
	}
	std::string GetCurrentSceneName(){
		return scene;
	}

	//float GetDeltaTime() {
	//	return time->GetDeltTime();
	//}
}