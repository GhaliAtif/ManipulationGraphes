#include <iostream>

#include "CGraphe.h"

using namespace std;

/**************************************************************************
***** CGRAPHE : Constructeur par defaut de la classe CGraphe		  *****
***************************************************************************
***** Entree: (rien)												  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : le nombre de sommets du graphe est initialise a 0	  *****
**************************************************************************/
CGraphe::CGraphe()
{
	uiGRANombreSommets = 0;
	bGRAUtiliseOperateurNew = false;
	pSOMGRAListeSommets = nullptr;
}

/**************************************************************************
***** CGRAPHE : Constructeur de recopie de la classe CGraphe		  *****
***************************************************************************
***** Entree: CGraphe & GRAParam									  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : une copie de GRAParam est creee					  *****
**************************************************************************/
CGraphe::CGraphe(CGraphe & GRAParam)
{
	uiGRANombreSommets = GRAParam.uiGRANombreSommets;
	bGRAUtiliseOperateurNew = true;

	/* Creation d'une nouvelle liste a partir de GRAParam */
	pSOMGRAListeSommets = new CSommet*[GRAParam.uiGRANombreSommets];

	/* On copie les sommets existant dans NouveauxSommets */
	for (unsigned int i = 0; i < GRAParam.uiGRANombreSommets; i++)
	{
		pSOMGRAListeSommets[i] = new CSommet(*GRAParam.pSOMGRAListeSommets[i]);
	}

}

/**************************************************************************
***** CGRAPHE : convertit un CFichierGraphe en CGraphe				  *****
***************************************************************************
***** Entree: CFichierGraphe & FIGParam								  *****
***** Necessite: (rien)												  *****
***** Sortie: (rien)												  *****
***** Entraine : cree un graphe a partir d'un fichier texte			  *****
**************************************************************************/
CGraphe::CGraphe(CFichierGraphe & FIGParam)
{
	uiGRANombreSommets = FIGParam.FIGLireNombreSommets();
	bGRAUtiliseOperateurNew = true;

	/* On cree les sommets listes dans pUNIFIGSommets de FIGParam */
	// On alloue la liste de sommets
	pSOMGRAListeSommets = new CSommet*[FIGParam.FIGLireNombreSommets()];

	// On alloue tous les sommets que contient cette liste
	for (unsigned int uiSommet = 0; uiSommet < FIGParam.FIGLireNombreSommets(); uiSommet++)
	{
		pSOMGRAListeSommets[uiSommet] = new CSommet(FIGParam.FIGLireSommets()[uiSommet]);
	}
	



	/* On cree les arcs du graphe avec AjouterArc */
	// Si une erreur fait que les nombres d'arcs arrivants et partants ne sont pas egaux, on leve une exception
	if (FIGParam.FIGLireNombreArcsArrivants() != FIGParam.FIGLireNombreArcsPartants())
	{
		CException EXCErreur(EXC_MAUVAIS_NOMBRE_ARCS, "Les nombres d'arcs arrivants et partants ne sont pas egaux : impossible de creer le graphe correspondant.\n");
		throw EXCErreur;
	}

	// Sinon, on cree les arcs
	for (unsigned int uiArc = 0; uiArc < FIGParam.FIGLireNombreArcsArrivants(); uiArc++)
	{

		GRAAjouterArc(FIGParam.FIGLireListeSommetsDepart()[uiArc], *(new CArc(FIGParam.FIGLireListeSommetsArrivee()[uiArc])));
	}
	
}

/******************************************************
***** ~CGRAPHE : Destructeur de la classe CGraphe *****
*******************************************************
***** Entree: (rien)							  *****
***** Necessite: (rien)							  *****
***** Sortie: (rien)							  *****
***** Entraine : L'objet est desinitialise		  *****
******************************************************/
CGraphe::~CGraphe()
{
	if (bGRAUtiliseOperateurNew)
	{
		for (unsigned int i = 0; i < uiGRANombreSommets; i++)
		{
			delete pSOMGRAListeSommets[i];
		}
	}
	delete[] pSOMGRAListeSommets;
}

