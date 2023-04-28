#pragma once
#include"../libs/frameWork/component.h"

class TitleSceneChange :public Component {
public:
	TitleSceneChange(Object* obj);
	~TitleSceneChange()override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

	bool TitleGameEnd();
private:
	bool keystop;
	bool mouseInput;
};
