#include "Game-of-Thrones.h"

int main()
{
	std::string sir;


	std::cout << "================= Salut aici vei vedea daca un sir de caractere poate fi rearanjat ca un palindrom! ================\n";

	do
	{
		sir = citeste_cheia();
		testare_palindrom(sir);

	} while (programul_ruleaza());

	return 0;
}