/*************************************************************************
                           TestCatalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TestCatalogue> (fichier TestCatalogue.h) ----------------
#if ! defined ( TESTCATALOGUE_H )
#define TESTCATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TestCatalogue>
// Test la classe Catalogue. Les tests choisis sont ceux considérés comme important.
// Il peut manquer quelques cas limites.
//
//------------------------------------------------------------------------

class TestCatalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void TestTous();
  // Mode d'emploi :
  //    Appelle tous les tests de catalogue
  // Contrat :
  //


//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

  static void testAfficher();
  // Mode d'emploi :
  //    Teste la fonction nafficher de catalogue
  // Contrat :
  static void testRechercheParcours1();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours1 de catalogue
  // Contrat :
  static void testRechercheParcoursAvecComposition();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours2 de catalogue
  // Contrat :
  //
  static void testRechercheParcoursAvecComposition2();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours1 de catalogue
  // Contrat :
  //
  static void testRechercheParcoursAvecComposition3();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours1 de catalogue
  // Contrat :
  //
  static void testRechercheParcoursAvecComposition4();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours1 de catalogue
  // Contrat :
  //
  static void testRechercheParcoursAvecComposition5();
  // Mode d'emploi :
  //    Teste la fonction recherche de parcours1 de catalogue
  // Contrat :
  //
  static void testAjouterTrajet();
  // Mode d'emploi :
  //    Teste la fonction d'ajout de traj de catalogue
  // Contrat :
  //
  static void testAjouterAucunTrajet();
  // Mode d'emploi :
  //    Test l'ajout d'aucun trajet
  // Contrat :
  //






//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestCatalogue>

#endif // TESTCATALOGUE_H
