#include "chests.h"

/*
void Chest::Spawn(Player* p, std::vector<Enemy> enemies, std::vector<Chest*>& chests) {

	bool free = true;

	int x;
	int y;

	do {
		free = true;
		x = rand() % 5;
		y = rand() % 5;

		if (x == p->mapPosition.x && y == p->mapPosition.y)
		{
			free = false;
		}

		if (enemies.size() != 0 && free == true)
		{
			for (Enemy* enemy : enemies)
			{

				if (x == enemy->mapPosition.x && y == enemy->mapPosition.y)
				{
					free = false;
				}
			}
		}

		if (chests.size() != 0 && free == true)
		{
			for (Chest* chest : chests)
			{

				if (x == chest->mapPosition.x && y == chest->mapPosition.y)
				{
					free = false;
				}
			}
		}

	} while (!free);

	mapPosition.x = x;
	mapPosition.y = y;

	gold = 50 + rand() % (200 + 1 - 50);
	isLooted = false;
	
	int randPotion = rand() % 100;
	if (randPotion >= 25)
	{
		containsPotion = false;
	}
	else {
		containsPotion = true;
	}
	
}*/
