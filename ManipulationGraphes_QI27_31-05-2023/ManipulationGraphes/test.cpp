/* ManipulationGraphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit. */

#include <iostream>

#include "CArc.h"
#include "CFichierGraphe.h"
#include "CGraphe.h"
#include "CSommet.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Bienvenue dans le logiciel de gestion de graphes." << endl << endl;

	/* Il n'y a pas exactement 1 argument passe en parametre */
	if (argc != 2)
	{
		cout << "Aucun ou plus d'un nom de fichier ont ete passes en parametre : veuillez reessayer." << endl;
		return EXC_MAUVAIS_NOMBRE_ARGUMENTS;
	}

	CFichierGraphe FIGFichierGraphe;
	unsigned int * listeIndicesSource = nullptr;

	try
	{
		/*test*/
		CGraphe test;
		CSommet som1(1), som2(2), som3(3);
		CArc arc12(2), arc23(3), arc31(1);
		test.GRAAjouterSommet(som1);
		test.GRAAjouterSommet(som2);
		test.GRAAjouterSommet(som3);
		test.GRAAjouterArc(1, arc12);
		test.GRAAjouterArc(2, arc23);
		test.GRAAjouterArc(3, arc31);
		cout << "test affichage" << endl;
		test.GEGAfficherGraphe();

		cout << "test inverser graphe" << endl;
		CGraphe testInverse = test.GEGInverserGraphe();
		testInverse.GEGAfficherGraphe();


	}
	catch (CException EXCErreur)
	{
		EXCErreur.AFEAfficherErreur();
		return EXCErreur.EXCLireValeur();
	}

}