#include "players.h"
#include "mapPositions.h"
#include "enemies.h"
#include "chests.h"
#include "gear.h"
#include "mainManager.h"
#include <time.h>

void Dungeon(MainManager* mn);
void Combat(MainManager* mn);
void Chest(MainManager* mn);
void GameOver(MainManager* mn);

int main() {
	srand(time(NULL));
	MainManager* mn = new MainManager;
	mn->Spawn();

	do{
		switch (mn->currentScene)
		{
		case DUNGEON:
			Dungeon(mn);
			break;
		case COMBAT:
			break;
		case CHEST:
			break;
		case GAMEOVER:
			break;
		default:
			break;
		}

	} while (!mn->gameFinished);

	void Dungeon(MainManager * mn);
	void Combat(MainManager * mn);
	void Chest(MainManager * mn);
	void GameOver(MainManager * mn);

}