#pragma once
#include<DxLib.h>

class DeltaTime {
public:
	DeltaTime() { time = GetNowHiPerformanceCount(); }
	//ƒƒCƒ“Update‚Ìˆê”ÔÅŒã‚É’u‚­
	void Update() { time = GetNowHiPerformanceCount(); }
	
	float GetDeltTime() {
		return (GetNowHiPerformanceCount() - time) / 1000000;
	}
private:
	double time;
};