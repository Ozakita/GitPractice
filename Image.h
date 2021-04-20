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

    static int playerShot1;   // �v���C���[1�̒e
    static int playerShot2;   // �v���C���[2�̒e
    static int playerNeedle1; // �v���C���[1�̐j
    static int playerNeedle2; // �v���C���[2�̐j
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
    static int player1Win; // �v���C���[�P�̏���
    static int player2Win; // �v���C���[�Q�̏���
    static int draw;       // ��������

    static DivImage majyo; // ����
    static DivImage majyo2;
	static DivImage mapchip;

};
#endif // !IMAGE_H_


