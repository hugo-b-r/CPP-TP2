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
// Algorithme : Simple itération, si le départ et l'arrivée correspondent, alors on l'affiche
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

void Catalogue::RechercheParcoursAvecComposition ( const char * VilleA, const char * VilleB ) const
// Algorithme : cette fonction membre appelle seulement une autre fonction s'occupant de la récursion
// et alloue les tableaux dont elle a besoin pour fonctionner
//
{
    bool * utilises = new bool[nbTrajets];
    int * ordre = new int[nbTrajets];
    for (int i = 0; i < nbTrajets; i++) {
        utilises[i] = false;
        ordre[i] = -1;
    }

    for (int i = 0; i < nbTrajets; i++) {
        if (strcmp(VilleA, trajets[i]->VilleDepart()) == 0) {
            utilises[i] = true;
            ordre[0] = i;
            RechercheParcoursAvecCompositionRecursion(VilleA, VilleB, ordre, utilises, 1);
            ordre[0] = -1;
            utilises[i] = false;
        }
    }


    delete[] ordre;
    delete[] utilises;

}

void Catalogue::RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const
// Algorithme : Ajoute des trajets à la liste des utilises, les ajoute à ordre et si le trajet ajouté finit par VilleB, alors il affiche tout
//
{
    // si le chemin passé correspond
    if (strcmp(trajets[ordre[nbAjoutes-1]]->VilleArrivee(), VilleB) == 0) {
        cout << "Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
        for (int i = 0; i < nbAjoutes; i++) {
            trajets[ordre[i]]->Afficher();
        }
    // sinon si on peut encore tester d'autres trajets
    } else if (nbAjoutes < nbTrajets) {
        // si on a ajouté autant de trajets qu'il y en a et que ca ne mene pas à un trajet comme on le veut, ca ne sert à rien de continuer
        ++nbAjoutes;

        for (int i = 0; i < nbTrajets; i++) {
            // si non utilisé et ville de départ matche avec l'arrivée du chemin en construction
            if (!utilises[i] && strcmp(trajets[ordre[nbAjoutes-2]]->VilleArrivee(), trajets[i]->VilleDepart()) == 0) {

                utilises[i] = true;
                ordre[nbAjoutes-1] = i;

                RechercheParcoursAvecCompositionRecursion(VilleA, VilleB, ordre, utilises, nbAjoutes);
                ordre[nbAjoutes-1] = -1;
                utilises[i] = false;
            }
        }
        --nbAjoutes;
    }
    // condition de sortie: on a etudie tous les trajets qui peuvent se suivre
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
        for (int i = 0; i < nbTrajets; i++) {
            if (trajets[i])
                delete trajets[i];
        }
        delete[] trajets;
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
