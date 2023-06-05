#ifndef CGESTIONCOULEURSOMMET_H
#define CGESTIONCOULEURSOMMET_H

class CGestionCouleurSommet
{
	private:
		unsigned int uiGCSNumeroCouleur;

	public:
		/************************************************************************************************
		***** CGESTIONCOULEURSOMMET : Constructeur par defaut de la classe CGestionCouleurSommet	*****
		*************************************************************************************************
		***** Entree: (rien)																		*****
		***** Necessite: (rien)																		*****
		***** Sortie: (rien)																		*****
		***** Entraine : initialise la couleur de l'objet a 0 (= pas de couleur)					*****
		************************************************************************************************/
		CGestionCouleurSommet();

		/************************************************************************************************
		***** CGESTIONCOULEURSOMMET : Constructeur de confort de la classe CGestionCouleurSommet	*****
		*************************************************************************************************
		***** Entree: unsigned int uiNumeroCouleur													*****
		***** Necessite: uiNumeroCouleur > 0														*****
		***** Sortie: (rien)																		*****
		***** Entraine : initialise la couleur de l'objet a "uiNumeroCouleur"						*****
		************************************************************************************************/
		CGestionCouleurSommet(unsigned int uiNumeroCouleur);

		/******************************************************************************
		***** GCSLIRENUMEROCOULEUR : lit le numero de couleur du sommet			  *****
		*******************************************************************************
		***** Entree: (rien)													  *****
		***** Necessite: (rien)													  *****
		***** Sortie: unsigned int uiGCSNumeroCouleur							  *****
		***** Entraine : retourne la valeur de uiGCSNumeroCouleur			      *****
		******************************************************************************/
		unsigned int GCSLireNumeroCouleur()
		{
			return uiGCSNumeroCouleur;
		}

		/******************************************************************************
		***** GCSMODIFIERNUMEROCOULEUR : modifie le numero de couleur du sommet   *****
		*******************************************************************************
		***** Entree: unsigned int uiNumeroCouleur								  *****
		***** Necessite: (rien)													  *****
		***** Sortie: (rien)													  *****
		***** Entraine : modifie la valeur de uiGCSNumeroCouleur			      *****
		******************************************************************************/
		void GCSModifierNumeroCouleur(unsigned int uiNumeroCouleur)
		{
			uiGCSNumeroCouleur = uiNumeroCouleur;
		}

		bool GCSPossederCouleur();


		

};




#endif

