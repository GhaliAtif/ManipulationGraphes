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
	cout << "Nombre total de sommets : " << uiGRANombreSommets << endl;

	unsigned int NombreArcs = 0;
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		NombreArcs += pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsArrivants();
	}
	cout << "Nombre total d'arcs : " << NombreArcs << endl;
	
	/* Pour un sommet du graphe... */
	for (unsigned int uiNumSommet = 0; uiNumSommet < uiGRANombreSommets; uiNumSommet++)
	{
		cout << "Arcs partant du sommet numero " << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " :" << endl << endl;

		/* ...on lit tous les arcs partants */
		for (unsigned int uiNumArc = 0; uiNumArc < pSOMGRAListeSommets[uiNumSommet]->SOMLireNombreArcsPartants(); uiNumArc++)
		{
			cout << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " ---> " << pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsPartants(uiNumArc)->ARCLireNumeroDestination() << endl;
		}

		cout << endl;
	}

	cout << endl;
}

/******************************************************************************
***** GEGAFFICHERGRAPHEINVERSE : affiche le graphe						  *****
*******************************************************************************
***** Entree: (rien)													  *****
***** Necessite: le graphe courant doit etre obtenu par GEGInverserGraphe *****
***** Sortie: (rien)													  *****
***** Entraine : le graphe est affiche									  *****
******************************************************************************/
void CGraphe::GEGAfficherGrapheInverse()
{
	cout << "Representation du graphe inverse : " << endl;
	cout << "Nombre total de sommets : " << uiGRANombreSommets << endl;

	unsigned int NombreArcs = 0;
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		NombreArcs += pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsArrivants();
	}
	cout << "Nombre total d'arcs : " << NombreArcs << endl;

	/* Pour un sommet du graphe... */
	for (unsigned int uiNumSommet = 0; uiNumSommet < uiGRANombreSommets; uiNumSommet++)
	{
		cout << "Arcs partant du sommet numero " << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " :" << endl << endl;

		/* ...on lit tous les arcs arrivants */
		for (unsigned int uiNumArc = 0; uiNumArc < pSOMGRAListeSommets[uiNumSommet]->SOMLireNombreArcsPartants(); uiNumArc++)
		{
			cout << pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsArrivants(uiNumArc)->ARCLireNumeroDestination() << " ---> " <<  pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << endl;
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
CGraphe & CGraphe::GEGInverserGraphe()
{
	CGraphe* pGRAGraphe = new CGraphe();

	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++) 
	{
		pGRAGraphe->GRAAjouterSommet(pSOMGRAListeSommets[uiBoucleSommet]->GEAInverserArcsArrivantsPartants());
	}

	return *pGRAGraphe;
}


