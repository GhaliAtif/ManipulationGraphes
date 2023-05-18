/* Methodes inline de CGestionGraphe */

#include <iostream>
using namespace std;

/***********************************************************************************
***** GEGCHERCHERSOURCEARCARRIVANT : lit le sommet de depart d'un arc arrivant *****
************************************************************************************
***** Entree: (rien)														   *****
***** Necessite: (rien)														   *****
***** Sortie: numero de sommet												   *****
***** Entraine : renvoie le numero du sommet de depart de l'arc				   *****
*****		  OU (arc n'existe pas dans le graphe) leve une exception		   *****
***********************************************************************************/
inline unsigned int CGraphe::GEGChercherSourceArcArrivant(CArc & ARCParam)
{
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		/* pour un sommet donne, on parcourt toute la liste des arcs partants */
		for (unsigned int uiArc = 0; uiArc < pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsPartants(); uiArc++)
			if (pSOMGRAListeSommets[uiSommet]->SOMLireListeArcsPartants()[uiArc]->ARCLireNumeroDestination() == ARCParam.ARCLireNumeroDestination())
			{
				return pSOMGRAListeSommets[uiSommet]->SOMLireNumero();
			}
	}

	CException EXCErreur(EXC_ARC_NON_EXISTANT, "l'arc en parametre n'existe pas dans le graphe.");
	throw EXCErreur;
}

/***************************************************************************************************
***** GEGRECHERCHERINDICESOMMET : lit le 1er indice de la liste ayant pour sommet "uiPosition" *****
****************************************************************************************************
***** Entree: unsigned int uiNumero															   *****
***** Necessite: (rien)																		   *****
***** Sortie: un indice de boucle															   *****
***** Entraine : renvoie le 1er indice de la liste ayant pour sommet "uiPosition"			   *****
*****		  OU (ce sommet n'est pas dans la liste) leve une exception						   *****
***************************************************************************************************/
inline unsigned int CGraphe::GEGRechercherIndiceSommet(unsigned int uiNumero)
{
	for (unsigned int uiIndiceBoucleSommet = 0; uiIndiceBoucleSommet < uiGRANombreSommets - 1; uiIndiceBoucleSommet++)
	{
		if (GRALireListeSommets()[uiIndiceBoucleSommet]->SOMLireNumero() == uiNumero) //pb avec uiIndiceBoucleSommet????
		{
			return uiIndiceBoucleSommet;
		}
	}
	return -1;
}