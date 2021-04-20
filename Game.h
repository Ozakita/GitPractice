#ifndef GAME_H_
#define GAME_H_

#include <algorithm>
#include "SceneManager.h"
#include "GameManager.h"

#include "DxLib.h"
#include "Input.h"
#include "MyMath.h"
#include "Image.h"
#include "Screen.h"
#include "Scene.h"
#include "Camera.h"
#include "Sound.h"

class Scene;

class Game
{
public:
	Game() = default;
	~Game() {}

	void Init();

	void Update();

	void Draw();

	SceneManager& sm = SceneManager::GetInstance();
	GameManager& gm = GameManager::GetInstance();
};
#endif
