#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include "mapPositions.h"

struct Player {
	std::string name;

	MapPosition mapPosition;

	int gold;

	int health;
	int maxHealth;

	int stamina;
	int maxStamina;

	int agility;
	int maxAgility;

	int potions;
	int maxPotions;

	void Spawn();
};