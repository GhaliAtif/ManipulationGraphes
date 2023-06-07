#include <iostream>
#include <fstream>
#include <cstring>
#include <istream>

#include "CFichierGraphe.h"


using namespace std;



/*****************************************************************************
***** CFICHIERGRAPHE: Constructeur par defaut de la classe CFichier		 *****
******************************************************************************
***** Entree: (rien)													 *****
***** Necessite:	(rien)												 *****
***** Sortie: (rien)													 *****
***** Entraîne : L'objet est initialise avec pcFIGNomFichier = NULL		 *****
******************************************************************************/
CFichierGraphe::CFichierGraphe()
{
	pcFIGNomFichier = nullptr;
	uiFIGNombreSommets = 0;
	uiFIGNombreArcsPartants = 0;
	uiFIGNombreArcsArrivants = 0;
	pUNIFIGSommets = nullptr;
	pUNIFIGListeSommetsDepart = nullptr;
	pUNIFIGListeSommetsArrivee = nullptr;
}

/*****************************************************************************
***** ~CFICHIERGRAPHE(): Destructeur de la classe CFichierGraphe		 *****
******************************************************************************
***** Entree: (rien)													 *****
***** Necessite:	(rien)												 *****
***** Sortie: (rien)													 *****
***** Entraîne :	L'objet est desinitialise							 *****
******************************************************************************/
CFichierGraphe::~CFichierGraphe()
{
	if (pcFIGNomFichier != nullptr)
	{
		free(pcFIGNomFichier);
	}

	if (pUNIFIGSommets != nullptr)
	{
		free(pUNIFIGSommets);
	}

	if (pUNIFIGListeSommetsDepart != nullptr)
	{
		free(pUNIFIGListeSommetsDepart);
	}

	if (pUNIFIGListeSommetsArrivee != nullptr)
	{
		free(pUNIFIGListeSommetsArrivee);
	}
}

/*****************************************************************************
***** FIGLIRENOMFICHIER: Lit le nom du fichier							 *****
******************************************************************************
***** Entree: (rien)													 *****
***** Necessite:	(rien)												 *****
***** Sortie: pcFIGNomFichier											 *****
***** Entraîne : renvoie pcFIGNomFichier								 *****
******************************************************************************/
char* CFichierGraphe::FIGLireNomFichier()
{
	if (pcFIGNomFichier == nullptr)
	{
		CException EXCErreur(EXC_ARGUMENT_NULL, "Le nom du fichier est nullptr : impossible de l'afficher.");
		throw(EXCErreur);

	}

	return pcFIGNomFichier;
}


/************************************************************************************************
***** FIGMODIFIERNOMFICHIER : modifie le nom du fichier										*****
*************************************************************************************************
***** Entree: const char * pcNom															*****
***** Necessite:	(rien)																    *****
***** Sortie: (rien)																	    *****
***** Entraîne : pcFIGNomFichier = pcNom													*****
*************************************************************************************************/
void CFichierGraphe::FIGModifierNomFichier(const char* pcNom)
{
	if (pcNom)
	{
		if (pcFIGNomFichier)
		{
			free(pcFIGNomFichier);
		}

		size_t stCompteur = strlen(pcNom);
		pcFIGNomFichier = (char*)malloc(stCompteur + 1);
		size_t stBoucle;
		for (stBoucle = 0; stBoucle < stCompteur; stBoucle++)
		{
			pcFIGNomFichier[stBoucle] = pcNom[stBoucle];
		}
		pcFIGNomFichier[stBoucle] = '\0';
	}
	else
	{
		pcFIGNomFichier = nullptr;
	}
}



