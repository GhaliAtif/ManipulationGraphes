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

bool CGestionCouleurSommet::GCSPossederCouleur()
{
	/* Possede une couleur */
	if (uiGCSNumeroCouleur != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