/***************************************************************************************************
***** OPERATOR= : copie un CGraphe membre a membre											   *****
****************************************************************************************************
***** Entree: CGraphe & GRAParam															   *****
***** Necessite: (rien)																		   *****
***** Sortie: (rien)																		   *****
***** Entraine : une copie de CGraphe est creee												   *****
***************************************************************************************************/
void CGraphe::operator=(CGraphe & GRAParam)
{
	uiGRANombreSommets = GRAParam.uiGRANombreSommets;
	bGRAUtiliseOperateurNew = true;

	/* Creation d'une nouvelle liste a partir de GRAParam */
	pSOMGRAListeSommets = new CSommet*[GRAParam.uiGRANombreSommets];

	/* On copie les sommets existant dans NouveauxSommets */
	for (unsigned int i = 0; i < GRAParam.uiGRANombreSommets; i++)
	{
		pSOMGRAListeSommets[i] = new CSommet(*GRAParam.pSOMGRAListeSommets[i]);
	}
}

/****************************************************************************************************************
***** GRAVERIFIEREXISTENCECOLORATION : regarde si une coloration particuliere est possible pour le graphe	*****
*****************************************************************************************************************
***** Entree: unsigned int uiNombreCouleurs, unsigned int uiIndiceListeSommet = 0							*****
***** Necessite: (rien)																						*****
***** Sortie: un booleen																					*****
***** Entraine : renvoie vrai																				*****
*****		  OU (une coloration n'est pas possible) renvoie faux											*****
****************************************************************************************************************/
bool CGraphe::GRAVerifierExistanceColoration(unsigned int uiNombreCouleurs, unsigned int uiIndiceListeSommet)
{
	/* Cas de base : tous les sommets sont colories */
	if (uiIndiceListeSommet >= GRALireNombreSommets()) 
	{
		return true;
	}

	CSommet& SOMSommet = *GRALireListeSommets()[uiIndiceListeSommet];

	// Si le sommet courant possede deja une couleur (donc pas 0), alors on passe au sommet suivant
	if (!SOMSommet.SOMLireGestionCouleur().GCSPossederCouleur(0)) 
	{
		return GRAVerifierExistanceColoration(uiNombreCouleurs, uiIndiceListeSommet + 1);
	}

	unsigned int* puiCouleursDisponibles = GRARenvoyerCouleursDisponibles(SOMSommet, uiNombreCouleurs);
	unsigned int uiTailleCouleursDisponibles = GRARenvoyerTailleCouleursDisponibles(SOMSommet, uiNombreCouleurs);

	/* Pas de couleurs disponibles pour colorier le sommet courant */
	if (uiTailleCouleursDisponibles == 0) 
	{
		delete[] puiCouleursDisponibles;
		return false;
	}

	for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiTailleCouleursDisponibles; uiBoucle2++) 
	{
		unsigned int uiCouleurOriginale = SOMSommet.SOMLireGestionCouleur().GCSLireNumeroCouleur();
		unsigned int uiNouvelleCouleur = puiCouleursDisponibles[uiBoucle2];

		SOMSommet.SOMLireGestionCouleur().GCSModifierNumeroCouleur(uiNouvelleCouleur);

		if (GRAVerifierExistanceColoration(uiNombreCouleurs, uiIndiceListeSommet + 1)) 
		{
			delete[] puiCouleursDisponibles;
			return true;
		}

		SOMSommet.SOMLireGestionCouleur().GCSModifierNumeroCouleur(uiCouleurOriginale);
	}

	delete[] puiCouleursDisponibles;
	return false;
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
bool CGraphe::GRAVerifierSommetsTousColories()
{
	/* Si un des sommets n'est pas colorie (ie possede le numero de couleur 0), on retourne faux */
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		if (GRALireListeSommets()[uiSommet]->SOMLireGestionCouleur().GCSPossederCouleur(0) == true)
		{
			return false;
		}
	}

	return true;
}

