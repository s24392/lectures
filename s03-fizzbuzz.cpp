#include <iostream>
#include <string>

int main(int argc , char* argv[])
{
	int liczba=std::stoi(argv[1]);
	for (int x = 1; x <=liczba ; x++)
	{
		std::cout << (x) <<'\n';
			if ((x) % 3==0)
			{
				std::cout <<"Fizz";
			}
			if ((x) % 5 == 0)
			{
				std::cout << "Buzz";
			}
		std::cout << '\n';
			
	}
	return 0;



}