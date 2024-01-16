#pragma once
#include "mapPositions.h"
#include "players.h"
#include "enemies.h"
#include "gear.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <vector>

struct Chest {
	MapPosition mapPosition;
	int gold;
	bool isLooted;
	Gear gear;
	bool containsPotion;

	void Spawn(Player* p, std::vector<Enemy*> enemies, std::vector< Chest* > chests);
};