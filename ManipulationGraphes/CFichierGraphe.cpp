#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <istream>

#include "CFichierGraphe.h"


using namespace std;

CFichierGraphe::CFichierGraphe()
{
	pcFIGNomFichier=NULL;
}


CFichierGraphe::CFichierGraphe(CFichierGraphe &FIGParam)
{
	FIGModifierNomFichier(FIGParam.FIGLireNomFichier());
}


CFichierGraphe::~CFichierGraphe()
{
	free(pcFIGNomFichier);
}


char* CFichierGraphe::FIGLireNomFichier()
{
	if (pcFIGNomFichier == NULL)
	{
		CException EXCErreur(EXCArgumentNull, "fichier est null");
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

		int iCompteur = strlen(pcNom);
		pcFIGNomFichier = (char*)malloc(iCompteur + 1);
		int iBoucle;
		for (iBoucle = 0; iBoucle < iCompteur; iBoucle++)
		{
			pcFIGNomFichier[iBoucle] = pcNom[iBoucle];
		}
		pcFIGNomFichier[iBoucle] = '\0';
	}
	else
	{
		pcFIGNomFichier = NULL;
	}
}




CGraphe& CFichierGraphe::FIGLireFichier()
{
	CGraphe* pGRAGraphe = new CGraphe();
	// Ouverture du fichier
	ifstream fFichier(FIGLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien d�roul�
		CException EXCErreur(EXCOuvertureFichier, "Impossible d'ouvrire le fichier	");
		throw(EXCErreur);
	}

	//cMotCle est notre s�parateur, Utilis� pour la fonction strtok_s() 	   
	char cMotCle[] = "=";

	char cNombreSommet[100], cNombreArc[100], cIgnore[200];

	char *pcNombreSommet = NULL, *pcNombreArc = NULL;

	char *pcElementsuivS = NULL, *pcElementsuivA = NULL;

	//R�cup�ration des 2 premi�re lignes du fichier
	fFichier >> cNombreSommet;
	fFichier >> cNombreArc;


	char *pctempNbSommet = strtok_s(cNombreSommet, cMotCle, &pcElementsuivS);
	char *pctempNbArc = strtok_s(cNombreArc, cMotCle, &pcElementsuivA);

	//on parcours ces lignes pour r�cup�rer le nombre de sommet et d'arc
	while (pctempNbSommet != NULL)
	{
		if (pctempNbSommet != NULL)
		{
			pcNombreSommet = pctempNbSommet;

			pctempNbSommet = strtok_s(NULL, cMotCle, &pcElementsuivS);
		}
		if (pctempNbArc != NULL)
		{
			pcNombreArc = pctempNbArc;

			pctempNbArc = strtok_s(NULL, cMotCle, &pcElementsuivA);
		}
	}

	//On ingore cette ligne du fichier
	fFichier >> cIgnore;

	char cSommet[100];
	char *pctempNumeroSommet;
	char *pcNumeroSommet = NULL;
	char *pcElementsuivN = NULL;

	//Conversion en unsigned int pour les it�rations de la boucle 
	unsigned int uiNombreSommet = atoi(pcNombreSommet);
	unsigned int uiNombreArc = atoi(pcNombreArc);

	unsigned int uiNumeroSommet;

	 //Dans cette boucle, on parcours les lignes contenant les sommet S�pararation au niveau"=" Convertion du num�ro du sommet  Cr�ation d'un nouveau sommet  Ajouter dans le graphe
	for (unsigned int uiBoucleSommet = 0; uiBoucleSommet < uiNombreSommet; ++uiBoucleSommet)
	{
		fFichier >> cSommet;

		pctempNumeroSommet = strtok_s(cSommet, cMotCle, &pcElementsuivN);

		while (pctempNumeroSommet != NULL)
		{
			pcNumeroSommet = pctempNumeroSommet;
			pctempNumeroSommet = strtok_s(NULL, cMotCle, &pcElementsuivN);
		}

		uiNumeroSommet = atoi(pcNumeroSommet);
		CSommet *pSOMSommet = new CSommet(uiNumeroSommet);
		pGRAGraphe->GRAAjouterSommet(*pSOMSommet);
	}
	fFichier >> cIgnore;
	fFichier >> cIgnore;

	//initilaisation des variables pour la boucle r�cup�rant les donn�es sur les arcs
	char cArc[100];
	char *pctmpArcPartant;
	char *pctmpArcArrivant;
	char *pcArcPartant = NULL;
	char *pcArcArrivant = NULL;
	unsigned int uiArcPartant;
	unsigned int uiArcArrivant;

	//cr�ation du d�limiteur ","
	char cMotCle2[] = ",";

	/*
	on r�cup�re "Debut=?, S�paration au niveau de la virgule puis au niveau du "=" Convertion en int de la valeur de l'arc partant ,R�cup�ration du reste de la ligne ,S�paration au niveau du "=" ,Convertion 
	Utilisation de la fonction GRAAjouterArc(uiArcPartant, uiArcArrivant) qui cr�� des arcs et les ajoute dans le graphe
	*/
	for (unsigned int uiBoucleArc = 0; uiBoucleArc < uiNombreArc; ++uiBoucleArc)
	{
		fFichier >> cArc;

		pctmpArcPartant = strtok_s(cArc, cMotCle2, &pcElementsuivA);
		pctmpArcPartant = strtok_s(cArc, cMotCle, &pcElementsuivA);

		while (pctmpArcPartant != NULL)
		{
			pcArcPartant = pctmpArcPartant;
			pctmpArcPartant = strtok_s(NULL, cMotCle, &pcElementsuivA);
		}

		uiArcPartant = atoi(pcArcPartant);

		fFichier >> cArc;

		pctmpArcArrivant = strtok_s(cArc, cMotCle, &pcElementsuivA);

		while (pctmpArcArrivant != NULL)
		{
			pcArcArrivant = pctmpArcArrivant;
			pctmpArcArrivant = strtok_s(NULL, cMotCle, &pcElementsuivA);
		}

		uiArcArrivant = atoi(pcArcArrivant);

		pGRAGraphe->GRAAjouterArc(uiArcPartant, uiArcArrivant);
	}
	return *pGRAGraphe;
}