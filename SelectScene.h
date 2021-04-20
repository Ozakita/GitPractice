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

	int right = 200;  //���[
	int left = 64;  //�E�[
	int top = 48;  //��[
	int bottom = 216;  //���[

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
