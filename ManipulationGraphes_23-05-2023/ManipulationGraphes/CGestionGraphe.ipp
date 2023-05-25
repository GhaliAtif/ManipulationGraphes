/* Methodes inline de CGestionGraphe */

#include <iostream>

using namespace std;

/***************************************************************************************************
***** GEGRECHERCHERINDICESOMMET : lit le 1er indice de la liste ayant pour sommet "uiPosition" *****
****************************************************************************************************
***** Entree: unsigned int uiNumero															   *****
***** Necessite: (rien)																		   *****
***** Sortie: un indice de boucle															   *****
***** Entraine : renvoie le 1er indice de la liste ayant pour sommet "uiPosition"			   *****
*****		  OU (ce sommet n'est pas dans la liste) leve une exception						   *****
***************************************************************************************************/
inline unsigned int CGraphe::GEGRechercherIndiceSommet(unsigned int uiNumero)
{
	/* On cherche "uiNumero" dans la liste des sommets */
	for (unsigned int uiIndiceBoucleSommet = 0; uiIndiceBoucleSommet < uiGRANombreSommets; uiIndiceBoucleSommet++)
	{
		/* Si un des sommets de la liste correspond, on retourne son indice dans la liste */
		if (GRALireListeSommets()[uiIndiceBoucleSommet]->SOMLireNumero() == uiNumero)
		{
			return uiIndiceBoucleSommet;
		}
	}

	/* Sinon, on retourne EXC_SOMMET_INEXISTANT */
	return EXC_SOMMET_INEXISTANT;
}