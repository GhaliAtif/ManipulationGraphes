#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "CException.h"

/***********************************************************************
***** CEXCEPTION : Constructeur par defaut de la classe CException *****
************************************************************************
***** Entree: (rien)											   *****
***** Necessite: (rien)											   *****
***** Sortie: (rien)											   *****
***** Entraine : les attributs sont initialises					   *****
***********************************************************************/
CException::CException()
{
	iEXCCodeErreurs = 0;
	cEXCErreurs[500] = NULL;
}

/*********************************************************************
***** CEXCEPTION : Constructeur de confort						 *****
**********************************************************************
***** Entree: int iArg, const char cArg[500]					 *****
***** Necessite: (rien)											 *****
***** Sortie: (rien)											 *****
***** Entraine : initialise l'objet avec les parametres d'entree *****
*********************************************************************/
CException::CException(int iArg, const char cEXCArg[500])
{
	iEXCCodeErreurs = iArg;
	strcpy_s(cEXCErreurs, 500, cEXCArg);
}

/************************************************************
***** ~CEXCEPTION : Destructeur de la classe CException *****
*************************************************************
***** Entree: (rien)									*****
***** Necessite: (rien)									*****
***** Sortie: (rien)									*****
***** Entraine : L'objet est desinitialise				*****
************************************************************/
CException::~CException()
{

}
