#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include "mapPositions.h"
#include "gear.h"

struct Chest
{
	MapPosition mapPosition;
	int gold;
	bool isLooted;
	Gear gear;
	int potions;
};