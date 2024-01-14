#pragma once
#include "mapPositions.h"
#include "players.h"
#include "chests.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <vector>

struct Enemy {
	MapPosition mapPosition;
	bool isDead;
	int health;
	int stamina;
	int maxStamina;

	void Spawn(Player* p, std::vector<Enemy*> enemies);
};