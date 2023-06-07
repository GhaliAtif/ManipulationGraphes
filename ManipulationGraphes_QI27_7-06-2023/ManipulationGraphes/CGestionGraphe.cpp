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

/************************************************************************
***** GEGAFFICHERGRAPHENONORIENTE : affiche le graphe non oriente	*****
*************************************************************************
***** Entree: (rien)												*****
***** Necessite: (rien)												*****
***** Sortie: (rien)												*****
***** Entraine : le graphe est affiche sans orientation				*****
************************************************************************/
void CGraphe::GEGAfficherGrapheNonOriente()
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
		cout << "Arcs connectes au sommet numero " << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " :" << endl << endl;

		/* ...on lit tous les arcs partants */
		for (unsigned int uiNumArc = 0; uiNumArc < pSOMGRAListeSommets[uiNumSommet]->SOMLireNombreArcsPartants(); uiNumArc++)
		{
			cout << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " ---- " << pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsPartants(uiNumArc)->ARCLireNumeroDestination() << endl;
		}

		cout << endl;
	}

	cout << endl;
}

/************************************************************************************************
***** GEGAFFICHERSOLUTIONCOLORATION : affiche le graphe avec une coloration particuliere	*****
*************************************************************************************************
***** Entree: (rien)																		*****
***** Necessite: (rien)																		*****
***** Sortie: (rien)																		*****
***** Entraine : le graphe est affiche avec les couleurs associees a chaque sommet			*****
************************************************************************************************/
void CGraphe::GEGAfficherSolutionColoration()
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
		cout << "Arcs connectes au sommet numero " << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " :" << endl << endl;

		/* ...on lit tous les arcs partants et le numero de couleur du sommet */
		unsigned int uiIndiceSommetArrivee = 0;
		for (unsigned int uiNumArc = 0; uiNumArc < pSOMGRAListeSommets[uiNumSommet]->SOMLireNombreArcsPartants(); uiNumArc++)
		{
			uiIndiceSommetArrivee = GEGRechercherIndiceSommet(pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsPartants(uiNumArc)->ARCLireNumeroDestination());
			cout << pSOMGRAListeSommets[uiNumSommet]->SOMLireNumero() << " (couleur " << pSOMGRAListeSommets[uiNumSommet]->SOMLireGestionCouleur().GCSLireNumeroCouleur() << ") ---- " << pSOMGRAListeSommets[uiNumSommet]->SOMLireListeArcsPartants(uiNumArc)->ARCLireNumeroDestination() << " (couleur " << pSOMGRAListeSommets[uiIndiceSommetArrivee]->SOMLireGestionCouleur().GCSLireNumeroCouleur() << ")" << endl;
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
	pGRAGraphe->bGRAUtiliseOperateurNew = true;

	/*  On copie tous les sommets du graphe courant */
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		pGRAGraphe->GRAAjouterSommet(*new CSommet(GRALireListeSommets()[uiSommet]->SOMLireNumero()));
	}


	/* Pour chaque sommet, on va modifier les destinations des arcs partants et arrivants */
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		/* Pour un sommet donne, on recupere l'indice de liste des sommets de depart de chacun de ses arcs arrivants */
		unsigned int * puiListeIndiceSourcesArcsArrivants = GEGChercherIndiceSourceArcsArrivants(*GRALireListeSommets()[uiSommet]);
		unsigned int uiIndiceSource;
		for (unsigned int uiArcArrivant = 0; uiArcArrivant < GRALireListeSommets()[uiSommet]->SOMLireNombreArcsArrivants(); uiArcArrivant++)
		{
			uiIndiceSource = puiListeIndiceSourcesArcsArrivants[uiArcArrivant];
			pGRAGraphe->GRALireListeSommets()[uiSommet]->SOMAjouterArcPartant(*new CArc(GRALireListeSommets()[uiIndiceSource]->SOMLireNumero()));
		}

		/* On ajoute a la copie un nombre d'arcs arrivants egal au nombre d'arcs partants du graphe initial */
		for (unsigned int uiArcArrivant = 0; uiArcArrivant < GRALireListeSommets()[uiSommet]->SOMLireNombreArcsPartants(); uiArcArrivant++)
		{
			pGRAGraphe->GRALireListeSommets()[uiSommet]->SOMAjouterArcArrivant(*new CArc(pGRAGraphe->GRALireListeSommets()[uiSommet]->SOMLireNumero()));
		}

		/* On desalloue la liste dynamique creee pour la prochaine iteration */
		delete[] puiListeIndiceSourcesArcsArrivants;
	}

	return *pGRAGraphe;
}


