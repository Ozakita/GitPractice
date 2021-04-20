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

// ★分割画像は初期化のときに{X方向画像数, Y方向画像数, 画像横幅XSize,画像縦幅YSize}を指定
DivImage Image::mapchip{ 16,16,32,32 };
DivImage Image::majyo{ 3,4,32,32 };
DivImage Image::majyo2{ 3, 4, 32, 32 };


void Image::Load()
{
	playerShot1 = LoadGraph("Image/player_shot_red.png");
	assert(playerShot1 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる

	playerShot2 = LoadGraph("Image/player_shot.png");
	assert(playerShot2 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる

	playerNeedle1 = LoadGraph("Image/needle.png");
	assert(playerNeedle1 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる

	playerNeedle2 = LoadGraph("Image/needle_blue.png");
	assert(playerNeedle2 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	movingNeedle = LoadGraph("Image/needle_green.png");
	assert(movingNeedle != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	titleBG = LoadGraph("Image/map2.jpg");
	assert(titleBG != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	selectBG = LoadGraph("Image/map1.jpg");
	assert(selectBG != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	select = LoadGraph("Image/StageSelection.png");
	assert(select != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	resultBG = LoadGraph("Image/map.jpg");
	assert(resultBG != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	stage1 = LoadGraph("Image/stage1.png");
	assert(stage1 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	stage2 = LoadGraph("Image/stage2.png");
	assert(stage2 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	stage3 = LoadGraph("Image/stage3.png");
	assert(stage3 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	stageRandom = LoadGraph("Image/Random.png");
	assert(stageRandom != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	playBG1 = LoadGraph("Image/playBG1.jpg");
	assert(playBG1 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	playBG2 = LoadGraph("Image/playBG2.jpg");
	assert(playBG2 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	playBG3 = LoadGraph("Image/playBG3.jpg");
	assert(playBG3 != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	title = LoadGraph("Image/Title.png");
	assert(title != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	button = LoadGraph("Image/PressAnyButton.png");
	assert(button != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	player1Win = LoadGraph("Image/Win1.png");
	assert(player1Win != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	player2Win = LoadGraph("Image/Win2.png");
	assert(player2Win != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる
	
	draw = LoadGraph("Image/Draw.png");
	assert(draw != -1); // 画像読込失敗、ファイル名かフォルダ名が間違ってる

	Image::LoadDivGraph("Image/majyo.png", majyo); // プレイヤー1のdiv分割画像をロード
	for (int i = 0; i < majyo.AllNum; i++)
	{
		if (majyo.HandleArray[i] == -1)
			assert("majyo画像読込失敗" == "");
	}

	Image::LoadDivGraph("Image/majyo_blue.png", majyo2); // プレイヤー2のdiv分割画像をロード
	for (int i = 0; i < majyo2.AllNum; i++)
	{
		if (majyo2.HandleArray[i] == -1)
			assert("majyo2画像読込失敗" == "");
	}

	Image::LoadDivGraph("Map/motoyamap.png", mapchip); // div分割画像をロード
	for (int i = 0; i < mapchip.AllNum; i++)
	{
		if (mapchip.HandleArray[i] == -1)
			assert("mapchip画像読込失敗" == "");
	}
}

// DXライブラリのLoadDivGraphを使いやすくラッピング
int Image::LoadDivGraph(const TCHAR* FileName, DivImage& divImage)
{
	return DxLib::LoadDivGraph(FileName, divImage.XNum * divImage.YNum,
		divImage.XNum, divImage.YNum, divImage.XSize, divImage.YSize, divImage.HandleArray);
}
