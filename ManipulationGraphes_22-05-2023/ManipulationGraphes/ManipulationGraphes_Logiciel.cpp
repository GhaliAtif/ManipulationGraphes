/* ManipulationGraphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit. */

#include <iostream>

#include "CArc.h"
#include "CFichierGraphe.h"
#include "CGraphe.h"
#include "CSommet.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Bienvenue dans le logiciel de gestion de graphes." << endl;

	/* Il n'y a pas exactement 1 argument passe en parametre */
	if (argc != 2)
	{
		cout << "Aucun ou plus d'un nom de fichier ont ete passes en parametre : veuillez reessayer." << endl;
		return EXC_MAUVAIS_NOMBRE_ARGUMENTS;
	}

	/* Creation d'un CGraphe a partir du CFichierGraphe associe */
	CFichierGraphe FIGFichierGraphe();
	CGraphe GRAGraphe(FIGFichierGraphe);
}