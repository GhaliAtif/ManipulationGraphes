#ifndef CFICHIERGRAPHE_H
#define CFICHIERGRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <fstream>
#include <string.h>

#include "CException.h"
#include "CGraphe.h"


class CFichierGraphe 
{
private:


	char* pcFIGNomFichier;

public:


	/*****************************************************************************
	*****CFichierGraphe(): Constructeur par d�faut de la classe CFichier	 *****
	******************************************************************************
	***** Entr�e: (rien)													 *****
	***** N�cessite:	(rien)												 *****
	***** Sortie: (rien)													 *****
	***** Entra�ne :	L'objet est initialis� avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	CFichierGraphe();


	/*****************************************************************************************************
	***** CFichierGraphe(CFichierGraphe &FIGParam): Constructeur de recopie de CFichierGraphe		 *****				 *****
	*****			prenant en param�tre un CFichierGraphe											 *****
	******************************************************************************************************
	***** Entr�e: (rien)																			 *****
	***** N�cessite:	CFichier &FIGParam doit �tre initialis�										 *****								 *****
	***** Sortie: (rien)																			 *****
	***** Entra�ne :	Modification du nom du fichier												 *****
	******************************************************************************************************/
	CFichierGraphe(CFichierGraphe &FIGParam);


	/*****************************************************************************
	*****~CFichierGraphe(): Destructeur de la classe CFichierGraphe			 *****
	******************************************************************************
	***** Entr�e: (rien)													 *****
	***** N�cessite:	(rien)												 *****
	***** Sortie: (rien)													 *****
	***** Entra�ne :	L'objet est initialis� avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	~CFichierGraphe();


	/*****************************************************************************
	*****FIGLireNomFichier(): Lit le nom du fichier							 *****
	******************************************************************************
	***** Entr�e: (rien)													 *****
	***** N�cessite:	(rien)												 *****
	***** Sortie: pcFIGNomFichier											 *****
	***** Entra�ne :	L'objet est initialis� avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	char* FIGLireNomFichier();



	/************************************************************************************************
	*****FIGModifierNomFichier(const char * pcNom):FIGModifierNomFichier(const char * pcNom)	*****							 *****
	*************************************************************************************************
	***** Entr�e: (rien)																		*****
	***** N�cessite:	(rien)																    *****
	***** Sortie: pcFIGNomFichier															    *****
	***** Entra�ne :	lib�ration de pcFIGNomFichier et pcFIGNomFichier = pcNom				*****
	*************************************************************************************************/
	void FIGModifierNomFichier(const char * pcNom);


	/************************************************************************************************
	*****FICLireFichier():	Lecture du fichier et extraction des informations dans le fichier	*****							 
	*************************************************************************************************
	***** Entr�e: (rien)																		*****
	***** N�cessite:	(rien)																    *****
	***** Sortie: pcFIGNomFichier															    *****
	***** Entra�ne :																			*****
	*************************************************************************************************/
	CGraphe& FIGLireFichier();


};

#endif // !CFICHIERGRAPHE_H