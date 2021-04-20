

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
	const float WalkSpeed = 3.0f;     // 歩きの速度
	const float JumpPower = 13.0f;    // ジャンプ力
	const float Gravity = 0.6f;     // 重力
	const float MaxFallSpeed = 12.0f; // 最大落下速度
	const int MutekiJikan = 120;    // 無敵時間

	float vx = 0.0f; // 横移動速度
	float vy = 0.0f; // 縦移動相度

	int life = 100;      // HP
	int mutekiTimer = 0; // 残り無敵時間。0以下なら無敵ではない

	PlayerState state = PlayerState::Walk; // 現在の状態
	Direction direction = Direction::Right; // 向いている方向

	std::shared_ptr<GameObject> groundObject{ nullptr };

	int ShotFlame = 0;
	int ShotCounter = 0; // プレイヤーの弾が当たった時
	int NeedleFlame = 0;  // プレイヤーの針のリロード

	Pad padPlaying;

	//自分が何番目に生成されたプレイヤーか（1～4）
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