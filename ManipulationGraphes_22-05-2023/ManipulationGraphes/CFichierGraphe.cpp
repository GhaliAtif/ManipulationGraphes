#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <istream>

#include "CFichierGraphe.h"


using namespace std;




CFichierGraphe::CFichierGraphe()
{
	pcFIGNomFichier = nullptr;
}


CFichierGraphe::~CFichierGraphe()
{
	if (pcFIGNomFichier != nullptr)
	{
		free(pcFIGNomFichier);

	}
}


char* CFichierGraphe::FIGLireNomFichier()
{
	if (pcFIGNomFichier == nullptr)
	{
		CException EXCErreur(EXC_ARGUMENT_NULL, "Le nom du fichier est nullptr : impossible de l'afficher.");
		throw(EXCErreur);

	}

	return pcFIGNomFichier;
}



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

	//Recuperation des 2 premiere lignes du fichier
	fFichier >> cNombreSommet;
	fFichier >> cNombreArc;


	char *pctempNbSommet = strtok_s(cNombreSommet, cMotCle, &pcElementsuivS);
	char *pctempNbArc = strtok_s(cNombreArc, cMotCle, &pcElementsuivA);

	//on parcourt ces lignes pour recuperer le nombre de sommets et d'arcs
	while (pctempNbSommet != nullptr)
	{
		if (pctempNbSommet != nullptr)
		{
			uiFIGNombreSommets = atoi(pctempNbSommet);

			pctempNbSommet = strtok_s(nullptr, cMotCle, &pcElementsuivS);
		}
		if (pctempNbArc != nullptr)
		{
			uiFIGNombreArcs = atoi(pctempNbArc);

			pctempNbArc = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}
	}

	//On ignore cette ligne du fichier
	fFichier >> cIgnore;

	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet = nullptr;
	char *pcElementsuivN = nullptr;

	//Conversion en unsigned int pour les iterations de la boucle 
	unsigned int uiNombreSommet = atoi(pcNombreSommet);
	unsigned int uiNombreArc = atoi(pcNombreArc);

	unsigned int uiNumeroSommet;

	//Dans cette boucle, on parcourt les lignes contenant les sommets Separation au niveau "=". Convertion du numero du sommet  Creation d'un nouveau sommet  Ajouter dans le graphe
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNombreSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;

		pctempNumeroSommet = strtok_s(cSommet, cMotCle, &pcElementsuivN);

		while (pctempNumeroSommet != nullptr)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(nullptr, cMotCle, &pcElementsuivN);
		}

		uiNumeroSommet = atoi(pcNumeroSommet);
		CSommet *pSOMSommet = new CSommet(uiNumeroSommet);
		pGRAGraphe->GRAAjouterSommet(*pSOMSommet);
	}
	fFichier >> cIgnore;
	fFichier >> cIgnore;

	//initilaisation des variables pour la boucle recuperant les donnees sur les arcs
	char cArc[100];
	char *pctmpArcPartant;
	char *pctmpArcArrivant;
	char *pcArcPartant = nullptr;
	char *pcArcArrivant = nullptr;
	unsigned int uiArcPartant;
	unsigned int uiArcArrivant;

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

		while (pctmpArcPartant != nullptr)
		{
			pcArcPartant = pctmpArcPartant;
			pctmpArcPartant = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}

		uiArcPartant = atoi(pcArcPartant);

		fFichier >> cArc;

		pctmpArcArrivant = strtok_s(cArc, cMotCle, &pcElementsuivA);

		while (pctmpArcArrivant != nullptr)
		{
			pcArcArrivant = pctmpArcArrivant;
			pctmpArcArrivant = strtok_s(nullptr, cMotCle, &pcElementsuivA);
		}

		/* On cree un CArc a partir de uiArcArrivant */
		uiArcArrivant = atoi(pcArcArrivant);
		CArc ARCArrivant(uiArcArrivant);

		pGRAGraphe->GRAAjouterArc(uiArcPartant, ARCArrivant);
	}

}
