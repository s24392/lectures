#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <string>

int main()
{
	srand(time(NULL));
	int liczba = rand() % 100 + 1;
	int guess=0;
	std::string guess_string;
	
	do
	{
		std::cout << "guess: ";
		std::getline(std::cin, guess_string);
		guess = std::stoi(guess_string);
		 if (guess>liczba) {
			std::cout << "number too big!" << '\n';
		}
		else if (guess < liczba) {
			std::cout << "number too small!" << '\n';
		} 
	} while (guess!=liczba);
	
	std::cout << "just right!" << '\n';
}