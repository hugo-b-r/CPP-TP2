/*************************************************************************
                           TrajetSimple  -  un trajet d'une ville à une autre en un moyen de transport
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher () const
// Affiche un trajet simple sous forme lisible, ex =: "de Paris à Lyon en Train"
{
    cout << "de " << this -> villeDepart << " à " << this -> villeArrivee << " en " << this -> moyenDeTransport << endl;
} //----- Fin de Méthode

char * TrajetSimple::VilleDepart() const
// Algorithme :
//
{
    return this -> villeDepart;
} //----- Fin de Méthode

char * TrajetSimple::VilleArrivee() const
// Algorithme :
//
{
    return this -> villeArrivee;
} //----- Fin de Méthode

char * TrajetSimple::MoyenDeTransport() const
// Algorithme :
//
{
    return this -> moyenDeTransport;
} //----- Fin de Méthode

Trajet* TrajetSimple::Clone() const {
    return new TrajetSimple(*this);
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme : suppression des string préallouées et allocaiton de la bonne taille pour les string de la rvalue
//
{
#ifdef MAP
    cout << "Appel à l'opérateur d'assignement <TrajetSimple>" << endl;
#endif
    delete[] this->villeDepart;
    delete[] this->villeArrivee;
    delete[] this->moyenDeTransport;
    this->villeDepart = new char[strlen(unTrajetSimple.villeDepart) + 1];
    strcpy(this->villeDepart, unTrajetSimple.villeDepart);

    this->villeArrivee = new char[strlen(unTrajetSimple.villeArrivee) + 1];
    strcpy(this->villeArrivee, unTrajetSimple.villeArrivee);

    this->moyenDeTransport = new char[strlen(unTrajetSimple.moyenDeTransport) + 1];
    strcpy(this->moyenDeTransport, unTrajetSimple.moyenDeTransport);

    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme : alloue un char *  de la bonne taille et copie les chaines dedans
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    this->villeDepart = new char[ strlen(unTrajetSimple.villeDepart) + 1];
    strcpy(villeDepart, unTrajetSimple.villeDepart);

    this->villeArrivee = new char[ strlen(unTrajetSimple.villeArrivee) + 1];
    strcpy(villeArrivee, unTrajetSimple.villeArrivee);

    this->moyenDeTransport = new char[ strlen(unTrajetSimple.moyenDeTransport) + 1];
    strcpy(moyenDeTransport, unTrajetSimple.moyenDeTransport);
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( ): villeDepart(nullptr), villeArrivee(nullptr), moyenDeTransport(nullptr)
// Algorithme : ne fait presque rien, le trajet est vide
//
{
#ifdef MAP

    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple ( const char * uneVilleDepart, const char * uneVilleArrivee, const char * unMoyenTransport )
// Alorithme : allocation et copie des différentes chaines de caractères
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeDepart = new char[strlen(uneVilleDepart) + 1];
    strcpy(villeDepart, uneVilleDepart);
    villeArrivee = new char[strlen(uneVilleArrivee) + 1];
    strcpy(villeArrivee, uneVilleArrivee);
    moyenDeTransport = new char[strlen(unMoyenTransport) + 1];
    strcpy(moyenDeTransport, unMoyenTransport);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete[] villeDepart;
    delete[] villeArrivee;
    delete[] moyenDeTransport;

#ifdef MAP
    std::cout << "Fin du destructeur de trajet simple" << std::endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
