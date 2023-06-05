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
	bSOMUtiliseOperateurNew = false;
	pARCSOMListeArcsArrivants = nullptr;
	pARCSOMListeArcsPartants = nullptr;
}

/*****************************************************************
***** CSOMMET : Constructeur de recopie de la classe CSommet *****
******************************************************************
***** Entree: CSommet & SOMParam							 *****
***** Necessite: (rien)										 *****
***** Sortie: (rien)										 *****
***** Entraine : une copie de SOMParam est creee			 *****
*****************************************************************/
CSommet::CSommet(CSommet & SOMParam)
{
	uiSOMNumero = SOMParam.uiSOMNumero;
	uiSOMNombreArcsArrivants = SOMParam.uiSOMNombreArcsArrivants;
	uiSOMNombreArcsPartants = SOMParam.uiSOMNombreArcsPartants;
	bSOMUtiliseOperateurNew = true;

	/* Copie de chacune des listes d'arcs */
	pARCSOMListeArcsArrivants = new CArc*[SOMParam.uiSOMNombreArcsArrivants];
	for (unsigned int i = 0; i < SOMParam.uiSOMNombreArcsArrivants; i++)
	{
		pARCSOMListeArcsArrivants[i] = new CArc(*SOMParam.SOMLireListeArcsArrivants(i));
	}

	pARCSOMListeArcsPartants = new CArc*[SOMParam.uiSOMNombreArcsPartants];
	for (unsigned int i = 0; i < SOMParam.uiSOMNombreArcsPartants; i++)
	{
		pARCSOMListeArcsPartants[i] = new CArc(*SOMParam.SOMLireListeArcsPartants(i));
	}
}

/********************************************************************
***** CSOMMET : Constructeur de confort de la classe CSommet	*****
*********************************************************************
***** Entree: unsigned int uiNumeroSommet						*****
***** Necessite: (rien)											*****
***** Sortie: (rien)											*****
***** Entraine : cree un sommet de numero "uiNumero"			*****
********************************************************************/
CSommet::CSommet(unsigned int uiNumeroSommet)
{
	uiSOMNumero = uiNumeroSommet;
	uiSOMNombreArcsArrivants = 0;
	uiSOMNombreArcsPartants = 0;
	bSOMUtiliseOperateurNew = false;
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
	if (bSOMUtiliseOperateurNew)
	{
		for (unsigned int uiArc = 0; uiArc < uiSOMNombreArcsArrivants; uiArc++)
		{
			delete pARCSOMListeArcsArrivants[uiArc];
		}

		delete[] pARCSOMListeArcsArrivants;
	}

	if (bSOMUtiliseOperateurNew)
	{
		for (unsigned int uiArc = 0; uiArc < uiSOMNombreArcsPartants; uiArc++)
		{
			delete pARCSOMListeArcsPartants[uiArc];
		}

		delete[] pARCSOMListeArcsPartants;
	}
}

