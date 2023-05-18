#include <iostream>

#include "CGraphe.h"
#include "CFichierGraphe.h"

using namespace std;

/**************************************************************************
***** CGRAPHE : Constructeur par defaut de la classe CGraphe		  *****
***************************************************************************
***** Entree: (rien)												  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : le nombre de sommets du graphe est initialise a 0	  *****
**************************************************************************/
CGraphe::CGraphe()
{
	uiGRANombreSommets = 0;
	pSOMGRAListeSommets = nullptr;
}

/**************************************************************************
***** CGRAPHE : Constructeur de recopie de la classe CGraphe		  *****
***************************************************************************
***** Entree: CGraphe & GRAParam									  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : une copie de GRAParam est creee					  *****
**************************************************************************/
CGraphe::CGraphe(CGraphe & GRAParam)
{
	uiGRANombreSommets = GRAParam.uiGRANombreSommets;

	pSOMGRAListeSommets = (CSommet**) malloc(GRAParam.GRALireNombreSommets() * sizeof(CSommet*));
	for (unsigned int uiSommet = 0; uiSommet < GRAParam.GRALireNombreSommets(); uiSommet++)
	{
		pSOMGRAListeSommets[uiSommet] = GRAParam.pSOMGRAListeSommets[uiSommet];
	}
}

/**************************************************************************
***** CGRAPHE : convertit un CFichierGraphe en CGraphe				  *****
***************************************************************************
***** Entree: CFichierGraphe & FIGParam								  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : cree un graphe a partir d'un fichier texte			  *****
**************************************************************************/
CGraphe::CGraphe(CFichierGraphe & FIGParam)
{

}

/******************************************************
***** ~CGRAPHE : Destructeur de la classe CGraphe *****
*******************************************************
***** Entree: (rien)							  *****
***** Necessite: (rien)							  *****
***** Sortie: (rien)							  *****
***** Entraine : L'objet est desinitialise		  *****
******************************************************/
CGraphe::~CGraphe()
{
	if (pSOMGRAListeSommets != nullptr)
	{
		free(pSOMGRAListeSommets);
	}
}
