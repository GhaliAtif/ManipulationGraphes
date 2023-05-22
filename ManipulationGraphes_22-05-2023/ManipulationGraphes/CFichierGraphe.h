#ifndef CFICHIERGRAPHE_H
#define CFICHIERGRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <fstream>
#include <string.h>

#include "CSommet.h"

class CFichierGraphe
{
	private:
		char* pcFIGNomFichier;
		unsigned int uiFIGNombreSommets;
		unsigned int uiFIGNombreArcs;
		CSommet** pSOMFIGSommets;


	public:


		/*****************************************************************************
		***** CFichierGraphe: Constructeur par defaut de la classe CFichier		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: (rien)													 *****
		***** Entraîne : L'objet est initialise avec pcFIGNomFichier = NULL		 *****
		******************************************************************************/
		CFichierGraphe();


		/*****************************************************************************
		***** ~CFichierGraphe(): Destructeur de la classe CFichierGraphe		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: (rien)													 *****
		***** Entraîne :	L'objet est desinitialise							 *****
		******************************************************************************/
		~CFichierGraphe();


		/*****************************************************************************
		***** FIGLireNomFichier(): Lit le nom du fichier						 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: pcFIGNomFichier											 *****
		***** Entraîne : renvoie pcFIGNomFichier								 *****
		******************************************************************************/
		char* FIGLireNomFichier();



		/************************************************************************************************
		***** FIGModifierNomFichier : modifie le nom du fichier										*****
		*************************************************************************************************
		***** Entree: const char * pcNom															*****
		***** Necessite:	(rien)																    *****
		***** Sortie: (rien)																	    *****
		***** Entraîne : pcFIGNomFichier = pcNom													*****
		*************************************************************************************************/
		void FIGModifierNomFichier(const char * pcNom);


		/************************************************************************************************
		***** FIGLIREGRAPHEDANSFICHIER : lit et extrait des informations du fichier texte			*****
		*************************************************************************************************
		***** Entree: (rien)																		*****
		***** Necessite: (rien)																		*****
		***** Sortie: un objet CGraphe															    *****
		***** Entraîne : le graphe cree possede les parametres ecrit dans le fichier texte			*****
		*************************************************************************************************/
		void FIGLireGrapheDansFichier();


};

#endif