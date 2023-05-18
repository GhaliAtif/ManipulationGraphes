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
	pSOMGRAListeSommets = static_cast<CSommet **> (realloc(pSOMGRAListeSommets, (uiGRANombreSommets + 1) * sizeof(CSommet *)));
	uiGRANombreSommets += 1;

	/* On ajoute un element alors que la liste est vide */
	if (uiGRANombreSommets - 1 == 0)
	{
		pSOMGRAListeSommets[0] = &SOMParam;
	}

	/* Le sommet existe deja */
	else if (GEGRechercherIndiceSommet(SOMParam.SOMLireNumero()) != -1)
	{
		CException EXCErreur(EXC_SOMMET_EXISTANT, "Le sommet existe deja : impossible d'ajouter ce sommet.");
		throw(EXCErreur);
	}

	/* On ajoute le sommet */
	else
	{
		pSOMGRAListeSommets[uiGRANombreSommets - 1] = &SOMParam;
	}
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
	if (GEGRechercherIndiceSommet(uiNumero) != -1)
	{
		CException EXCErreur(EXC_SOMMET_EXISTANT, "Le sommet existe deja : impossible de modifier.");
		throw EXCErreur;

	}

	/* le sommet n'existe pas */
	unsigned int uiIndiceSommet = GEGRechercherIndiceSommet(SOMParam.SOMLireNumero());
	if (uiIndiceSommet == -1)
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Le sommet n'existe pas : impossible de modifier.");
		throw(EXCErreur);
	}

	/* Cas normal */
	pSOMGRAListeSommets[uiIndiceSommet]->SOMModifierNumero(uiNumero);
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
	if (uiIndiceSommet == -1)
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Le sommet n'existe pas : impossible de modifier.");
		throw(EXCErreur);
	}

	/* Cas normal : on decale tous les elements a droite de celui a supprimer a gauche  */
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

	/* Un des 2 sommets n'existe pas */
	if ((uiIndiceSommetDepart == -1) || (uiIndiceSommetArrivee == -1))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible d'ajouter cet arc.");
		throw(EXCErreur);
	}

	/* Cas ou l'arc a ajouter n'existe pas encore */
	cout << "Il y a " << uiGRANombreSommets << " sommets dans le graphe." << endl;
	cout << "Or uiIndiceSommetDepart vaut " << uiIndiceSommetDepart << " d'ou :" << endl;

	cout << "Le numero du sommet pSOMGRAListeSommets[uiIndiceSommetDepart] est " << pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMLireNumero() << ", donc ce n'est pas ca le pb !" << endl;
	cout << "ARCParam.ARCLireNumeroDestination() vaut " << ARCParam.ARCLireNumeroDestination() << ", donc ca n'est ps le pb !" << endl;

	cout << "LE nombre d'arcs partants est " << pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMLireNombreArcsPartants() << ", donc ca n'est pas le pb!" << endl;
	cout << "LE nombre d'arcs arrivants est " << pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMLireNombreArcsArrivants() << ", donc ca n'est pas le pb!" << endl;

	cout << "test: faisons pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()). On obtient alors : " << pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()) << endl;

	if (pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()) == -1)
	{
		cout << "On a passe le if " << endl;
		// Ajout d'un arc partant pour le sommet "uiNumeroSommetDepart"
		pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMAjouterArcPartant(ARCParam);

		// Ajout d'un arc arrivant pour le sommet "uiNumeroSommetArrivee"
		pSOMGRAListeSommets[uiIndiceSommetArrivee]->SOMAjouterArcArrivant();
	}
	else
	{
		CException EXCErreur(EXC_ARC_EXISTANT, "L'arc existe deja : impossible de l'ajouter.");
		throw(EXCErreur);
	}
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
	/* un des 2 sommets n'existe pas */
	unsigned int uiIndiceDepart = GEGRechercherIndiceSommet(uiDepart);
	unsigned int uiIndiceArrivee = GEGRechercherIndiceSommet(uiArrivee);
	if ((uiIndiceDepart == -1) || (uiIndiceArrivee == -1))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible de modifier.");
		throw(EXCErreur);
	}

	try
	{
		/* on supprime l'ancien arc... */
		GRASupprimerArc(GEGChercherSourceArcArrivant(ARCParam), ARCParam);

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
	if ((uiIndiceSommetDepart == -1) || (uiIndiceSommetArrivee == -1))
	{
		CException EXCErreur(EXC_SOMMET_INEXISTANT, "Un des 2 sommets n'existe pas : impossible d'ajouter cet arc.");
		throw(EXCErreur);
	}

	/* l'arc a supprimer n'existe pas */
	if ((pSOMGRAListeSommets[uiIndiceSommetDepart]->GEARechercherIndiceArcPartant(ARCParam.ARCLireNumeroDestination()) == -1) && (pSOMGRAListeSommets[uiIndiceSommetArrivee]->GEARechercherIndiceArcArrivant() == -1))
	{
		CException EXCErreur(EXC_ARC_INEXISTANT, "L'arc n'existe pas : impossible de le supprimer.");
		throw(EXCErreur);
	}

	/* Suppression de l'arc */
	pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMSupprimerArcPartant(ARCParam);
	pSOMGRAListeSommets[uiIndiceSommetArrivee]->SOMSupprimerArcArrivant();



}
