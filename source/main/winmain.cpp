#include <DxLib.h>

#include"config.h"
#include"app.h"
//#include"../resource/resource.h"

//初期化前設定
void LoadInit() {
	//SetUseCharCodeFormat( DX_CHARCODEFORMAT_UTF8 )	;//UTF-8を使用する
	SetOutApplicationLogValidFlag(LOGSET_MODE)		;//ログの書き出し設定
	ChangeWindowMode(WINDOW_MODE)					;//ウィンドウモードにする
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32)	;//ウィンドウサイズを設定する
	SetWindowSizeExtendRate(WINDOW_EXTEND)			;//ウィンドウ拡大率
	//SetWindowSizeChangeEnableFlag(TRUE)			;//途中大きさ変更あり
	SetWindowStyleMode(WINDOW_STYLE)				;//ウィンドウの最大化ボタンを機能させる。
	//SetUseIMEFlag(true)							;//ＩＭＥを使用するかどうかを設定する
	SetMainWindowText(WINDOW_NAME);//ウィンドウの名前
	//SetAlwaysRunFlag(TRUE)						;//ウィンドウが非アクティブでも動くか
	SetUseDXArchiveFlag(TRUE)						;//DxLibのアーカイブを読み込むかどうか
	//SetWaitVSyncFlag(FALSE)							;//垂直同期信号待ち
	//SetWindowIconID(IDI_ICON1);

	Live2D_SetCubism4CoreDLLPath("Library/Live2D_dll/x86/Live2DCubismCore.dll");//Live2Dを扱うためのパス指定
}

//プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LoadInit()				;//初期化前設定
	
	if (DxLib_Init() == -1)	 // ＤＸライブラリ初期化処理
		return -1			;// エラーが起きたら直ちに終了
	
	SetDrawScreen(DX_SCREEN_BACK);//裏画面を描画対象へ
	CreateMaskScreen();//マスク画面作成
	SetUseMaskScreenFlag(FALSE);
		
	//SetAlwaysRunFlag(TRUE);//ウィンドウがアクティブではない状態でも動く
	//SetUseZBuffer3D(TRUE)	;
	//SetWriteZBuffer3D(TRUE);
		
	
	APP::Init()				;//最初に１回呼ぶ
	//メイン処理
	while (true) {
		clsDx()				;//prinfdxの描画を消去
		ClearDrawScreen()	;//裏画面の描画を全て消去
		FillMaskScreen(0);//マスク画面を黒で作成時と同じようにする。

		APP::Update()		;//毎フレームの更新



		APP::Draw()			;//毎フレームの描画
		if ((ProcessMessage() == -1)|| APP::GameEnd())
			break;

		ScreenFlip()		;//裏画面と表画面の入替

	}

	DeleteMaskScreen();
	APP::Delete()			;//後始末

	DxLib_End()				;// ＤＸライブラリ使用の終了処理

	return 0				;// ソフトの終了 
}
