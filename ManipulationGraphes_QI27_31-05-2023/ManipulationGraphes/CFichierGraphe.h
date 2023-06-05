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
		***** Entra�ne : L'objet est initialise avec pcFIGNomFichier = NULL		 *****
		******************************************************************************/
		CFichierGraphe();


		/*****************************************************************************
		***** ~CFICHIERGRAPHE(): Destructeur de la classe CFichierGraphe		 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: (rien)													 *****
		***** Entra�ne :	L'objet est desinitialise							 *****
		******************************************************************************/
		~CFichierGraphe();


		/*****************************************************************************
		***** FIGLIRENOMFICHIER: Lit le nom du fichier							 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: pcFIGNomFichier											 *****
		***** Entra�ne : renvoie pcFIGNomFichier								 *****
		******************************************************************************/
		char* FIGLireNomFichier();

		/*****************************************************************************
		***** FIGLIRENOMBRESOMMETS : lit le nombre de sommets					 *****
		******************************************************************************
		***** Entree: (rien)													 *****
		***** Necessite:	(rien)												 *****
		***** Sortie: uiFIGNombreSommets										 *****
		***** Entra�ne : renvoie la valeur de uiFIGNombreSommets				 *****
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
		***** Entra�ne : renvoie la valeur de uiFIGNombreArcsPartants			 *****
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
		***** Entra�ne : renvoie la valeur de uiFIGNombreArcsArrivants			 *****
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
		***** Entra�ne : renvoie le pointeur pUNIFIGSommets						 *****
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
		***** Entra�ne : renvoie le pointeur pUNIFIGListeSommetsDepart								   *****
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
		***** Entra�ne : renvoie le pointeur pUNIFIGListeSommetsArrivee									*****
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
		***** Entra�ne : pcFIGNomFichier = pcNom													*****
		*************************************************************************************************/
		void FIGModifierNomFichier(const char * pcNom);


		/************************************************************************************************
		***** FIGLIREGRAPHEDANSFICHIER : lit et extrait des informations du fichier texte			*****
		*************************************************************************************************
		***** Entree: (rien)																		*****
		***** Necessite: (rien)																		*****
		***** Sortie: un objet CGraphe															    *****
		***** Entra�ne : le graphe cree possede les parametres ecrit dans le fichier texte			*****
		*************************************************************************************************/
		void FIGLireGrapheDansFichier();


};

#endif