

#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>

#include "DxLib.h"
#include "Input.h"
#include "Image.h"
#include "Direction.h"
#include "Map.h"

#include "GameManager.h"
#include "GameObject.h"

enum class PlayerState
{
	Walk,
	Jump,
};

class Player : public GameObject
{
public:
	const float WalkSpeed = 3.0f;     // �����̑��x
	const float JumpPower = 13.0f;    // �W�����v��
	const float Gravity = 0.6f;     // �d��
	const float MaxFallSpeed = 12.0f; // �ő嗎�����x
	const int MutekiJikan = 120;    // ���G����

	float vx = 0.0f; // ���ړ����x
	float vy = 0.0f; // �c�ړ����x

	int life = 100;      // HP
	int mutekiTimer = 0; // �c�薳�G���ԁB0�ȉ��Ȃ疳�G�ł͂Ȃ�

	PlayerState state = PlayerState::Walk; // ���݂̏��
	Direction direction = Direction::Right; // �����Ă������

	std::shared_ptr<GameObject> groundObject{ nullptr };

	int ShotFlame = 0;
	int ShotCounter = 0; // �v���C���[�̒e������������
	int NeedleFlame = 0;  // �v���C���[�̐j�̃����[�h

	Pad padPlaying;

	//���������Ԗڂɐ������ꂽ�v���C���[���i1�`4�j
	int playerNum;

	GameManager& gm = GameManager::GetInstance();
	SceneManager& sm = SceneManager::GetInstance();


	Player(Pad padPlaying, float x, float y, int playerNum)
		: GameObject()
	{
		this->tag = "Player";
		this->playerNum = playerNum;
		this->padPlaying = padPlaying;
		this->x = x;
		this->y = y;

		imageWidth = 32;
		imageHeight = 35;
		hitboxOffsetLeft = 0;
		hitboxOffsetRight = 0;
		hitboxOffsetTop = 1;
		hitboxOffsetBottom = 1;
	}

	void Update() override;

	void HandleInput();

	void MoveX();

	void MoveY();

	void Draw() override;

	void OnCollision(std::shared_ptr<GameObject> other) override;

	void TakeDamage(int damage);

	void Die();

	void Shot();

	void ShotNeedle();
};
#endif 