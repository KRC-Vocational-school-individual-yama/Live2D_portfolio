#include "scene.h"
#include"object.h"

Scene::Scene(){
	objectList.clear();
	objectDrawList.clear();
	rankChange = false;
}
Scene::~Scene(){
	AllDestroy();
}

void Scene::Update(){
	for (auto it = objectList.begin(); it != objectList.end();) {
		ObjectParam& node = (*it);

		//初期化フラグが立っていれば初期化
		if (node.wantInit) {
			node.object->Init();
			node.wantInit = false;
		}

		//更新停止じゃなかったら オブジェクトの更新
		if( !node.object->GetStopUpdate())
			node.object->Update();//更新

		//破棄
		if (node.object->GetDestroy()) {
			DestroyDrawObject(node.object);

			delete node.object;
			node.object = nullptr;

			it=objectList.erase(it);
		}
		else {
			it++;
		}
	}
	if (!rankChange)return;
	objectDrawList.clear();
	objectDrawList = objectList;
	objectDrawList.sort(DispSort);//上昇順（上昇　1..2..3..
	rankChange = false;
}
void Scene::Draw(){
	//オブジェクトの描画
	for (auto& object : objectDrawList)
		object.object->Draw();
}

void Scene::Destroy(Object* object){
	for (auto it = objectList.begin(); it != objectList.end(); it++) {
		Object*& nodeObject = (*it).object;
		if (object != nodeObject)continue;

		delete nodeObject;
		nodeObject = nullptr;

		DestroyDrawObject(object);
		objectList.erase(it);

		return;
	}
}

void Scene::AllUpdateStop(){
	for (auto& it = objectList.begin(); it != objectList.end(); it++) {
		ObjectParam& node = (*it);
		node.object->SetMyUpdate(true);
	}
}

void Scene::AllUpdateStart(){
	for (auto& it = objectList.begin(); it != objectList.end(); it++) {
		ObjectParam& node = (*it);
		node.object->SetMyUpdate(false);
	}
}


void Scene::AllDestroy(){

	if (objectList.empty())
		return;
	
	//全てを削除
	for (auto it = objectList.begin(); it != objectList.end(); ) {
		Object*& object = (*it).object;
		if (nullptr != object) {
			delete object;
			it=objectList.erase(it);
		}
	}
}

void Scene::DestroyDrawObject(Object* object){
	for (auto it = objectDrawList.begin(); it != objectDrawList.end(); it++) {
		ObjectParam& node = (*it);
		if (object != node.object)continue;
		objectDrawList.erase(it);
		return;
	}
}

bool Scene::DispSort(const ObjectParam& rank1, const ObjectParam& rank2){
	return rank1.dispRank < rank2.dispRank;
}

inline std::list<Object*> Scene::Invokes(std::string name) {
	std::list<Object*> list;
	for (ObjectParam& m : objectList) {
		if (m.name != name)continue;
		Object* object = dynamic_cast<Object*>(m.object);
		list.emplace_back(object);
	}
	return list;
}

void Scene::ChangeDispRank(Object* obj, int rank) {
	for (auto& node : objectList) {
		if (obj != node.object)continue;
		node.dispRank = rank;
		rankChange = true;
		return;
	}
}