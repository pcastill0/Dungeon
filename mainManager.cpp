#include "mainManager.h"

void MainManager::Spawn() {

	currentScene = DUNGEON;

	gameFinished = false;

	player = new Player();
	player->Spawn();

	Gear list[10];

	list[0] = Gear("Richard’s Hatred", 200, 20, 40, 1);
	list[1] = Gear("Swift boots", 10, -10, -5, 1);
	list[2] = Gear("White Powder", 150, -20, 20, 1);
	list[3] = Gear("Radev’s Mug", -300, -20, -40, -1);
	list[4] = Gear("Raven feather", 50, -10, 0, 2);
	list[5] = Gear("Red Mushroom", 170, 30, 0, 0);
	list[6] = Gear("Ugly Facemask", 10, 5, 0, 0);
	list[7] = Gear("Broken Shield", 25, 10, 0, 0);
	list[8] = Gear("Green mushroom", -50, 0, -10, 0);
	list[9] = Gear("Naughty book", 69, 0, 7, 0);

	int numEnemies = 5 + rand() % (7 + 1 - 5);
	for (int i = 0; i < numEnemies; i++)
	{
		Enemy* e = new Enemy;
		e->Spawn(player, enemies);
		map[e->mapPosition.x][e->mapPosition.y] = 'E';
		enemies.push_back(e);
	}

	map[player->mapPosition.x][player->mapPosition.y] = 'P';

	/*
	int numChests = 2;
	for (int i = 0; i < numChests; i++)
	{
		Chest* c = new Chest;
		c->Spawn(player, enemies, chests);
		c->gear = list[0]; //TO-DO make random gear
		chests.push_back(c);
	}*/


}

void MainManager::MoveEnemies() {
	player->agility = player->maxAgility;

	bool free = true;

	int x;
	int y;

	for (int i = 0; i < enemies.size(); i++)
	{
		do {
			free = true;
			x = rand() % 5;
			y = rand() % 5;

			if (x == player->mapPosition.x && y == player->mapPosition.y)
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

		} while (!free);

		map[enemies[i]->mapPosition.x][enemies[i]->mapPosition.y] = '=';

		enemies[i]->mapPosition.x = x;
		enemies[i]->mapPosition.y = y;
		
		map[x][y] = 'E';
	}
}

/*
Gear* getGearlist() {
	Gear list[10];

	list[0] = Gear("Richard’s Hatred", 200, 20, 40, 1);
	list[1] = Gear("Swift boots", 10, -10, -5, 1);
	list[2] = Gear("White Powder", 150, -20, 20, 1);
	list[3] = Gear("Radev’s Mug", -300, -20, -40, -1);
	list[4] = Gear("Raven feather", 50, -10, 0, 2);
	list[5] = Gear("Red Mushroom", 170, 30, 0, 0);
	list[6] = Gear("Ugly Facemask", 10, 5, 0, 0);
	list[7] = Gear("Broken Shield", 25, 10, 0, 0);
	list[8] = Gear("Green mushroom", -50, 0, -10, 0);
	list[9] = Gear("Naughty book", 69, 0, 7, 0);

	return list;
}*/