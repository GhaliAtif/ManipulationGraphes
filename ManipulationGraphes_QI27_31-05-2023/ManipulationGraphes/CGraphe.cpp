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


bool CGraphe::GRAVerifierExistanceColoration(unsigned int uiNombreCouleurs)
{
	/* si tous les sommets de CGraphe sont colories, retourner vrai */
	if (GRAVerifierSommetsTousColories() == true) 
	{
		return true;
	}

	/* sinon */
	else 
	{

		/* pour chaque sommet de CGraphe... */
		for (unsigned int uiBoucle = 0; uiBoucle < GRALireNombreSommets(); uiBoucle++) 
		{

			/*...si le sommet n'est pas colorie */
			if (GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSPossederCouleur() == false) 
			{
				// allocation de couleurDispo
				unsigned int* couleursDispo = new unsigned int[GRANombreSommetsVoisins(*GRALireListeSommets()[uiBoucle])]; 

				// couleursDispo contient les couleurs dispo du sommet parcouru
				couleursDispo = GRARenvoyerCouleursDisponibles(*GRALireListeSommets()[uiBoucle], uiNombreCouleurs); 

				/*si il n'y a pas de couleur disponible, renvoie faux*/
				if (GRARenvoyerTailleCouleursDisponibles(*GRALireListeSommets()[uiBoucle], uiNombreCouleurs) == 0) 
				{
					return false;
				}

				/*pour chaque couleur disponible, on colorie le sommet parcouru*/
				for (unsigned int uiBoucle2 = 0; uiBoucle2 < GRARenvoyerTailleCouleursDisponibles(*GRALireListeSommets()[uiBoucle], uiNombreCouleurs); uiBoucle2++) 
				{
					GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSModifierNumeroCouleur(couleursDispo[uiBoucle2]);

					/*si pour cette coloration GEGVerifierExistanceColoration renvoie vrai alors on retourne vrai*/
					if (GRAVerifierExistanceColoration(uiNombreCouleurs) == true) 
					{
						return true;
					}

					// on enleve la couleur au sommet parcouru
					GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSModifierNumeroCouleur(0); 
				}

				//si pour aucune des colorations GEGVerifierExistanceColoration n'a retourne vrai alors on retourne faux.
				return false; 
			}
		}
	}
}


bool CGraphe::GRAVerifierSommetsTousColories()
{
	/* Si un des sommets n'est pas colorie, on retourne false */
	for (unsigned int uiSommet = 0; uiSommet < uiGRANombreSommets; uiSommet++)
	{
		if (GRALireListeSommets()[uiSommet]->SOMLireGestionCouleur().GCSPossederCouleur() != true)
		{
			return false;
		}
	}

	return true;
}


unsigned int * CGraphe::GRARenvoyerCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur)
{
	/* Allocation tableau temporaire qui contiendra 
	toutes les couleurs numerotees de 1 a uiNombreCouleur. */
	unsigned int* couleurs = new unsigned int[uiNombreCouleur]; 

	/* Allocation tableau temporaire qui sera un compteur pour "couleurs". */
	unsigned int* compteurCouleur = new unsigned int[uiNombreCouleur];

	/* on affecte chaque couleur a une case du tableau */
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		// la numerotation des couleurs commence a 1, 0 est l'etat sans couleur
		couleurs[uiBoucle] = uiBoucle + 1; 
	}

	/* on initialise chaque case de compteurCouleur a 0 */
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		compteurCouleur[uiBoucle] = 0;
	}

	/* pour chaque sommet voisin de SOMParam */
	for (unsigned int uiBoucle = 0; uiBoucle < GRANombreSommetsVoisins(SOMParam); uiBoucle++) 
	{

		/* pour chaque couleur */
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiNombreCouleur; uiBoucle2++) 
		{

			/* si une couleur correspond a la couleur d'un sommet voisin */
			if (couleurs[uiBoucle2] == GRALireListeSommets()[GRARenvoyerIndiceSommetsVoisins(SOMParam)[uiBoucle]]->SOMLireGestionCouleur().GCSLireNumeroCouleur()) 
			{
				compteurCouleur[uiBoucle2]++;//on incremente la case de compteurCouleur correspondante a la couleur trouve.
			}
		}
	}
	unsigned int taille = 0;

	/*pour chaque case de couleurs*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) {
		/*si la couleur en position uiBoucle n'a pas ete trouve dans les sommets voisin*/
		if (compteurCouleur[uiBoucle] == 0) {
			taille++; //la taille que prendra le tableau des couleurs disponible pour un sommet incremente de 1.
		}
	}

	unsigned int* couleursDispo = new unsigned int[taille]; //on alloue le tableau qui contiendra les couleurs disponible pour un sommet
	unsigned int compteurCouleurDispo = 0; //initialise un compteur a 0.

	/*on initialise les cases de couleursDispo a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < taille; uiBoucle++) {
		couleursDispo[uiBoucle] = 0;
	}

	/*pour chaques couleurs inferieur a uiNombreCouleur*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) {

		/*si la couleur n'est pas presente chez les voisin de SOMParam et inferieur a uiNombreCouleur*/
		if (compteurCouleur[uiBoucle] == 0 && compteurCouleurDispo < taille) {
			couleursDispo[compteurCouleurDispo] = uiBoucle + 1; //on ajoute cette couleur a couleurDispo 
			compteurCouleurDispo++;
		}
	}
	delete[] compteurCouleur;
	delete[] couleurs;
	return couleursDispo;
}


