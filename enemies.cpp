#include "enemies.h"

void Enemy::Spawn(Player* p, std::vector<Enemy*> enemies) {

	bool free = true;

	int x;
	int y;

	do {
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

	} while (!free);

	mapPosition.x = x;
	mapPosition.y = y;

	isDead = false;
	health = 90 + rand() % (110 + 1 - 90);
	maxStamina = 60 + rand() % (90 + 1 - 60);
	stamina = maxStamina;

}