#ifndef CGRAPHE_H
#define CGRAPHE_H

#include "CSommet.h"
#include "CFichierGraphe.h"

class CGraphe
{
	private:
		unsigned int uiGRANombreSommets;
		bool bGRAUtiliseOperateurNew;
		CSommet ** pSOMGRAListeSommets;

	public:

		/**************************************************************************
		***** CGRAPHE : Constructeur par defaut de la classe CGraphe		  *****
		***************************************************************************
		***** Entree: (rien)												  *****
		***** Necessite: (rien)												  *****
		***** Sortie: (rien)												  *****
		***** Entraine : le nombre de sommets du graphe est initialise a 0	  *****
		**************************************************************************/
		CGraphe();

		/**************************************************************************
		***** CGRAPHE : Constructeur de recopie de la classe CGraphe		  *****
		***************************************************************************
		***** Entree: CGraphe & GRAParam									  *****
		***** Necessite: (rien)												  *****
		***** Sortie: (rien)												  *****
		***** Entraine : une copie de GRAParam est creee					  *****
		**************************************************************************/
		CGraphe(CGraphe & GRAParam);

		/**************************************************************************
		***** CGRAPHE : convertit un CFichierGraphe en CGraphe				  *****
		***************************************************************************
		***** Entree: CFichierGraphe & FIGParam								  *****
		***** Necessite: (rien)												  *****
		***** Sortie: (rien)												  *****
		***** Entraine : cree un graphe a partir d'un fichier texte			  *****
		**************************************************************************/
		CGraphe(CFichierGraphe & FIGParam);

		/******************************************************
		***** ~CGRAPHE : Destructeur de la classe CGraphe *****
		*******************************************************
		***** Entree: (rien)							  *****
		***** Necessite: (rien)							  *****
		***** Sortie: (rien)							  *****
		***** Entraine : L'objet est desinitialise		  *****
		******************************************************/
		~CGraphe();

		/*************************************************************
		***** GRALIRENOMBRESOMMETS : lit le nombre de sommets	 *****
		**************************************************************
		***** Entree: (rien)									 *****
		***** Necessite: (rien)									 *****
		***** Sortie: unsigned int uiGRANombreSommets		     *****
		***** Entraine : renvoie la liste uiGRANombreSommets	 *****
		*************************************************************/
		unsigned int GRALireNombreSommets()
		{
			return uiGRANombreSommets;
		}

		/*************************************************************
		***** GRALIRELISTESOMMETS : lit la liste de sommets		 *****
		**************************************************************
		***** Entree: (rien)									 *****
		***** Necessite: (rien)									 *****
		***** Sortie: CSommet ** pSOMGRAListeSommets		     *****
		***** Entraine : renvoie la liste pSOMGRAListeSommets	 *****
		*************************************************************/
		CSommet ** GRALireListeSommets()
		{
			return pSOMGRAListeSommets;
		}

		/******************************************************************************
		***** GRAAJOUTERSOMMET : ajoute un sommet								  *****
		*******************************************************************************
		***** Entree: CSommet & SOMParam										  *****
		***** Necessite: (rien)													  *****
		***** Sortie: (rien)													  *****
		***** Entraine: ajoute SOMParam a pSOMGRAListeSommets					  *****
		*****		 OU (le sommet existe deja) leve une exception				  *****
		******************************************************************************/
		void GRAAjouterSommet(CSommet & SOMParam);

		/*******************************************************************************************************************
		***** GRAAJOUTERARC : ajoute un arc au graphe																   *****
		********************************************************************************************************************
		***** Entree: unsigned int uiDepart, CArc & ARCParam														   *****
		***** Necessite: (rien)																						   *****
		***** Sortie: un indice de boucle																			   *****
		***** Entraine : ajoute ARCParam dans le graphe																   *****
		*****		  OU (un des sommets n'existe pas) leve une exception											   *****
		*****		  OU (l'arc existe deja) leve une exception														   *****
		*******************************************************************************************************************/
		void GRAAjouterArc(unsigned int uiDepart, CArc & ARCParam);

		/******************************************************************************************
		***** GRAMODIFIERSOMMET : modifie un sommet du graphe								  *****
		*******************************************************************************************
		***** Entree: unsigned int uiNumero, CSommet & SOMParam								  *****
		***** Necessite: (rien)																  *****
		***** Sortie: (rien)																  *****
		***** Entraine : modifie un sommet de pSOMGRAListeSommets							  *****
		*****         OU (liste vide) leve une exception									  *****
		*****		  OU (le sommet modifie est un sommet qui existe deja) leve une exception *****
		*****		  OU (le sommet n'est pas dans la liste) leve une exception				  *****
		******************************************************************************************/
		void GRAModifierSommet(unsigned int uiNumero, CSommet & SOMParam);

