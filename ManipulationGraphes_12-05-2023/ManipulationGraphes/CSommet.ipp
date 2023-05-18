/* Methodes inline de CSommet */

#include <cstdlib>

/****************************************************************************************************
***** SOMAJOUTERARCARRIVANT : ajoute un arc arrivant											*****
*****************************************************************************************************
***** Entree: (rien)																			*****
***** Necessite: (rien)																			*****
***** Sortie: (rien)																			*****
***** Entraine : ajoute un arc de destination "uiSOMNumero" a pARCSOMListeArcsArrivants			*****
****************************************************************************************************/
inline void CSommet::SOMAjouterArcArrivant()
{
	pARCSOMListeArcsArrivants = static_cast<CArc **> (realloc(pARCSOMListeArcsArrivants, (uiSOMNombreArcsArrivants + 1) * sizeof(CArc *)));
	uiSOMNombreArcsArrivants += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiSOMNombreArcsArrivants - 1 == 0)
	{
		pARCSOMListeArcsArrivants[0] = new CArc(uiSOMNumero);
	}

	/* On ajoute un element a la fin de la liste non vide */
	else
	{
		pARCSOMListeArcsArrivants[uiSOMNombreArcsArrivants - 1] = new CArc(uiSOMNumero);
	}
}

/****************************************************************************************************
***** SOMAJOUTERARCPARTANT : ajoute un arc partant												*****
*****************************************************************************************************
***** Entree: CArc & ARCParam																	*****
***** Necessite: (rien)																			*****
***** Sortie: (rien)																			*****
***** Entraine : ajoute un arc de destination "uiNumeroDestination" a pARCSOMListeArcsPartants	*****
*****         OU (cet arc existe deja) leve une exception										*****
****************************************************************************************************/
inline void CSommet::SOMAjouterArcPartant(CArc & ARCParam)
{
	pARCSOMListeArcsPartants = static_cast<CArc **> (realloc(pARCSOMListeArcsPartants, (uiSOMNombreArcsPartants + 1) * sizeof(CArc *)));
	uiSOMNombreArcsPartants += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiSOMNombreArcsPartants - 1 == 0)
	{
		pARCSOMListeArcsPartants[0] = &ARCParam;
	}

	/* On verifie que l'arc ne soit pas deja dans la liste */
	else if (GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()) != -1)
	{
		CException EXCErreur(EXC_ARC_EXISTANT, "L'arc est deja present dans la liste des arcs partants : impossible d'ajouter cet arc.");
		throw(EXCErreur);
	}

	/* On ajoute un element avec une liste non vide */
	else
	{
		pARCSOMListeArcsPartants[uiSOMNombreArcsPartants - 1] = &ARCParam;
	}
}


/********************************************************************************************************
***** SOMMODIFIERARCPARTANT : modifie un arc partant												*****
*********************************************************************************************************
***** Entree: unsigned int uiNumero, CArc & ARCParam												*****
***** Necessite: (rien)																				*****
***** Sortie: (rien)																				*****
***** Entraine : modifie la destination de l'arc partant a la position "uiPosition" avec "uiNumero" *****
*****         OU (liste vide) leve une exception													*****
*****         OU (l'arc n'est pas dans la liste) leve une exception								    *****
*****         OU (arc modifie a meme destination qu'un arc existant) leve une exception				*****
********************************************************************************************************/
inline void CSommet::SOMModifierArcPartant(unsigned int uiNumero, CArc & ARCParam)
{
	/* On modifie alors que la liste est vide */
	if (uiSOMNombreArcsPartants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs partants est deja vide : impossible de modifier.");
	}

	/* l'arc n'est pas dans la liste */
	unsigned int uiIndiceArcPartant = GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination());
	if (uiIndiceArcPartant == -1)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "ARCParam n'est pas dans la liste d'arcs partants : impossible de modifier.");
	}

	/* On modifie l'arc en un arc qui existe deja  */
	if (GEARechercherIndiceArcPartant(uiNumero) != -1)
	{
		CException EXCErreur(EXC_ARC_EXISTANT, "l'arc modifie devient un arc qui existe deja : impossible de modifier.");
		throw EXCErreur;
	}


	/* Cas normal */
	pARCSOMListeArcsPartants[uiIndiceArcPartant]->ARCModifierNumeroDestination(uiNumero);
}

/************************************************************************************
***** SOMSUPPRIMERARCARRIVANT : supprime un arc arrivant						*****
*************************************************************************************
***** Entree: (rien)															*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : supprime le 1er arc de pARCSOMListeArcsArrivants				*****
*****         OU (liste vide) leve une exception								*****
************************************************************************************/
inline void CSommet::SOMSupprimerArcArrivant()
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiSOMNombreArcsArrivants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNombreArcsArrivants - 1; uiBoucle++)
	{
		pARCSOMListeArcsArrivants[uiBoucle] = pARCSOMListeArcsArrivants[uiBoucle + 1];
	}
	uiSOMNombreArcsArrivants -= 1;

	pARCSOMListeArcsArrivants = static_cast<CArc **> (realloc(pARCSOMListeArcsArrivants, uiSOMNombreArcsArrivants * sizeof(CArc *)));
}

/************************************************************************************
***** SOMSUPPRIMERARCPARTANT : supprime un arc partant							*****
*************************************************************************************
***** Entree: CArc & ARCParam													*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : supprime ARCParam dans pARCSOMListeArcsPartants				*****
*****         OU (liste vide) leve une exception								*****
*****         OU (ARCParam n'est pas dans la liste) leve une exception			*****
************************************************************************************/
inline void CSommet::SOMSupprimerArcPartant(CArc & ARCParam)
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiSOMNombreArcsPartants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs partants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* On supprime un arc hors de la liste */
	unsigned int uiIndiceArcPartant = GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination());
	if (uiIndiceArcPartant == -1)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "l'arc a supprimer n'est pas dans la liste : impossible de supprimer.");
		throw EXCErreur;
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
	for (unsigned int uiBoucle = uiIndiceArcPartant; uiBoucle < uiSOMNombreArcsPartants - 1; uiBoucle++)
	{
		pARCSOMListeArcsPartants[uiBoucle] = pARCSOMListeArcsPartants[uiBoucle + 1];
	}
	uiSOMNombreArcsPartants -= 1;

	pARCSOMListeArcsPartants = static_cast<CArc **> (realloc(pARCSOMListeArcsPartants, uiSOMNombreArcsPartants * sizeof(CArc *)));
}


