#include <iostream>
#include  <string>
int main(int argc, char* argv[])
{	
	auto const password = std::string{argv[1]};
	auto x = std::string{};
	 do{
		 std::cout << "password: ";
		std::cin >> x;
	}while (x != password);
		std::cout << "ok!" << '\n';
		return 0;
}