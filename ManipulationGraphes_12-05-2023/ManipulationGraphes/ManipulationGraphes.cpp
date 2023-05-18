/* ManipulationGraphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit. */

#include <iostream>

#include "CArc.h"
#include "CFichierGraphe.h"
#include "CGraphe.h"
#include "CSommet.h"

using namespace std;

int main()
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

	cout << "Le graphe possede " << GRAGraphe.GRALireNombreSommets() << " sommets, et dans chaque case de la liste, on a :" << endl;
	for (unsigned int i = 0; i < GRAGraphe.GRALireNombreSommets(); i++)
	{
		cout << "ds la case " << i << ", on a l'adresse " << GRAGraphe.GRALireListeSommets()[i] << endl;
		cout << "le sommet associe a cette case possede " << GRAGraphe.GRALireListeSommets()[i]->SOMLireNombreArcsArrivants() << "arcs arrivants et " << GRAGraphe.GRALireListeSommets()[i]->SOMLireNombreArcsPartants() << "arcs partants." << endl << endl;
	}

	GRAGraphe.GRAAjouterArc(1, Arc12);
	GRAGraphe.GRAAjouterArc(1, Arc13);
	GRAGraphe.GRAAjouterArc(2, Arc23);
	GRAGraphe.GRAAjouterArc(3, Arc34);



	/* Affichage graphe */
	GRAGraphe.GEGAfficherGraphe();

	/* Modification numeros sommets */

}
