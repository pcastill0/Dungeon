#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include <vector>
#include "mapPositions.h"
#include "players.h"

struct Enemy {
	MapPosition mapPosition;
	bool isDead;
	int health;
	int maxHealth;
	int stamina;
	int maxStamina;

	void Spawn(Player* p, std::vector<Enemy*> enemies);
};