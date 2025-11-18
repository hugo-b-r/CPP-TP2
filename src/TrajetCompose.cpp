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
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
const int DEFAULT_NB_TRAJETS = 10;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ()
// Algorithme :
//
{ 
    for (int i =0 ; i< nbTrajets ; i++){
        TrajetSimple traj = trajets[i];
        cout << "de"<< traj.VilleDepart() << "à" << traj.VilleArrivee() << "en" << traj.MoyenDeTransport() << "||";
    }
    cout << "\r\n";
} //----- Fin de Méthode
char * TrajetCompose:: VilleDepart()
{
    return trajets[0].VilleDepart();
}//----- Fin de Méthode

char * TrajetCompose:: VilleArrivee()
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
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
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
    nbTrajets = unTrajetCompose.nbTrajets;
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( ) : nbTrajets(0), trajets(new TrajetSimple[DEFAULT_NB_TRAJETS])
// Algorithme :
//TrajetSimple
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete [] trajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

