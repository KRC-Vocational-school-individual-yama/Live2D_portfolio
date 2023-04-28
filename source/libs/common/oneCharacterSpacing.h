#pragma once

#include"../frameWork/myDxLib.h"
#include<string>

/// <summary>
/// 1文字送り 字幕表示
/// </summary>
class OneCharacterSpacing {
public:
	OneCharacterSpacing();
	//~OneCharacterSpacing();
	//void Init();
	void Update();
	void Draw(float x,float y,int color);

	//文字とフォントハンドルを設定
	void SetStr(std::string str);
	//フォントハンドル設定
	void SetFont(int handle) { hFont = handle; }
	//表示スピードを変更　１秒何文字
	void SetSpeed(float speed) { dispSpeed = speed; }
	//何秒で全部表示するか
	int GetSize();
	//表示カウント貰う
	int GetCount() { return static_cast<int>(count); }

	//文字を全部表示したか　true：全部表示している
	bool GetAllDisp();
	//文字を全部表示する
	void AllDisp();
	
	//wstringをstringへ変換
	static std::string WStringToString(std::wstring oWString);
	//stringをwstringへ変換
	static std::wstring StringToWString(std::string oString);
private:


	std::wstring myWStr;
	float count;
	float dispSpeed;
	int hFont;
};