/* Methodes inline de CSommet */

#include "CSommet.h"
#include <cstdlib>

/****************************************************************************************************
***** SOMAJOUTERARCARRIVANT : ajoute un arc arrivant											*****
*****************************************************************************************************
***** Entree: unsigned int uiNumeroDestination													*****
***** Necessite: (rien)																			*****
***** Sortie: (rien)																			*****
***** Entraine : ajoute un arc de destination "uiNumeroDestination" a pARCSOMListeArcsArrivants	*****
****************************************************************************************************/
inline void CSommet::SOMAjouterArcArrivant(unsigned int uiNumeroDestination)
{
	pARCSOMListeArcsArrivants = static_cast<CArc **> (realloc(pARCSOMListeArcsArrivants, (uiSOMNombreArcsArrivants + 1) * sizeof(CArc *)));
	uiSOMNombreArcsArrivants += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiSOMNombreArcsArrivants - 1 == 0)
	{
		pARCSOMListeArcsArrivants[0] = new CArc(uiNumeroDestination);
	}

	/* On ajoute un element a la fin de la liste non vide */
	else
	{
		pARCSOMListeArcsArrivants[uiSOMNombreArcsArrivants - 1] = new CArc(uiNumeroDestination);
	}
}

/****************************************************************************************************
***** SOMAJOUTERARCPARTANT : ajoute un arc partant												*****
*****************************************************************************************************
***** Entree: unsigned int uiNumeroDestination													*****
***** Necessite: (rien)																			*****
***** Sortie: (rien)																			*****
***** Entraine : ajoute un arc de destination "uiNumeroDestination" a pARCSOMListeArcsPartants	*****
****************************************************************************************************/
inline void CSommet::SOMAjouterArcPartant(unsigned int uiNumeroDestination)
{
	pARCSOMListeArcsPartants = static_cast<CArc **> (realloc(pARCSOMListeArcsPartants, (uiSOMNombreArcsPartants + 1) * sizeof(CArc *)));
	uiSOMNombreArcsPartants += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiSOMNombreArcsPartants - 1 == 0)
	{
		pARCSOMListeArcsPartants[0] = &ARCParam;
	}

	/* On ajoute un element en dehors de la liste (ie uiPosition >= uiLISTaille) */
	else if (uiPosition >= uiSOMNombreArcsPartants)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs partants : impossible d'ajouter.");
		throw EXCErreur;
	}

	/* On ajoute un element avec une liste non vide */
	else
	{
		for (unsigned int uiBoucle = uiSOMNombreArcsPartants - 1; uiBoucle > uiPosition; uiBoucle--)
		{
			pARCSOMListeArcsPartants[uiBoucle] = pARCSOMListeArcsPartants[uiBoucle - 1];
		}
		pARCSOMListeArcsPartants[uiPosition] = &ARCParam;

	}
}

/*********************************************************************************************************
***** SOMMODIFIERARCARRIVANT : modifie un arc arrivant												 *****
**********************************************************************************************************
***** Entree: unsigned int uiNumero, unsigned int uiPosition										 *****
***** Necessite: (rien)																				 *****
***** Sortie: (rien)																				 *****
***** Entraine : modifie la destination de l'arc arrivant a la position "uiPosition" avec "uiNumero" *****
*****         OU (liste vide) leve une exception													 *****
*****         OU (uiPosition >= uiSOMNombreArcsArrivants) leve une exception						 *****
*********************************************************************************************************/
inline void CSommet::SOMModifierArcArrivant(unsigned int uiNumero, unsigned int uiPosition)
{
	/* On modifie alors que la liste est vide */
	if (uiSOMNombreArcsArrivants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
	}

	/* On modifie en dehors de la liste */
	if (uiPosition >= uiSOMNombreArcsArrivants)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs arrivants : impossible de supprimer.");
	}

	/* Cas normal */
	pARCSOMListeArcsArrivants[uiPosition]->ARCModifierNumeroDestination(uiNumero);
}

/********************************************************************************************************
***** SOMMODIFIERARCPARTANT : modifie un arc partant												*****
*********************************************************************************************************
***** Entree: unsigned int uiNumero, unsigned int uiPosition										*****
***** Necessite: (rien)																				*****
***** Sortie: (rien)																				*****
***** Entraine : modifie la destination de l'arc partant a la position "uiPosition" avec "uiNumero" *****
*****         OU (liste vide) leve une exception													*****
*****         OU (uiPosition >= uiSOMNombreArcsPartants) leve une exception						    *****
********************************************************************************************************/
inline void CSommet::SOMModifierArcPartant(unsigned int uiNumero, unsigned int uiPosition)
{
	/* On modifie alors que la liste est vide */
	if (uiSOMNombreArcsPartants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs partants est deja vide : impossible de supprimer.");
	}

	/* On modifie en dehors de la liste */
	if (uiPosition >= uiSOMNombreArcsPartants)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs partants : impossible de supprimer.");
	}

	/* Cas normal */
	pARCSOMListeArcsPartants[uiPosition]->ARCModifierNumeroDestination(uiNumero);
}

/************************************************************************************
***** SOMSUPPRIMERARCARRIVANT : supprime un arc arrivant						*****
*************************************************************************************
***** Entree: CArc & ARCParam, unsigned int uiPosition							*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : supprime un arc a pARCSOMListeArcsArrivants					*****
*****         OU (liste vide) leve une exception								*****
*****         OU (uiPosition >= uiSOMNombreArcsArrivants) leve une exception    *****
************************************************************************************/
inline void CSommet::SOMSupprimerArcArrivant(unsigned int uiPosition)
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiSOMNombreArcsArrivants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* On supprime en dehors de la liste */
	if (uiPosition >= uiSOMNombreArcsArrivants)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs arrivants : impossible de supprimer.");
		throw EXCErreur;
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
	for (unsigned int uiBoucle = uiPosition; uiBoucle < uiSOMNombreArcsArrivants - 1; uiBoucle++)
	{
		pARCSOMListeArcsArrivants[uiBoucle] = pARCSOMListeArcsArrivants[uiBoucle + 1];
	}
	uiSOMNombreArcsArrivants -= 1;

	pARCSOMListeArcsArrivants = static_cast<CArc **> (realloc(pARCSOMListeArcsArrivants, uiSOMNombreArcsArrivants * sizeof(CArc *)));
}

/************************************************************************************
***** SOMSUPPRIMERARCPARTANT : supprime un arc partant							*****
*************************************************************************************
***** Entree: unsigned int uiPosition											*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : supprimer un arc a pARCSOMListeArcsPartants					*****
*****         OU (liste vide) leve une exception								*****
*****         OU (uiPosition >= uiSOMNombreArcsPartants) leve une exception     *****
************************************************************************************/
inline void CSommet::SOMSupprimerArcPartant(unsigned int uiPosition)
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiSOMNombreArcsPartants == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs partants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* On supprime en dehors de la liste */
	if (uiPosition >= uiSOMNombreArcsPartants)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs partants : impossible de supprimer.");
		throw EXCErreur;
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
	for (unsigned int uiBoucle = uiPosition; uiBoucle < uiSOMNombreArcsPartants - 1; uiBoucle++)
	{
		pARCSOMListeArcsPartants[uiBoucle] = pARCSOMListeArcsPartants[uiBoucle + 1];
	}
	uiSOMNombreArcsPartants -= 1;

	pARCSOMListeArcsPartants = static_cast<CArc **> (realloc(pARCSOMListeArcsPartants, uiSOMNombreArcsPartants * sizeof(CArc *)));
}
