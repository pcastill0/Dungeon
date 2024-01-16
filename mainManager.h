#pragma once
#include "players.h"
#include "enemies.h"
#include "chests.h"
#include <vector>


enum Scene { DUNGEON, COMBAT, CHEST, GAMEOVER, END };

struct MainManager {

	Scene currentScene;

	char map[5][5];

	bool gameFinished;

	Player* player;
	
	std::vector<Enemy*> enemies;

	std::vector<Chest*> chests;

	int idCombatEnemy;

	int idChest;

	void Spawn();

	void MoveEnemies();
	
};


