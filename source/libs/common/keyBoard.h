#pragma once

class KeyBoard {
public:
	KeyBoard();
	KeyBoard(int keyNumber);
	void SetKey(int keyNumber) { key = keyNumber; }
	//押した１フレーム
	bool KeyDown();
	//離した１フレーム
	bool KeyUp();
	//押し続ける
	bool KeyDownKeep();
private:
	bool keystop;
	int key;
};