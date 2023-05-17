/* Methodes de la classe CGestionGraphe */

#include <iostream>

#include "CGraphe.h"


using namespace std;

/******************************************************
***** GEGAFFICHERGRAPHE : affiche le graphe		  *****
*******************************************************
***** Entree: (rien)							  *****
***** Necessite: (rien)							  *****
***** Sortie: (rien)							  *****
***** Entraine : le graphe est affiche			  *****
******************************************************/
void CGraphe::GEGAfficherGraphe()
{
	cout << "Representation du graphe : " << endl;

	/* Pour un sommet du graphe... */
	for (unsigned int uiNumSommet = 0; uiNumSommet < uiGRANombreSommets; uiNumSommet++)
	{
		cout << "Arcs partant du sommet numero " << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " :" << endl << endl;

		/* ...on lit tous les arcs partants */
		for (unsigned int uiNumArc = 0; uiNumArc < pSOMGRAListeSommets[uiNumSommet]->SOMLireNombreArcsPartants(); uiNumArc++)
		{
			cout << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " ---> " << pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsPartants()[uiNumArc]->ARCLireNumeroDestination() << endl;
		}

		cout << endl;
	}

	cout << endl;
}

/******************************************************
***** GEGINVERSERGRAPHE : inverse le graphe		  *****
*******************************************************
***** Entree: (rien)							  *****
***** Necessite: (rien)							  *****
***** Sortie: (rien)							  *****
***** Entraine : le graphe est inverse			  *****
******************************************************/
void CGraphe::GEGInverserGraphe()
{

}