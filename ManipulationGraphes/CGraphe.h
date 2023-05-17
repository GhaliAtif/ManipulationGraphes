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
	CGraphe(unsigned int uiNombreSommet);

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


	/*****************************************************************************************
	***** GRARechercheIndiceSommet :Chreche si le sommet est présent dans le graphe		 *****
	******************************************************************************************
	***** Entree: iNombreSommet															 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	unsigned int GRARechercheIndiceSommet(unsigned int iNumeroSommet);


	/*****************************************************************************************
	***** GRALireSommet :Chreche si le sommet est présent dans le graphe				 *****
	******************************************************************************************
	***** Entree: uiIndice																 *****
	***** Necessite: (rien)																 *****
	***** Sortie: *pSOMGRAListeSommets à l'indice donné									 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	CSommet& GRALireSommet(unsigned int uiIndice);



	/*****************************************************************************************
	***** GRAAjouterSommet :Ajout d'un sommet au graphe									 *****
	******************************************************************************************
	***** Entree: CSommet& SOMParam														 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	void GRAAjouterSommet(CSommet& SOMParam);


	/*****************************************************************************************
	***** GRAModifierSommet :Modifier un sommet du graphe								 *****
	******************************************************************************************
	***** Entree: CSommet& SOMParam	et unsigned int iNumeroSommet						 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	void GRAModifierSommet(unsigned int iNumeroSommet, CSommet& SOMParam);


	/*****************************************************************************************
	***** GRASupprimerSommet :Suppression d'un sommet du graphe							 *****
	******************************************************************************************
	***** Entree: unsigned int iNumeroSommet											 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	void GRASupprimerSommet(unsigned int iNumeroSommet);


	/*****************************************************************************************
	***** GRAAjouterArc :Ajout d'un Arc au graphe									 *****
	******************************************************************************************
	***** Entree: unsigned int iNumeroSommetDepart et unsigned int iNumeroSommetArrive	 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	void GRAAjouterArc(unsigned int iNumeroSommetDepart,unsigned int iNumeroSommetArrive);


	/*****************************************************************************************
	***** GRASupprimerArc :Suppression d'un Arc du graphe							 *****
	******************************************************************************************
	***** Entree: unsigned int iNumeroDepart,unsigned int iNumeroDestination			 *****
	***** Necessite: (rien)																 *****
	***** Sortie: (rien)																 *****
	***** Entraine : rien																 *****
	******************************************************************************************/
	void GRASupprimerArc(unsigned int iNumeroDepart,unsigned int iNumeroDestination);



	/********************************************************************************************************************************************************************
	***** GRAModifierSommet :Modifier un sommet du graphe																											*****
	*********************************************************************************************************************************************************************
	***** Entree: unsigned int iAncienSommetDepart,unsigned int iAncienSommetDestination,unsigned int iNouveauSommetDepart,unsigned int iNouveauSommetDestination	*****
	***** Necessite: (rien)																																			*****
	***** Sortie: (rien)																																			*****
	***** Entraine : rien																																			*****
	*********************************************************************************************************************************************************************/
	void GRAModifierArc(unsigned int iAncienSommetDepart,unsigned int iAncienSommetDestination,unsigned int iNouveauSommetDepart,unsigned int iNouveauSommetDestination);



};

#endif