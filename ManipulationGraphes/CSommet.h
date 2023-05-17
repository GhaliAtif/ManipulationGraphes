#ifndef CSOMMET_H
#define CSOMMET_H

#include "CArc.h"
#include "CException.h"

class CSommet
{
private:
	unsigned int uiSOMNumero;
	unsigned int uiSOMNombreArcsArrivants;
	unsigned int uiSOMNombreArcsPartants;
	CArc ** pARCSOMListeArcsArrivants;
	CArc ** pARCSOMListeArcsPartants;

public:
	/*****************************************************************
	***** CSOMMET : Constructeur par defaut de la classe CSommet *****
	******************************************************************
	***** Entree: (rien)										 *****
	***** Necessite: (rien)										 *****
	***** Sortie: (rien)										 *****
	***** Entraine : les attributs sont initialises				 *****
	*****************************************************************/
	CSommet();

	/******************************************************
	***** ~CSOMMET : Destructeur de la classe CSommet *****
	*******************************************************
	***** Entree: (rien)							  *****
	***** Necessite: (rien)							  *****
	***** Sortie: (rien)							  *****
	***** Entraine : L'objet est desinitialise		  *****
	******************************************************/
	~CSommet();

	/************************************************************
	***** SOMLIRENUMERO : lit le numero du sommet			*****
	*************************************************************
	***** Entree: (rien)									*****
	***** Necessite: (rien)									*****
	***** Sortie: unsigned int uiSOMNumero					*****
	***** Entraine : renvoie la valeur de uiSOMNumero		*****
	************************************************************/
	unsigned int SOMLireNumero()
	{
		return uiSOMNumero;
	}

	/********************************************************************************
	***** SOMLIRENOMBREARCSARRIVANTS : lit le nombre d'arcs arrivants du sommet	*****
	*********************************************************************************
	***** Entree: (rien)														*****
	***** Necessite: (rien)														*****
	***** Sortie: unsigned int uiSOMNombreArcsArrivants							*****
	***** Entraine : renvoie la valeur de uiSOMNombreArcsArrivants				*****
	********************************************************************************/
	unsigned int SOMLireNombreArcsArrivants()
	{
		return uiSOMNombreArcsArrivants;
	}

	/********************************************************************************
	***** SOMLIRENOMBREARCSPARTANTS : lit le nombre d'arcs partants du sommet	*****
	*********************************************************************************
	***** Entree: (rien)														*****
	***** Necessite: (rien)														*****
	***** Sortie: unsigned int uiSOMNombreArcsPartants							*****
	***** Entraine : renvoie la valeur de uiSOMNombreArcsPartants				*****
	********************************************************************************/
	unsigned int SOMLireNombreArcsPartants()
	{
		return uiSOMNombreArcsPartants;
	}

	/********************************************************************************
	***** SOMLIRELISTEARCSARRIVANTS : lit la liste d'arcs arrivants du sommet	*****
	*********************************************************************************
	***** Entree: (rien)														*****
	***** Necessite: (rien)														*****
	***** Sortie: CArc** pARCSOMListeArcsArrivants								*****
	***** Entraine : renvoie la valeur de pARCSOMListeArcsArrivants				*****
	********************************************************************************/
	CArc** SOMLireListeArcsArrivants()
	{
		return pARCSOMListeArcsArrivants;
	}

	/********************************************************************************
	***** SOMLIRELISTEARCSPARTANTS : lit la liste d'arcs partants du sommet		*****
	*********************************************************************************
	***** Entree: (rien)														*****
	***** Necessite: (rien)														*****
	***** Sortie: CArc** pARCSOMListeArcsPartants								*****
	***** Entraine : renvoie la valeur de pARCSOMListeArcsPartants				*****
	********************************************************************************/
	CArc** SOMLireListeArcsPartants()
	{
		return pARCSOMListeArcsPartants;
	}

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
	void SOMAjouterArcArrivant(CArc* pARCArc);

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
	void SOMAjouterArcPartant(CArc* pARCArc);


	/************************************************************
	***** SOMMODIFIERNUMERO : modifie le numero du sommet	*****
	*************************************************************
	***** Entree: unsigned int uiNum						*****
	***** Necessite: (rien)									*****
	***** Sortie: (rien)									*****
	***** Entraine : (rien)									*****
	************************************************************/
	void SOMModifierNumero(unsigned int uiNum)
	{
		uiSOMNumero = uiNum;
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
	void SOMModifierArcArrivant(CArc & ARCParam, unsigned int uiPosition);

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
	void SOMModifierArcPartant(CArc & ARCParam, unsigned int uiPosition);

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
	void SOMSupprimerArcArrivant(unsigned int uiPosition);

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
	void SOMSupprimerArcPartant(unsigned int uiPosition);


	int SOMRechercheIndiceArcArrivant(unsigned int uiDestination);


	int SOMRechercheIndiceArcPartant(unsigned int uiDestination);

};

#include "CSommet.ipp"

#endif 