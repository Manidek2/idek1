// Roulette.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <tchar.h>

using namespace std;

//Calculates the users bank account if they win
int win(int bet, int odds, int account) {
	int newBank = 0;
	int oldBank = account;
	newBank = oldBank + (bet * odds);
	return newBank;
}

//Calculates users bank account if they lose
int lose(int bet, int account) {
	int newBank = 0;
	int oldBank = account;
	newBank = oldBank - bet;
	return newBank;
}

int _tmain(int argc, _TCHAR* argv[]) {
	int bankAccount = 500, playAgain = 1, betNumber = 0, betAmount = 0, betOdds = 35, randomNumber = 0, betChoice = 0;
	string betName[11] = { "Single Number", "Split Bet", "Corner Bet", "Street Bet", "Line Bet", "Dozens", "Odd or Even", "Red or Black", "Column Bets", "1-18", "19-36" };
	int betType[11] = { 35, 17, 8, 11, 5, 2, 1, 1, 2, 1, 1 };
	int red[18] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	int black[18] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };
	int firstColumn[12] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
	int secondColumn[12] = { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
	int thirdColumn[12] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };
	bool columnWin = false;
	bool colourWin = false;

	//Displays a large dollar sign
	cout << endl << "       " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36;
	cout << endl << "       " << (char)36 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << "   " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36;
	cout << endl << " " << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << "       " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36;
	cout << endl << " " << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36;
	cout << endl << "   " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << "            " << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << "            " << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << "       " << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << (char)36 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36;
	cout << endl << " " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << (char)58 << (char)58 << (char)58 << (char)36 << (char)36 << (char)36 << (char)36 << (char)36;
	cout << endl << "      " << (char)36 << (char)58 << (char)58 << (char)58 << (char)36;
	cout << endl << "      " << (char)36 << (char)36 << (char)36 << (char)36 << (char)36 << endl;
	cout << endl;

	cout << "*****************************" << endl;
	cout << "Welcome to Wildfire Roulette!" << endl;
	cout << "*****************************" << endl;

	//Checks if user wants to play
	while (playAgain == 1) {
		//Displays amount of money remaining in account
		cout << endl << "You have $" << bankAccount << " in your account." << endl << endl;

		for (int i = 0; i < 11; i++) {
			cout << i + 1 << ". " << betName[i] << " - " << betType[i] << " to 1" << endl;
		}

		cout << endl << "Please select a bet type: ";
		cin >> betChoice;

		while (betChoice < 1 || betChoice > 11) {
			cout << endl << "Please choose a number between 1 and 11, inclusive: ";
			cin >> betChoice;
		}

		cout << "You chose " << betName[betChoice - 1] << "." << endl;

		//Stores their bet odds in a variable
		betOdds = betType[betChoice - 1];

		//Checks which type of bet the user chose, and then proceeds with the calculations
		switch (betChoice) {
		case 1:
			//Asks for number to place bet on
			cout << endl << "Please choose a number to place your bet on: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber < 1 || betNumber > 36) {
				cout << endl << "You must choose a valid number between 1 and 36, inclusive!" << endl;
				cout << "Please choose a number to place your bet on: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the number " << betNumber << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 2:
			//Asks for the first number to place a bet on
			cout << endl << "Please choose your first number to place your bet on: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber < 1 || betNumber > 33) {
				cout << endl << "You must choose a valid number between 1 and 33, inclusive!" << endl;
				cout << "Please choose a number to place your bet on: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the numbers " << betNumber << " and " << betNumber + 3 << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber || betNumber + 3 == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 3:
			//Asks for the first number to place a bet on
			cout << endl << "Please choose your first number to place your bet on: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber < 1 || betNumber > 32) {
				cout << endl << "You must choose a valid number between 1 and 32, inclusive!" << endl;
				cout << "Please choose a number to place your bet on: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the numbers " << betNumber << ", " << betNumber + 1 << ", " << betNumber + 3 << " and " << betNumber + 4 << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber || betNumber + 1 == randomNumber || betNumber + 3 == randomNumber || betNumber + 4 == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 4:
			//Asks for the first number to place a bet on
			cout << endl << "Please choose your first number to place your bet on: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber < 3 || betNumber > 36) {
				cout << endl << "You must choose a valid number between 3 and 36, inclusive!" << endl;
				cout << "Please choose a number to place your bet on: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the numbers " << betNumber << ", " << betNumber - 1 << " and " << betNumber - 2 << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber || betNumber - 1 == randomNumber || betNumber - 2 == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 5:
			//Asks for the first number to place a bet on
			cout << endl << "Please choose your first number to place your bet on: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber < 3 || betNumber > 33) {
				cout << endl << "You must choose a valid number between 3 and 33, inclusive!" << endl;
				cout << "Please choose a number to place your bet on: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the numbers " << betNumber << ", " << betNumber - 1 << ", " << betNumber - 2 << ", " << betNumber + 1 << ", " << betNumber + 2 << " and " << betNumber + 3 << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber || betNumber - 1 == randomNumber || betNumber - 2 == randomNumber || betNumber + 1 == randomNumber || betNumber + 2 == randomNumber || betNumber + 3 == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 6:
			//Asks for the range of numbers to place a bet on
			cout << endl << "Please select a range of numbers to place your bet on.";
			cout << endl << "Enter '1' for 1-12, '13' for 13-24, or '25' for 25-36: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber != 1 && betNumber != 13 && betNumber != 25) {
				cout << endl << "Please enter '1' for 1-12, '13' for 13-24, or '25' for 25-36: ";
				cin >> betNumber;
			}

			//Asks for amount to bet on that number
			cout << endl << "How much would you like to bet on the numbers " << betNumber << "-" << betNumber + 11 << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == randomNumber || betNumber + 1 == randomNumber || betNumber + 2 == randomNumber || betNumber + 3 == randomNumber || betNumber + 4 == randomNumber || betNumber + 5 == randomNumber || betNumber + 6 == randomNumber || betNumber + 7 == randomNumber || betNumber + 8 == randomNumber || betNumber + 9 == randomNumber || betNumber + 11 == randomNumber) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 7:
			//Asks for a type of number to place a bet on
			cout << endl << "Please select a type of number to place your bet on.";
			cout << endl << "Enter '1' for odd, or '2' for even: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber != 1 && betNumber != 2) {
				cout << endl << "Please enter '1' for odd, or '2' for even: ";
				cin >> betNumber;
			}

			//Asks for amount to bet
			if (betNumber == 1) {
				cout << endl << "How much would you like to bet on the odd numbers? $";
				cin >> betAmount;
			}
			else if (betNumber == 2) {
				cout << endl << "How much would you like to bet on the even numbers? $";
				cin >> betAmount;
			}

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (betNumber == 1 && randomNumber % 2 != 0 || betNumber == 2 && randomNumber % 2 == 0) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 8:
			//Asks for a colour to place a bet on
			cout << endl << "Please select a type of number to place your bet on.";
			cout << endl << "Enter '1' for red, or '2' for black: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber != 1 && betNumber != 2) {
				cout << endl << "Please enter '1' for red, or '2' for black: ";
				cin >> betNumber;
			}

			//Asks for amount to bet
			if (betNumber == 1) {
				cout << endl << "How much would you like to bet on the red numbers? $";
				cin >> betAmount;
			}
			else if (betNumber == 2) {
				cout << endl << "How much would you like to bet on the black numbers? $";
				cin >> betAmount;
			}

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			for (int x = 0; x < 18; x++) {
				colourWin = false;

				if (betNumber == 1 && randomNumber == red[x] || betNumber == 2 && randomNumber == black[x]) {
					bankAccount = win(betAmount, betOdds, bankAccount);
					cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
					colourWin = true;
					x = 18;
				}
			}

			if (colourWin == false) {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 9:
			//Asks for a colour to place a bet on
			cout << endl << "Please select a column to place your bet on.";
			cout << endl << "Enter '1' for the 1st column, '2' for 2nd column, or '3' for the 3rd column: ";
			cin >> betNumber;

			//Checks if number is valid (between 1 and 36)
			while (betNumber != 1 && betNumber != 2 && betNumber != 3) {
				cout << endl << "Please enter '1' for the first column, '2' for second column, or '3' for the third column: ";
				cin >> betNumber;
			}

			//Asks for amount to bet
			cout << endl << "How much would you like to bet on the numbers in column " << betNumber << "? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			for (int y = 0; y < 12; y++) {
				columnWin = false;

				if (betNumber == 1 && randomNumber == firstColumn[y] || betNumber == 2 && randomNumber == secondColumn[y] || betNumber == 3 && randomNumber == thirdColumn[y]) {
					bankAccount = win(betAmount, betOdds, bankAccount);
					cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
					columnWin = true;
					y = 12;
				}
			}

			if (columnWin == false) {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 10:
			//Asks for amount to bet
			cout << endl << "How much would you like to bet on the numbers between 1 and 18, inclusive? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (randomNumber >= 1 && randomNumber <= 18) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		case 11:
			//Asks for amount to bet
			cout << endl << "How much would you like to bet on the numbers between 19 and 36, inclusive? $";
			cin >> betAmount;

			//Checks if minimum amount is $1 and if the player has enough money in their account
			while (betAmount < 1 || betAmount > bankAccount) {
				cout << endl << "You have $" << bankAccount << " in your bank account: $";
				cin >> betAmount;
			}

			//Seeds random number to the generator
			srand(time(0));

			//Generates a random number
			randomNumber = 1 + (rand() % 36);

			cout << endl << "The ball landed on the number " << randomNumber << ".";

			//Checks if player won or lost their bet
			if (randomNumber >= 19 && randomNumber <= 36) {
				bankAccount = win(betAmount, betOdds, bankAccount);
				cout << endl << "Congratulations, you won! You now have $" << bankAccount << " in your account." << endl;
			}
			else {
				bankAccount = lose(betAmount, bankAccount);
				cout << endl << "Bad luck, you lost! You now have $" << bankAccount << " in your account." << endl;
			}

			break;
		}

		//Checks if user has any money left and notifies them if they have less than $50 remaining
		if (bankAccount == 0) {
			playAgain = 0;
		}
		else if (bankAccount < 50) {
			cout << endl << "Your funds are quite low." << endl;
			cout << endl << "Would you like to play again? Enter 1 to play or 0 to quit: ";
			cin >> playAgain;
		}
		else {
			cout << endl << "Would you like to play again? Enter 1 to play or 0 to quit: ";
			cin >> playAgain;
		}

		//Checks if user entered 1 or 0 - if not, they are asked to enter a valid number
		while (playAgain != 0 && playAgain != 1) {
			cout << endl << "Please enter 1 to play or 0 to quit: ";
			cin >> playAgain;
		}
	}

	if (bankAccount > 500) {
		cout << endl << "You made $" << bankAccount - 500 << "in total!" << endl;
	}
	else if (bankAccount < 500) {
		cout << endl << "You lost $" << 500 - bankAccount << " in total!" << endl;
	}
	else {
		cout << endl << "You still have $500 in your account!" << endl;
	}

	cout << endl << "Hope to see you soon!" << endl << endl;
	system("pause");
	return 0;
}
