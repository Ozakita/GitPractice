#ifndef SELECTSCENE_H_
#define SELECTSCENE_H_

#include "Scene.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "MyRandom.h"

class SelectScene : public Scene
{
public:
	SceneManager& sm = SceneManager::GetInstance();
	GameManager& gm = GameManager::GetInstance();

	int right = 200;  //左端
	int left = 64;  //右端
	int top = 48;  //上端
	int bottom = 216;  //下端

	SelectScene() : Scene()
	{
		this->tag = "SelectScene";
	}

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Set(int stageNum);

	void Draw() override;
};
#endif
