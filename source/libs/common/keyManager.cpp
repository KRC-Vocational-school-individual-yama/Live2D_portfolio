#include "keyManager.h"

#include"../frameWork/myDxLib.h"

#include"keyBoard.h"

KeyManager::KeyManager()
{}

KeyManager::~KeyManager(){
	//if (keys.empty())
	//	return;
	//for (auto& key : keys)
	//	delete key.second;
}

bool KeyManager::Down(int keyNumber){
	SetKey(keyNumber);
	return keys[keyNumber]->KeyDown();
}

bool KeyManager::DownKeep(int keyNumber){
	SetKey(keyNumber);
	return keys[keyNumber]->KeyDownKeep();
}

bool KeyManager::Up(int keyNumber){
	SetKey(keyNumber);
	return keys[keyNumber]->KeyUp();
}

void KeyManager::SetKey(int keyNumber) {
	/*if (keys.empty()) {
		keys[keyNumber] = new KeyBoard(keyNumber);
		return;
	}*/

	auto ret= keys.find(keyNumber);
	
	if(ret==keys.end())// .end()‚È‚ç”z—ñ‚É‚È‚¢
		keys[keyNumber] = new KeyBoard(keyNumber);
}

void KeyManager::SetKey(std::vector<int> keyList){
	for (int i = 0; static_cast<unsigned int>(i) < keyList.size(); i++) {
		SetKey(keyList.at(i));
	}
}
