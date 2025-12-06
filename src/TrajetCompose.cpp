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
// Algorithme :
//
{
    for (int i =0 ; i< nbTrajets ; i++){
        TrajetSimple traj = trajets[i];
        cout << "de "<< traj.VilleDepart() << " à " << traj.VilleArrivee() << " en " << traj.MoyenDeTransport() << " - ";
    }
    cout << endl;
} //----- Fin de Méthode
char * TrajetCompose:: VilleDepart() const
{
    return trajets[0].VilleDepart();
}//----- Fin de Méthode

char * TrajetCompose:: VilleArrivee() const
{
    return trajets[nbTrajets-1].VilleArrivee();
}//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
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
// Algorithme :
//
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

TrajetCompose::TrajetCompose ( TrajetSimple * trajetsSimples, int taille_tableau ) : nbTrajets(taille_tableau), trajets(trajetsSimples)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << std::endl;
#endif


}

TrajetCompose::TrajetCompose ( ) : nbTrajets(0)
// Algorithme :
//TrajetSimple
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
