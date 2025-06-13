
#include <iostream>
#include<string>
#include"Libalre.h"

enum EGameWinner { Player1=1, Computer =2 ,Drow=3};
struct stRoundInfo
{
	short RoundNumber = 0;
	EGameChoice Player1Choice;
	EGameChoice ComputerChoice;
	EGameWinner Winner; // 1 = Player1, 2 = Computer, 3 = Draw
	string WinnerName = " ";
};
struct stGameResult
{
    short GameRound = 0;
	short Player1WinTimes = 0;
	short computerWinTimes = 0;
	short DrewTimes = 0;
    EGameWinner  GameWinner;  // 
    string WinnerName = " ";
  
};

string ChoiceName(EGameChoice Choice)
{
	switch (Choice)
	{
	case EGameChoice::Stone:
		return "Stone";
	case EGameChoice::Paper:
		return "Paper";
	case EGameChoice::Scissors:
		return "Scissors";
	default:
		return "Unknown";
	}
}

string WinnerName(EGameWinner Winner)
{
	switch (Winner)
	{
	case EGameWinner::Player1:
		return "Player1";
	case EGameWinner::Computer:
		return "Computer";
	case EGameWinner::Drow:
		return "Drow";
	default:
		return "Unknown";
	}
}

void PrintRoundResult(stRoundInfo ReadInfo)
{
	cout << "\n______________________________________ Round  [ " << ReadInfo.RoundNumber << " ] ____________________________________\n" << endl;

	cout << "\nPlayer1 Choice     :    " << ChoiceName(ReadInfo.Player1Choice) << endl;
	cout << "\nComputer Choice    :    " << ChoiceName(ReadInfo.ComputerChoice)<<endl;
	cout << "\nWinner             :    " << WinnerName(ReadInfo.Winner) << endl;
	cout <<"\n______________________________________________________________________________________\n" << endl;
}

EGameWinner WhoWonTheRound(stRoundInfo ReadInfo)
{
	if (ReadInfo.Player1Choice == ReadInfo.ComputerChoice)
	{
		ReadInfo.Winner = EGameWinner::Drow;
	}
	switch (ReadInfo.Player1Choice)
	{

	case EGameChoice::Stone:
		if (ReadInfo.ComputerChoice == EGameChoice::Paper)
		{
			return EGameWinner::Computer;
		}
		break;
		case EGameChoice::Paper:
		if (ReadInfo.ComputerChoice == EGameChoice::Scissors)
		{
			return  EGameWinner::Computer;
		}
		break;
		case EGameChoice::Scissors:
			if (ReadInfo.ComputerChoice == EGameChoice::Stone)
		{
			return  EGameWinner::Computer;
			}
			break;
			return EGameWinner::Player1;

	}
}

EGameWinner WhoWonTheGame(short Player1WinTimes ,short computerWinTimes)
{
	if (Player1WinTimes > computerWinTimes)
	{
		return EGameWinner::Player1;
	}
	else if (Player1WinTimes < computerWinTimes)
	{
		return EGameWinner::Computer;
	}
	else
	{
		return EGameWinner::Drow;
	} 
}

stGameResult    FillGameResult(short GameRound, short PlayWinTimes,short ComputerWinTimes ,short DramTimes)
{
	stGameResult GameResult;

	GameResult.GameRound = GameRound;
	GameResult.Player1WinTimes = PlayWinTimes;	
	GameResult.computerWinTimes = ComputerWinTimes;
	GameResult.DrewTimes= DramTimes;
	GameResult.GameWinner = WhoWonTheGame(PlayWinTimes,ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.GameWinner);
	return GameResult;

}

void SetWinneerScreenColor(EGameWinner Winner)
{

	switch (Winner)

	{
		case EGameWinner::Computer:
			system("color 4f"); // Red background, white text
			cout << "\a";
			break;
		case EGameWinner::Player1:
			system("color 2f"); // Green background, white text
			break;
		case EGameWinner::Drow:
			system("color 6f");
			break;
	}
}

stGameResult PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, computerWinTimes = 0, DrewTimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{  
		cout << "\t\tRound  (  " << GameRound<<" ) Begins +  +  +\n" << endl;
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = LibalreRead::ReadPlayerChoice();
		RoundInfo.ComputerChoice = LibalreRead::ReadComputerChoice();// 1,2,3
	    RoundInfo.Winner = WhoWonTheRound(RoundInfo);// 1 = Player1, 2 = Computer, 3 = Draw
     	RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		if (RoundInfo.Winner= EGameWinner::Player1)
		{
			Player1WinTimes++;
		}
		else if (RoundInfo.Winner == EGameWinner::Computer)
		{
			computerWinTimes++;
		}
		else if (RoundInfo.Winner == EGameWinner::Drow)
		{
			DrewTimes++;
		}
		PrintRoundResult(RoundInfo);
	}
	return FillGameResult(HowManyRounds,Player1WinTimes,computerWinTimes,DrewTimes);


}

void ShowGameOveresult()
{
	cout << "\t\n=====================================================================" << endl;
	cout << "\t\t +   +   +   Game Over  +   +   + " <<endl;
	cout << "\t\n=====================================================================" << endl;


}

void ShowGameOveresult(stGameResult GameResult)
{


	system("cls");

	cout << "\t\n____________________________[ Game  Results ]________________________________________\n" << endl;
	cout << "Game Round         : " << GameResult.GameRound << endl;
	cout << "Player1 Win Times  : " << GameResult.Player1WinTimes << endl;
	cout << "Computer Win Times : " << GameResult.computerWinTimes<<endl;
	cout << "Drew Times         : " << GameResult.DrewTimes<<endl;
	cout << "Game Winner        : " << GameResult.WinnerName << endl;
	cout << "\t\n_____________________________________________________________________________________\n" << endl;


}

void ResetScreen()
{
    system("cls");
	system("color 0f");

}

void startGame()
{

	char playAgain = 'y';
	do
	{
		ResetScreen();
	 LibalreRead::Header();
		stGameResult PlayGameResults = PlayGame(LibalreRead::ReadHowManyRounds());
		ShowGameOveresult(PlayGameResults);
		SetWinneerScreenColor(PlayGameResults.GameWinner);
		ShowGameOveresult();
		//system("cls");
		cout << "\t #  Do You Want To Play The Game? (Y/N) :-  \n ";
		cin >> playAgain;
		if(playAgain == 'n'||playAgain=='N')
		{
			system("cls");
			SetWinneerScreenColor(PlayGameResults.GameWinner);
			LibalreRead::Thank_User_For_Play_Game();
		}
	
	}
	while (playAgain == 'y' || playAgain == 'Y');

}

int main()
{
     srand((unsigned)time(NULL));
	ResetScreen();
     startGame();
   
    return 0;
}