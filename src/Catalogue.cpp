/*************************************************************************
                           Catalogue  -  une aggrégation de trajets dans
                           laquelle on peut chercher et ajouter des trajets et
                           afficher
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const int NB_TRAJET_DEFAUT_CATA = 10;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
// Algorithme :
//
{
    #ifdef MAP
    std::cout << "Appel à la méthode Afficher de <Catalogue>" << std::endl;
    #endif
    for (int i =0; i< nbTrajets; i++){
        trajets[i]->Afficher();
    } //----- Fin de Méthode
}

void Catalogue::RechercheParcours1 ( const char * VilleA, const char * VilleB ) const
// Algorithme :
//
{
    int compt =0;
    for (int i =0; i< nbTrajets; i++){
        if (!strcmp(trajets[i]->VilleDepart(), VilleA) && !strcmp(trajets[i]->VilleArrivee(), VilleB)){
            compt +=1;
            cout << compt << " : ";
            trajets[i]->Afficher();
        }

    }
}

void Catalogue::RechercheParcours2 ( const char * VilleA, const char * VilleB ) const
// Algorithme :
//
{
    for (int i =0; i< nbTrajets; i++){
        Trajet *Traj = trajets[i];
        if (Traj->VilleDepart()== VilleA && Traj->VilleArrivee()== VilleB){
            Traj->Afficher();
        }

    }
}


void Catalogue::AjouterTrajet ( Trajet * traj )
{
    #ifdef MAP
    std::cout << "Appel à l'ajout d'un trajet dans Catalogue" << std::endl;
    #endif

    trajets[nbTrajets] = traj;
    if (nbTrajets == tailleTrajets) {
        // On ne change que si on veut vraiment
        tailleTrajets *= 2;
        Trajet ** newtrajets =  new Trajet*[tailleTrajets];
        for (int i = 0; i < nbTrajets-1; i++) {
            newtrajets[i] = trajets[i];
        }
        delete[] trajets;
        trajets = newtrajets;
    }
    nbTrajets +=1;
    //Trajet * oldtrajets = trajets;

}

//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel à l'opérateur d'affectation de <Catalogue>" << endl;
    #endif
    trajets = new Trajet*[nbTrajets];
    nbTrajets = unCatalogue.nbTrajets;
    tailleTrajets = unCatalogue.tailleTrajets;
    for (int i = 0; i < unCatalogue.nbTrajets; i++) {
        this->trajets[i] = unCatalogue.trajets[i];
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( ) : nbTrajets(0), tailleTrajets(NB_TRAJET_DEFAUT_CATA)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    trajets = new Trajet*[NB_TRAJET_DEFAUT_CATA];
    if (!trajets) {
        std::cerr << "N'a pas pu initialiser le catalogue"<< std::endl;
    }
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    if (trajets) {
        delete[] trajets;
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
