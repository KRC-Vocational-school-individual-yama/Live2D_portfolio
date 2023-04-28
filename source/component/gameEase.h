#pragma once
#include"../libs/frameWork/component.h"

class GameEase :public Component {
public:
	GameEase(Object* obj);
	~GameEase()		override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;
private:
	int counter;
	float anser;
};
