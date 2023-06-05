#ifndef CSOMMET_H
#define CSOMMET_H

#include "CArc.h"
#include "CGestionCouleurSommet.h"

class CSommet
{
	private:
		unsigned int uiSOMNumero;
		unsigned int uiSOMNombreArcsArrivants;
		unsigned int uiSOMNombreArcsPartants;
		bool bSOMUtiliseOperateurNew;
		CGestionCouleurSommet GCSSOMGestionCouleur;
		CArc ** pARCSOMListeArcsArrivants;
		CArc ** pARCSOMListeArcsPartants;

	public:
		/*****************************************************************
		***** CSOMMET : Constructeur par defaut de la classe CSommet *****
		******************************************************************
		***** Entree: (rien)										 *****
		***** Necessite: (rien)										 *****
		***** Sortie: (rien)										 *****
		***** Entraine : les attributs sont initialises				 *****
		*****************************************************************/
		CSommet();

		/*****************************************************************
		***** CSOMMET : Constructeur de recopie de la classe CSommet *****
		******************************************************************
		***** Entree: CSommet & SOMParam							 *****
		***** Necessite: (rien)										 *****
		***** Sortie: (rien)										 *****
		***** Entraine : une copie de SOMParam est creee			 *****
		*****************************************************************/
		CSommet(CSommet & SOMParam);

		/********************************************************************
		***** CSOMMET : Constructeur de confort de la classe CSommet	*****
		*********************************************************************
		***** Entree: unsigned int uiNumeroSommet						*****
		***** Necessite: (rien)											*****
		***** Sortie: (rien)											*****
		***** Entraine : cree un sommet de numero "uiNumero"			*****
		********************************************************************/
		CSommet(unsigned int uiNumeroSommet);

		/******************************************************
		***** ~CSOMMET : Destructeur de la classe CSommet *****
		*******************************************************
		***** Entree: (rien)							  *****
		***** Necessite: (rien)							  *****
		***** Sortie: (rien)							  *****
		***** Entraine : L'objet est desinitialise		  *****
		******************************************************/
		~CSommet();

		/************************************************************
		***** SOMLIRENUMERO : lit le numero du sommet			*****
		*************************************************************
		***** Entree: (rien)									*****
		***** Necessite: (rien)									*****
		***** Sortie: unsigned int uiSOMNumero					*****
		***** Entraine : renvoie la valeur de uiSOMNumero		*****
		************************************************************/
		unsigned int SOMLireNumero()
		{
			return uiSOMNumero;
		}

		/********************************************************************************
		***** SOMLIRENOMBREARCSARRIVANTS : lit le nombre d'arcs arrivants du sommet	*****
		*********************************************************************************
		***** Entree: (rien)														*****
		***** Necessite: (rien)														*****
		***** Sortie: unsigned int uiSOMNombreArcsArrivants							*****
		***** Entraine : renvoie la valeur de uiSOMNombreArcsArrivants				*****
		********************************************************************************/
		unsigned int SOMLireNombreArcsArrivants()
		{
			return uiSOMNombreArcsArrivants;
		}

		/********************************************************************************
		***** SOMLIRENOMBREARCSPARTANTS : lit le nombre d'arcs partants du sommet	*****
		*********************************************************************************
		***** Entree: (rien)														*****
		***** Necessite: (rien)														*****
		***** Sortie: unsigned int uiSOMNombreArcsPartants							*****
		***** Entraine : renvoie la valeur de uiSOMNombreArcsPartants				*****
		********************************************************************************/
		unsigned int SOMLireNombreArcsPartants()
		{
			return uiSOMNombreArcsPartants;
		}

		/****************************************************************************************
		***** SOMLIRELISTEARCSARRIVANTS : lit la liste d'arcs arrivants du sommet			*****
		*****************************************************************************************
		***** Entree: unsigned int uiIndice													*****
		***** Necessite: (rien)																*****
		***** Sortie: pARCSOMListeArcsArrivants[iIndice]									*****
		***** Entraine : renvoie l'arc a la position "iIndice" de pARCSOMListeArcsArrivants *****
		****************************************************************************************/
		CArc* SOMLireListeArcsArrivants(unsigned int uiIndice)
		{
			return pARCSOMListeArcsArrivants[uiIndice];
		}

		/****************************************************************************************
		***** SOMLIRELISTEARCSPARTANTS : lit la liste d'arcs partants du sommet				*****
		*****************************************************************************************
		***** Entree: unsigned int uiIndice												    *****
		***** Necessite: (rien)															    *****
		***** Sortie: pARCSOMListeArcsPartants											    *****
		***** Entraine : renvoie l'arc a la position "iIndice" de pARCSOMListeArcsPartants  *****
		****************************************************************************************/
		CArc* SOMLireListeArcsPartants(unsigned int uiIndice)
		{
			return pARCSOMListeArcsPartants[uiIndice];
		}

		/****************************************************************************************
		***** SOMLIREGESTIONCOULEUR : lit l'attribut de type CGestionCouleurSommet			*****
		*****************************************************************************************
		***** Entree: (rien)																*****
		***** Necessite: (rien)															    *****
		***** Sortie: CGestionCouleurSommet GCSSOMGestionCouleur						    *****
		***** Entraine : renvoie GCSSOMGestionCouleur									    *****
		****************************************************************************************/
		CGestionCouleurSommet SOMLireGestionCouleur()
		{
			return GCSSOMGestionCouleur;
		}

