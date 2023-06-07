#ifndef CAFFICHEEXCEPTION
#define CAFFICHEEXCEPTION

#include "CException.h"

class CAfficherException : public CException {
private:
	unsigned int uiEXCCodeErreurs; 
	char cEXCErreurs[500];
public:

	/*************************************************************************
	***** EXCAFFICHERERREUR : Affiche l'erreur							 *****
	**************************************************************************
	***** Entree: (rien)												 *****
	***** Necessite: (rien)												 *****
	***** Sortie: (rien)												 *****
	***** Entraine : lit le message d'erreur dans cEXCErreurs			 *****
	*************************************************************************/
	void AFEAfficherErreur();



};

#endif // !CAFFICHEEXCEPTION




