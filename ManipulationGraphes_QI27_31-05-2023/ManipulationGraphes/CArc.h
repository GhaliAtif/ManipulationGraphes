#ifndef CARC_H
#define CARC_H

#include "CException.h"

class CArc
{
	private:
		unsigned int uiARCNumeroDestination;

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

		/**************************************************************************
		***** CARC : Constructeur de recopie de la classe CArc				  *****
		***************************************************************************
		***** Entree: CArc & ARCParam										  *****
		***** Necessite: (rien)												  *****
		***** Sortie: (rien)												  *****
		***** Entraine : une copie de ARCParam est creee					  *****
		**************************************************************************/
		CArc(CArc & ARCParam)
		{
			uiARCNumeroDestination = ARCParam.uiARCNumeroDestination;
		}

		/***********************************************************************************************************
		***** CARC : Constructeur de confort de la classe CArc												   *****
		************************************************************************************************************
		***** Entree: unsigned int uiNumeroDestination														   *****
		***** Necessite: (rien)																				   *****
		***** Sortie: (rien)																				   *****
		***** Entraine : le numero de destination de l'arc est initialise avec la valeur "uiNumeroDestination" *****
		***********************************************************************************************************/
		CArc(unsigned int uiNumeroDestination)
		{
			uiARCNumeroDestination = uiNumeroDestination;
		}

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
		***** Sortie: unsigned int uiARCNumeroDestination						   *****
		***** Entraine : renvoie la valeur de uiARCNumeroDestination			   *****
		***************************************************************************/
		unsigned int ARCLireNumeroDestination()
		{
			return uiARCNumeroDestination;
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
			uiARCNumeroDestination = uiNumero;
		}


};


#endif 

