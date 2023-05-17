#include <cstdlib>

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

