#include "players.h"
#include "mapPositions.h"
#include "enemies.h"
#include "chests.h"
#include "gear.h"
#include "mainManager.h"
#include <time.h>

void Dungeon(MainManager* mn, Player* player, std::vector<Enemy*> enemies);
void Combat(MainManager* mn);
void Chest(MainManager* mn);
void GameOver(MainManager* mn);
void changeStatus(MainManager* mn, Player* player, std::vector<Enemy*> enemies);

int main() {
	srand(time(NULL));
	MainManager* mn = new MainManager;
	mn->Spawn();

	do {
		switch (mn->currentScene)
		{
		case DUNGEON:
			Dungeon(mn, mn->player, mn->enemies);
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
		system("cls");
	} while (!mn->gameFinished);

}	

void Dungeon(MainManager* mn, Player* player, std::vector<Enemy*> enemies) {

	char respuesta;
	std::cout << "------ DUNGEON ------" << std::endl;

	//Legend
	std::cout << "E -> Enemy   P -> Player   C -> Chest" << std::endl;

	//Stats player
	std::cout << "Health: " << player->health << "/" << player->maxHealth << std::endl;
	std::cout << "Potions: " << player->potions << "/" << player->maxPotions << std::endl;
	std::cout << "Moves: " << player->agility << "/" << player->maxAgility << std::endl;

	//Mapa
	std::cout << "" << std::endl;
	std::cout << " ___  ___  ___  ___  ___" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;

	std::cout << "| " << mn->map[0][4] << " || " << mn->map[1][4] << " || " << mn->map[2][4] << " || " << mn->map[3][4] << " || " << mn->map[4][4] << " |" << std::endl;
	
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;

	std::cout << "| " << mn->map[0][3] << " || " << mn->map[1][3] << " || " << mn->map[2][3] << " || " << mn->map[3][3] << " || " << mn->map[4][3] << " |" << std::endl;
	
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	
	std::cout << "| " << mn->map[0][2] << " || " << mn->map[1][2] << " || " << mn->map[2][2] << " || " << mn->map[2][2] << " || " << mn->map[4][2] << " |" << std::endl;
	
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	
	std::cout << "| " << mn->map[0][1] << " || " << mn->map[1][1] << " || " << mn->map[2][1] << " || " << mn->map[3][1] << " || " << mn->map[4][1] << " |" << std::endl;
	
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	
	std::cout << "| " << mn->map[0][0] << " || " << mn->map[1][0] << " || " << mn->map[2][0] << " || " << mn->map[3][0] << " || " << mn->map[4][0] << " |" << std::endl;
	
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "_______________________" << std::endl;

	//Actions
	std::cout << "W A S D -> Move" << std::endl;
	std::cout << "P -> Potion" << std::endl;

	std::cout << "Enter your action: " << std::endl;
	std::cin >> respuesta;
	std::cout << std::endl;

	if (player->agility = 0)
	{
		mn->MoveEnemies(); //TO-DO cambiar la posicion de todos los enemigos
		player->agility = player->maxAgility;
	}
	else if ((respuesta == 'W' || respuesta == 'w') && player->agility > 0 && player->mapPosition.y > 0) {

		player->mapPosition.y--;
		changeStatus(mn, mn->player, mn->enemies);

	}
	else if ((respuesta == 'A' || respuesta == 'a') && player->agility > 0 && player->mapPosition.x > 0) {

		player->mapPosition.x--;
		changeStatus(mn, mn->player, mn->enemies);

	}
	else if ((respuesta == 'S' || respuesta == 's') && player->agility > 0 && player->mapPosition.y < 4) {

		player->mapPosition.y++;
		changeStatus(mn, mn->player, mn->enemies);

	}
	else if ((respuesta == 'D' || respuesta == 'd') && player->agility > 0 && player->mapPosition.x < 4) {

		player->mapPosition.x++;
		changeStatus(mn, mn->player, mn->enemies);

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

void changeStatus(MainManager* mn, Player* player, std::vector<Enemy*> enemies) {
	player->agility--;

	if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'E')
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->mapPosition.x == player->mapPosition.x && enemies[i]->mapPosition.y == player->mapPosition.y) {
				mn->idCombatEnemy = i;
			}
		}

		mn->currentScene = COMBAT;
	}
	else if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'C')
	{
		mn->currentScene = CHEST;
	}
}

void Combat(MainManager* mn, Player* player, std::vector<Enemy*> enemies, int& id) {
	std::cout << "------- COMBAT------" << std::endl;
	std::cout << "-- Enemy --" << std::endl;
	std::cout << "[";
	float aux = enemies[id]->maxHealth * 0.1f;
	float porcentaje = aux;

	for (int i = 0; i < 10; i++)
	{

		if (enemies[id]->health >= porcentaje) {
			std::cout << "=";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "]" << " ? HP" << std::endl;

	std::cout << "[";

	aux = enemies[id]->maxStamina * 0.1f;
	porcentaje = aux;
	for (int i = 0; i < 10; i++)
	{

		if (enemies[1]->stamina >= porcentaje) {
			std::cout << ">";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "] ? Stamina" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "-- Player --" << std::endl;
	std::cout << "[";
	aux = enemies[id]->maxHealth * 0.1f;
	porcentaje = aux;

	for (int i = 0; i < 10; i++)
	{

		if (enemies[id]->health >= porcentaje) {
			std::cout << "=";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "]" << player->health << "/" << player->maxHealth << "HP" << std::endl;

	std::cout << "[";

	aux = enemies[id]->maxStamina * 0.1f;
	porcentaje = aux;
	for (int i = 0; i < 10; i++)
	{

		if (enemies[id]->stamina >= porcentaje) {
			std::cout << ">";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "]" << player->stamina << "/" << player->maxStamina << "Stamina" << std::endl;
	std::cout << "Potions " << player->potions << "/" << player->maxPotions << std::endl;

}

void Chest(MainManager* mn){}
void GameOver(MainManager* mn){}