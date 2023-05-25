/* Methodes inline de CGestionArc */

/************************************************************************************************************
***** GEARECHERCHERINDICEARCARRIVANT : lit le 1er indice de la liste avec un arc pointant sur le sommet *****
*************************************************************************************************************
***** Entree: unsigned int uiNumeroDestination															*****
***** Necessite: (rien)																					*****
***** Sortie: indice de boucle																			*****
***** Entraine : renvoie le 1er indice de la liste avec un arc pointant sur le sommet					*****
*****		  OU (cet arc n'est pas dans la liste) leve une exception									*****
************************************************************************************************************/
inline unsigned int CSommet::GEARechercherIndiceArcArrivant(unsigned int uiNumeroDestination)
{
	/* On cherche l'arc de destination "uiSOMNumero" dans la liste des arcs arrivants */
	for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < uiSOMNombreArcsArrivants; uiBoucleArcArrivant++)
	{
		/* Si l'un des arcs de la liste correspond, on retourne son indice dans la liste */
		if (pARCSOMListeArcsArrivants[uiBoucleArcArrivant]->ARCLireNumeroDestination() == uiNumeroDestination)
		{
			return uiBoucleArcArrivant;
		}
	}

	/* Sinon, on retourne EXC_ARC_INEXISTANT */
	return EXC_ARC_INEXISTANT;
}

/***********************************************************************************************************************
***** GEARECHERCHERINDICEARCPARTANT : lit le 1er indice de la liste avec un arc pointant sur "uiNumeroDestination" *****
************************************************************************************************************************
***** Entree: unsigned int uiNumeroDestination																	   *****
***** Necessite: (rien)																							   *****
***** Sortie: indice de boucle																					   *****
***** Entraine : renvoie le 1er indice de la liste avec un arc pointant sur uiNumeroDestination					   *****
***********************************************************************************************************************/
inline unsigned int CSommet::GEARechercherIndiceArcPartant(unsigned int uiNumeroDestination)
{
	/* On cherche l'arc de destination "uiNumeroDestination" dans la liste des arcs partants */
	for (unsigned int uiBoucleArcPartant = 0; uiBoucleArcPartant < uiSOMNombreArcsPartants; uiBoucleArcPartant++)
	{
		/* Si l'un des arcs de la liste correspond, on retourne son indice dans la liste */
		if (pARCSOMListeArcsPartants[uiBoucleArcPartant]->ARCLireNumeroDestination() == uiNumeroDestination)
		{
			return uiBoucleArcPartant;
		}
	}

	/* Sinon, on retourne EXC_ARC_INEXISTANT */
	return EXC_ARC_INEXISTANT;

}

/****************************************************************************************
***** GEAINVERSERARCSARRIVANTSPARTANTS : inverse tous les arcs du sommet			*****
*****************************************************************************************
***** Entree: (rien)																*****
***** Necessite: (rien)															    *****
***** Sortie: CSommet &																*****
***** Entraine : tous les arcs partants deviennent des arcs arrivants et vice-versa *****
****************************************************************************************/
inline CSommet & CSommet::GEAInverserArcsArrivantsPartants()
{
	CSommet* pSOMSommet = new CSommet(uiSOMNumero);

	for (unsigned int uiBoucleArrivant = 0; uiBoucleArrivant < uiSOMNombreArcsArrivants; uiBoucleArrivant++) 
	{

		pSOMSommet->SOMAjouterArcArrivant(*SOMLireListeArcsPartants(uiBoucleArrivant));
	}

	for (unsigned int uiBouclePartant = 0; uiBouclePartant < uiSOMNombreArcsPartants; uiBouclePartant++) 
	{

		pSOMSommet->SOMAjouterArcPartant(*SOMLireListeArcsArrivants(uiBouclePartant));
	}

	return *pSOMSommet;
}

