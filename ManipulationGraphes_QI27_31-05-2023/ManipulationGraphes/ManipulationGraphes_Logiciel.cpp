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

	/* Il n'y a pas exactement 2 arguments passe en parametre */
	if (argc != 3)
	{
		cout << "Il n'y a pas un nom de fichier et un nombre de couleurs passes en parametre : veuillez reessayer. Rappel : le premier parametre est le fichier texte creant le graphe, tandis que le 2eme est le nombre de couleurs souhaite." << endl;
		return EXC_MAUVAIS_NOMBRE_ARGUMENTS;
	}

	CFichierGraphe FIGFichierGraphe;

	try
	{
		// On prend le parametre k mis en 2eme parametre de l'executable
		unsigned int uiNombreCouleurs = atoi(argv[2]);

		// On actualise le nom du fichier dans FIGFichierGraphe
		FIGFichierGraphe.FIGModifierNomFichier(argv[1]);

		// On stocke les donnees du fichier texte dans FIGFichierGraphe
		FIGFichierGraphe.FIGLireGrapheDansFichier();

		// Creation d'un CGraphe a partir du CFichierGraphe associe
		CGraphe GRAGraphe(FIGFichierGraphe);

		/* Affichage du graphe a l'ecran */
		GRAGraphe.GEGAfficherGraphe();


		/* Inversement de tous les arcs du graphe puis affichage */
		CGraphe GRAInverse;
		GRAInverse = GRAGraphe.GEGInverserGraphe();
		GRAInverse.GEGAfficherGraphe();

		/* Affiche l'existence ou non de la coloration specifique
		du graphe d'apres les regles de l'enonce */

		// Il existe une coloration possible
		if (GRAGraphe.GRAVerifierExistanceColoration(uiNombreCouleurs) == true)
		{
			cout << "Le graphe cree a partir du fichier texte peut etre colorie comme detaille dans l'enonce." << endl;
		}

		// Il n'en existe pas
		else
		{
			cout << "Le graphe cree a partir du fichier texte ne peut pas etre colorie comme detaille dans l'enonce." << endl;
		}

	}
	catch (CException EXCErreur)
	{
		EXCErreur.AFEAfficherErreur();
		return EXCErreur.EXCLireValeur();
	}
	
}