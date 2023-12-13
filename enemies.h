#pragma once
#include<iostream>
#include<string>
#include <cstdlib>
#include "mapPositions.h"

struct Enemy
{
	MapPosition mapPosition;
	bool isDead;
	int healt;
	int stamina;
};