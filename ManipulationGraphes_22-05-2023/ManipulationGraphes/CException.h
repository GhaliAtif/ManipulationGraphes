#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define EXC_VIOLATION_ACCES 1
#define EXC_ARC_EXISTANT 2
#define EXC_ARC_INEXISTANT 9999000
#define EXC_ARGUMENT_NULL 3
#define EXC_ARC_NON_EXISTANT 4
#define EXC_SOMMET_EXISTANT 5
#define EXC_SOMMET_INEXISTANT 9999001
#define EXC_MAUVAIS_NOMBRE_ARGUMENTS 6
#define EXC_OUVERTURE_FICHIER 7

class CException
{
	private:
		int iEXCCodeErreurs; //Code d'erreur
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
		***** Entree: int iArg, const char cArg[500]					 *****
		***** Necessite: (rien)											 *****
		***** Sortie: (rien)											 *****
		***** Entraine : initialise l'objet avec les parametres d'entree *****
		*********************************************************************/
		CException(int iArg, const char cArg[500]);

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
		***** Sortie: int iEXCCodeErreurs						    *****
		***** Entraine : lit la valeur du code d'erreur				*****
		****************************************************************/
		int EXCLireValeur()
		{
			return iEXCCodeErreurs;
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