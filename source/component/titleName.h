#pragma once
#include"../libs/frameWork/component.h"

class TitleName :public Component {
public:
	TitleName(Object* obj);
	~TitleName()		override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;
private:
	int hFont;
};