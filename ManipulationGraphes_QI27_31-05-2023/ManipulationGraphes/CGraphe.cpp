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

	/* pour chaque sommet de CGraphe... */
	for (unsigned int uiBoucle = 0; uiBoucle < GRALireNombreSommets(); uiBoucle++) 
	{

		/*...si le sommet n'est pas colorie */
		if (GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSPossederCouleur() == false) 
		{
			// Pour recuperer les couleurs disponibles du sommet courant
			unsigned int* couleursDispo = GRARenvoyerCouleursDisponibles(*GRALireListeSommets()[uiBoucle], uiNombreCouleurs);
			unsigned int tailleCouleursDispo = GRARenvoyerTailleCouleursDisponibles(*GRALireListeSommets()[uiBoucle], uiNombreCouleurs);

			/*test*/
			static unsigned int nbiterations = 0;
			cout<<"pour iteration numero "<<nbiterations<<"de mth VerifierExistenceColoration, taillecouleursDispo vaut "<< tailleCouleursDispo <<endl;

			/* Pour chaque couleur disponible, on essaie de colorier le sommet courant */
			for (unsigned int uiBoucle2 = 0; uiBoucle2 < tailleCouleursDispo; uiBoucle2++) 
			{
				/* Colorie le sommet */
				GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSModifierNumeroCouleur(couleursDispo[uiBoucle2]);


				nbiterations++;

				/* Appel recursif avec le graphe mis a jour et les couleurs restantes */
				if (GRAVerifierExistanceColoration(uiNombreCouleurs)) 
				{
					/* Si cet appel renvoie vrai, alors le graphe peut etre colorie */
					delete[] couleursDispo;
					return true;
				}

				// on enleve la couleur au sommet parcouru
				GRALireListeSommets()[uiBoucle]->SOMLireGestionCouleur().GCSModifierNumeroCouleur(0); 
			}

			delete[] couleursDispo;

			/* S'il n'existe aucune coloration valide, on renvoie faux */
			return false; 
		}
	}

	/* Cas de base : on a teste tous les sommets sans trouver de coloration adequate */
	return false; 

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
	for (unsigned int uiNumeroCouleur = 0; uiNumeroCouleur < uiNombreCouleur; uiNumeroCouleur++) 
	{
		// la numerotation des couleurs commence a 1, 0 est l'etat sans couleur
		couleurs[uiNumeroCouleur] = uiNumeroCouleur + 1; 
	}


	/*test*/
	for (unsigned int i = 0; i < uiNombreCouleur; i++)
	{
		cout << "dans CGraphe.cpp, dans mth renvoyercouleursdispo, couleurs a la case " << i << " est " << couleurs[i] << endl;

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

	/* pour chaque case de "couleurs" */
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		/*si la couleur en position uiBoucle n'a pas ete trouvee dans les sommets voisins*/
		if (compteurCouleur[uiBoucle] == 0) 
		{
			taille++; //la taille que prendra le tableau des couleurs disponible pour un sommet incremente de 1.
		}
	}

	unsigned int* couleursDispo = new unsigned int[taille]; //on alloue le tableau qui contiendra les couleurs disponible pour un sommet
	unsigned int compteurCouleurDispo = 0; //initialise un compteur a 0.

	/*on initialise les cases de couleursDispo a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < taille; uiBoucle++) 
	{
		couleursDispo[uiBoucle] = 0;
	}

	

	/* pour chaque couleur */
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{

		/* si la couleur n'est pas presente chez les voisins de SOMParam */
		if (compteurCouleur[uiBoucle] == 0 && compteurCouleurDispo < taille) 
		{
			couleursDispo[compteurCouleurDispo] = uiBoucle + 1; //on ajoute cette couleur a couleurDispo 
			compteurCouleurDispo++;
		}
	}

	/*test*/
	for (unsigned int i = 0; i < taille; i++)
	{
		cout << "dans CGraphe.cpp, dans mth renvoyercouleursdispo, couleurDispo a la case " << i << " est " << couleurs[i] << endl;

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

	/* On parcourt tous les arcs partants de SOMParam pour connaitre ses voisins */
	for (unsigned int uiArcPartant = 0; uiArcPartant < SOMParam.SOMLireNombreArcsPartants(); uiArcPartant++)
	{
		/* A 1 arc partant donne, on parcourt la liste des sommets pour retrouver l'indice de liste de ce sommet pointe par cet arc */
		for (unsigned int uiSommet = 0; uiSommet < GRALireNombreSommets(); uiSommet++)
		{
			if (SOMParam.SOMLireListeArcsPartants(uiArcPartant)->ARCLireNumeroDestination() == GRALireListeSommets()[uiSommet]->SOMLireNumero())
			{
				NumeroVoisin[uiArcPartant] = uiSommet;
			}
		}
	}

	/* Apres les voisins connus par les arcs partants de SOMParam, 
	on rajoute les voisins connus par les arcs arrivants de SOMParam grace a GEGChercherIndiceSourceArcsArrivants */
	unsigned int * puiSourcesArcsArrivants = GEGChercherIndiceSourceArcsArrivants(SOMParam);
	for (unsigned int uiArcArrivant = SOMParam.SOMLireNombreArcsPartants(); uiArcArrivant < GRANombreSommetsVoisins(SOMParam); uiArcArrivant++)
	{
		NumeroVoisin[uiArcArrivant] = puiSourcesArcsArrivants[uiArcArrivant - SOMParam.SOMLireNombreArcsPartants()];
	}

	return NumeroVoisin;
}


unsigned int CGraphe::GRARenvoyerTailleCouleursDisponibles(CSommet & SOMParam, unsigned int uiNombreCouleur)
{
	/* Au depart, tailleCouleursDispo vaut 0 */
	unsigned int tailleCouleursDispo = 0;

	/* Allocation tableau temporaire qui sera un compteur pour "couleurs". */
	unsigned int* compteurCouleur = new unsigned int[uiNombreCouleur];

	/* Allocation tableau temporaire qui contiendra
	toutes les couleurs numerotees de 1 a uiNombreCouleur. */
	unsigned int* couleurs = new unsigned int[uiNombreCouleur];

	// on affecte chaque couleur a une case du tableau
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		// la numerotation des couleurs commence a 1, 0 etant l'etat sans couleur
		couleurs[uiBoucle] = uiBoucle + 1; 
	}

	/*on initialise chaque case de compteurCouleur a 0*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{
		compteurCouleur[uiBoucle] = 0;
	}





	/*pour chaque sommet voisin de SOMParam*/
	unsigned int uiNombreVoisins = GRANombreSommetsVoisins(SOMParam);
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreVoisins; uiBoucle++) 
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

	/*pour chaque case de couleurs*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiNombreCouleur; uiBoucle++) 
	{

		/*si la couleur en position uiBoucle n'a pas ete trouve dans les sommets voisins*/
		if (compteurCouleur[uiBoucle] == 0) 
		{
			//la taille que prendra le tableau des couleurs disponibles, pour un sommet, est incrementee de 1.
			tailleCouleursDispo++; 
		}
	}

	cout << "dans CGraphe.cpp, dans mth taillecouleursdispo, taillecouleursdispo vaut" << tailleCouleursDispo << endl;


	/* On fait delete aux tableaux initialises avec new */
	delete[] compteurCouleur;
	delete[] couleurs;

	return tailleCouleursDispo;
}


