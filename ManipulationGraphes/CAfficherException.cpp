#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "CException.h"

using namespace std;

/*************************************************************************
***** AFEAFFICHERERREUR : affiche l'erreur							 *****
**************************************************************************
***** Entree: (rien)												 *****
***** Necessite: (rien)												 *****
***** Sortie: (rien)												 *****
***** Entraine : lit le message d'erreur dans cEXCErreurs			 *****
*************************************************************************/
void CException::AFEAfficherErreur()
{
	cout << cEXCErreurs << endl << endl;
}