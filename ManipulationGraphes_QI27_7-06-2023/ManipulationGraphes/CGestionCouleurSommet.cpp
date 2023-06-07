#include "CGestionCouleurSommet.h"

/************************************************************************************************
***** CGESTIONCOULEURSOMMET : Constructeur par defaut de la classe CGestionCouleurSommet	*****
*************************************************************************************************
***** Entree: (rien)																		*****
***** Necessite: (rien)																		*****
***** Sortie: (rien)																		*****
***** Entraine : initialise la couleur de l'objet a 0 (= pas de couleur)					*****
************************************************************************************************/
CGestionCouleurSommet::CGestionCouleurSommet()
{
	uiGCSNumeroCouleur = 0;
}

/************************************************************************************************
***** CGESTIONCOULEURSOMMET : Constructeur de confort de la classe CGestionCouleurSommet	*****
*************************************************************************************************
***** Entree: unsigned int uiNumeroCouleur													*****
***** Necessite: uiNumeroCouleur > 0														*****
***** Sortie: (rien)																		*****
***** Entraine : initialise la couleur de l'objet a "uiNumeroCouleur"						*****
************************************************************************************************/
CGestionCouleurSommet::CGestionCouleurSommet(unsigned int uiNumeroCouleur)
{
	uiGCSNumeroCouleur = uiNumeroCouleur;
}

/****************************************************************************************
***** GCSPOSSEDERCOULEUR : regarde si le sommet possede la couleur en parametre		*****
*****************************************************************************************
***** Entree: unsigned int uiNumeroCouleur											*****
***** Necessite: (rien)																*****
***** Sortie: un booleen															*****
***** Entraine : retourne vrai														*****
*****			 OU (uiGCSNumeroCouleur != uiNumeroCouleur) retourne faux			*****
****************************************************************************************/
bool CGestionCouleurSommet::GCSPossederCouleur(unsigned int uiNumeroCouleur)
{
	/* Si le sommet possede la couleur 'uiNumeroCouleur' alors on renvoie vrai */
	if (uiGCSNumeroCouleur == uiNumeroCouleur)
	{
		return true;
	}
	else
	{
		return false;
	}
}

