#include "enemies.h"

void Spawn(Player* p, std::vector<Enemy*> enemies) {

	bool free = true;

	int x = rand() % 5;
	int y = rand() % 5;

	if (x == p->mapPosition.x && y == p->mapPosition.y)
	{
		free = false;
	}

	if (enemies.size() != 0)
	{

	}
}