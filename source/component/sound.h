#pragma once
#include"../libs/frameWork/component.h"
#include<unordered_map>

class Sound :public Component {
public:
	Sound(Object*obj);
	~Sound()			override;
	void Init()		override{}
	void Update()	override{}
	void Draw()		override{}

	int Load(std::string pass);
	int Play(std::string pass);
	int Get(std::string pass);
private:
	std::unordered_map<std::string, int>sounds;
};