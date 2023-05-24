/* Methodes inline de CSommet */

#include "CSommet.h"
#include <cstdlib>

/************************************************************************************
***** SOMAJOUTERARCARRIVANT : ajoute un arc arrivant							*****
*************************************************************************************
***** Entree: CArc & ARCParam, unsigned int uiPosition							*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : ajoute un arc a pARCSOMListeArcsArrivants						*****
*****         OU (liste vide) uiPosition = 0									*****
*****         OU (uiPosition > uiSOMNombreArcsArrivants + 1) leve une exception *****
************************************************************************************/
inline void CSommet::SOMAjouterArcArrivant(CArc* pARCArc)
{
	//On vérifie que l'arc ne soit pas déjà dans la liste
	if (SOMRechercherIndiceArcArrivant(pARCArc->ARCLireNumeroDestination()) != -1)
	{
		CException EXCErreur(EXCArcExistant, "L'arc est deja present");
		throw(EXCErreur);
	}

	// Test paramètre non null
	if (pARCArc == nullptr)
	{
		CException EXCErreur(EXCArgumentNull, "L'argument est null");
		throw(EXCErreur);
	}

	pARCSOMListeArcsArrivants = (CArc**)realloc(pARCSOMListeArcsArrivants, sizeof(CArc*) * (uiSOMNombreArcsArrivants + 1));
	// Si l'allocation à réussi ajout de l'arc en fin de liste et actualisation du nombre d'arc entrant
	if (pARCSOMListeArcsArrivants != nullptr)
	{
		pARCSOMListeArcsArrivants[uiSOMNombreArcsArrivants] = new CArc(*pARCArc);
		uiSOMNombreArcsArrivants++;
	}
	// Sinon une exception est levé
	else
	{
		CException EXCErreur(EXCAllocationEchoué, "l'allocation a échoué");
		throw(EXCErreur);
	}
}

/************************************************************************************
***** SOMAJOUTERARCPARTANT : ajoute un arc partant								*****
*************************************************************************************
***** Entree: CArc & ARCParam, unsigned int uiPosition							*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : ajoute un arc a pARCSOMListeArcsPartants						*****
*****         OU (liste vide) uiPosition = 0									*****
*****         OU (uiPosition > uiSOMNombreArcsPartants + 1) leve une exception  *****
************************************************************************************/
inline void CSommet::SOMAjouterArcPartant(CArc* pARCArc)
{
	if (SOMRechercherIndiceArcPartant(pARCArc->ARCLireNumeroDestination()) != -1)
	{
		CException EXCErreur(EXCArcExistant, "L'arc est deja present");
		throw(EXCErreur);
	}

	// Test paramètre non null
	if (pARCArc == nullptr)
	{
		CException EXCErreur(EXCArgumentNull, "L'argument est null");
		throw(EXCErreur);
	}

	pARCSOMListeArcsPartants = (CArc**)realloc(pARCSOMListeArcsPartants, sizeof(CArc*) * (uiSOMNombreArcsPartants + 1));
	/// Si l'allocation à réussi on rajoute l'arc
	if (pARCSOMListeArcsPartants != nullptr)
	{
		pARCSOMListeArcsPartants[uiSOMNombreArcsPartants] = pARCArc;
		uiSOMNombreArcsPartants++;
	}
	/// Sinon une exception est levé
	else
	{
		CException EXCErreur(EXCAllocationEchoué, "l'allocation a échoué");
		throw(EXCErreur);
	}
}

/************************************************************************************
***** SOMMODIFIERARCARRIVANT : modifie un arc arrivant							*****
*************************************************************************************
***** Entree: CArc & ARCParam, unsigned int uiPosition							*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : modifie un arc a pARCSOMListeArcsArrivants						*****
*****         OU (liste vide) leve une exception								*****
*****         OU (uiPosition >= uiSOMNombreArcsArrivants) leve une exception    *****
************************************************************************************/
inline void CSommet::SOMModifierArcArrivant(CArc & ARCParam, unsigned int uiPosition)
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
	pARCSOMListeArcsArrivants[uiPosition]->ARCModifierNumeroDestination(ARCParam.ARCLireNumeroDestination());
}

/************************************************************************************
***** SOMMODIFIERARCPARTANT : modifie un arc partant							*****
*************************************************************************************
***** Entree: CArc & ARCParam, unsigned int uiPosition							*****
***** Necessite: (rien)															*****
***** Sortie: (rien)															*****
***** Entraine : modifie un arc a pARCSOMListeArcsPartants						*****
*****         OU (liste vide) leve une exception								*****
*****         OU (uiPosition >= uiSOMNombreArcsPartants) leve une exception     *****
************************************************************************************/
inline void CSommet::SOMModifierArcPartant(CArc & ARCParam, unsigned int uiPosition)
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
	pARCSOMListeArcsPartants[uiPosition]->ARCModifierNumeroDestination(ARCParam.ARCLireNumeroDestination());
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

