#include "fpstimer.h"

FpsTimer::FpsTimer()
	:mStartTime(0)
	,mCount(0)
	,mFps(0)
{
}

void FpsTimer::Update(){
	//１フレーム目なら時刻を記憶
	if (mCount == 0)
		mStartTime = GetNowCount();

	//６０フレーム目なら平均を計算
	if (mCount == N) {
		int nowTime = GetNowCount();
		mFps = 1000.f/((nowTime - mStartTime) / static_cast<float>(N));
		mCount = 0;
		mStartTime = nowTime;
	}

	mCount++;

}

void FpsTimer::Draw(){
	DrawFormatString(0, 0,0xffffff, "%.1f", mFps);
}

void FpsTimer::Wait(){
	int tookTime = GetNowCount() - mStartTime;		//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0)
		Sleep(waitTime);	//待機
}
