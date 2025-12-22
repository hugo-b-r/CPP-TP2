/*************************************************************************
                           Trajet  -  un trajet généraliste
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>

#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Trajet::LireNbEtapes(ifstream & flux)
{
    string taille_str;
    getline(flux, taille_str, ':');
    return stoi(taille_str);
}

string Trajet::LireVilleDepart(ifstream & flux)
{
    string villeDep;
    getline(flux, villeDep, '>');
    return villeDep;
}

string Trajet::LireVilleArrivee(ifstream & flux)
{
    string villeArr;
    getline(flux, villeArr, ':');
    return villeArr;
}

Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
