#ifndef CARC_H
#define CARC_H

#include "CException.h"

class CArc
{
private:
	unsigned int uiNumeroDestination;

public:
	/**************************************************************************
	***** CARC : Constructeur par defaut de la classe CArc				  *****
	***************************************************************************
	***** Entree: (rien)												  *****
	***** Necessite: (rien)												  *****
	***** Sortie: (rien)												  *****
	***** Entraine : le numero de destination de l'arc est initialise a 0 *****
	**************************************************************************/
	CArc();

	/******************************************************
	***** ~CARC : Destructeur de la classe CArc		  *****
	*******************************************************
	***** Entree: (rien)							  *****
	***** Necessite: (rien)							  *****
	***** Sortie: (rien)							  *****
	***** Entraine : L'objet est desinitialise		  *****
	******************************************************/
	~CArc();

	/***************************************************************************
	***** ARCLIRENUMERODESTINATION : lit le numero de destination de l'arc *****
	****************************************************************************
	***** Entree: (rien)												   *****
	***** Necessite: (rien)												   *****
	***** Sortie: unsigned int uiNumeroDestination						   *****
	***** Entraine : renvoie la valeur de uiNumeroDestination			   *****
	***************************************************************************/
	unsigned int ARCLireNumeroDestination()
	{
		return uiNumeroDestination;
	}

	/***********************************************************************************
	***** ARCMODIFIERNUMERODESTINATION : modifie le numero de destination de l'arc *****
	************************************************************************************
	***** Entree: unsigned int uiNumero											   *****
	***** Necessite: (rien)														   *****
	***** Sortie: (rien)														   *****
	***** Entraine : (rien)														   *****
	***********************************************************************************/
	void ARCModifierNumeroDestination(unsigned int uiNumero)
	{
		uiNumeroDestination = uiNumero;
	}

	CArc(int iDestination);

};


#endif 