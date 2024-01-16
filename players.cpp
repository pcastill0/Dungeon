#include "players.h"

using namespace std;

void Player::Spawn() {

	cout << "Introduce nombre: ";
	cin >> name;
	//std::getline(std::cin, name);

	mapPosition.x = 2;
	mapPosition.y = 1;

	gold = 0;

	maxHealth = 90 + rand() % (110 + 1 - 90);
	health = maxHealth;

	maxStamina = 90 + rand() % (110 + 1 - 90);
	stamina = maxStamina;

	agility = 3;
	maxAgility = 3;

	potions = 3;
	maxPotions = 3;
}