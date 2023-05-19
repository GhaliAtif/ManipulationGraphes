/* Methodes inline de CGraphe */

#include <cstdlib>
#include <iostream>
using namespace std;

/******************************************************************************
***** GRAAJOUTERSOMMET : ajoute un sommet								  *****
*******************************************************************************
***** Entree: CSommet & SOMParam										  *****
***** Necessite: (rien)													  *****
***** Sortie: (rien)													  *****
***** Entraine: ajoute SOMParam a pSOMGRAListeSommets					  *****
*****		 OU (le sommet existe deja) leve une exception				  *****
******************************************************************************/
inline void CGraphe::GRAAjouterSommet(CSommet & SOMParam)
{
	/* Le sommet existe deja */
	if (GEGRechercherIndiceSommet(SOMParam.SOMLireNumero()) != EXC_SOMMET_INEXISTANT)
	{
		CException EXCErreur(EXC_SOMMET_EXISTANT, "Le sommet existe deja : impossible d'ajouter ce sommet.");
		throw(EXCErreur);
	}

	CSommet** NouveauxSommets = new CSommet*[uiGRANombreSommets + 1];

	/* On copie les sommets existant dans NouveauxSommets */
	for (unsigned int i = 0; i < uiGRANombreSommets; i++)
	{
		NouveauxSommets[i] = pSOMGRAListeSommets[i];
	}

	/* On ajoute SOMParam a la liste */
	NouveauxSommets[uiGRANombreSommets] = &SOMParam;

	/* On desalloue la memoire pour l'ancienne liste de sommets */
	delete[] pSOMGRAListeSommets;

	/* on fait pointer pSOMGRAListeSommets sur la nouvelle liste */
	pSOMGRAListeSommets = NouveauxSommets;

	uiGRANombreSommets += 1;

	/* On ajoute le sommet */
	pSOMGRAListeSommets[uiGRANombreSommets - 1] = &SOMParam;
}

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
inline void CGraphe::GRAModifierSommet(unsigned int uiNumero, CSommet & SOMParam)
{
	/* On modifie alors que la liste est vide */
	if (uiGRANombreSommets == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de modifier.");
		throw EXCErreur;
	}

	/* le sommet existe deja */
	if (GEGRechercherIndiceSommet(uiNumero) != EXC_SOMMET_INEXISTANT)
	{
		CException EXCErreur(EXC_SOMMET_EXISTANT, "Le sommet existe deja : impossible de modifier.");
		throw EXCErreur;

	}

	/* le sommet en parametre n'existe pas */
	unsigned int uiIndiceSommet = GEGRechercherIndiceSommet(SOMParam.SOMLireNumero());

	if (uiIndiceSommet == EXC_SOMMET_INEXISTANT)
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Le sommet en parametre n'existe pas : impossible de modifier.");
		throw EXCErreur;
	}

	/* Cas normal : on change le numero de SOMParam et des potentiels arcs qui pointaient sur SOMParam en "uiNumero" */
	unsigned int uiSourceArcArrivant;
	unsigned int uiIndiceSource;
	unsigned int uiIndiceArcPartantPointantSOMParam;

	/* SOMParam possede des arcs arrivants */
	for (unsigned int uiArcArrivant = 0; uiArcArrivant < SOMParam.SOMLireNombreArcsArrivants(); uiArcArrivant++)
	{
		/* On cherche le sommet source d'un des arcs arrivants sur SOMParam */
		uiSourceArcArrivant = GEGChercherSourceArcArrivant(SOMParam);

		/* On cherche l'indice du sommet source, de cet arc arrivant, dans la liste des sommets du graphe */
		uiIndiceSource = GEGRechercherIndiceSommet(uiSourceArcArrivant);

		/* Dans ce sommet source, on cherche l'indice de l'arc partant pointant sur SOMParam */
		uiIndiceArcPartantPointantSOMParam = pSOMGRAListeSommets[uiIndiceSource]->GEARechercherIndiceArcPartant(SOMParam.SOMLireNumero());

		/* Dans ce sommet source, on change la destination de cet arc partant par "uiNumero" */
		pSOMGRAListeSommets[uiIndiceSource]->SOMLireListeArcsPartants()[uiIndiceArcPartantPointantSOMParam]->ARCModifierNumeroDestination(uiNumero);
	}

	/* On change le numero de SOMParam en "uiNumero" */
	SOMParam.SOMModifierNumero(uiNumero);
}

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
inline void CGraphe::GRASupprimerSommet(CSommet & SOMParam)
{
	/* Cas de la liste vide : rien a supprimer */
	if (uiGRANombreSommets == 0)
	{
		CException EXCErreur(EXC_VIOLATION_ACCES, "La liste d'arcs arrivants est deja vide : impossible de supprimer.");
		throw EXCErreur;
	}

	/* le sommet n'existe pas */
	unsigned int uiIndiceSommet = GEGRechercherIndiceSommet(SOMParam.SOMLireNumero());
	if (uiIndiceSommet == EXC_SOMMET_INEXISTANT)
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Le sommet n'existe pas : impossible de modifier.");
		throw(EXCErreur);
	}

	/* On desalloue la memoire du sommet supprime */
	delete pSOMGRAListeSommets[uiIndiceSommet];

	/* Cas normal : on decale tous les elements, a droite de celui a supprimer, a gauche  */
	for (unsigned int uiBoucle = uiIndiceSommet; uiBoucle < uiGRANombreSommets - 1; uiBoucle++)
	{
		pSOMGRAListeSommets[uiBoucle] = pSOMGRAListeSommets[uiBoucle + 1];
	}
	uiGRANombreSommets -= 1;

	pSOMGRAListeSommets = static_cast<CSommet **> (realloc(pSOMGRAListeSommets, uiGRANombreSommets * sizeof(CSommet *)));
}

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
inline void CGraphe::GRAAjouterArc(unsigned int uiDepart, CArc & ARCParam)
{
	// Recherche du sommet de depart
	unsigned int uiIndiceSommetDepart = GEGRechercherIndiceSommet(uiDepart);

	// Recherche du sommet d'arrivee
	unsigned int uiIndiceSommetArrivee = GEGRechercherIndiceSommet(ARCParam.ARCLireNumeroDestination());

	/* Recherche de l'arc partant */
	unsigned int uiIndiceArcPartant = 0;

	/* Un des 2 sommets n'existe pas */
	if ((uiIndiceSommetDepart == EXC_SOMMET_INEXISTANT) || (uiIndiceSommetArrivee == EXC_SOMMET_INEXISTANT))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible d'ajouter cet arc.");
		throw(EXCErreur);
	}

	/* L'arc existe deja */
	uiIndiceArcPartant = pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination());
	if (uiIndiceArcPartant != EXC_ARC_INEXISTANT)
	{
		CException EXCErreur(EXC_ARC_EXISTANT, "L'arc existe deja : impossible de l'ajouter.");
		throw(EXCErreur);
	}

	/* Cas normal : l'arc a ajouter n'existe pas encore */

	// Ajout d'un arc partant pour le sommet "uiNumeroSommetDepart"
	pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMAjouterArcPartant(ARCParam);

	// Ajout d'un arc arrivant pour le sommet "uiNumeroSommetArrivee"
	pSOMGRAListeSommets[uiIndiceSommetArrivee]->SOMAjouterArcArrivant();

}

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
inline void CGraphe::GRAModifierArc(unsigned int uiDepart, unsigned int uiArrivee, CArc & ARCParam)
{
	/* Un des 2 sommets n'existe pas */
	unsigned int uiIndiceDepart = GEGRechercherIndiceSommet(uiDepart);
	unsigned int uiIndiceArrivee = GEGRechercherIndiceSommet(uiArrivee);
	if ((uiIndiceDepart == EXC_SOMMET_INEXISTANT) || (uiIndiceArrivee == EXC_SOMMET_INEXISTANT))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible de modifier.");
		throw(EXCErreur);
	}

	try
	{
		/* on supprime l'ancien arc... */
		GRASupprimerArc(GEGChercherSourceArcArrivant(*pSOMGRAListeSommets[ARCParam.ARCLireNumeroDestination()]), ARCParam);

		/*... et on ajoute l'arc modifie */
		ARCParam.ARCModifierNumeroDestination(uiArrivee);
		GRAAjouterArc(uiDepart, ARCParam);
	}
	catch (CException EXCErreur)
	{
		EXCErreur.EXCLireValeur();
		EXCErreur.AFEAfficherErreur();
	}
}

