#include "CArc.h"

/**************************************************************************
***** CARC : Constructeur par defaut de la classe CArc				  *****
***************************************************************************
***** Entree: (rien)												  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : le numero de destination de l'arc est initialise a 0 *****
**************************************************************************/
CArc::CArc()
{
	uiARCNumeroDestination = 0;
}

/***********************************************************************************************************
***** CARC : Constructeur de confort de la classe CArc												   *****
************************************************************************************************************
***** Entree: (rien)																				   *****
***** Necessite: (rien)																				   *****
***** Sortie: (rien)																				   *****
***** Entraine : le numero de destination de l'arc est initialise avec la valeur "uiNumeroDestination" *****
***********************************************************************************************************/
CArc::CArc(unsigned int uiNumeroDestination)
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
CArc::~CArc()
{

}

