#pragma once
#include "players.h"
#include "enemies.h"
#include "chests.h"
#include <vector>

enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {

	Scene currentScene;

	bool gameFinished;

	Player* player;

	std::vector<Enemy*> enemies;

	std::vector<Chest*> chests;

	void Spawn();

	void MoveEnemies();
};
