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
***** Entraine : les arcs du graphe sont inverses *****
******************************************************/
void CGraphe::GEGInverserGraphe()
{
	/* l'indice de l'arc a supprimer dans la liste des arcs partants */
	unsigned int uiIndiceArcPartant = 0;

	/* conserve le numero de destination de l'arc avant suppression */
	unsigned int uiDestination = 0;

	/* l'indice de l'arc a ajouter dans la liste des arcs arrivants */
	unsigned int uiIndiceArcArrivant = 0;

	/* contient le numero du sommet source de l'arc arrivant */
	unsigned int uiSource = 0;

	unsigned int uiNombreArcsArrivants = 0;
	unsigned int uiNombreArcsPartants = 0;

	/* On parcourt la liste des sommets */
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		uiNombreArcsArrivants = pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsArrivants();
		uiNombreArcsPartants = pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsPartants();

		/* On parcourt toute la liste des arcs partants du sommet */
		for (unsigned int uiArc = 0; uiArc < uiNombreArcsPartants; uiArc++)
		{
			/* On recupere le numero de la destination */
			uiDestination = pSOMGRAListeSommets[uiSommet]->SOMLireListeArcsPartants()[uiArc]->ARCLireNumeroDestination();

			/* on recupere l'indice de l'arc associe a "uiDestination" */
			uiIndiceArcPartant = pSOMGRAListeSommets[uiSommet]->GEARechercherIndiceArcPartant(uiDestination);

			/* on supprime cet arc */
			pSOMGRAListeSommets[uiSommet]->SOMSupprimerArcPartant(*pSOMGRAListeSommets[uiSommet]->SOMLireListeArcsPartants()[uiIndiceArcPartant]);

			/* On ajoute le numero du sommet courant dans sa liste des arcs arrivants */
			pSOMGRAListeSommets[uiSommet]->SOMAjouterArcArrivant();
		}

		/* On parcourt la liste des arcs arrivants du sommet */
		for (unsigned int uiArc = 0; uiArc < uiNombreArcsArrivants; uiArc++)
		{
			/* On cree un arc vers la source de l'arc precedemment supprime */
			uiSource = GEGChercherSourceArcArrivant(*pSOMGRAListeSommets[uiSommet]->SOMLireListeArcsArrivants()[uiArc]);
			pSOMGRAListeSommets[uiSommet]->SOMAjouterArcPartant(*(new CArc(uiSource)));

			/* on supprime un des arcs de destination le sommet courant */
			pSOMGRAListeSommets[uiSommet]->SOMSupprimerArcArrivant();
		}

	}
	
	
}