		/************************************************************************************************************************************************
		***** GRAMODIFIERARC : modifie un arc du graphe																								*****
		*************************************************************************************************************************************************
		***** Entree: unsigned int uiNouveauDepart, unsigned int uiNouvelleArrivee, unsigned int uiAncienDepart, CArc & ARCParam				    *****
		***** Necessite: (rien)																														*****
		***** Sortie: (rien)																														*****
		***** Entraine : ARCParam a pour destination "uiNouvelleArrivee" et pour source uiNouveauDepart												*****
		*****		  OU (un des sommets n'existe pas) leve une exception																			*****
		*****		  OU (l'arc n'existe pas) leve une exception																					*****
		************************************************************************************************************************************************/
		void GRAModifierArc(unsigned int uiNouveauDepart, unsigned int uiNouvelleArrivee, unsigned int uiAncienDepart, CArc & ARCParam);

		/************************************************************************************
		***** GRASUPPRIMERSOMMET : supprime un sommet									*****
		*************************************************************************************
		***** Entree: CSommet & SOMParam												*****
		***** Necessite: (rien)															*****
		***** Sortie: (rien)															*****
		***** Entraine : supprime un arc a pSOMGRAListeSommets							*****
		*****         OU (liste vide) leve une exception								*****
		*****         OU (le sommet n'est pas dans la liste) leve une exception		    *****
		************************************************************************************/
		void GRASupprimerSommet(CSommet & SOMParam);

		/************************************************************************************************************************************************
		***** GRASUPPRIMERARC : supprime un arc de source "uiNumeroSommetDepart" et de destination "uiNumeroSommetArrivee"							*****
		*************************************************************************************************************************************************
		***** Entree: unsigned int uiDepart, CArc & ARCParam																						*****
		***** Necessite: (rien)																														*****
		***** Sortie: (rien)																														*****
		***** Entraine : l'arc "ARCParam" est supprime du graphe																					*****
		*****		  OU (un des sommets n'existe pas) leve une exception																			*****
		*****		  OU (l'arc n'existe pas) leve une exception																					*****
		************************************************************************************************************************************************/
		void GRASupprimerArc(unsigned int uiDepart, CArc & ARCParam);

		/****************************************************************************************************************
		***** GRAVERIFIEREXISTENCECOLORATION : regarde si une coloration particuliere est possible pour le graphe	*****
		*****************************************************************************************************************
		***** Entree: unsigned int uiNombreCouleurs, unsigned int uiIndiceListeSommet = 0							*****
		***** Necessite: (rien)																						*****
		***** Sortie: un booleen																					*****
		***** Entraine : renvoie vrai																				*****
		*****		  OU (une coloration n'est pas possible) renvoie faux											*****
		****************************************************************************************************************/
		bool GRAVerifierExistanceColoration(unsigned int uiNombreCouleurs, unsigned int uiIndiceListeSommet = 0);

		/****************************************************************************************
		***** GRANOMBRESOMMETSVOISINS : renvoie le nombre de sommets voisins d'un sommet	*****
		*****************************************************************************************
		***** Entree: CSommet & SOMParam													*****
		***** Necessite: (rien)																*****
		***** Sortie: un naturel															*****
		***** Entraine : renvoie le nombre de voisins										*****
		****************************************************************************************/
		unsigned int GRANombreSommetsVoisins(CSommet & SOMParam)
		{
			// retourne le nombre de sommets voisins de SOMParam
			return SOMParam.SOMLireNombreArcsPartants() + SOMParam.SOMLireNombreArcsArrivants();
		}

		/****************************************************************************************
		***** GRAVERIFIERSOMMETSTOUSCOLORIES : regarde si tous les sommets sont colories	*****
		*****************************************************************************************
		***** Entree: (rien)																*****
		***** Necessite: (rien)																*****
		***** Sortie: un booleen															*****
		***** Entraine : retourne vrai														*****
		***** OU (1 des sommets n'est pas colorie) retourne faux							*****
		****************************************************************************************/
		bool GRAVerifierSommetsTousColories();

