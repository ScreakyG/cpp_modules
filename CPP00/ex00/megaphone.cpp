#include <iostream> // Library qui permet les fonctions d'affichage , recuperer input utilisateurs etc..

//using namespace std; // Sorte de dossier regroupand des fonctions, variables etc .. std correspond a la bibliotheque standard.


int	main(int argc, char **argv)
{
	int			i;
	int			j;
	std::string	str;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	//cout << argv[1] << endl; // à prononcer "c" "out" , cout est fourni par iostream. "endl" cree un retour a la ligne.
	return (0);
}
