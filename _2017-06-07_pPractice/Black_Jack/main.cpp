#include<iostream>
#include "Game_System.h"
#include "Manual.h"

Game_System *gameSys;

void release();
int main()
{
	Manual manu;
	gameSys = new Game_System;

	std::cout << "Game Start!!!!" << std::endl;
	std::cout << "--------------------------" << std::endl;

	int input;
	
	std::cout << "Please Select Menu!" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "| 1.GameStart	|" << std::endl;
	std::cout << "| 2.Manual	|" << std::endl;
	std::cout << "| 3.Exit	    |" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cin >> input;

	if (input == 1)
	{
		gameSys->Gameloop();
	}
	if (input == 2)
	{
		manu.Print();
	}
	if (input == 3)
	{
		release();
		return 0;
	}

	int a;
	std::cin >> a;

	delete gameSys;
	return 0;
}

void release()
{
	delete gameSys;
}
