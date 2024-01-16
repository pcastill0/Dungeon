#include "enemies.h"

void Enemy::Spawn(Player* p, std::vector<Enemy*> enemies) {

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
			continue;
		}

		for (Enemy* enemy : enemies)
		{
			if (x == enemy->mapPosition.x && y == enemy->mapPosition.y)
			{
				free = false;
				continue;
			}
		}

	} while (!free);

	mapPosition.x = x;
	mapPosition.y = y;

	isDead = false;
	maxHealth = 90 + rand() % (110 + 1 - 90);
	health = maxHealth;
	maxStamina = 60 + rand() % (90 + 1 - 60);
	stamina = maxStamina;

}