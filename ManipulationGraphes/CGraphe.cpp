#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "CException.h"
#include "CGraphe.h"
#include "CSommet.h"






CGraphe::CGraphe()
{
	// Initialisation des attributs
	uiNombreSommets = 0;
	pSOMGRAListeSommets = nullptr;
}

CGraphe::CGraphe(CGraphe& GRAParam)
{
	// Recopie du nombre de sommet
	uiNombreSommets = GRAParam.uiNombreSommets;

	// Allocation en mémoire de la lsite de sommet
	pSOMGRAListeSommets = (CSommet**)malloc(uiNombreSommets * sizeof(CSommet*));

	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreSommets; uiBoucle++)
	{
		// Copie des sommets 
		//pSOMGRAListeSommets[uiNombreSommets] = new CSommet(*GRAParam.pSOMGRAListeSommets[uiBoucle]);
		GRAAjouterSommet(*GRAParam.pSOMGRAListeSommets[uiBoucle]);
	}
}

CGraphe::~CGraphe()
{
	if (pSOMGRAListeSommets != nullptr)
	{
		free(pSOMGRAListeSommets);
	}
}


CGraphe::CGraphe(int iNombreSommet)
{
	// Initialisation du nombre de sommet
	uiNombreSommets = iNombreSommet;

	// Allocation en mémoire de la liste de sommet
	pSOMGRAListeSommets = (CSommet**)malloc(uiNombreSommets * sizeof(CSommet*));
}

CSommet& CGraphe::GRALireSommet(int iIndice)
{
	// Vérification de l'indice en paramètre
	if (iIndice < 0 || iIndice > int(uiNombreSommets))
	{
		CException EXCErreur(EXCDimensionLigne, "La dimension des lignes ne peut pas etre negative ou nulle");
		throw(EXCErreur);
	}

	return *pSOMGRAListeSommets[iIndice];
}

int CGraphe::GRARechercheIndiceSommet(int iNumeroSommet)
{
	for (unsigned int uiIndiceBoucleSommet = 0; uiIndiceBoucleSommet < uiNombreSommets; uiIndiceBoucleSommet++)
	{
		if (GRALireSommet(uiIndiceBoucleSommet).SOMLireNumero() == iNumeroSommet)
		{
			return uiIndiceBoucleSommet;
		}
	}
	return -1;
}

void CGraphe::GRAAjouterSommet(CSommet& SOMParam)
{
	if (GRARechercheIndiceSommet(SOMParam.SOMLireNumero()) != -1)
	{
		CException EXCErreur(EXCSommetExistant, "Le sommet est deja present");
		throw(EXCErreur);
	}

	// Reallocation de la liste de sommet du graphe
	pSOMGRAListeSommets = (CSommet**)realloc(pSOMGRAListeSommets, (uiNombreSommets + 1) * sizeof(CSommet*));
	///Si l'allocation à réussi
	if (pSOMGRAListeSommets != nullptr)
	{
		// Ajout du sommet dans la liste et mise à jour du nombre de sommet du graphe
		pSOMGRAListeSommets[uiNombreSommets] = new CSommet(SOMParam);
		uiNombreSommets++;
	}
	///Sinon on lève une exception
	else
	{
		CException EXCErreur(EXCAllocationEchoué, "l'allocation a échoué");
		throw(EXCErreur);
	}
}