/************************************************************************************************************************************************
***** GRASUPPRIMERARC : supprime un arc du graphe																							*****
*************************************************************************************************************************************************
***** Entree: unsigned int uiDepart, CArc & ARCParam																						*****
***** Necessite: (rien)																														*****
***** Sortie: (rien)																														*****
***** Entraine : l'arc "ARCParam" est supprime du graphe																					*****
*****		  OU (un des sommets n'existe pas) leve une exception																			*****
*****		  OU (l'arc n'existe pas) leve une exception																					*****
************************************************************************************************************************************************/
inline void CGraphe::GRASupprimerArc(unsigned int uiDepart, CArc & ARCParam)
{
	// Recherche du sommet de depart
	unsigned int uiIndiceSommetDepart = GEGRechercherIndiceSommet(uiDepart);
																
	// Recherche du sommet d'arrivee
	unsigned int uiIndiceSommetArrivee = GEGRechercherIndiceSommet(ARCParam.ARCLireNumeroDestination());

	/* Un des 2 sommets n'existe pas */
	if ((uiIndiceSommetDepart == EXC_SOMMET_INEXISTANT) || (uiIndiceSommetArrivee == EXC_SOMMET_INEXISTANT))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible d'ajouter cet arc.");
		throw(EXCErreur);
	}

	/* L'arc a supprimer n'existe pas */
	if ((pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()) == EXC_ARC_INEXISTANT) 
		&& (pSOMGRAListeSommets[uiIndiceSommetArrivee]->GEARechercherIndiceArcArrivant() == EXC_ARC_INEXISTANT))
	{
		CException EXCErreur(EXC_ARC_INEXISTANT, "L'arc n'existe pas : impossible de le supprimer.");
		throw(EXCErreur);
	}

	/* Suppression de l'arc */
	pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMSupprimerArcPartant(ARCParam);
	pSOMGRAListeSommets[uiIndiceSommetArrivee]->SOMSupprimerArcArrivant();



}
