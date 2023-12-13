#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include "mapPositions.h"

struct Player
{
	MapPosition mapPosition;
	int gold;
	int health;
	int agility;
	int potions;
};