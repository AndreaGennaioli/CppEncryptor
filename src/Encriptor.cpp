#include <fstream>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
#include <iomanip>
#include <cstdlib>


char Enctriptor(char key, char input) {
	return ((int) key + (int) input) + 10;
}
char Decriptor(char key, char input) {
	return ((int) input - (int) key) - 10;
}
// key:  becd al posto di abcd quindi:
// se txt:  abcd => becd

std::string  gen_random(int len) {
	std::srand(time(NULL));
    std::string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

int main() {
	int scelta = 0;
	std::cout << "Seleziona operazione:\n1: Encript\n2: Decript\n3: Generate Key\n> ";
	std::cin >> scelta;
	if(scelta == 1) {
		std::string keysFile;
		std::string inputFile;
				
		std::cout << "Key file: ";
		std::cin >> keysFile;
		
	
		std::cout << "Input file: ";
		std::cin >> inputFile;
		
		std::ifstream input(inputFile.c_str());
		std::ofstream output("encripted.txt");
		std::ifstream keys(keysFile.c_str());
		char cK;
		char cI;
		char keysArray[21];
		int index = 0;
		while(keys.get(cK)) {
			index++;
			keysArray[index] = cK;
		}
		index = 0;
		while(input.get(cI)) {
			output << (char)Enctriptor(keysArray[index], cI);
			if(index == 21) {
				index = 0;
			} else index++;
		}
		std::cout << "Il testo criptato è stato salvato in: ./encripted.txt";
		keys.close();
		input.close();
		output.close();
		system("PAUSE");
	} else if(scelta ==2) {
		std::string keysFile;
		std::string inputFile;
		
		std::cout << "Key file: ";
		std::cin >> keysFile;
		
	
		std::cout << "Input file: ";
		std::cin >> inputFile;
		
		std::ifstream input(inputFile.c_str());
		std::ofstream output("decripted.txt");
		std::ifstream keys(keysFile.c_str());
		char cK;
		char cI;
		char keysArray[21];
		int index = 0;
		while(keys.get(cK)) {
			index++;
			keysArray[index] = cK;
		}
		index = 0;
		while(input.get(cI)) {
			output << Decriptor(keysArray[index], cI);
			if(index == 21) {
				index = 0;
			} else index++;
		}
		std::cout << "Il testo decriptato è stato salvato in: ./decripted.txt";
		keys.close();
		input.close();
		output.close();
		system("PAUSE");
	} else if(scelta == 3) {
		std::ofstream output("Key.txt");
		std::string key = gen_random(21);
		int index = 0;
		while(index < 21) {
			output << key[index];
			index++;
		}
		std::cout << "Una nuova Key è stata generata nel file: ./Key.txt";
		system("PAUSE");
	} else exit(0);
	
}
