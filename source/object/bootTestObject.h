#pragma once

#include"../libs/frameWork/object.h"

class BootTestObject :public Object {
public:
	BootTestObject(Scene* sc);
	~BootTestObject()			override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

private:
	int hFont;

	void SceneChangeKey()	;//ƒV[ƒ“‚ÌØ‚è‘Ö‚¦ó•t
};
