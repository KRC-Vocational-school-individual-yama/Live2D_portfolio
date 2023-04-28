#include "object.h"
#include"component.h"

namespace {

}

Object::Object(Scene* sc)
	:myScene(sc)
	, myDestroy(false)
	, myStopUpdate(false)
	,comPonentList()
{
	//Component* com;
	//Create<Component>();
}

Object::~Object(){

	for (auto& aCom : comPonentList) {
		if(aCom.myComponent)
			delete aCom.myComponent;
		aCom.myComponent = nullptr;
	}
}

void Object::Init(){





	if (comPonentList.empty())
		return;

	for (auto& aCom : comPonentList) {
		aCom.myComponent->Init();
		aCom.wantInit = false;
	}
}

void Object::Update() {
	if (comPonentList.empty())
		return;

	for (auto& aCom : comPonentList) {
		if (aCom.wantInit) {
			aCom.myComponent->Init();
		}


		aCom.myComponent->Update();
	}
}

void Object::Draw() {
	if (comPonentList.empty())
		return;

	for (auto& aCom : comPonentList) {
		aCom.myComponent->Draw();
	}
}

inline void Object::SetComponent(Component* setComponent){
	if (!setComponent)
		return;
	
	ComponentParam send;
	send.myComponent = setComponent;

	comPonentList.emplace_back(send);
}
