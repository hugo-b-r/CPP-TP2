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
// C'est un trajet très imple : il a un départ, une arrivé et un moyen de transport. Hérite de Trajet.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual char * VilleDepart () const override;
    // Mode d'emploi : Retourne la ville de départ du trajet
    //
    // Contrat :
    //

    virtual char * VilleArrivee () const override;
    // Mode d'emploi : Retourne la ville d'arrivé du trajet
    //
    // Contrat :
    //

    virtual char * MoyenDeTransport () const;
    // Mode d'emploi : Moyen de transport du trajet
    //
    // Contrat :
    //

    virtual void Afficher () const override;
    // Mode d'emploi : Affichage sympathique dans cout du trajet
    //
    // Contrat :
    //

    virtual Trajet* Clone() const override;
    // Mode d'emploi : Allocation puis copie d'un nouvel objet dont l'adresse est renvoyée
    //
    // Contrat : l'adresse doit bien être stockée pour bien appeler les destructeurs.
    //

    virtual ofstream & FormaterPourFichier(ofstream & flux) const override;

    virtual TypeTrajet Type() const override;


//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi : affectation simple de l'objet
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) : copie simple de l'objet
    //


    TrajetSimple ( );
    // Mode d'emploi : Construit un traje simple vide
    //

    TrajetSimple ( const char * uneVilleDepart, const char * uneVilleArrivee, const char * moyenTransport );
    // Mode d'emploi : Construit le trajet à partir des paramaètres passés
    //
    // Contrat :
    //      Le trajet fait sa propre copie des chaine de caractères

    TrajetSimple ( ifstream & flux, string villeA, string villeB);
    // Mode d'emploi : Construit le trajet à partir des paramaètres passés
    //
    // Contrat :
    //      Le trajet fait sa propre copie des chaine de caractères


    virtual ~TrajetSimple ( ) override;
    // Mode d'emploi :
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
