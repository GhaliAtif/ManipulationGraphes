#include <cstdlib>

#include "CArc.h"
#include "CSommet.h"

/*****************************************************************
***** CSOMMET : Constructeur par defaut de la classe CSommet *****
******************************************************************
***** Entree: (rien)										 *****
***** Necessite: (rien)										 *****
***** Sortie: (rien)										 *****
***** Entraine : les attributs sont initialises				 *****
*****************************************************************/
CSommet::CSommet()
{
	uiSOMNumero = 0;
	uiSOMNombreArcsArrivants = 0;
	uiSOMNombreArcsPartants = 0;
	pARCSOMListeArcsArrivants = nullptr;
	pARCSOMListeArcsPartants = nullptr;
}

/******************************************************
***** ~CSOMMET : Destructeur de la classe CSommet *****
*******************************************************
***** Entree: (rien)							  *****
***** Necessite: (rien)							  *****
***** Sortie: (rien)							  *****
***** Entraine : L'objet est desinitialise		  *****
******************************************************/
CSommet::~CSommet()
{
	if (pARCSOMListeArcsArrivants != nullptr)
	{
		free(pARCSOMListeArcsArrivants);
	}

	if (pARCSOMListeArcsPartants != nullptr)
	{
		free(pARCSOMListeArcsPartants);
	}
}

int CSommet::SOMRechercheIndiceArcArrivant(unsigned int uiDestination)
{
	for (unsigned int uiBoucleArcArrivant = 0; uiBoucleArcArrivant < uiSOMNombreArcsArrivants; uiBoucleArcArrivant++)
	{
		if (pARCSOMListeArcsArrivants[uiBoucleArcArrivant]->ARCLireNumeroDestination() == uiDestination)
		{
			return uiBoucleArcArrivant;
		}
	}
	return -1;
}

int CSommet::SOMRechercheIndiceArcPartant(unsigned int uiDestination)
{
	for (unsigned int uiBoucleArcSortant = 0; uiBoucleArcSortant < uiSOMNombreArcsPartants; uiBoucleArcSortant++)
	{
		if (pARCSOMListeArcsPartants[uiBoucleArcSortant]->ARCLireNumeroDestination() == uiDestination)
		{
			return uiBoucleArcSortant;
		}
	}
	return -1;
}

