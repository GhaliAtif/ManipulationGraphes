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


CArc::CArc(unsigned int uiNumeroDestination)
{

	// Initialisation de l'attribut
	uiARCNumeroDestination = uiNumeroDestination;
}