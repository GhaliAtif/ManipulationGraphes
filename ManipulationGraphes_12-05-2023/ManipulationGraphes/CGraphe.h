#ifndef CGRAPHE_H
#define CGRAPHE_H

#include "CSommet.h"

class CGraphe
{
	private:
		unsigned int uiGRANombreSommets;
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

		/************************************************************************************************************************************************
		***** GRAMODIFIERARC : modifie un arc du graphe																								*****
		*************************************************************************************************************************************************
		***** Entree: unsigned int uiDepart, unsigned int uiArrivee, CArc & ARCParam															    *****
		***** Necessite: (rien)																														*****
		***** Sortie: (rien)																														*****
		***** Entraine : ARCParam a pour destination "uiArrivee" et pour source uiDepart															*****
		*****		  OU (un des sommets n'existe pas) leve une exception																			*****
		*****		  OU (l'arc n'existe pas) leve une exception																					*****
		************************************************************************************************************************************************/
		void GRAModifierArc(unsigned int uiDepart, unsigned int uiArrivee, CArc & ARCParam);

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

		/******************************************************
		***** GEGINVERSERGRAPHE : inverse le graphe		  *****
		*******************************************************
		***** Entree: (rien)							  *****
		***** Necessite: (rien)							  *****
		***** Sortie: (rien)							  *****
		***** Entraine : les arcs du graphe sont inverses *****
		******************************************************/
		void GEGInverserGraphe();

		/***********************************************************************************
		***** GEGCHERCHERSOURCEARCARRIVANT : lit le sommet de depart d'un arc arrivant *****
		************************************************************************************
		***** Entree: (rien)														   *****
		***** Necessite: (rien)														   *****
		***** Sortie: numero de sommet												   *****
		***** Entraine : renvoie le numero du sommet de depart de l'arc				   *****
		***********************************************************************************/
		unsigned int GEGChercherSourceArcArrivant(CArc & ARCParam);

		/***************************************************************************************************
		***** GEGRECHERCHERINDICESOMMET : lit le 1er indice de la liste ayant pour sommet "uiPosition" *****
		****************************************************************************************************
		***** Entree: unsigned int uiNumero															   *****
		***** Necessite: (rien)																		   *****
		***** Sortie: un indice de boucle															   *****
		***** Entraine : renvoie le 1er indice de la liste ayant pour sommet "uiPosition"			   *****
		*****		  OU (ce sommet n'est pas dans la liste) leve une exception						   *****
		***************************************************************************************************/
		unsigned int GEGRechercherIndiceSommet(unsigned int uiNumero);
};

#include "CGraphe.ipp"
#include "CGestionGraphe.ipp"

#endif 