		/************************************************************************************************************
		***** GRARENVOYERCOULEURSDISPONIBLES : renvoie la liste des couleurs disponibles pour un sommet			*****
		*************************************************************************************************************
		***** Entree: CSommet & SOMParam, unsigned int uiNombreCouleur											*****
		***** Necessite: (rien)																					*****
		***** Sortie: un pointeur																				*****
		***** Entraine : renvoie la liste des couleurs disponibles												*****
		************************************************************************************************************/
		unsigned int * GRARenvoyerCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur);

		/********************************************************************************************************
		***** GRARENVOYERINDICESOMMETSVOISINS : renvoie l'indice de liste des sommets voisins d'un sommet	*****
		*********************************************************************************************************
		***** Entree: CSommet & SOMParam																	*****
		***** Necessite: (rien)																				*****
		***** Sortie: un pointeur																			*****
		***** Entraine : la liste des indices de liste des voisins											*****
		********************************************************************************************************/
		unsigned int * GRARenvoyerIndiceSommetsVoisins(CSommet & SOMParam);

		/************************************************************************************************************
		***** GRARENVOYERTAILLECOULEURSDISPONIBLES : renvoie le nombre de couleurs disponibles pour un sommet	*****
		*************************************************************************************************************
		***** Entree: CSommet & SOMParam, unsigned int uiNombreCouleur											*****
		***** Necessite: (rien)																					*****
		***** Sortie: un naturel																				*****
		***** Entraine : renvoie le nombre de couleurs disponibles												*****
		************************************************************************************************************/
		unsigned int GRARenvoyerTailleCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur);
		




		/* Dans CGestionGraphe.h */

		/******************************************************
		***** GEGAFFICHERGRAPHE : affiche le graphe		  *****
		*******************************************************
		***** Entree: (rien)							  *****
		***** Necessite: (rien)							  *****
		***** Sortie: (rien)							  *****
		***** Entraine : le graphe est affiche			  *****
		******************************************************/
		void GEGAfficherGraphe();

		/************************************************************************
		***** GEGAFFICHERGRAPHENONORIENTE : affiche le graphe non oriente	*****
		*************************************************************************
		***** Entree: (rien)												*****
		***** Necessite: (rien)												*****
		***** Sortie: (rien)												*****
		***** Entraine : le graphe est affiche sans orientation				*****
		************************************************************************/
		void GEGAfficherGrapheNonOriente();

		/************************************************************************************************
		***** GEGAFFICHERSOLUTIONCOLORATION : affiche le graphe avec une coloration particuliere	*****
		*************************************************************************************************
		***** Entree: (rien)																		*****
		***** Necessite: (rien)																		*****
		***** Sortie: (rien)																		*****
		***** Entraine : le graphe est affiche avec les couleurs associees a chaque sommet			*****
		************************************************************************************************/
		void GEGAfficherSolutionColoration();

		/******************************************************
		***** GEGINVERSERGRAPHE : inverse le graphe		  *****
		*******************************************************
		***** Entree: (rien)							  *****
		***** Necessite: (rien)							  *****
		***** Sortie: (rien)							  *****
		***** Entraine : les arcs du graphe sont inverses *****
		******************************************************/
		CGraphe & GEGInverserGraphe();

		/****************************************************************************************************************************
		***** GEGCHERCHERINDICESOURCEARCSARRIVANTS : cherche l'indice de liste de tous les sommets de depart des arcs arrivants	*****
		*****************************************************************************************************************************
		***** Entree: CSommet & SOMParam																						*****
		***** Necessite: (rien)																									*****
		***** Sortie: une liste contenant les numeros de liste de chaque sommet source											*****
		***** Entraine : renvoie cette liste																					*****
		****************************************************************************************************************************/
		unsigned int * GEGChercherIndiceSourceArcsArrivants(CSommet & SOMParam);

		/***************************************************************************************************
		***** GEGRECHERCHERINDICESOMMET : lit le 1er indice de la liste ayant pour sommet "uiNumero"   *****
		****************************************************************************************************
		***** Entree: unsigned int uiNumero															   *****
		***** Necessite: (rien)																		   *****
		***** Sortie: un indice de boucle															   *****
		***** Entraine : renvoie le 1er indice de la liste ayant pour sommet "uiNumero"				   *****
		*****		  OU (ce sommet n'est pas dans la liste) leve une exception						   *****
		***************************************************************************************************/
		unsigned int GEGRechercherIndiceSommet(unsigned int uiNumero);

		/***************************************************************************************************
		***** OPERATOR= : copie un CGraphe membre a membre											   *****
		****************************************************************************************************
		***** Entree: CGraphe & GRAParam															   *****
		***** Necessite: (rien)																		   *****
		***** Sortie: (rien)																		   *****
		***** Entraine : une copie de CGraphe est creee												   *****
		***************************************************************************************************/
		void operator=(CGraphe & GRAParam);

	

};

#include "CGraphe.ipp"
#include "CGestionGraphe.ipp"

#endif 

