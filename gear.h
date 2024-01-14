#pragma once
#include<iostream>
#include<string>
#include <cstdlib>

struct Gear {
	std::string name;
	int gold;
	int healt;
	int stamina;
	int agility;

	//void Gear(std::string name, int gold, int healt, int stamina, int agility);
	Gear() {}

	Gear(std::string name_, int gold_, int healt_, int stamina_, int agility_) {
		name = name_;
		gold = gold_;
		healt = healt_;
		stamina = stamina_;
		agility = agility_;
	}

};