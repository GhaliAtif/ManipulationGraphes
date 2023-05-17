#ifndef CGRAPHE_H
#define CGRAPHE_H

#include "CSommet.h"



class CGraphe {

private:
	unsigned int uiNombreSommets;
	CSommet** pSOMGRAListeSommets;
public:


	/***********************************************************************
	***** CGraphe : Constructeur par defaut de la classe CGraphe	   *****
	************************************************************************
	***** Entree: (rien)											   *****
	***** Necessite: (rien)											   *****
	***** Sortie: (rien)											   *****
	***** Entraine : les attributs sont initialises					   *****
	***********************************************************************/
	CGraphe();


	/***********************************************************************
	***** CGraphe : Constructeur de recopiede la classe CGraphe		   *****
	************************************************************************
	***** Entree: CGraphe& GRAParam									   *****
	***** Necessite: (rien)											   *****
	***** Sortie: (rien)											   *****
	***** Entraine : rien											  *****
	***********************************************************************/
	CGraphe(CGraphe& GRAParam);

	/***********************************************************************
	***** CGraphe : Constructeur de recopiede la classe CGraphe		   *****
	*****               prenant un entier en entré					   *****
	************************************************************************
	***** Entree: iNombreSommet										   *****
	***** Necessite: (rien)											   *****
	***** Sortie: (rien)											   *****
	***** Entraine : rien											   *****
	***********************************************************************/
	CGraphe(int iNombreSommet);

	/***********************************************************************
	***** CGraphe : Destructeur de la classe CGraphe				   *****
	************************************************************************
	***** Entree: iNombreSommet										   *****
	***** Necessite: (rien)											   *****
	***** Sortie: (rien)											   *****
	***** Entraine : rien											   *****
	***********************************************************************/
	~CGraphe();

	unsigned int GRALireNombreSommet()
	{
		return uiNombreSommets;
	}

	int GRARechercheIndiceSommet(int iNumeroSommet);

	CSommet& GRALireSommet(int iIndice);

	void GRAAjouterSommet(CSommet& SOMParam);

	void GRAModifierSommet(int iNumeroSommet, CSommet& SOMParam);

	void GRASupprimerSommet(int iNumeroSommet);

	void GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetArrive);

	void GRAModifierSommet(int iAncienDepart, int iAncienneDestination, int iNouveauDepart, int iNouvelDestination);

	void GRASupprimerArc(int iNumeroDepart, int iNumeroDestination);

	void GRAModifierArc(int iAncienSommetDepart, int iAncienSommetDestination, int iNouveauSommetDepart, int iNouveauSommetDestination);



};

#endif