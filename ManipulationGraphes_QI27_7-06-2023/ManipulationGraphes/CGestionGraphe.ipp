/* Methodes inline de CGestionGraphe */

#include <iostream>
#include <cstdlib>

using namespace std;

/***************************************************************************************************
***** GEGRECHERCHERINDICESOMMET : lit le 1er indice de la liste ayant pour sommet "uiNumero"   *****
****************************************************************************************************
***** Entree: unsigned int uiNumero															   *****
***** Necessite: (rien)																		   *****
***** Sortie: un indice de boucle															   *****
***** Entraine : renvoie le 1er indice de la liste ayant pour sommet "uiNumero"				   *****
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

/****************************************************************************************************************************
***** GEGCHERCHERINDICESOURCEARCSARRIVANTS : cherche l'indice de liste de tous les sommets de depart des arcs arrivants	*****
*****************************************************************************************************************************
***** Entree: CSommet & SOMParam																						*****
***** Necessite: (rien)																									*****
***** Sortie: une liste contenant les numeros de liste de chaque sommet source											*****
***** Entraine : renvoie cette liste																					*****
****************************************************************************************************************************/
inline unsigned int* CGraphe::GEGChercherIndiceSourceArcsArrivants(CSommet& SOMParam)
{
	unsigned int* puiListeIndiceSommets = new unsigned int[GRALireNombreSommets()];
	unsigned int uiCompteurListeIndiceSommets = 0;

	/* On parcourt chaque sommet du graphe */
	for (unsigned int uiSommet = 0; uiSommet < GRALireNombreSommets(); uiSommet++)
	{
		/* Pour chaque sommet, on parcourt tous ses arcs partants */
		for (unsigned int uiArcPartant = 0; uiArcPartant < GRALireListeSommets()[uiSommet]->SOMLireNombreArcsPartants(); uiArcPartant++)
		{
			/* Si l'arc partant pointe sur SOMParam, alors ce sommet est un des sommets sources pour un des arcs arrivants de SOMParam */
			if (GRALireListeSommets()[uiSommet]->SOMLireListeArcsPartants(uiArcPartant)->ARCLireNumeroDestination() == SOMParam.SOMLireNumero())
			{
				/* On ajoute l'indice de liste de ce sommet */
				puiListeIndiceSommets[uiCompteurListeIndiceSommets] = uiSommet;
				uiCompteurListeIndiceSommets++;

				// On quitte la boucle des arcs partants des que l'arc partant cherche a ete trouve
				break; 
			}
		}
	}

	/* On change la taille de cette liste pour qu'elle corresponde au nombre d'elements trouves */
	puiListeIndiceSommets = (unsigned int*)realloc(puiListeIndiceSommets, uiCompteurListeIndiceSommets * sizeof(unsigned int));

	return puiListeIndiceSommets;
}
