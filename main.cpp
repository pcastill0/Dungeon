#include "players.h"
#include "mapPositions.h"
#include "enemies.h"
#include "chests.h"
#include "gear.h"
#include "mainManager.h"
#include <time.h>

void Dungeon(MainManager* mn,Player* player);
void Combat(MainManager* mn);
void Chest(MainManager* mn);
void GameOver(MainManager* mn);

int main() {
	srand(time(NULL));
	MainManager* mn = new MainManager;
	mn->Spawn();
	

	do{
		switch (mn->currentScene)
		{
		case DUNGEON:
			Dungeon(mn,mn->player);
			break;
		case COMBAT:
			break;
		case CHEST:
			break;
		case GAMEOVER:
			break;
		default:
			break;
		}

	} while (!mn->gameFinished);

	
	void Combat(MainManager * mn);
	void Chest(MainManager * mn);
	void GameOver(MainManager * mn);

}void Dungeon(MainManager * mn,Player* player){

		std::cout << "------ DUNGEON ------" << std::endl;

		std::cout << "E -> Enemy   P -> Player   C -> Chest" << std::endl;
		std::cout << "Health: " << player->health << "/" << player->maxHealth << std::endl;
		std::cout << "Potions: " << player->potions << "/" << player->maxPotions << std::endl;
		std::cout << "Moves: " << player->agility << "/" << player->maxAgility << std::endl;
		//Aqui va el mapa
		/*
		std::cout << "" << std::endl;
		std::cout << " ___  ___  ___  ___  ___" << std::endl;
		std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
		std::cout << "| " << map[0][0] << " || " << map[0][1] << " || " << map[0][2] << " || " << map[0][3] << " || " << map[0][4] << " |" << std::endl;
		std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
		std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
		std::cout << "| " << map[1][0] << " || " << map[1][1] << " || " << map[1][2] << " || " << map[1][3] << " || " << map[1][4] << " |" << std::endl;
		std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
		std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
		std::cout << "| " << map[2][0] << " || " << map[2][1] << " || " << map[2][2] << " || " << map[2][3] << " || " << map[2][4] << " |" << std::endl;
		std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
		std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
		std::cout << "| " << map[3][0] << " || " << map[3][1] << " || " << map[3][2] << " || " << map[3][3] << " || " << map[3][4] << " |" << std::endl;
		std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
		std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
		std::cout << "| " << map[4][0] << " || " << map[4][1] << " || " << map[4][2] << " || " << map[4][3] << " || " << map[4][4] << " |" << std::endl;
		std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
		std::cout << "_______________________" << std::endl;
*/

		std::cout << "W A S D -> Move" << std::endl;
		std::cout << "P -> Potion" << std::endl;
		
		std::cout << " " << std::endl;
		std::cout << "P -> Potion" << std::endl;




	};