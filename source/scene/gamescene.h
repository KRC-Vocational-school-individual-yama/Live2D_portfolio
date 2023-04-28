#pragma once

#include"../libs/frameWork/scene.h"

class GameScene :public Scene {
public:
	GameScene();
	~GameScene();
	void Update()override;
	void Draw()override;
private:
};