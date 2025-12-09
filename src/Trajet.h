/*************************************************************************
                           Trajet  -  un trajet généraliste
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Trajet est une classe abstraite non instanciable. Un trajet a une ville de départ, une ville d'arrivée et est clonable
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual char * VilleDepart () const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual char * VilleArrivee () const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher () const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Trajet* Clone() const = 0;

//------------------------------------------------- Surcharge d'opérateurs

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
