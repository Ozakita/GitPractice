#ifndef IMAGE_H_
#define IMAGE_H_

#include "DxLib.h"
#include <assert.h>
#include "DivImage.h"

class Image
{
public:
	Image() {};
	~Image() {};
	static void Load();
	static int LoadDivGraph(const TCHAR* FileName, DivImage& divImage);

    static int playerShot1;   // プレイヤー1の弾
    static int playerShot2;   // プレイヤー2の弾
    static int playerNeedle1; // プレイヤー1の針
    static int playerNeedle2; // プレイヤー2の針
    static int movingNeedle;
    static int titleBG;
    static int selectBG;
    static int select;
    static int resultBG;
    static int stage1;
    static int stage2;
    static int stage3;
    static int stageRandom;
    static int playBG1;
    static int playBG2;
    static int playBG3;
    static int title;
    static int button;
    static int player1Win; // プレイヤー１の勝利
    static int player2Win; // プレイヤー２の勝利
    static int draw;       // 引き分け

    static DivImage majyo; // 魔女
    static DivImage majyo2;
	static DivImage mapchip;

};
#endif // !IMAGE_H_


