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
		***** Entraine : les attributs sont initialises					   *****
		***********************************************************************/
		CException();

		/*********************************************************************
		***** CEXCEPTION : Constructeur de confort						 *****
		**********************************************************************
		***** Entree: unsigned int uiArg, const char cArg[500]			 *****
		***** Necessite: (rien)											 *****
		***** Sortie: (rien)											 *****
		***** Entraine : initialise l'objet avec les parametres d'entree *****
		*********************************************************************/
		CException(unsigned int uiArg, const char cArg[500]);

		/************************************************************
		***** ~CEXCEPTION : Destructeur de la classe CException *****
		*************************************************************
		***** Entree: (rien)									*****
		***** Necessite: (rien)									*****
		***** Sortie: (rien)									*****
		***** Entraine : L'objet est desinitialise				*****
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
		unsigned int EXCLireValeur()
		{
			return uiEXCCodeErreurs;
		}



		/* ----- Dans le fichier CAfficherException.h -----*/

		/*************************************************************************
		***** AFEAFFICHERERREUR : affiche l'erreur							 *****
		**************************************************************************
		***** Entree: (rien)												 *****
		***** Necessite: (rien)												 *****
		***** Sortie: (rien)												 *****
		***** Entraine : lit le message d'erreur dans cEXCErreurs			 *****
		*************************************************************************/
		void AFEAfficherErreur();


};



#endif