/************************************************************************************************************
***** GRARENVOYERCOULEURSDISPONIBLES : renvoie la liste des couleurs disponibles pour un sommet			*****
*************************************************************************************************************
***** Entree: CSommet & SOMParam, unsigned int uiNombreCouleur											*****
***** Necessite: (rien)																					*****
***** Sortie: un pointeur																				*****
***** Entraine : renvoie la liste des couleurs disponibles												*****
************************************************************************************************************/
unsigned int * CGraphe::GRARenvoyerCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur)
{
	/* Allocation tableau temporaire qui contiendra 
	toutes les couleurs numerotees de 1 a uiNombreCouleur. */
	unsigned int* puiCouleurs = new unsigned int[uiNombreCouleur]; 

	/* Allocation tableau temporaire qui sera un compteur pour "puiCouleurs". */
	unsigned int* puiCompteurCouleurs = new unsigned int[uiNombreCouleur];

	/* on affecte chaque couleur a une case du tableau */
	for (unsigned int uiNumeroCouleur = 0; uiNumeroCouleur < uiNombreCouleur; uiNumeroCouleur++) 
	{
		// la numerotation des puiCouleurs commence a 1, 0 est l'etat sans couleur
		puiCouleurs[uiNumeroCouleur] = uiNumeroCouleur + 1; 
	}


	/* on initialise chaque case de puiCompteurCouleurs a 0 */
	for (unsigned int uiCouleur = 0; uiCouleur < uiNombreCouleur; uiCouleur++) 
	{
		puiCompteurCouleurs[uiCouleur] = 0;
	}

	/* pour chaque sommet voisin de SOMParam */
	for (unsigned int uiVoisin = 0; uiVoisin < GRANombreSommetsVoisins(SOMParam); uiVoisin++) 
	{

		/* pour chaque couleur */
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiNombreCouleur; uiBoucle2++) 
		{

			/* si une couleur correspond a la couleur d'un sommet voisin */
			if (puiCouleurs[uiBoucle2] == GRALireListeSommets()[GRARenvoyerIndiceSommetsVoisins(SOMParam)[uiVoisin]]->SOMLireGestionCouleur().GCSLireNumeroCouleur()) 
			{
				puiCompteurCouleurs[uiBoucle2]++;//on incremente la case de puiCompteurCouleurs correspondante a la couleur trouve.
			}
		}
	}
	unsigned int uiTaille = 0;

	/* pour chaque case de "puiCouleurs" */
	for (unsigned int uiCouleur = 0; uiCouleur < uiNombreCouleur; uiCouleur++) 
	{
		/*si la couleur en position uiCouleur n'a pas ete trouvee dans les sommets voisins*/
		if (puiCompteurCouleurs[uiCouleur] == 0) 
		{
			uiTaille++; //la uiTaille que prendra le tableau des couleurs disponible pour un sommet incremente de 1.
		}
	}

	unsigned int* puiCouleursDispo = new unsigned int[uiTaille]; //on alloue le tableau qui contiendra les couleurs disponible pour un sommet
	unsigned int puiCompteurCouleursDispo = 0; //initialise un compteur a 0.

	/*on initialise les cases de puiCouleursDispo a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiTaille; uiBoucle++) 
	{
		puiCouleursDispo[uiBoucle] = 0;
	}

	

	/* pour chaque couleur */
	for (unsigned int uiCouleur = 0; uiCouleur < uiNombreCouleur; uiCouleur++) 
	{

		/* si la couleur n'est pas presente chez les voisins de SOMParam */
		if (puiCompteurCouleurs[uiCouleur] == 0 && puiCompteurCouleursDispo < uiTaille) 
		{
			puiCouleursDispo[puiCompteurCouleursDispo] = uiCouleur + 1; //on ajoute cette couleur a couleurDispo 
			puiCompteurCouleursDispo++;
		}
	}

	delete[] puiCompteurCouleurs;
	delete[] puiCouleurs;
	return puiCouleursDispo;
}

