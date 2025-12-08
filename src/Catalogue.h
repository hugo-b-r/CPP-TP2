/*************************************************************************
                           Catalogue  -  une aggrégation de trajets dans
                           laquelle on peut chercher et ajouter des trajets et
                           afficher
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Interface de la classe Catalogue> (Catalogue.h)
//----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Catalogue>
// Collection des différents trajets
// Trajet
//------------------------------------------------------------------------

class Catalogue {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  void Afficher() const;
  // Mode d'emploi :
  //    Quand appelée, affiche tout les trajets du catalogue
  // Contrat :
  //

  void RechercheParcours1(const char * VilleA, const char * VilleB) const;
  // Mode d'emploi :
  //    Quand appelée, affiche tout les trajets du catalogue allant de A à B
  // Contrat :
  //
  void RechercheParcoursAvecComposition(const char * VilleA, const char * VilleB) const;
  // Mode d'emploi :
  //    Quand appelée, affiche tout les trajets du catalogue allant de A à B
  // Contrat :
  //
  void AjouterTrajet(Trajet * Traj);
  // Mode d'emploi :
  //    Quand appelée, affiche tout les trajets du catalogue allant de A à B
  // Contrat :
  //

  //------------------------------------------------- Surcharge d'opérateurs
  Catalogue &operator=(const Catalogue &uCatalogue);
  // Mode d'emploi :
  //
  // Contrat :
  //

  //-------------------------------------------- Constructeurs - destructeur
  Catalogue(const Catalogue &uCatalogue);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

  virtual ~Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées
  void RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  //----------------------------------------------------- Attributs protégés
  // Le nombre de trajets enregistrés dans le catalogue
  int nbTrajets;
  // La capacité réservée par trajets
  int tailleTrajets;
  // Un tableau de pointeurs sur des Trajets
  Trajet **trajets;
};

//-------------------------------- Autres définitions dépendantes de Catalogue>

#endif // CATALOGUE_H
