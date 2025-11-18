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
#include <cstdio>
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher()
{
    for (int i =0; i< nbTrajets; i++){
        Trajet Traj = trajets[i];
        Traj.Afficher();
    } //----- Fin de Méthode
}

void Catalogue::RechercheParcours(const char * VilleA, const char * VilleB)
{
    for (int i =0; i< nbTrajets; i++){
        Trajet Traj = trajets[i];
        if (Traj.VilleDepart()== VilleA)
        {
            // mqen,fMQKEf IHEDJKEFDJOKLEZDJOKLEFZSDPOJJEZFSDOJEZFDJOEFDIJHBJESFDIHBJEFSDIHBJESDIHB ESDJILJEFSDVJPOPLKN.nSFDXJPL.EFSFXOJMKEZFSDPOJEZFSDùOSDFVOJJNEDSVIJJLBKSDFSHJBDSclAKQSN
            //EPIHAKLFJQDVopNKMefL AjVQDO¨nEFKmVqdjoNEFZKmVGNmlKLGJDVIPKEJMLGN
            // ( il y avait PPP ici)
        }
        Traj.Afficher();
    } //----- Fin de Méthode
}


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel à l'opérateur d'affectation de <Catalogue>" << endl;
    #endif
    trajets = new Trajet[nbTrajets];
    nbTrajets = unCatalogue.nbTrajets;
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


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

