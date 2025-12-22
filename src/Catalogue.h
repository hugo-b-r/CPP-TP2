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

// Différents types de résultat du chargement d'un fichier
// SUCCES: c'est une réussite, cela a bien fonctionné
// MAUVAIS_FORMAT : le fichier est trouvé mais son format n'est pas le bon
// MAUVAIS_FICHIER : le fichier n'est pas trouvé ou non accessible
enum class StatutChargement { SUCCES, MAUVAIS_FORMAT, MAUVAIS_FICHIER };

// Différents types de résultat du chargement d'un fichier
// SUCCES: c'est une réussite, cela a bien fonctionné
// MAUVAIS_FICHIER : le fichier n'est pas trouvé ou non accessible
enum class StatutSauvegarde { SUCCES, MAUVAIS_FICHIER };


//------------------------------------------------------------------------
// Rôle de la classe Catalogue>
// Catalogue est une collection ordonnée de Trajet dans laquelle on peut faire
// différents types de recherches, comme pour un itinéraire.
//
//------------------------------------------------------------------------

class Catalogue {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  void Afficher() const;
  // Mode d'emploi :
  //    Affichage sumpathique des trajets qui sont présents dans le catalogue
  // Contrat :
  //

  void RechercheParcours1(const char * VilleA, const char * VilleB) const;
  // Mode d'emploi :
  //    Rechercher parmis les trajets ceux dont la ville de départ est la même que VilleA et
  //    dont l'arrivée est la même que VilleB
  // Contrat :
  //

  void RechercheParcoursAvecComposition(const char * VilleA, const char * VilleB) const;
  // Mode d'emploi :
  //    Quand appelée, affiche tout les trajets du catalogue allant de A à B, en essayant aussi
  //    d'imbriquer les trajets entre eux quand cela est possible
  // Contrat :
  //

  void AjouterTrajet(Trajet * Traj);
  // Mode d'emploi :
  //    Ajoute un trajet dans le catalogue
  // Contrat :
  //  Le trajet reste à charge de l'utilisateur, le catalogue fait sa propre copie.

  //------------------------------------------------- Surcharge d'opérateurs
  Catalogue &operator=(const Catalogue &uCatalogue);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutChargement Charger(string cheminFichier);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutChargement ChargerTypeTrajet(string cheminFichier, TypeTrajet type);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutChargement ChargerVilleDepartOuArrivee(string cheminFichier, string ville, bool depart);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutChargement ChargerSelonSelection(string cheminFichier, int dep, int arrivee);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //


  StatutSauvegarde Sauvergarder(string cheminFichier);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutSauvegarde SauvergarderTypeTrajet(string cheminFichier, TypeTrajet type);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutSauvegarde SauvergarderVilleDepartOuArrivee(string cheminFichier, string ville, bool depart);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //

  StatutSauvegarde SauvergarderSelonSelection(string cheminFichier, int dep, int arrivee);
  // Mode d'emploi : copie en profondeur d'un catalogue
  //


  //-------------------------------------------- Constructeurs - destructeur
  Catalogue(const Catalogue &unCatalogue);
  // Mode d'emploi (constructeur de copie) :
  //


  Catalogue();
  // Mode d'emploi : construction d'un catalogue vide
  //

  virtual ~Catalogue();

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées
  void RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const;
  // Mode d'emploi : Fait la recherche de trajets qui s'imbriquent à partir de villes de départ (VilleA) et d'arrivée (VilleB).
  //
  // Contrat :
  //    ordre est un tableau de taille nbTrajets, utilises est un tableau de taille nbTrajets

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
