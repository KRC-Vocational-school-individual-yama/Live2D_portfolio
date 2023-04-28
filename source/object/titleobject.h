#pragma once
#include"../libs/frameWork/object.h"

class TitleObject :public Object {
public:
	TitleObject(Scene* sc)	;
	~TitleObject()	override;
	void Init()		override { Object::Init(); }
	void Update()	override { Object::Update(); }
	void Draw()		override { Object::Draw(); }

	/// <summary>
	/// I—¹‚·‚éƒL[‚ğ‰Ÿ‚µ‚½‚©
	/// </summary>
	/// <param name="true	">‰Ÿ‚µ‚½</param>
	/// <param name="false	">‰Ÿ‚µ‚Ä‚È‚¢</param>
	/// <returns></returns>
	bool EndKeyInput()		;

private:
};