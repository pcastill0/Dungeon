#pragma once
#include "players.h"
#include "enemies.h"
#include <vector>


enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER };

struct MainManager {

	Scene currentScene;

	bool gameFinished;

	Player* player;

	std::vector<Enemy*> enemies;

	void Spawn();

	void MoveEnemies();
	
};


