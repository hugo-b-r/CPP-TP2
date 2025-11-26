/*************************************************************************
                           TrajetSimple  -  un trajet d'une ville à une autre en un moyen de transport
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual char * VilleDepart () const override;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * VilleArrivee () const override;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * MoyenDeTransport () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher () const override;
    // Mode d'emploi :
    //
    // Contrat :
    //




//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    TrajetSimple ( const char * uneVilleDepart, const char * uneVilleArrivee, const char * moyenTransport );
    // Mode d'emploi :
    //
    // Contrat :
    //  les chaines char * sont allouées sur le tas dynamiquement

    virtual ~TrajetSimple ( ) override;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char * villeDepart;
char * villeArrivee;
char * moyenDeTransport;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
