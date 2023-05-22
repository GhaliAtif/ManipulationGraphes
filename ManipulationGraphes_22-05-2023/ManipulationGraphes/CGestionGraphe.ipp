/* Methodes inline de CGestionGraphe */

#include <iostream>
using namespace std;

/****************************************************************************************
***** GEGCHERCHERSOURCEARCARRIVANT : cherche le sommet de depart d'un arc arrivant	*****
*****************************************************************************************
***** Entree: CSommet & SOMParam													*****
***** Necessite: (rien)																*****
***** Sortie: numero de sommet qui possede un arc partant sur SOMParam				*****
***** Entraine : renvoie ce numero de sommet										*****
****************************************************************************************/
inline unsigned int CGraphe::GEGChercherSourceArcArrivant(CSommet & SOMParam)
{
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		/* Pour un sommet donne, on parcourt la liste de ses arcs partants */
		for (unsigned int uiArc = 0; uiArc < pSOMGRAListeSommets[uiSommet]->SOMLireNombreArcsPartants(); uiArc++)

			/* Si ce sommet possede un arc partant sur le meme sommet que ARCParam, 
			alors ce sommet possede un arc arrivant sur la destination de ARCParam.
			Donc il est un sommet source d'un des arcs arrivant sur la destination de ARCParam. */
			if (pSOMGRAListeSommets[uiSommet]->GEARechercherIndiceArcPartant(SOMParam.SOMLireNumero()) != EXC_ARC_INEXISTANT)
			{
				return pSOMGRAListeSommets[uiSommet]->SOMLireNumero();
			}
	}

	/* Sinon, on retourne EXC_ARC_INEXISTANT */
	return EXC_ARC_INEXISTANT;
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
	/* On cherche "uiNumero" dans la liste des sommets */
	for (unsigned int uiIndiceBoucleSommet = 0; uiIndiceBoucleSommet < uiGRANombreSommets; uiIndiceBoucleSommet++)
	{
		/* Si un des sommets de la liste correspond, on retourne son indice dans la liste */
		if (GRALireListeSommets()[uiIndiceBoucleSommet]->SOMLireNumero() == uiNumero)
		{
			return uiIndiceBoucleSommet;
		}
	}

	/* Sinon, on retourne EXC_SOMMET_INEXISTANT */
	return EXC_SOMMET_INEXISTANT;
}