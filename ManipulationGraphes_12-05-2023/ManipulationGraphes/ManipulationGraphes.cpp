/* ManipulationGraphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit. */

#include <iostream>

#include "CArc.h"
#include "CFichierGraphe.h"
#include "CGraphe.h"
#include "CSommet.h"

using namespace std;

int main()
{
	/* Creation arc */
	CArc ARCArc1;
	ARCArc1.ARCModifierNumeroDestination(2);

	/* Creation sommets */
	CSommet SOMSommet1; 
	SOMSommet1.SOMModifierNumero(1);
	SOMSommet1.SOMAjouterArcPartant(ARCArc1, 3);

	CSommet SOMSommet2;
	SOMSommet2.SOMModifierNumero(2);
	SOMSommet2.SOMAjouterArcArrivant(ARCArc1, 3);
	

	/* Creation graphe */
	CGraphe GRAGraphe;
	GRAGraphe.GRAAjouterSommet(SOMSommet1, 3);
	GRAGraphe.GRAAjouterSommet(SOMSommet2, 1);

	/* Affichage graphe */
	GRAGraphe.GEGAfficherGraphe();

	/* Modification numeros sommets */

}
