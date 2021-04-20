#include "DxLib.h"
#include "Screen.h"
#include "Game.h"

// 設定画面の【リンカー】→【システム】の【サブシステム】をWindows(SUBSYSTEM:WINDOWS)に設定するとWinMainからプログラムが開始する
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 画面モードの設定
    SetGraphMode(Screen::Width, Screen::Height, 32);  // 画面サイズ960×540のカラービット数32ビットで起動
    SetWindowSize(Screen::Width, Screen::Height);     // ウィンドウサイズ960×540(こことSetGraphModeのサイズが異なると画像がゆがむ)
    ChangeWindowMode(TRUE);                           //フルスクリーン表示かウィンドウ表示か
    SetMouseDispFlag(TRUE);                           // ここをFALSEにするとマウスカーソル非表示
    SetMainWindowText("Action");                      //この行でエラーになったら【設定】マルチバイト文字セットが間違ってるかも
    //↑ここまでの設定は↓下のDXライブラリ初期化より先にやらないとDxLib_Init()中は画面がフルスクリーンになって終わってからウィンドウサイズが変更になり見苦しい

    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    Game game;
    game.Init();

    ScreenFlip();

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        game.Update();

        game.Draw();

        ScreenFlip();
    }

    // キー入力待ちをする
    WaitKey();
    // ＤＸライブラリの後始末
    DxLib_End();
    // ソフトの終了
    return 0;
}