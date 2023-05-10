
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
***** Entraine : L'objet est initialise par la valeur par defaut 0 *****
***********************************************************************/
CException::CException()
{
	uiEXCCodeErreurs = 0;
	cEXCErreurs[500] = NULL;
}

/******************************************************************************************
***** CEXCEPTION : Constructeur de confort											  *****
*******************************************************************************************
***** Entree: (rien)																  *****
***** Necessite: (rien)																  *****
***** Sortie: (rien)																  *****
***** Entraine : construit un objet Exception auquel est attribue un message d'erreur *****
******************************************************************************************/
CException::CException(unsigned int uiEXCArg, const char cEXCArg[500])
{
	uiEXCCodeErreurs = uiEXCArg;
	strcpy_s(cEXCErreurs, 500, cEXCArg);
}

/************************************************************
***** ~CEXCEPTION : Destructeur de la classe CException *****
*************************************************************
***** Entree: (rien)									*****
***** Necessite: (rien)									*****
***** Sortie: (rien)									*****
***** Entraine : L'objet est desalloue					*****
************************************************************/
CException::~CException()
{

}

/****************************************************************
***** EXCLireValeur : Lit le code de l'exception levee		*****
*****************************************************************
***** Entree: (rien)									    *****
***** Necessite: (rien)										*****
***** Sortie: unsigned int uiEXCCodeErreurs				    *****
***** Entraine : lit la valeur du code d'erreur				*****
****************************************************************/
unsigned int CException::EXCLireValeur()
{
	return uiEXCCodeErreurs;
}