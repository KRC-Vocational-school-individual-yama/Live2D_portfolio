#include "titleobject.h"

#include"../component/titleSceneChange.h"
#include"../component/titleName.h"



TitleObject::TitleObject(Scene* sc)
	:Object				(sc)
{
	Create<TitleSceneChange>();
	Create<TitleName>();
}

TitleObject::~TitleObject(){

}

bool TitleObject::EndKeyInput(){
	TitleSceneChange* sceneChange= Invoke<TitleSceneChange>();

	return sceneChange->TitleGameEnd();
}
