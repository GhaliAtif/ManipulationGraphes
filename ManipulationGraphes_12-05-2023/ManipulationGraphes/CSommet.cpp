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

/*****************************************************************
***** CSOMMET : Constructeur de confort de la classe CSommet *****
******************************************************************
***** Entree: unsigned int uiNumero							 *****
***** Necessite: (rien)										 *****
***** Sortie: (rien)										 *****
***** Entraine : cree un sommet de numero "uiNumero"		 *****
*****************************************************************/
CSommet::CSommet(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
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
	for (unsigned int uiArc = 0; uiArc < uiSOMNombreArcsArrivants; uiArc++)
	{
		delete pARCSOMListeArcsArrivants[uiArc];
	}

	if (pARCSOMListeArcsArrivants != nullptr)
	{
		free(pARCSOMListeArcsArrivants);
	}

	if (pARCSOMListeArcsPartants != nullptr)
	{
		free(pARCSOMListeArcsPartants);
	}
}

