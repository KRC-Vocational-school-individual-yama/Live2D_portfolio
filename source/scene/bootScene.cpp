#include "bootScene.h"

#include"../object/bootTestObject.h"



BootScene::BootScene() {
	Create<BootTestObject>();

//	SceneManager::GetCommonScene()->Create<Debug>();
}
BootScene::~BootScene(){
}

