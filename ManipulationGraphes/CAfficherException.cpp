
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "CAfficherException.h"

/*************************************************************************
***** EXCAfficherErreur : Affiche l'erreur							 *****
**************************************************************************
***** Entree: (rien)												 *****
***** Necessite: (rien)												 *****
***** Sortie: (rien)												 *****
***** Entraine : lit le message d'erreur dans cEXCErreurs			 *****
*************************************************************************/
void CAfficherException::AFEAfficherErreur()
{
	std::cout << cEXCErreurs << "\n\n";
}