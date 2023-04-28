#pragma once
#include<string>

class Scene;

class SceneChanger {
public:
	/// <summary>
	/// 文字列に合わせシーンクラスを返す
	/// </summary>
	/// <param name="sceneName">シーンの名前</param>
	/// <returns></returns>
	Scene* Changer(std::string sceneName);
private:

};