/************************************************************************************************
***** FIGLIREGRAPHEDANSFICHIER : lit et extrait des informations du fichier texte			*****
*************************************************************************************************
***** Entree: (rien)																		*****
***** Necessite: (rien)																		*****
***** Sortie: un objet CGraphe															    *****
***** Entraîne : le graphe cree possede les parametres ecrit dans le fichier texte			*****
*************************************************************************************************/
void CFichierGraphe::FIGLireGrapheDansFichier()
{
	// Ouverture du fichier
	ifstream fFichier(FIGLireNomFichier());
	if (!fFichier)
	{
		// On teste si l'ouverture s'est bien deroulee
		CException EXCErreur(EXC_OUVERTURE_FICHIER, "Echec de l'ouverture du fichier texte.");
		throw(EXCErreur);
	}

	// cMotCle est notre separateur. Il est utilise pour la fonction strtok_s() 	   
	char cMotCle[] = "=";

	char cNombreSommet[100], cNombreArc[100], cIgnore[200];

	char *pcNombreSommet = nullptr, *pcNombreArc = nullptr;

	char *pcElementsuivS = nullptr, *pcElementsuivA = nullptr;


	unsigned int uiFIGNombreArcs;

	// Recuperation des 2 premieres lignes du fichier
	fFichier >> cNombreSommet;
	fFichier >> cNombreArc;


	char *pctempNbSommet = strtok_s(cNombreSommet, cMotCle, &pcElementsuivS);
	char *pctempNbArc = strtok_s(cNombreArc, cMotCle, &pcElementsuivA);

	//on parcourt ces lignes pour recuperer le nombre de sommets et d'arcs ecrits dans le fichier
	while (pctempNbSommet != nullptr)
	{
		if (pctempNbSommet != nullptr)
		{
			pcNombreSommet = pctempNbSommet;
			pctempNbSommet = strtok_s(nullptr, cMotCle, &pcElementsuivS);
		}
		if (pctempNbArc != nullptr)
		{
			pcNombreArc = pctempNbArc;
			pctempNbArc = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}
	}

	/* On recupere le nombre de sommets et d'arcs du fichier */
	uiFIGNombreSommets = atoi(pcNombreSommet);

	// On alloue la liste de sommets correspondant a cette taille
	pUNIFIGSommets = (unsigned int *) malloc(uiFIGNombreSommets * sizeof(unsigned int));

	uiFIGNombreArcs = atoi(pcNombreArc);

	//On ignore cette ligne du fichier
	fFichier >> cIgnore;

	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet = nullptr;
	char *pcElementsuivN = nullptr;

	//Conversion en unsigned int pour les iterations de la boucle 
	unsigned int uiNombreSommet = atoi(pcNombreSommet);
	unsigned int uiNombreArc = atoi(pcNombreArc);

	//Dans cette boucle, on parcourt les lignes contenant les sommets Separation au niveau "=". Convertion du numero du sommet  Creation d'un nouveau sommet  Ajouter dans le graphe
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNombreSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;

		pctempNumeroSommet = strtok_s(cSommet, cMotCle, &pcElementsuivN);

		/* On recupere le "Numero_Sommet", ecrit dans le fichier, d'un sommet a la fois */  
		while (pctempNumeroSommet != nullptr)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(nullptr, cMotCle, &pcElementsuivN);
		}

		/* Ajout du numero de sommet recupere, dans "pcNumeroSomme", dans la liste pUNIFIGSommets */
		pUNIFIGSommets[uiBoucleSommet] = atoi(pcNumeroSommet);

	}
	fFichier >> cIgnore;
	fFichier >> cIgnore;

	//initialisation des variables pour la boucle recuperant les donnees sur les arcs
	char cArc[100];
	char *pctmpArcPartant;
	char *pctmpArcArrivant;
	char *pcArcPartant = nullptr;
	char *pcArcArrivant = nullptr;

	//creation du delimiteur ","
	char cMotCle2[] = ",";

	/*
	on recupere "Debut=?, Separation au niveau de la virgule puis au niveau du "=" Convertion en int de la valeur de l'arc partant ,Recuperation du reste de la ligne ,Separation au niveau du "=" ,Convertion
	Utilisation de la fonction GRAAjouterArc(uiArcPartant, uiArcArrivant) qui cree des arcs et les ajoute dans le graphe
	*/
	for (unsigned int uiBoucleArc = 0; uiBoucleArc < uiNombreArc; ++uiBoucleArc)
	{
		fFichier >> cArc;

		pctmpArcPartant = strtok_s(cArc, cMotCle2, &pcElementsuivA);
		pctmpArcPartant = strtok_s(cArc, cMotCle, &pcElementsuivA);

		/* On recupere le "Sommet_depart_arc", ecrit dans le fichier, d'un arc a la fois */
		while (pctmpArcPartant != nullptr)
		{
			pcArcPartant = pctmpArcPartant;
			pctmpArcPartant = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}

		/* Ajout du numero de depart de l'arc recupere, dans "pcArcPartant", dans la liste pUNIFIGListeSommetsDepart */
		uiFIGNombreArcsPartants += 1;
		pUNIFIGListeSommetsDepart = (unsigned int *)realloc(pUNIFIGListeSommetsDepart, uiFIGNombreArcsPartants * sizeof(unsigned int));
		pUNIFIGListeSommetsDepart[uiBoucleArc] = atoi(pcArcPartant);

		fFichier >> cArc;

		pctmpArcArrivant = strtok_s(cArc, cMotCle, &pcElementsuivA);

		/* On recupere le "Sommet_arrivee_arc", ecrit dans le fichier, d'un arc a la fois */
		while (pctmpArcArrivant != nullptr)
		{
			pcArcArrivant = pctmpArcArrivant;
			pctmpArcArrivant = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}

		/* Ajout du numero d'arrivee de l'arc recupere, dans "pcArcArrivant", dans la liste pUNIFIGListeSommetsArrivee */
		uiFIGNombreArcsArrivants += 1;
		pUNIFIGListeSommetsArrivee = (unsigned int *)realloc(pUNIFIGListeSommetsArrivee, uiFIGNombreArcsArrivants * sizeof(unsigned int));
		pUNIFIGListeSommetsArrivee[uiBoucleArc] = atoi(pcArcArrivant);
		
	}

}
