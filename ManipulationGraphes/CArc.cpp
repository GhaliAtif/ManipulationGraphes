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
	uiNumeroDestination = 0;
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


CArc::CArc(int iDestination)
{
	// Vérification paramètre positif
	if (iDestination < 0)
	{
		CException EXCErreur(EXCValeurDestination, "Valeur destination negative");
		throw(EXCErreur);
	}

	// Initialisation de l'attribut
	uiNumeroDestination = iDestination;
}