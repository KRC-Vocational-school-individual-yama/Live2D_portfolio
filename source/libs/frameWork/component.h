#pragma once
#include"myDxLib.h"
class Object;

class Component {
public:
	Component(Object* obj)
		:myObject(obj)
	{}
	virtual ~Component() = default;
	virtual void Init()		{}
	virtual void Update()	{}
	virtual void Draw()		{}

	Object* GetMyObject() { return myObject; }
private:
	Object* myObject;
};