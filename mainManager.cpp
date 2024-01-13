#include "mainManager.h"

void MainManager::Spawn() {

	currentScene = DUNGEON;

	gameFinished = false;

	player = new Player();
	player->Spawn();

	int numEnemies = 5 + rand() % (7 + 1 - 5);
	for (int i = 0; i < numEnemies; i++)
	{
		Enemy* e = new Enemy;
		e->Spawn(player, enemies);
		enemies.push_back(e);
	}
	
}