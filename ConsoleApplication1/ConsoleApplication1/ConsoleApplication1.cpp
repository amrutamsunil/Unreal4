// BullCowGame.cpp : Defines the entry point32 for the console application.


#include "stdafx.h"
#include<iostream>
#include<string>
#include "Header.h" 

using FText = std::string;
using int32 = int;
void printIntro();
void playGame();
FText getGuess();
bool playAgain();
FbullCowGame BCGame;
int main()
{

	printIntro();
	playGame();
	while (playAgain()) {
		playGame();
	}
	return 0;
}
void printIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows Game\n";
	std::cout << "Can you guess the Xletter isogram I'm thinking of\n";
	std::cout << "WORD_LENGTH : " << WORD_LENGTH << std::endl;
}
FText getGuess() {
	FText guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, guess);

	return guess;
}
void playGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	for (int32 i = 0; i <= MaxTries; i++) {
		FText Guess = getGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows;
	}
	//TODO make loop checking valid
	//submit valid guess to the game
	//print32 number to bulls and cows
}
bool playAgain() {
	FText response = "";
	std::cout << "Do you wanna play again:\n";
	getline(std::cin, response);
	if (response[0] == 'y' || response[0] == 'Y')
		return true;
	return false;
}