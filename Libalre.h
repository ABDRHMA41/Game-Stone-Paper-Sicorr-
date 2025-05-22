#pragma once
#include <iostream>
using namespace std;
enum EGameChoice { Stone = 1, Paper=2, Scissors =3};

namespace LibalreRead
{
	void Header()
	{
		cout << "\t\n==========================================================================\n\n" << endl;

		cout << "\t\t  +  +  +  Welcome  To  Play   +  +  + \n \n";
		cout << "\t\t  +  +  +  Stone Paper Scissor  +  +  + \n ";

		cout << "\t\n===========================================================================\n" << endl;
		cout << "\t \t \t Goe\n";

		cout << "\n __________________________________________________________________________\n\n\n";
	}

	//==============================================================
	short ReadHowManyRounds()
	{
		short HowManyRounds = 0;
		do {
			cout << "How Many Rounds Do You Want To Play? (1-10) : ";
			cin >> HowManyRounds;
		} while (HowManyRounds < 1 || HowManyRounds > 10);
		return HowManyRounds;
	}
	//==============================================================
	EGameChoice ReadPlayerChoice()
	{
		short PlayerChoice = 0;
		cout << "Please Enter Your Choice   [   1=Stone    2=Paper    3=Scissors]  :-";
		cin >> PlayerChoice;
		while (PlayerChoice < 1 || PlayerChoice > 3)
		{
			cout << "Invalid choice. Please enter again [ 1=Stone    2=Paper     3=Scissors  ]   :-";
			cin >> PlayerChoice;
		}
		return (EGameChoice)PlayerChoice;
	}
	//==============================================================
	short ReandNumber(int min, int max)
	{
		short RandomNumber = 0;
		RandomNumber = min + rand() % (max - min + 1);
		return RandomNumber;
	}
	EGameChoice ReadComputerChoice()
	{
		short ComputerChoice = 0;
		ComputerChoice = ReandNumber(1, 3);
		return (EGameChoice)ComputerChoice;
		//==================================================================
	}
}