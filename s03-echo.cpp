#include <iostream>
#include <string>

int main(int argc, char* argv[])
{	
	auto const pierwszy = std::string{ argv[1] };
	auto const drugi = std::string{ argv[2] };

	if (pierwszy=="-r")
	{	
		for (int i = (argc-1); i >= 1; i--)
		{
			std::cout << argv[i] << " ";
			if (drugi=="-l")
			{
				std::cout << '\n';
			}
		}
	}
	else
	{
		for (int i = 1; i <= (argc-1); i++)
		{
			std::cout << argv[i] << " ";
			if (pierwszy == "-l")
			{
				std::cout << '\n';
			}
		}
	}
	if (pierwszy == "-n" || pierwszy=="-r" && drugi=="-n")
	{
		return 0;
	}
	else
	{
		std::cout << '\n';
	}
	return 0;
}