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
		***** Entree: CSommet& SOMParam, unsigned int uiPosition				  *****
		***** Necessite: (rien)													  *****
		***** Sortie: ajoute un sommet a pSOMGRAListeSommets					  *****
		*****         OU (liste vide) uiPosition = 0							  *****
		*****         OU (uiPosition > uiGRANombreSommets + 1) leve une exception *****
		******************************************************************************/
		void GRAAjouterSommet(CSommet& SOMParam, unsigned int uiPosition);

		/*******************************************************************************
		***** GRAMODIFIERSOMMET : modifie un sommet du graphe					   *****
		********************************************************************************
		***** Entree: CSommet& SOMParam, unsigned int uiPosition				   *****
		***** Necessite: (rien)													   *****
		***** Sortie: (rien)													   *****
		***** Entraine : modifie un sommet de pSOMGRAListeSommets				   *****
		*****         OU (liste vide) leve une exception						   *****
		*****         OU (uiPosition > uiGRANombreSommets + 1) leve une exception  *****
		*******************************************************************************/
		void GRAModifierSommet(CSommet& SOMParam, unsigned int uiPosition);

		/************************************************************************************
		***** GRASUPPRIMERSOMMET : supprime un sommet									*****
		*************************************************************************************
		***** Entree: unsigned int uiPosition											*****
		***** Necessite: (rien)															*****
		***** Sortie: (rien)															*****
		***** Entraine : supprime un arc a pSOMGRAListeSommets							*****
		*****         OU (liste vide) leve une exception								*****
		*****         OU (uiPosition >= uiSOMNombreSommets) leve une exception		    *****
		************************************************************************************/
		void GRASupprimerSommet(unsigned int uiPosition);



		/* Methodes dans CGestionGraphe */

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
		***** Entraine : le graphe est inverse			  *****
		******************************************************/
		void GEGInverserGraphe();



};

#include "CGraphe.ipp"

#endif 

