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

	
	

}void Dungeon(MainManager * mn,Player* player){
		
		char respuesta;
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

		std::cout << "Enter your action: " << std::endl;
		std::cin >> respuesta;
		std::cout << std::endl;
		if (player->agility = 0)
		{
			mn->MoveEnemies();
			player->agility = player->maxAgility;
		}
		else if (respuesta == 'W' || respuesta == 'w') {
			if (player->agility > 0 && player->mapPosition.y > 0) {
				player->mapPosition.y--;
				player->agility--;
			}
		}
		else if (respuesta == 'A' || respuesta == 'a') {
			if (player->agility > 0 && player->mapPosition.x > 0) {
				player->mapPosition.x--;
				player->agility--;
			}
		}
		else if (respuesta == 'S' || respuesta == 's') {
			if (player->agility > 0 && player->mapPosition.y < 4) {
				player->mapPosition.y++;
				player->agility--;
			}
		}
		else if (respuesta == 'D' || respuesta == 'd') {
			if (player->agility > 0 && player->mapPosition.x < 4) {
				player->mapPosition.x++;
				player->agility--;
			}
		}
		else if (respuesta == 'P' || respuesta == 'p') {
			if (player->agility < 0 && player->potions > 0) {
				player->potions--;
				player->health += 0.4f * player->maxHealth;
				if (player->health > player->maxHealth) {
					player->health = player->maxHealth;
				}
				player->agility--;
			}
			else 
			{
				std::cout << "No tienes pociones disponibles o movimientos." << std::endl;
			} 
				
			
		}
		else {
			std::cout << "This action is not valid, please try again.";
		}

		

	};
	
	void Combat(MainManager * mn);
	void Chest(MainManager* mn);
	void GameOver(MainManager* mn);