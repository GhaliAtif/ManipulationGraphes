/* Methodes inline de CGraphe */

#include "CGraphe.h"
#include <cstdlib>

/******************************************************************************
***** GRAAJOUTERSOMMET : ajoute un sommet								  *****
*******************************************************************************
***** Entree: CSommet& SOMParam, unsigned int uiPosition				  *****
***** Necessite: (rien)													  *****
***** Sortie: ajoute un sommet a pSOMGRAListeSommets					  *****
*****         OU (liste vide) uiPosition = 0							  *****
*****         OU (uiPosition > uiGRANombreSommets + 1) leve une exception *****
******************************************************************************/
inline void CGraphe::GRAAjouterSommet(CSommet& SOMParam, unsigned int uiPosition)
{
	pSOMGRAListeSommets = static_cast<CSommet **> (realloc(pSOMGRAListeSommets, (uiGRANombreSommets + 1) * sizeof(CSommet *)));
	uiGRANombreSommets += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiGRANombreSommets - 1 == 0)
	{
		pSOMGRAListeSommets[0] = &SOMParam;
	}

	/* On ajoute un element en dehors de la liste (ie uiPosition >= uiLISTaille) */
	else if (uiPosition >= uiGRANombreSommets)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste de sommets : impossible d'ajouter.");
		throw EXCErreur;
	}

	/* On ajoute un element avec une liste non vide */
	else
	{
		for (unsigned int uiBoucle = uiGRANombreSommets - 1; uiBoucle > uiPosition; uiBoucle--)
		{
			pSOMGRAListeSommets[uiBoucle] = pSOMGRAListeSommets[uiBoucle - 1];
		}
		pSOMGRAListeSommets[uiPosition] = &SOMParam;

	}
}

/*******************************************************************************
***** GRAMODIFIERSOMMET : modifie un sommet du graphe					   *****
********************************************************************************
***** Entree: CSommet& SOMParam, unsigned int uiPosition				   *****
***** Necessite: (rien)													   *****
***** Sortie: (rien)													   *****
***** Entraine : modifie un sommet de pSOMGRAListeSommets				   *****
*****         OU (liste vide) leve une exception						   *****
*****         OU (uiPosition > uiGRANombreSommets + 1) leve une exception  *****
*******************************************************************************/
inline void CGraphe::GRAModifierSommet(CSommet& SOMParam, unsigned int uiPosition)
{
	/* On modifie alors que la liste est vide */
	if (uiGRANombreSommets == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
	}

	/* On modifie en dehors de la liste */
	if (uiPosition >= uiGRANombreSommets)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs arrivants : impossible de supprimer.");
	}

	/* Cas normal */
	pSOMGRAListeSommets[uiPosition]->SOMModifierNumero(SOMParam.SOMLireNumero());
}

/************************************************************************************
***** GRASUPPRIMERSOMMET : supprime un sommet									*****
*************************************************************************************
***** Entree: unsigned int uiPosition											*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : supprime un arc a pSOMGRAListeSommets							*****
*****         OU (liste vide) leve une exception								*****
*****         OU (uiPosition >= uiGRANombreSommets) leve une exception		    *****
************************************************************************************/
inline void CGraphe::GRASupprimerSommet(unsigned int uiPosition)
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiGRANombreSommets == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* On supprime en dehors de la liste */
	if (uiPosition >= uiGRANombreSommets)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "uiPosition est en dehors de la liste d'arcs arrivants : impossible de supprimer.");
		throw EXCErreur;
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
	for (unsigned int uiBoucle = uiPosition; uiBoucle < uiGRANombreSommets - 1; uiBoucle++)
	{
		pSOMGRAListeSommets[uiBoucle] = pSOMGRAListeSommets[uiBoucle + 1];
	}
	uiGRANombreSommets -= 1;

	pSOMGRAListeSommets = static_cast<CSommet **> (realloc(pSOMGRAListeSommets, uiGRANombreSommets * sizeof(CSommet *)));
}