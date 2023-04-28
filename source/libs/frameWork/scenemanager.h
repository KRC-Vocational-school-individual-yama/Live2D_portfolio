#pragma once
#include<string>
#include"scene.h"

namespace SceneManager {
	void Init()								;
	void Update()							;
	void Draw()								;
	void Delete()							;

	/// <summary>
	/// シーンの切り替え関数
	/// </summary>
	/// <param name="sceneName">シーンの名前</param>
	void SceneChange(std::string sceneName)	;
	/// <summary>
	/// <para>フレームカウンター</para>
	/// <para>ゲームが始まってからのフレームを取得</para>
	/// </summary>
	/// <returns></returns>
	int GetFrame()							;

	/// <summary>
	/// ゲーム終了フラグ
	/// </summary>
	/// <param name="true	">終了</param>
	/// <param name="false	">続行</param>
	/// <returns></returns>
	bool GameEnd()							;
	/// <summary>
	/// ゲームを終了する
	/// </summary>
	void SetGameEnd();
	/// <summary>
	/// Common シーンを取得
	/// </summary>
	/// <returns></returns>
	Scene* GetCommonScene()					;
	/// <summary>
	/// Current シーンを取得
	/// </summary>
	/// <returns></returns>
	Scene* GetCurrentScene()				;
	/// <summary>
	/// 現在シーンの名前を取得
	/// </summary>
	/// <returns></returns>
	std::string GetCurrentSceneName()		;
}