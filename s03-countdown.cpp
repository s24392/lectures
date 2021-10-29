#include <iostream>

int main(int argc, char* argv[]) 
{	
	for (int i = std::stoi(argv[1]); i >= 0; i--) {
		std::cout << (i) << '\n';
	}
	return 0;
}