#include <iostream>


main(int argc, char* argv[])
{
	
	if (argc != 1)
	{
		int i = std::stoi(argv[1]);
		for (i;i>0;i--)
		{
			std::cout << (i) << " bottles of beer on the wall, "<< (i) <<" bottles of beer." << '\n' << "  Take one down, pass it around, ";
		}
	}
	else
	{
		for (int i = 99; i > 0; i--)
		{
			std::cout << (i) << " bottles of beer on the wall, "<< (i) << " bottles of beer." << '\n' << "  Take one down, pass it around,";
		}
	}
	std::cout << "No more bottles of beer on the wall, no more bottles of beer" << '\n' << "Go to the store and buy some more";
	return 0;
}