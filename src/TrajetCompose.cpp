/*************************************************************************
                           TrajetCompose  -  un trajet composé de plusieurs trajets simples
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
const int NB_TRAJET_DEFAUT_COMP = 10;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher () const
// Affiche tous les segments du trajet composé, dans l'ordre.
{
    for (int i =0 ; i< nbTrajets ; i++){
        TrajetSimple traj = trajets[i];
        cout << "de "<< traj.VilleDepart() << " à " << traj.VilleArrivee() << " en " << traj.MoyenDeTransport() << " - ";
    }
    cout << endl;
} 

char * TrajetCompose:: VilleDepart() const
// Retourne la ville de départ
{
    return trajets[0].VilleDepart();
}

char * TrajetCompose:: VilleArrivee() const
// Retourne la ville d'arrivée
{
    return trajets[nbTrajets-1].VilleArrivee();
}

Trajet* TrajetCompose::Clone() const
{
    // Alloue un nouvel objet sur lequel on appelle le constructeur de copie
    return new TrajetCompose(*this);
}

//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
{
#ifdef MAP
    cout << "Appel à l'opérateur d'assignement <TrajetCompose>" << endl;
#endif
    trajets = new TrajetSimple[unTrajetCompose.nbTrajets];
    for (int i = 0; i < unTrajetCompose.nbTrajets; i++)
    {
        trajets[i] = unTrajetCompose.trajets[i];
    }
    nbTrajets = unTrajetCompose.nbTrajets;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ) : nbTrajets(unTrajetCompose.nbTrajets)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
    trajets = new TrajetSimple[unTrajetCompose.nbTrajets];
    for (int i = 0; i < unTrajetCompose.nbTrajets; i++)
    {
        trajets[i] = unTrajetCompose.trajets[i];
    }
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose ( TrajetSimple * trajetsSimples, int taille_tableau ) : nbTrajets(taille_tableau)
// Initialise un trajet multi-segments, qui contiendra plusieurs TrajetSimple.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << std::endl;
#endif
    trajets = new TrajetSimple[taille_tableau];
    for (int i = 0; i < taille_tableau; i++) {
        trajets[i] = trajetsSimples[i];
    }
}

TrajetCompose::TrajetCompose ( ) : nbTrajets(0)
// Initialise un trajet multi-segments, qui contiendra plusieurs TrajetSimple.
// par défault, aucun segment n'est présent
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajets = new TrajetSimple[NB_TRAJET_DEFAUT_COMP];
    if (!trajets) {
        std::cerr << "N'a pas pu initialiser les trajets" << std::endl;
    }

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    if (trajets != nullptr) {
        delete [] trajets;
    }
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
