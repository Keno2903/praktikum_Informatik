///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code

	for(int i = 0; i<wort.length(); i++) {
		for(int j = 0; j<26;j++) {
			if(wort[i] == schluessel[0][j])
			{
				wort[i] = schluessel[1][j];
				break;
			}
		}
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	for(int i = 0; i<wort.length(); i++) {
			for(int j = 0; j<26;j++) {
				if(wort[i] == schluessel[1][j])
				{
					wort[i] = schluessel[0][j];
					break;
				}
			}
		}

	return wort;
}

int main()
{
	char encryption[2][26] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}, {'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Y', 'X', 'C', 'V', 'B', 'N', 'M'} };

	std::string key;

	std::cout << "Bitte geben sie ein Wort ein" << std::endl;
	std::cin >> key;

	// Encrypt the string
	key = verschluesseln(encryption, key);
	std::cout << "Encrypted: " << key << std::endl;

	// Decrypt the string back
	key = entschluesseln(encryption, key);
	std::cout << "Decrypted: " << key << std::endl;

	return 0;


	return 0;
}
