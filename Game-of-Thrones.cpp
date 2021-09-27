#include "Game-of-Thrones.h"

bool validare_cheie(std::string& cheie)
{
	if (cheie.empty())
		return false;

	if (cheie.length() <= 1)
		return false;

	for (int j = 0; j < cheie.length(); j++)
		if (!std::islower(cheie[j]))
			return false;


	return true;
}

std::string citeste_cheia()
{
	std::cout << "Apasati tasta enter pt a continua! ";
	std::cin.ignore();
	system("CLS");

	std::string cheie;

	std::cout << "Te rog sa introduci cifrul pentru seiful regelui: ";
	std::getline(std::cin, cheie);

	if (!validare_cheie(cheie))
	{
		std::cout << "=========================================================== \n";
		std::cout << "Nu ai introdus un cifru format din litere mici! \n";
		std::cout << "Te rog sa introduci un sir format doar din litere mici si fara spatii! \n";
		std::cout << "Asteapta pana cand se actualizeaza ecranul! \n";
		Sleep(4000);
		system("CLS");
		return citeste_cheia();
	}

	return cheie;
}

bool testare_palindrom(std::string& cheie)
{
	int contor_aparitii = 0;
	std::vector<char> litere;

	for (int j = 0; j < cheie.length(); j++)
		litere.push_back(cheie[j]);

	for (int j = 0; j < cheie.length(); j++)
	{
		for (int i = 0; i < cheie.length(); i++)
		{
			if (j == i || cheie[j] == '\0' || cheie[i] == '\0')
				continue;

			else if (litere[j] == litere[i])
			{
				litere[j] = '\0';
				litere[i] = '\0';
			}
		}
	}

	for (int j = 0; j < cheie.length(); j++)
	{
		if (litere[j] != '\0')
			contor_aparitii++;
	}

	if (cheie.length() % 2 == 0 && contor_aparitii == 0)
	{
		std::cout << "Da, sirul poate fi rearanjat ca un palindrom! \n";
		std::cout << "=========================================================== \n";
		return true;
	}

	else if (cheie.length() % 2 != 0 && contor_aparitii == 1)
	{
		std::cout << "Da, sirul poate fi rearanjat ca un palindrom! \n";
		std::cout << "=========================================================== \n";
		return true;
	}

	else
	{
		std::cout << "Sirul nu poate fi rearanjat ca un palindrom! \n";
		std::cout << "=========================================================== \n";
		return false;
	}
}

bool programul_ruleaza()
{
	std::string validare_optiune;

	std::cout << "Pentru a verifica daca un alt sir de caractere poate fi rearanjat ca un palindrom apasa tasta 1. \n";
	std::cout << "Daca vrei sa parasesti aplicatia apasa tasta 2. \n";

	std::cout << "=========================================================== \n";

	std::cout << "Alege una din aceste optiuni: ";

	std::cin >> validare_optiune;

	if (validare_optiune.length() > 1)
	{
		system("CLS");
		std::cout << "Optiunea selectata de tine nu exista! \n";
		std::cout << "=========================================================== \n";
		Sleep(500);
		std::cout << "Optiunile posibile sunt: \n";
		return programul_ruleaza();
	}

	char optiune = validare_optiune[0];

	switch (optiune)
	{
	case '1':
		std::cout << "=========================================================== \n";
		std::cout << "Te rugam sa astepti cateva secunde si sa nu apesi nicio tasta in tot acest timp! ";
		Sleep(3000);
		system("CLS");
		return true;

	case '2':
		std::cout << "=========================================================== \n";
		std::cout << "Multumim te mai asteptam cand vei mai dori sa te joci cu sirurile de caractere! \n";
		return false;

	default:
		system("CLS");
		std::cout << "Optiunea selectata de tine nu exista! \n";
		std::cout << "=========================================================== \n";
		Sleep(500);
		std::cout << "Optiunile posibile sunt: \n";
		return programul_ruleaza();
	}
}