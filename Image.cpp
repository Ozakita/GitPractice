#include "Image.h"

int Image::playerShot1{ -1 };
int Image::playerShot2 { -1 };
int Image::playerNeedle1{ -1 };
int Image::playerNeedle2{ -1 };
int Image::movingNeedle{ -1 };
int Image::titleBG{ -1 };
int Image::selectBG{ -1 };
int Image::select{ -1 };
int Image::resultBG{ -1 };
int Image::stage1{ -1 };
int Image::stage2{ -1 };
int Image::stage3{ -1 };
int Image::stageRandom{ -1 };
int Image::playBG1{ -1 };
int Image::playBG2{ -1 };
int Image::playBG3{ -1 };
int Image::title{ -1 };
int Image::button{ -1 };
int Image::player1Win{ -1 };
int Image::player2Win{ -1 };
int Image::draw{ -1 };

// �������摜�͏������̂Ƃ���{X�����摜��, Y�����摜��, �摜����XSize,�摜�c��YSize}���w��
DivImage Image::mapchip{ 16,16,32,32 };
DivImage Image::majyo{ 3,4,32,32 };
DivImage Image::majyo2{ 3, 4, 32, 32 };


void Image::Load()
{
	playerShot1 = LoadGraph("Image/player_shot_red.png");
	assert(playerShot1 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�

	playerShot2 = LoadGraph("Image/player_shot.png");
	assert(playerShot2 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�

	playerNeedle1 = LoadGraph("Image/needle.png");
	assert(playerNeedle1 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�

	playerNeedle2 = LoadGraph("Image/needle_blue.png");
	assert(playerNeedle2 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	movingNeedle = LoadGraph("Image/needle_green.png");
	assert(movingNeedle != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	titleBG = LoadGraph("Image/map2.jpg");
	assert(titleBG != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	selectBG = LoadGraph("Image/map1.jpg");
	assert(selectBG != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	select = LoadGraph("Image/StageSelection.png");
	assert(select != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	resultBG = LoadGraph("Image/map.jpg");
	assert(resultBG != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	stage1 = LoadGraph("Image/stage1.png");
	assert(stage1 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	stage2 = LoadGraph("Image/stage2.png");
	assert(stage2 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	stage3 = LoadGraph("Image/stage3.png");
	assert(stage3 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	stageRandom = LoadGraph("Image/Random.png");
	assert(stageRandom != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	playBG1 = LoadGraph("Image/playBG1.jpg");
	assert(playBG1 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	playBG2 = LoadGraph("Image/playBG2.jpg");
	assert(playBG2 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	playBG3 = LoadGraph("Image/playBG3.jpg");
	assert(playBG3 != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	title = LoadGraph("Image/Title.png");
	assert(title != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	button = LoadGraph("Image/PressAnyButton.png");
	assert(button != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	player1Win = LoadGraph("Image/Win1.png");
	assert(player1Win != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	player2Win = LoadGraph("Image/Win2.png");
	assert(player2Win != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�
	
	draw = LoadGraph("Image/Draw.png");
	assert(draw != -1); // �摜�Ǎ����s�A�t�@�C�������t�H���_�����Ԉ���Ă�

	Image::LoadDivGraph("Image/majyo.png", majyo); // �v���C���[1��div�����摜�����[�h
	for (int i = 0; i < majyo.AllNum; i++)
	{
		if (majyo.HandleArray[i] == -1)
			assert("majyo�摜�Ǎ����s" == "");
	}

	Image::LoadDivGraph("Image/majyo_blue.png", majyo2); // �v���C���[2��div�����摜�����[�h
	for (int i = 0; i < majyo2.AllNum; i++)
	{
		if (majyo2.HandleArray[i] == -1)
			assert("majyo2�摜�Ǎ����s" == "");
	}

	Image::LoadDivGraph("Map/motoyamap.png", mapchip); // div�����摜�����[�h
	for (int i = 0; i < mapchip.AllNum; i++)
	{
		if (mapchip.HandleArray[i] == -1)
			assert("mapchip�摜�Ǎ����s" == "");
	}
}

// DX���C�u������LoadDivGraph���g���₷�����b�s���O
int Image::LoadDivGraph(const TCHAR* FileName, DivImage& divImage)
{
	return DxLib::LoadDivGraph(FileName, divImage.XNum * divImage.YNum,
		divImage.XNum, divImage.YNum, divImage.XSize, divImage.YSize, divImage.HandleArray);
}