		/************************************************************************************
		***** SOMAJOUTERARCARRIVANT : ajoute un arc arrivant							*****
		*************************************************************************************
		***** Entree: CArc & ARCParam													*****
		***** Necessite: (rien)															*****
		***** Sortie: (rien)															*****
		***** Entraine : ajoute un arc a pARCSOMListeArcsArrivants						*****
		*****         OU (liste vide) uiPosition = 0									*****
		*****         OU (uiPosition > uiSOMNombreArcsArrivants + 1) leve une exception *****
		************************************************************************************/
		void SOMAjouterArcArrivant(CArc & ARCParam);

		/****************************************************************************************************
		***** SOMAJOUTERARCPARTANT : ajoute un arc partant												*****
		*****************************************************************************************************
		***** Entree: CArc & ARCParam																	*****
		***** Necessite: (rien)																			*****
		***** Sortie: (rien)																			*****
		***** Entraine : ajoute ARCParam a pARCSOMListeArcsPartants										*****
		*****         OU (cet arc existe deja) leve une exception										*****
		****************************************************************************************************/
		void SOMAjouterArcPartant(CArc & ARCParam);


		/************************************************************
		***** SOMMODIFIERNUMERO : modifie le numero du sommet	*****
		*************************************************************
		***** Entree: unsigned int uiNumero						*****
		***** Necessite: (rien)									*****
		***** Sortie: (rien)									*****
		***** Entraine : (rien)									*****
		************************************************************/
		void SOMModifierNumero(unsigned int uiNumero)
		{
			uiSOMNumero = uiNumero;
		}

		/********************************************************************************************************
		***** SOMMODIFIERARCPARTANT : modifie un arc partant												*****
		*********************************************************************************************************
		***** Entree: unsigned int uiNumero, CArc & ARCParam												*****
		***** Necessite: (rien)																				*****
		***** Sortie: (rien)																				*****
		***** Entraine : modifie la destination de ARCParam avec "uiNumero"									*****
		*****         OU (liste vide) leve une exception													*****
		*****         OU (uiPosition >= uiSOMNombreArcsPartants) leve une exception						    *****
		*****         OU (arc modifie a meme destination qu'un arc existant) leve une exception				*****
		********************************************************************************************************/
		void SOMModifierArcPartant(unsigned int uiNumero, CArc & ARCParam);

		/************************************************************************************
		***** SOMSUPPRIMERARCARRIVANT : supprime un arc arrivant						*****
		*************************************************************************************
		***** Entree: CArc & ARCParam													*****
		***** Necessite: (rien)															*****
		***** Sortie: (rien)															*****
		***** Entraine : supprime le 1er arc de pARCSOMListeArcsArrivants				*****
		*****         OU (liste vide) leve une exception								*****
		*****         OU (ARCParam n'est pas dans la liste) leve une exception			*****
		************************************************************************************/
		void SOMSupprimerArcArrivant(CArc & ARCParam);

		/************************************************************************************
		***** SOMSUPPRIMERARCPARTANT : supprime un arc partant							*****
		*************************************************************************************
		***** Entree: CArc & ARCParam													*****
		***** Necessite: (rien)															*****
		***** Sortie: (rien)															*****
		***** Entraine : supprimer un arc a pARCSOMListeArcsPartants					*****
		*****         OU (liste vide) leve une exception								*****
		*****         OU (ARCParam n'est pas dans la liste) leve une exception			*****
		************************************************************************************/
		void SOMSupprimerArcPartant(CArc & ARCParam);



		/* Dans le CGestionArc.h */

		/************************************************************************************************************
		***** GEARECHERCHERINDICEARCARRIVANT : lit le 1er indice de la liste avec un arc pointant sur le sommet *****
		*************************************************************************************************************
		***** Entree: unsigned int uiNumeroDestination															*****
		***** Necessite: (rien)																					*****
		***** Sortie: indice de boucle																			*****
		***** Entraine : renvoie le 1er indice de la liste avec un arc pointant sur le sommet					*****	
		*****		  OU (cet arc n'est pas dans la liste) leve une exception									*****
		************************************************************************************************************/
		unsigned int GEARechercherIndiceArcArrivant(unsigned int uiNumeroDestination);

		/***********************************************************************************************************************
		***** GEARECHERCHERINDICEARCPARTANT : lit le 1er indice de la liste avec un arc pointant sur "uiNumeroDestination" *****
		************************************************************************************************************************
		***** Entree: unsigned int uiNumeroDestination																	   *****
		***** Necessite: (rien)																							   *****
		***** Sortie: indice de boucle																					   *****
		***** Entraine : renvoie le 1er indice de la liste avec un arc pointant sur "uiNumeroDestination"				   *****
		*****		  OU (cet arc n'est pas dans la liste) leve une exception											   *****
		***********************************************************************************************************************/
		unsigned int GEARechercherIndiceArcPartant(unsigned int uiNumeroDestination);

		/****************************************************************************************
		***** GEAINVERSERARCSARRIVANTSPARTANTS : inverse tous les arcs du sommet			*****
		*****************************************************************************************
		***** Entree: (rien)																*****
		***** Necessite: (rien)															    *****
		***** Sortie: CSommet &																*****
		***** Entraine : tous les arcs partants deviennent des arcs arrivants et vice-versa *****
		****************************************************************************************/
		CSommet & GEAInverserArcsArrivantsPartants();

};

#include "CSommet.ipp"
#include "CGestionArc.ipp"

#endif 
