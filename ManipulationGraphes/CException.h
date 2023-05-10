
#ifndef CEXCEPTION_H
#define CEXCEPTION_H

class CException
{
private:
	unsigned int uiEXCCodeErreurs; //Code d'erreur
	char cEXCErreurs[500]; //Chaine de caracteres contenant un message d'erreur;

public:
	/***********************************************************************
	***** CEXCEPTION : Constructeur par defaut de la classe CException *****
	************************************************************************
	***** Entree: (rien)											   *****
	***** Necessite: (rien)											   *****
	***** Sortie: (rien)											   *****
	***** Entraine : L'objet est initialise par la valeur par defaut 0 *****
	***********************************************************************/
	CException();

	/******************************************************************************************
	***** CEXCEPTION : Constructeur de confort											  *****
	*******************************************************************************************
	***** Entree: (rien)																  *****
	***** Necessite: (rien)																  *****
	***** Sortie: (rien)																  *****
	***** Entraine : construit un objet Exception auquel est attribue un message d'erreur *****
	******************************************************************************************/
	CException(unsigned int uiArg, const char cArg[500]);

	/************************************************************
	***** ~CEXCEPTION : Destructeur de la classe CException *****
	*************************************************************
	***** Entree: (rien)									*****
	***** Necessite: (rien)									*****
	***** Sortie: (rien)									*****
	***** Entraine : L'objet est desalloue					*****
	************************************************************/
	~CException();

	/****************************************************************
	***** EXCLIREVALEUR : Lit le code de l'exception levee		*****
	*****************************************************************
	***** Entree: (rien)									    *****
	***** Necessite: (rien)										*****
	***** Sortie: unsigned int uiEXCCodeErreurs				    *****
	***** Entraine : lit la valeur du code d'erreur				*****
	****************************************************************/
	unsigned int EXCLireValeur();




};



#endif