void CGraphe::GRAModifierSommet(int iNumeroSommet, CSommet& SOMParam)
{
	int iIndiceSommet = GRARechercheIndiceSommet(iNumeroSommet);
	if (iIndiceSommet == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	//Suppression de l'ancien sommet
	delete(pSOMGRAListeSommets[iIndiceSommet]);

	//Ajout du nouveau sommet
	pSOMGRAListeSommets[iIndiceSommet] = new CSommet(SOMParam);
}

void CGraphe::GRASupprimerSommet(int iNumeroSommet)
{
	// Si la liste est vide on lève une exception
	if (uiNombreSommets == 0)
	{
		CException EXCErreur(EXCListeVide, "La liste est vide");
		throw(EXCErreur);
	}

	//Recherche de l'indice du sommet à supprimer
	int iIndiceSommet = GRARechercheIndiceSommet(iNumeroSommet);
	if (iIndiceSommet == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	// On décale les sommets à partir du sommet à supprimer pour l'écraser
	for (unsigned int uiBoucle = iIndiceSommet; uiBoucle < uiNombreSommets - 1; uiBoucle++)
	{
		pSOMGRAListeSommets[uiBoucle] = pSOMGRAListeSommets[uiBoucle + 1];
	}

	// Si il n'y avait qu'un seul sommet on désalloue la liste
	if (uiNombreSommets - 1 == 0)
	{
		free(pSOMGRAListeSommets);
		pSOMGRAListeSommets = nullptr;
	}
	// Sinon on réalloue la liste avec la nouvelle taille
	else
	{
		pSOMGRAListeSommets = (CSommet**)realloc(pSOMGRAListeSommets, (uiNombreSommets - 1) * sizeof(CSommet*));
		// Si l'allocation à réussi on met à jour le nombre de sommet
		if (pSOMGRAListeSommets != nullptr)
		{
			uiNombreSommets--;
		}
		// Sinon on lève une exception
		else
		{
			CException EXCErreur(EXCAllocationEchoué, "l'allocation a échoué");
			throw(EXCErreur);
		}
	}
}


void CGraphe::GRAAjouterArc(int iNumeroSommetDepart, int iNumeroSommetArrive)
{
	// Recherche du sommet de départ
	int uiIndiceSommetDepart = GRARechercheIndiceSommet(iNumeroSommetDepart);
	// Recherche du sommet de l'arrive
	int uiIndiceSommetArrive = GRARechercheIndiceSommet(iNumeroSommetArrive);

	// Si le sommet de départ n'est pas dans la liste on lève une exception
	if (uiIndiceSommetDepart == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	// Si le sommet de l'arrive n'est pas dans la liste on lève une exception
	if (uiIndiceSommetArrive == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	if (pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMRechercheIndiceArcPartant(iNumeroSommetArrive) == -1)
	{
		// Ajout d'un arc partant en arrive de iNumeroSometArrive
		CArc* pARCArcPartant = new CArc(iNumeroSommetArrive);
		pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMAjouterArcPartant(pARCArcPartant);

		// Ajout d'un arc arrivant en arrive de iNumeroSommetDepart
		CArc* pARCArcArrivant = new CArc(iNumeroSommetDepart);
		pSOMGRAListeSommets[uiIndiceSommetArrive]->SOMAjouterArcArrivant(pARCArcArrivant);
	}
	else
	{
		CException EXCErreur(EXCArcExistant, "L'arc est deja present");
		throw(EXCErreur);
	}
}

void CGraphe::GRASupprimerArc(int iNumeroDepart, int iNumeroDestination)
{
	// Recherche du sommet de départ
	int uiIndiceSommetDepart = GRARechercheIndiceSommet(iNumeroDepart);
	// Recherche du sommet de destination
	int uiIndiceSommetDestination = GRARechercheIndiceSommet(iNumeroDestination);

	// Si le sommet de départ n'est pas dans la liste on lève une exception 
	if (uiIndiceSommetDepart == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	// Si le sommet de destination n'est pas dans la liste on lève une exception 
	if (uiIndiceSommetDestination == -1)
	{
		CException EXCErreur(EXCSommetIntrouvable, "Le sommet ne se trouve pas dans la liste");
		throw(EXCErreur);
	}

	// Si l'arc iNumeroDepart -> iNumeroDestination n'est pas présent on lève une exception
	if (pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMRechercheIndiceArcPartant(iNumeroDestination) == -1)
	{
		CException EXCErreur(EXCArcInExistant, "L'arc est deja present");
		throw(EXCErreur);
	}

	// Si l'arc iNumeroDestination -> iNumeroDepart n'est pas présent on lève une exception
	if (pSOMGRAListeSommets[uiIndiceSommetDestination]->SOMRechercheIndiceArcArrivant(iNumeroDepart) == -1)
	{
		CException EXCErreur(EXCArcInExistant, "L'arc est deja present");
		throw(EXCErreur);
	}

	// Suppression des arcs
	pSOMGRAListeSommets[uiIndiceSommetDepart]->SOMSupprimerArcPartant(iNumeroDestination);
	pSOMGRAListeSommets[uiIndiceSommetDestination]->SOMSupprimerArcArrivant(iNumeroDepart);
}

void CGraphe::GRAModifierArc(int iAncienDepart, int iAncienneDestination, int iNouveauDepart, int iNouvelleDestination)
{
	try
	{
		GRASupprimerArc(iAncienDepart, iAncienneDestination);
		GRAAjouterArc(iNouveauDepart, iNouvelleDestination);
	}
	catch (CException EXCErreur)
	{
		std::cout << EXCErreur.AFEAfficherErreur << std::endl;
	}
}
