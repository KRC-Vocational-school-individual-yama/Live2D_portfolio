#include "keyBoard.h"
#include"../frameWork/myDxLib.h"

KeyBoard::KeyBoard()
	:keystop(true)
	,key{-1}
{}

KeyBoard::KeyBoard(int keyNumber)
	:keystop(true)
	,key(keyNumber)
{}
bool KeyBoard::KeyDown(){
	bool push = CheckHitKey(key);
	bool ret = push && !keystop;
	keystop = push;
	return ret;
}

bool KeyBoard::KeyUp(){
	bool push = CheckHitKey(key);
	bool ret = !push && keystop;
	keystop = push;
	return ret;
}

bool KeyBoard::KeyDownKeep(){
	bool ret = CheckHitKey(key);
	keystop = ret;
	return ret;
}