unsigned int * CGraphe::GRARenvoyerIndiceSommetsVoisins(CSommet & SOMParam)
{
	unsigned int uiNumero = 0;

	/* allocation d'un tableau qui contiendra la position des sommets, 
	voisins de SOMParam, dans pSOMGRAListeSommets. */
	unsigned int* NumeroVoisin = new unsigned int[GRANombreSommetsVoisins(SOMParam)]; 

	/* On parcourt tous les arcs partants de SOMParam pour connaitre 
	ses voisins */
	for (unsigned int uiArc = 0; uiArc < SOMParam.SOMLireNombreArcsPartants(); uiArc++)
	{
		/* A 1 arc partant donne, on parcourt la liste des sommets pour retrouver
		l'indice de liste de ce sommet pointe par cet arc */
		for (unsigned int uiSommet = 0; uiSommet < GRALireNombreSommets(); uiSommet++)
		{
			if (SOMParam.SOMLireListeArcsPartants(uiArc)->ARCLireNumeroDestination() == GRALireListeSommets()[uiSommet]->SOMLireNumero())
			{
				NumeroVoisin[uiArc] = uiSommet;
			}
		}
	}

	return NumeroVoisin;
}


unsigned int CGraphe::GRARenvoyerTailleCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur)
{
	/* Allocation tableau temporaire qui contiendra
	toutes les couleurs numerotees de 1 a uiNombreCouleur. */
	unsigned int* couleurs = new unsigned int[uiNombreCouleur];

	/* Allocation tableau temporaire qui sera un compteur pour "couleurs". */
	unsigned int* compteurCouleur = new unsigned int[uiNombreCouleur];

	/*on affecte chaque couleur a une case du tableau*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		// la numerotation des couleurs commence a 1, 0 est l'etat sans couleur
		couleurs[uiBoucle] = uiBoucle + 1; 
	}

	/*on initialise chaque case de compteurCouleur a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		compteurCouleur[uiBoucle] = 0;
	}

	/*pour chaque sommet voisin de SOMParam*/
	for (unsigned int uiBoucle = 0; uiBoucle < GRANombreSommetsVoisins(SOMParam); uiBoucle++) 
	{

		/* pour chaque couleur */
		for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiNombreCouleur; uiBoucle2++) 
		{

			/*si une couleur correspond a la couleur d'un sommet voisin*/
			if (couleurs[uiBoucle2] == GRALireListeSommets()[GRARenvoyerIndiceSommetsVoisins(SOMParam)[uiBoucle]]->SOMLireGestionCouleur().GCSLireNumeroCouleur()) 
			{
				//on incremente la case de compteurCouleur correspondant a la couleur trouvee
				compteurCouleur[uiBoucle2]++; 
			}
		}
	}

	unsigned int tailleCouleurDispo = 0;

	/*pour chaque case de couleurs*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{

		/*si la couleur en position uiBoucle n'a pas ete trouve dans les sommets voisins*/
		if (compteurCouleur[uiBoucle] == 0) 
		{
			//la taille que prendra le tableau des couleurs disponibles, pour un sommet, est incrementee de 1.
			tailleCouleurDispo++; 
		}
	}

	/* On fait delete aux tableaux initialises avec new */
	delete[] compteurCouleur;
	delete[] couleurs;

	return tailleCouleurDispo;
}


