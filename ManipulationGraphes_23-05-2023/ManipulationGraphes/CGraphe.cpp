#include <iostream>

#include "CGraphe.h"

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

	/* Creation d'une nouvelle liste a partir de GRAParam */
	pSOMGRAListeSommets = new CSommet*[GRAParam.uiGRANombreSommets];

	/* On copie les sommets existant dans NouveauxSommets */
	for (unsigned int i = 0; i < GRAParam.uiGRANombreSommets; i++)
	{
		pSOMGRAListeSommets[i] = new CSommet(*GRAParam.pSOMGRAListeSommets[i]);
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
	uiGRANombreSommets = FIGParam.FIGLireNombreSommets();

	/* On cree les sommets listes dans pUNIFIGSommets de FIGParam */
	// On alloue la liste de sommets
	pSOMGRAListeSommets = new CSommet*[FIGParam.FIGLireNombreSommets()];

	// On alloue tous les sommets que contient cette liste
	for (unsigned int uiSommet = 0; uiSommet < FIGParam.FIGLireNombreSommets(); uiSommet++)
	{
		pSOMGRAListeSommets[uiSommet] = new CSommet(FIGParam.FIGLireSommets()[uiSommet]);
	}
	



	/* On cree les arcs du graphe avec AjouterArc */
	// Si une erreur fait que les nombres d'arcs arrivants et partants ne sont pas egaux, on leve une exception
	if (FIGParam.FIGLireNombreArcsArrivants() != FIGParam.FIGLireNombreArcsPartants())
	{
		CException EXCErreur(EXC_MAUVAIS_NOMBRE_ARCS, "Les nombres d'arcs arrivants et partants ne sont pas egaux : impossible de creer le graphe correspondant.\n");
		throw EXCErreur;
	}

	// Sinon, on cree les arcs
	for (unsigned int uiArc = 0; uiArc < FIGParam.FIGLireNombreArcsArrivants(); uiArc++)
	{

		GRAAjouterArc(FIGParam.FIGLireListeSommetsDepart()[uiArc], *(new CArc(FIGParam.FIGLireListeSommetsArrivee()[uiArc])));
	}
	
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
		for (unsigned int i = 0; i < uiGRANombreSommets; i++)
		{
			delete pSOMGRAListeSommets[i];
		}
	}
	delete[] pSOMGRAListeSommets;
}

/***************************************************************************************************
***** OPERATOR= : copie un CGraphe membre a membre											   *****
****************************************************************************************************
***** Entree: CGraphe & GRAParam															   *****
***** Necessite: (rien)																		   *****
***** Sortie: (rien)																		   *****
***** Entraine : une copie de CGraphe est creee												   *****
***************************************************************************************************/
void CGraphe::operator=(CGraphe & GRAParam)
{
	uiGRANombreSommets = GRAParam.uiGRANombreSommets;

	/* Creation d'une nouvelle liste a partir de GRAParam */
	pSOMGRAListeSommets = new CSommet*[GRAParam.uiGRANombreSommets];

	/* On copie les sommets existant dans NouveauxSommets */
	for (unsigned int i = 0; i < GRAParam.uiGRANombreSommets; i++)
	{
		pSOMGRAListeSommets[i] = new CSommet(*GRAParam.pSOMGRAListeSommets[i]);
	}
}