/********************************************************************************************************
***** GRARENVOYERINDICESOMMETSVOISINS : renvoie l'indice de liste des sommets voisins d'un sommet	*****
*********************************************************************************************************
***** Entree: CSommet & SOMParam																	*****
***** Necessite: (rien)																				*****
***** Sortie: un pointeur																			*****
***** Entraine : la liste des indices de liste des voisins											*****
********************************************************************************************************/
unsigned int * CGraphe::GRARenvoyerIndiceSommetsVoisins(CSommet & SOMParam)
{
	unsigned int uiNumero = 0;

	/* allocation d'un tableau qui contiendra la position des sommets, 
	voisins de SOMParam, dans pSOMGRAListeSommets. */
	unsigned int* puiNumeroVoisins = new unsigned int[GRANombreSommetsVoisins(SOMParam)]; 

	/* On parcourt tous les arcs partants de SOMParam pour connaitre ses voisins */
	for (unsigned int uiArcPartant = 0; uiArcPartant < SOMParam.SOMLireNombreArcsPartants(); uiArcPartant++)
	{
		/* A 1 arc partant donne, on parcourt la liste des sommets pour retrouver l'indice de liste de ce sommet pointe par cet arc */
		for (unsigned int uiSommet = 0; uiSommet < GRALireNombreSommets(); uiSommet++)
		{
			if (SOMParam.SOMLireListeArcsPartants(uiArcPartant)->ARCLireNumeroDestination() == GRALireListeSommets()[uiSommet]->SOMLireNumero())
			{
				puiNumeroVoisins[uiArcPartant] = uiSommet;
			}
		}
	}

	/* Apres les voisins connus par les arcs partants de SOMParam, 
	on rajoute les voisins connus par les arcs arrivants de SOMParam grace a GEGChercherIndiceSourceArcsArrivants */
	unsigned int * puiSourcesArcsArrivants = GEGChercherIndiceSourceArcsArrivants(SOMParam);
	for (unsigned int uiArcArrivant = SOMParam.SOMLireNombreArcsPartants(); uiArcArrivant < GRANombreSommetsVoisins(SOMParam); uiArcArrivant++)
	{
		puiNumeroVoisins[uiArcArrivant] = puiSourcesArcsArrivants[uiArcArrivant - SOMParam.SOMLireNombreArcsPartants()];
	}

	return puiNumeroVoisins;
}

/************************************************************************************************************
***** GRARENVOYERTAILLECOULEURSDISPONIBLES : renvoie le nombre de couleurs disponibles pour un sommet	*****
*************************************************************************************************************
***** Entree: CSommet & SOMParam, unsigned int uiNombreCouleur											*****
***** Necessite: (rien)																					*****
***** Sortie: un naturel																				*****
***** Entraine : renvoie le nombre de couleurs disponibles												*****
************************************************************************************************************/
unsigned int CGraphe::GRARenvoyerTailleCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur)
{
	/* Au depart, uiTailleCouleursDisponibles vaut 0 */
	unsigned int uiTailleCouleursDisponibles = 0;

	/* Allocation tableau temporaire qui sera un compteur pour "puiCouleurs". */
	unsigned int* puiCompteurCouleurs = new unsigned int[uiNombreCouleur];

	/* Allocation tableau temporaire qui contiendra
	toutes les couleurs numerotees de 1 a uiNombreCouleur. */
	unsigned int* puiCouleurs = new unsigned int[uiNombreCouleur];

	// on affecte chaque couleur a une case du tableau
	for (unsigned int uiCouleur = 0; uiCouleur < uiNombreCouleur; uiCouleur++) 
	{
		// la numerotation des couleurs commence a 1, 0 etant l'etat sans couleur
		puiCouleurs[uiCouleur] = uiCouleur + 1; 
	}

	/*on initialise chaque case de puiCompteurCouleurs a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		puiCompteurCouleurs[uiBoucle] = 0;
	}





	/*pour chaque sommet voisin de SOMParam*/
	unsigned int uiNombreVoisins = GRANombreSommetsVoisins(SOMParam);
	for (unsigned int uiVoisin = 0; uiVoisin < uiNombreVoisins; uiVoisin++) 
	{

		/* pour chaque couleur */
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiNombreCouleur; uiBoucle2++) 
		{

			/*si une couleur correspond a la couleur d'un sommet voisin*/
			if (puiCouleurs[uiBoucle2] == GRALireListeSommets()[GRARenvoyerIndiceSommetsVoisins(SOMParam)[uiVoisin]]->SOMLireGestionCouleur().GCSLireNumeroCouleur()) 
			{
				//on incremente la case de puiCompteurCouleurs correspondant a la couleur trouvee
				puiCompteurCouleurs[uiBoucle2]++; 
			}
		}
	}

	/*pour chaque case de couleurs*/
	for (unsigned int uiCouleur = 0; uiCouleur < uiNombreCouleur; uiCouleur++) 
	{

		/*si la couleur en position uiCouleur n'a pas ete trouve dans les sommets voisins*/
		if (puiCompteurCouleurs[uiCouleur] == 0) 
		{
			//la taille que prendra le tableau des couleurs disponibles, pour un sommet, est incrementee de 1.
			uiTailleCouleursDisponibles++; 
		}
	}

	/* On fait delete aux tableaux initialises avec new */
	delete[] puiCompteurCouleurs;
	delete[] puiCouleurs;

	return uiTailleCouleursDisponibles;
}


