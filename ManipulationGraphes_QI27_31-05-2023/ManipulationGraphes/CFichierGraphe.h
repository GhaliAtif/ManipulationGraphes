#ifndef CFICHIERGRAPHE_H
#define CFICHIERGRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <fstream>
#include <string.h>

#include "CException.h"

class CFichierGraphe
{
	private:
		char* pcFIGNomFichier;
		unsigned int uiFIGNombreSommets;
		unsigned int uiFIGNombreArcsPartants;
		unsigned int uiFIGNombreArcsArrivants;
		unsigned int* pUNIFIGSommets;
		unsigned int* pUNIFIGListeSommetsDepart;
		unsigned int* pUNIFIGListeSommetsArrivee;


	public:


		/*****************************************************************************
		***** CFICHIERGRAPHE: Constructeur par defaut de la classe CFichier		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: (rien)													 *****
		***** Entraîne : L'objet est initialise avec pcFIGNomFichier = NULL		 *****
		******************************************************************************/
		CFichierGraphe();


		/*****************************************************************************
		***** ~CFICHIERGRAPHE(): Destructeur de la classe CFichierGraphe		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: (rien)													 *****
		***** Entraîne :	L'objet est desinitialise							 *****
		******************************************************************************/
		~CFichierGraphe();


		/*****************************************************************************
		***** FIGLIRENOMFICHIER: Lit le nom du fichier							 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: pcFIGNomFichier											 *****
		***** Entraîne : renvoie pcFIGNomFichier								 *****
		******************************************************************************/
		char* FIGLireNomFichier();

		/*****************************************************************************
		***** FIGLIRENOMBRESOMMETS : lit le nombre de sommets					 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: uiFIGNombreSommets										 *****
		***** Entraîne : renvoie la valeur de uiFIGNombreSommets				 *****
		******************************************************************************/
		unsigned int FIGLireNombreSommets()
		{
			return uiFIGNombreSommets;
		}

		/*****************************************************************************
		***** FIGLIRENOMBREARCSPARTANTS : lit le nombre d'arcs partants			 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: uiFIGNombreArcsPartants									 *****
		***** Entraîne : renvoie la valeur de uiFIGNombreArcsPartants			 *****
		******************************************************************************/
		unsigned int FIGLireNombreArcsPartants()
		{
			return uiFIGNombreArcsPartants;
		}

		/*****************************************************************************
		***** FIGLIRENOMBREARCSARRIVANTS : lit le nombre d'arcs arrivants		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: uiFIGNombreArcsArrivants									 *****
		***** Entraîne : renvoie la valeur de uiFIGNombreArcsArrivants			 *****
		******************************************************************************/
		unsigned int FIGLireNombreArcsArrivants()
		{
			return uiFIGNombreArcsArrivants;
		}

		/*****************************************************************************
		***** FIGLIRESOMMETS : lit la liste des numeros des sommets				 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: pUNIFIGSommets											 *****
		***** Entraîne : renvoie le pointeur pUNIFIGSommets						 *****
		******************************************************************************/
		unsigned int* FIGLireSommets()
		{
			return pUNIFIGSommets;
		}

		/***************************************************************************************************
		***** FIGLIRELISTESOMMETSDEPART : lit la liste des numeros des sommets de depart de chaque arc *****
		****************************************************************************************************
		***** Entree: (rien)																		   *****
		***** Necessite:	(rien)																	   *****
		***** Sortie: pUNIFIGListeSommetsDepart														   *****
		***** Entraîne : renvoie le pointeur pUNIFIGListeSommetsDepart								   *****
		***************************************************************************************************/
		unsigned int* FIGLireListeSommetsDepart()
		{
			return pUNIFIGListeSommetsDepart;
		}

		/****************************************************************************************************
		***** FIGLIRELISTESOMMETSARRIVEE: lit la liste des numeros des sommets d'arrivee de chaque arc	*****
		*****************************************************************************************************
		***** Entree: (rien)																			*****
		***** Necessite:	(rien)																		*****
		***** Sortie: pUNIFIGListeSommetsArrivee														*****
		***** Entraîne : renvoie le pointeur pUNIFIGListeSommetsArrivee									*****
		****************************************************************************************************/
		unsigned int* FIGLireListeSommetsArrivee()
		{
			return pUNIFIGListeSommetsArrivee;
		}

		/************************************************************************************************
		***** FIGMODIFIERNOMFICHIER : modifie le nom du fichier										*****
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