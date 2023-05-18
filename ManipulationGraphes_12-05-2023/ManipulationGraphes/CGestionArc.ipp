/* Methodes inline de CGestionArc */

/************************************************************************************************************
***** GEARECHERCHERINDICEARCARRIVANT : lit le 1er indice de la liste avec un arc pointant sur le sommet *****
*************************************************************************************************************
***** Entree: (rien)																					*****
***** Necessite: (rien)																					*****
***** Sortie: indice de boucle																			*****
***** Entraine : renvoie le 1er indice de la liste avec un arc pointant sur le sommet					*****
*****		  OU (cet arc n'est pas dans la liste) leve une exception									*****
************************************************************************************************************/
inline unsigned int CSommet::GEARechercherIndiceArcArrivant()
{
	/* On cherche l'arc de destination "uiSOMNumero" dans la liste */
	for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < uiSOMNombreArcsArrivants; uiBoucleArcArrivant++)
	{
		if (pARCSOMListeArcsArrivants[uiBoucleArcArrivant]->ARCLireNumeroDestination() == uiSOMNumero)
		{
			return uiBoucleArcArrivant;
		}
	}

	/* Si l'arc n'a pas ete trouve, on retourne -1 */
	return -1;
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
	/* On cherche l'arc de destination "uiNumeroDestination" dans la liste */
	for (unsigned int uiBoucleArcPartant = 0; uiBoucleArcPartant < uiSOMNombreArcsPartants - 1; uiBoucleArcPartant++)
	{
		if (pARCSOMListeArcsPartants[uiBoucleArcPartant]->ARCLireNumeroDestination() == uiNumeroDestination)
		{
			return uiBoucleArcPartant;
		}
	}

	/* Si l'arc n'a pas ete trouve, on retourne -1 */
	return -1;
}

