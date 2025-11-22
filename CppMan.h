#ifndef CPPMAN
#define CPPMAN

#include "Words.h"
#include <array>
#include "Random.h"
#include <cstddef>
#include <iostream>
#include <string_view>


constexpr std::string_view g_congrats
{
	"Congrats! you guessed the word!!"
};

constexpr std::string_view g_failure
{
	"You suck => "
};


inline std::string genOutline (std::string_view word)			//Generates the outline of the word to guess
{
	std::string outline {};
	outline.reserve(word.size());

	for (size_t len { 0 }; len < word.size(); ++len)
	{
		outline.push_back('_');
	}

	return outline;
}


inline void setOutline(											//Fills in letters as guessed correct
	std::string&	   outline,
	size_t 			   corrIndex,
	char			   letter)
{
	outline[corrIndex] = letter;
}


inline void checkOutline(std::string& outline, bool& status)	//Checks if we got the word to end game
{
	for (char letter : outline)
	{
		if (letter == '_')
		{
			return;
		}
	}

	status = true;
}


inline void setLives(std::string& lives,
					 char letter,
					 bool& status)								//Returns health
{
	static size_t index { lives.size() - 1 };
	lives[index] = letter;
	--index;

	for (char charctr : lives)
	{
		if (charctr == '*') return;								//Make sure we still have lives
	}															//If not then we end the game

	status = true;
}


inline bool checkLetter(										//Checks the letter
	std::string_view   word,									//Sets the index for setting completion
	char 			   letter,
	size_t&			   corrIndex)
{
	for (size_t index { 0 }; index < word.size(); ++index)
	{
		if (letter == word[index])
		{
			corrIndex = index;
			return true;
		}
	}

	return false;
}


inline std::string_view genWord()								//Generates the word to guess
{
	const std::array<std::string_view, 100>* Dict { getDict() };

	size_t index { Random::get(0, 99) };

	std::string_view word = Dict->at(index);

	return word;
}


inline void cppMan()
{
	std::string 	  word 	  { genWord() };					//Generates a word
																//Uses move semantics if not elided
	std::string 	  lives   { "******" };						//Generates lives
	std::string 	  outline { genOutline(word) };				//Generates the outline thats filled in as the user makes guesses
	char			  letter  {};								//letter that the user guesses
	size_t			  cIndex  {};								//The index of the correct letter
	bool			  status  { false };						//Status of game

	while (!status)
	{
		std::cout << "The word: " << outline;					//Prints stats
		std::cout << "   Wrong guesses: " << lives << '\n';
		std::cout << "Enter your next letter: ";
		std::cin  >> letter;

		if (checkLetter(word, letter, cIndex))					//If true
		{
			std::cout << "Yes, \'" << letter;
			std::cout << "\' is in the word!\n\n";
			
			setOutline(outline, cIndex, letter);				//Fill in letters
			checkOutline(outline, status);						//Check if we won

			if (status) std::cout << g_congrats;				//Print winning message
		}
		else													//If false
		{
			std::cout << "No, \'" << letter;
			std::cout << "\' is not the in the word\n\n";

			setLives(lives, letter, status);					//Take away a life and loose game if out
			
			if (status) { std::cout << g_failure << word; }		//Print failing message
		}
	}
}


#endif
