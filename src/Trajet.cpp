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



//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher () const
// Algorithme :
//
{
    #ifdef MAP
        std::cout << "Appel à la méthode Afficher de trajet (celle que l'on ne veut pas appeler)" << std::endl;
    #endif
} //----- Fin de Méthode

char * Trajet::VilleDepart () const
// Algorithme :
//
{
    #ifdef MAP
        std::cout << "Appel à la méthode VilleDepart" << std::endl;
    #endif
    return nullptr;
} //----- Fin de Méthode

char * Trajet::VilleArrivee () const
// Algorithme :
//
{
    #ifdef MAP
        std::cout << "Appel à la méthode VilleArrivee" << std::endl;
    #endif
    return nullptr;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
    #ifdef MAP
        std::cout << "Appel à l'opérateur =" << std::endl;
    #endif
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


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
