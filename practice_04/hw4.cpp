#include <iostream>
#include <string>

char Incode(char stringSymbol, int key) {
	return char(int(stringSymbol) + key);
}

char Decode(char stringSymbol, int key) {
	return char(int(stringSymbol) - key);
}
int main() {
	std::string input;
	char mode;
	int key;

	std::cout << "Enter \"e\" to incode/ \"d\" to decode" << std::endl;

	std::cin >> mode;
	switch (mode)
	{
	case ('e'):
		std::cout << "Enter the string to incode: " << std::endl;
		std::cin >> input;
		std::cout << "Enter the incoding key: " << std::endl;
		std::cin >> key;
		for (int i = 0; i < input.length(); i++) {
			input[i] = Incode(input[i], key);
		}
		std::cout << input;
		break;
	case('d'):
		std::cout << "Enter the string to decode: " << std::endl;
		std::cin >> input;
		std::cout << "Enter the decoding key: " << std::endl;
		std::cin >> key;
		for (int i = 0; i < input.length(); i++) {
			input[i] = Decode(input[i], key);
		}
		std::cout << input;
		break;
	default:
		std::cout << "Wrong option!" << std::endl;
		break;
	}

}
