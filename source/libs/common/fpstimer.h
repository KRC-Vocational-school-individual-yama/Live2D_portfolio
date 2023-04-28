#pragma once
#include<DxLib.h>

namespace {
	static const int FPS = 60;	//設定したFPS
}

class FpsTimer {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	const int N = 60;//平均を取るサンプル数

public:
	FpsTimer();
	void Update();
	void Draw();
	void Wait();
};