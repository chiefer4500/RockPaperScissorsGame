#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct stHowManyWin
{
	int PlayerWinCount = 0;
	int ComputerWinCount = 0;
	int DrawCount = 0;
};

enum enRoundResult {
	UserWin = 1,
	ComputerWin = 2,
	Draw = 3
};

enum enRPS
{
	Rock = 1, Paper = 2, Scissors = 3
};

// 
int ReadPositiveNumberFrom1to10(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 1 || Number > 10);

	return Number;
}

short RandomNumberFromTo(short From, short To)
{
	short Number;
	return Number = rand() % (To - From + 1) + From;
}

enRPS GetPlayerChoice()
{
	short Choice = 0;

	do
	{
		cout << "Your Choice : [1] Rock ,[2] Paper ,[3] Scissors ? ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			return enRPS::Rock;

		case 2:
			return enRPS::Paper;

		case 3:
			return enRPS::Scissors;

		default:
			cout << "Invalid choice ! Enter just numbers 1, 2 or 3.\n ";
		}

	} while (Choice < 1 || Choice > 3);

	return enRPS::Rock;
}

enRPS GetComputerChoice()
{
	short Choice = RandomNumberFromTo(1, 3);

	switch (Choice)
	{
	case 1:
		return enRPS::Rock;

	case 2:
		return enRPS::Paper;

	case 3:
		return enRPS::Scissors;
	}

	return enRPS::Rock;
}

enRoundResult GetRoundWinner(enRPS ChoiceUser, enRPS ChoiceComputer)
{
	if (ChoiceUser == enRPS::Rock && ChoiceComputer == enRPS::Scissors)
	{
		return enRoundResult::UserWin;
	}
	else if (ChoiceUser == enRPS::Rock && ChoiceComputer == enRPS::Paper)
	{
		return enRoundResult::ComputerWin;
	}
	else if (ChoiceUser == enRPS::Paper && ChoiceComputer == enRPS::Rock)
	{
		return enRoundResult::UserWin;
	}
	else if (ChoiceUser == enRPS::Paper && ChoiceComputer == enRPS::Scissors)
	{
		return enRoundResult::ComputerWin;
	}
	else if (ChoiceUser == enRPS::Scissors && ChoiceComputer == enRPS::Paper)
	{
		return enRoundResult::UserWin;
	}
	else if (ChoiceUser == enRPS::Scissors && ChoiceComputer == enRPS::Rock)
	{
		return enRoundResult::ComputerWin;
	}
	else if (ChoiceUser == ChoiceComputer)
	{
		return enRoundResult::Draw;
	}

	return enRoundResult::Draw;
}

void SetScreenColor(enRoundResult Winner)
{
	switch (Winner)
	{
	case enRoundResult::UserWin:
		system("color 2F");
		break;

	case enRoundResult::ComputerWin:
		cout << "\a";
		system("color 4F");
		break;

	case enRoundResult::Draw:
		system("color 6F");
		break;
	}
}

enRoundResult PrintRoundResults(enRPS ChoiceUser, enRPS ChoiceComputer)
{
	enRoundResult Winner = GetRoundWinner(ChoiceUser, ChoiceComputer);

	SetScreenColor(Winner);

	switch (ChoiceUser)
	{
	case enRPS::Rock:
		cout << "Player1 choice : Rock\n";
		break;
	case enRPS::Paper:
		cout << "Player1 choice : Paper\n";
		break;
	case enRPS::Scissors:
		cout << "Player1 choice : Scissors\n";
		break;
	}

	switch (ChoiceComputer)
	{
	case enRPS::Rock:
		cout << "Computer choice : Rock\n";
		break;
	case enRPS::Paper:
		cout << "Computer choice : Paper \n";
		break;
	case enRPS::Scissors:
		cout << "Computer choice : Scissors \n";
		break;
	}

	switch (Winner)
	{
	case enRoundResult::UserWin:
		cout << "Round winner  : [Player1]\n";
		break;
	case enRoundResult::ComputerWin:
		cout << "Round winner : [Computer]\n";
		break;
	case enRoundResult::Draw:
		cout << "Round winner  : [Draw]\n";
		break;
	}

	return Winner;
}

stHowManyWin RunGameRounds(short Round)
{
	stHowManyWin Win;

	for (int i = 1; i <= Round; i++)
	{
		cout << "----------Round[" << i << "]---------------\n\n";

		enRoundResult Winner = PrintRoundResults(GetPlayerChoice(), GetComputerChoice());

		if (Winner == enRoundResult::UserWin) Win.PlayerWinCount++;
		else if (Winner == enRoundResult::ComputerWin) Win.ComputerWinCount++;
		else Win.DrawCount++;

		cout << "\n------------------------------\n";
	}

	return Win;
}

void PrintGameOver()
{
	cout << "\t-----------------------------------------\n";
	cout << "\t             ++Game Over++                \n";
	cout << "\t-----------------------------------------\n";
}

void PrintGameScore(short Round)
{
	stHowManyWin Win = RunGameRounds(Round);

	PrintGameOver();
	cout << "\n\t------------------[Game Results]------------\n";
	cout << "\t Game Rounds        : " << Round << "\n";
	cout << "\t Player1 Win Times  : " << Win.PlayerWinCount << "\n";
	cout << "\t Computer Win Times : " << Win.ComputerWinCount << "\n";
	cout << "\t Draw Times         : " << Win.DrawCount << "\n";

	if (Win.PlayerWinCount > Win.ComputerWinCount)
		cout << "\t Final Winner       : Player1\n";
	else if (Win.ComputerWinCount > Win.PlayerWinCount)
		cout << "\t Final Winner       : Computer\n";
	else
		cout << "\t Final Winner       : No Winner\n";

	cout << "______________________________________________\n";
}

void StartPlay()
{
	char Answer;
	do
	{
		system("color 07");
		PrintGameScore(ReadPositiveNumberFrom1to10("How many rounds ?"));
		cout << "\n Do you want to play again? Y/N: ";
		cin >> Answer;
	} while (Answer == 'Y' || Answer == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartPlay();
	return 0;
}