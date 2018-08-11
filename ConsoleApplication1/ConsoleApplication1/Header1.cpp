#include "Header.h"
#include "stdafx.h"


FbullCowGame::FbullCowGame()
{
	Reset();
}
void FbullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
}
int32 FbullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FbullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FbullCowGame::IsGameWon() const
{
	return false;
}
bool FbullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FbullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j <= HiddenWordLength; j++) {
			if (Guess[i] == MyHiddenWord[j] && i == j)
			{
				++BullCowCount.Bulls;
			}
			else if (Guess[i] == MyHiddenWord[j]) { ++BullCowCount.Cows; }


		}
	}

	return BullCowCount;
}
