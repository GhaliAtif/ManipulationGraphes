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
	*****CFichierGraphe(): Constructeur par défaut de la classe CFichier	 *****
	******************************************************************************
	***** Entrée: (rien)													 *****
	***** Nécessite:	(rien)												 *****
	***** Sortie: (rien)													 *****
	***** Entraîne :	L'objet est initialisé avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	CFichierGraphe();


	/*****************************************************************************************************
	***** CFichierGraphe(CFichierGraphe &FIGParam): Constructeur de recopie de CFichierGraphe		 *****				 *****
	*****			prenant en paramètre un CFichierGraphe											 *****
	******************************************************************************************************
	***** Entrée: (rien)																			 *****
	***** Nécessite:	CFichier &FIGParam doit être initialisé										 *****								 *****
	***** Sortie: (rien)																			 *****
	***** Entraîne :	Modification du nom du fichier												 *****
	******************************************************************************************************/
	CFichierGraphe(CFichierGraphe &FIGParam);


	/*****************************************************************************
	*****~CFichierGraphe(): Destructeur de la classe CFichierGraphe			 *****
	******************************************************************************
	***** Entrée: (rien)													 *****
	***** Nécessite:	(rien)												 *****
	***** Sortie: (rien)													 *****
	***** Entraîne :	L'objet est initialisé avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	~CFichierGraphe();


	/*****************************************************************************
	*****FIGLireNomFichier(): Lit le nom du fichier							 *****
	******************************************************************************
	***** Entrée: (rien)													 *****
	***** Nécessite:	(rien)												 *****
	***** Sortie: pcFIGNomFichier											 *****
	***** Entraîne :	L'objet est initialisé avec pcFIGNomFichier = NULL	 *****
	******************************************************************************/
	char* FIGLireNomFichier();



	/************************************************************************************************
	*****FIGModifierNomFichier(const char * pcNom):FIGModifierNomFichier(const char * pcNom)	*****							 *****
	*************************************************************************************************
	***** Entrée: (rien)																		*****
	***** Nécessite:	(rien)																    *****
	***** Sortie: pcFIGNomFichier															    *****
	***** Entraîne :	libération de pcFIGNomFichier et pcFIGNomFichier = pcNom				*****
	*************************************************************************************************/
	void FIGModifierNomFichier(const char * pcNom);


	/************************************************************************************************
	*****FICLireFichier():	Lecture du fichier et extraction des informations dans le fichier	*****							 
	*************************************************************************************************
	***** Entrée: (rien)																		*****
	***** Nécessite:	(rien)																    *****
	***** Sortie: pcFIGNomFichier															    *****
	***** Entraîne :																			*****
	*************************************************************************************************/
	CGraphe& FIGLireFichier();


};

#endif // !CFICHIERGRAPHE_H