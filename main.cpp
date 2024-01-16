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

int main() {
	srand(time(NULL));
	MainManager* mn = new MainManager;
	mn->Spawn();
	int numEnemies = mn->enemies.size();


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

	} while (!mn->gameFinished);




}	void Dungeon(MainManager* mn, Player* player, std::vector<Enemy*> enemies) {
	system("cls");
	char respuesta;
	std::cout << "------ DUNGEON ------" << std::endl;

	std::cout << "E -> Enemy   P -> Player   C -> Chest" << std::endl;
	std::cout << "Health: " << player->health << "/" << player->maxHealth << std::endl;
	std::cout << "Potions: " << player->potions << "/" << player->maxPotions << std::endl;
	std::cout << "Moves: " << player->agility << "/" << player->maxAgility << std::endl;
	//Aqui va el mapa

	std::cout << "" << std::endl;
	std::cout << " ___  ___  ___  ___  ___" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	std::cout << "| " << mn->map[0][0] << " || " << mn->map[1][0] << " || " << mn->map[2][0] << " || " << mn->map[3][0] << " || " << mn->map[4][0] << " |" << std::endl;
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	std::cout << "| " << mn->map[0][1] << " || " << mn->map[1][1] << " || " << mn->map[2][1] << " || " << mn->map[3][1] << " || " << mn->map[4][1] << " |" << std::endl;
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	std::cout << "| " << mn->map[0][2] << " || " << mn->map[1][2] << " || " << mn->map[2][2] << " || " << mn->map[3][2] << " || " << mn->map[4][2] << " |" << std::endl;
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	std::cout << "| " << mn->map[0][3] << " || " << mn->map[1][3] << " || " << mn->map[2][3] << " || " << mn->map[3][3] << " || " << mn->map[4][3] << " |" << std::endl;
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "|   " << "||   " << "||   " << "||   " << "||   " << "|" << std::endl;
	std::cout << "| " << mn->map[0][4] << " || " << mn->map[1][4] << " || " << mn->map[2][4] << " || " << mn->map[3][4] << " || " << mn->map[4][4] << " |" << std::endl;
	std::cout << "|___" << "||___" << "||___" << "||___" << "||___" << "|" << std::endl;
	std::cout << "_______________________" << std::endl;


	std::cout << "W A S D -> Move" << std::endl;
	std::cout << "P -> Potion" << std::endl;

	std::cout << " " << std::endl;
	

	std::cout << "Enter your action: " << std::endl;
	std::cin >> respuesta;
	std::cout << std::endl;
	int id;
	if (player->agility == 0)
	{
		//mn->MoveEnemies();
		player->agility = player->maxAgility;
	}
	else if ((respuesta == 'W' || respuesta == 'w') && player->agility > 0 && player->mapPosition.y > 0) {

		player->mapPosition.y--;
		player->agility--;

		if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'E')
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (enemies[i]->mapPosition.x && enemies[i]->mapPosition.y == player->mapPosition.x && player->mapPosition.y) {
					id = i;

				}
			}


			mn->currentScene = COMBAT;
		}
		else if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'C')
		{
			mn->currentScene = CHEST;
		}
	}
	else if ((respuesta == 'A' || respuesta == 'a') && player->agility > 0 && player->mapPosition.x > 0) {

		player->mapPosition.x--;
		player->agility--;
		if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'E')
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (enemies[i]->mapPosition.x && enemies[i]->mapPosition.y == player->mapPosition.x && player->mapPosition.y) {
					id = i;

				}
			}


			mn->currentScene = COMBAT;
		}
		else if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'C')
		{
			mn->currentScene = CHEST;
		}


	}
	else if ((respuesta == 'S' || respuesta == 's') && player->agility > 0 && player->mapPosition.y < 4) {

		player->mapPosition.y++;
		player->agility--;
		if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'E')
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (enemies[i]->mapPosition.x && enemies[i]->mapPosition.y == player->mapPosition.x && player->mapPosition.y) {
					id = i;

				}
			}


			mn->currentScene = COMBAT;
		}
		else if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'C')
		{
			mn->currentScene = CHEST;
		}
	}
	else if ((respuesta == 'D' || respuesta == 'd') && player->agility > 0 && player->mapPosition.x < 4) {

		player->mapPosition.x++;
		player->agility--;
		if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'E')
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				if (enemies[i]->mapPosition.x && enemies[i]->mapPosition.y == player->mapPosition.x && player->mapPosition.y) {
					id = i;

				}
			}


			mn->currentScene = COMBAT;
		}
		else if (mn->map[player->mapPosition.x][player->mapPosition.y] == 'C')
		{
			mn->currentScene = CHEST;
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

void Combat(MainManager* mn, Player* player, std::vector<Enemy*> enemies, int& id) {
	char respuesta;
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

		if (enemies[id]->stamina >= porcentaje) {
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
	aux = player->maxHealth * 0.1f;
	porcentaje = aux;

	for (int i = 0; i < 10; i++)
	{

		if (player->health >= porcentaje) {
			std::cout << "=";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "]" << player->health << "/" << player->maxHealth << "HP" << std::endl;

	std::cout << "[";

	aux = player->maxStamina * 0.1f;
	porcentaje = aux;
	for (int i = 0; i < 10; i++)
	{

		if (player->stamina >= porcentaje) {
			std::cout << ">";
		}
		else {
			std::cout << " ";
		}
		porcentaje += aux;
	}
	std::cout << "]" << player->stamina << "/" << player->maxStamina << "Stamina" << std::endl;
	std::cout << "Potions " << player->potions << "/" << player->maxPotions << std::endl;
	std::cout << "------------------------";
	std::cout << "A -> Attack" << std::endl;
	std::cout << "D -> Defend" << std::endl;
	std::cout << "R -> Rest" << std::endl;
	std::cout << "P -> Potion" << std::endl;
	std::cout << "Enter your action: " << std::endl;
	std::cin >> respuesta;
	std::cout << std::endl;

	switch (respuesta)
	{
		int dmg;
		int dmgEnemy;
		bool defend; 
		bool rest;
		bool attack;
	case 'A':
		defend = enemies[id]->health > enemies[id]->health * 0.3f && enemies[id]->stamina > enemies[id]->stamina * 0.3f;
		rest = enemies[id]->stamina < enemies[id]->stamina * 0.2f;
		attack = (defend = false) && (rest = false);
		do
		{

			std::cout << "Select the amount of stamina to attack,MAX(" << player->stamina << "): " << std::endl;
			std::cin >> dmg;
			if (dmg > player->stamina)
			{
				std::cout << "You don't have that much stamina, try again." << std::endl;
			}
		} while (dmg <= player->stamina);
		
		
		

		if (defend)
		{
			enemies[id]->health -= dmg *0.25f;
			enemies[id]->stamina += enemies[id]->maxStamina * 0.25f;
			player->stamina -= dmg;
			std::cout << "The enemy defended from your attack. He received 25% from your damage." << std::endl;
			

		}
		else if (rest)
		{
			enemies[id]->health -= dmg;
			enemies[id]->stamina = enemies[id]->maxStamina;
			player->stamina -= dmg;
			std::cout << "The enemy took a rest to recover energies, he receives your attack." << std::endl;
		}
		else if (attack)
		{
			dmgEnemy = enemies[id]->stamina * 0.2f + rand() % (enemies[id]->stamina) - (enemies[id]->stamina * 0.2f) + 1;
				if (dmg>=dmgEnemy)
				{
					enemies[id]->health -= dmg;
					enemies[id]->stamina -= dmgEnemy;
					player->stamina -= dmg;
					std::cout << "You struck harder than the enemy, he receives your attack." << std::endl;

				}
				else if (dmgEnemy<dmg)
				{
					enemies[id]->stamina -= dmgEnemy;
					player->health -= dmgEnemy;
					player->stamina -= dmg;
					std::cout << "The enemy strikes harder than you, you receive damage." << std::endl;
				}
				
		}
		if (enemies[id]->health >= 0)
		{
			std::cout << "You win, the enemy dies." << std::endl;
			mn->map[enemies[id]->mapPosition.x][enemies[id]->mapPosition.y] = '=';
			enemies.erase(enemies.begin() + id);
			mn->currentScene = DUNGEON;

		}
		else if (player->health <= 0)
		{
			std::cout << "You died, the enemy won. " << std::endl;
			mn->currentScene = GAMEOVER;
		}
		
		

		break;

	case'D':
		defend = enemies[id]->health > enemies[id]->health * 0.3f && enemies[id]->stamina > enemies[id]->stamina * 0.3f;
		rest = enemies[id]->stamina < enemies[id]->stamina * 0.2f;
		attack = (defend = false) && (rest = false);
		if (defend)
		{
			
			enemies[id]->stamina += enemies[id]->maxStamina * 0.25f;
			player->stamina += player->maxStamina * 0.25f;
			std::cout << "The enemy defended from your attack. He received 25% from your damage." << std::endl;
		}
		else if (rest)
		{
			
			enemies[id]->stamina = enemies[id]->maxStamina;
			player->stamina += player->maxStamina * 0.25f;
		}
		else if (attack)
		{
			dmgEnemy = enemies[id]->stamina * 0.2f + rand() % (enemies[id]->stamina) - (enemies[id]->stamina * 0.2f) + 1;
			enemies[id]->stamina -= dmgEnemy;
			player->health -= dmgEnemy * 0.25f;
			player->stamina += player->maxStamina * 0.25f;
		}
		if (player->health <= 0)
		{
			std::cout << "El enemigo te ha quitado toda la vida." << std::endl;
			mn->currentScene = GAMEOVER;
		}

		break;
	case'R':
		defend = enemies[id]->health > enemies[id]->health * 0.3f && enemies[id]->stamina > enemies[id]->stamina * 0.3f;
		rest = enemies[id]->stamina < enemies[id]->stamina * 0.2f;
		attack = (defend = false) && (rest = false);
		if (defend)
		{

			enemies[id]->stamina += enemies[id]->maxStamina * 0.25f;
			player->stamina = player->maxStamina;
		}
		else if (rest)
		{

			enemies[id]->stamina = enemies[id]->maxStamina;
			player->stamina = player->maxStamina;
		}
		else if (attack)
		{
			dmgEnemy = enemies[id]->stamina * 0.2f + rand() % (enemies[id]->stamina) - (enemies[id]->stamina * 0.2f) + 1;
			enemies[id]->stamina -= dmgEnemy;
			player->health -= dmgEnemy * 0.25f;
			player->stamina += player->maxStamina * 0.25f;
		}

		if (player->health <= 0)
		{
			std::cout << "El enemigo te ha quitado toda la vida." << std::endl;
			mn->currentScene = GAMEOVER;
		}

		break;
	case'P':
		if (player->potions > 0)
		{
			player->potions--;
			player->health += player->maxHealth * 0.4f;
			if (player->health >player->maxHealth)
			{
				player->health = player->maxHealth;
			}
			std::cout << "Has usado una poción!" << std::endl;
		}

		break;
	default:
		std::cout << "This action is not valid or doesn't exist." << std::endl;
		break;
	}
	

}
void Chest(MainManager* mn){}
void GameOver(MainManager* mn){}