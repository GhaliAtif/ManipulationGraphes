/* ManipulationGraphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit. */

#include <iostream>

#include "CArc.h"
#include "CFichierGraphe.h"
#include "CGraphe.h"
#include "CSommet.h"

using namespace std;

int main()
{
	try
	{
		/* Creation arcs */
		CArc Arc12(2), Arc13(3), Arc23(3), Arc34(4);

		/* Creation des sommets */
		CSommet Sommet1(1), Sommet2(2), Sommet3(3), Sommet4(4);

		/* Creation graphe */
		CGraphe GRAGraphe;
		GRAGraphe.GRAAjouterSommet(Sommet1);
		GRAGraphe.GRAAjouterSommet(Sommet2);
		GRAGraphe.GRAAjouterSommet(Sommet3);
		GRAGraphe.GRAAjouterSommet(Sommet4);

		GRAGraphe.GRAAjouterArc(1, Arc12);
		GRAGraphe.GRAAjouterArc(1, Arc13);
		GRAGraphe.GRAAjouterArc(2, Arc23);
		GRAGraphe.GRAAjouterArc(3, Arc34);

		/* Affichage graphe */
		GRAGraphe.GEGAfficherGraphe();

		/* Modification numeros sommets */
		GRAGraphe.GRAModifierSommet(5, Sommet1);
		GRAGraphe.GRAModifierSommet(6, Sommet2);
		GRAGraphe.GEGAfficherGraphe();

		/* Modifs arcs */

		GRAGraphe.GRAModifierSommet(1, Sommet1);
		GRAGraphe.GRAModifierSommet(2, Sommet2);


		/*
		cout << "les sommets dans la liste pSOMGRAListeSommets sont :" << endl;
		for (unsigned int i = 0; i < GRAGraphe.GRALireNombreSommets(); i++)
		{
			cout << "dans la case " << i << ", on a le sommet de numero " << GRAGraphe.GRALireListeSommets()[i]->SOMLireNumero() << endl;
		}
		*/

		GRAGraphe.GRAModifierArc(4, 1, Arc13);
		GRAGraphe.GEGAfficherGraphe();
	}

	catch(CException EXCErreur)
	{
		EXCErreur.AFEAfficherErreur();
		return EXCErreur.EXCLireValeur();
	}
}
