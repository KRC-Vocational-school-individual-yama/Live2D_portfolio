#pragma once

namespace APP {
	void Init()		;
	void Update()	;
	void Draw()		;
	void Delete()	;

	/// <summary>
	/// ゲーム全体の終了フラグ
	/// </summary>
	/// <param name="true	">終了</param>
	/// <param name="false	">続行</param>
	/// <returns></returns>
	bool GameEnd()	;
}