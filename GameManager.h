#ifndef GAMEMANAGER
#define GAMEMANAGER

#include <memory>
#include <vector>


#include "Singleton.h"
#include "Input.h"

class Map;
class SelectScene;
class PlayScene;
class Player;
class Input;
class GameObject;

class GameManager : public Singleton<GameManager>
{
public:
	friend class Singleton<GameManager>;

	std::shared_ptr<Map>map{ nullptr };
	std::vector<std::shared_ptr<Player>> players; // 自機の辞書配列(複数プレイ対応)
	std::vector<Pad>playingPad;
	std::vector<std::shared_ptr<GameObject>>gameObjects;

protected:
	GameManager() {};
	virtual ~GameManager() {};
};
#endif
