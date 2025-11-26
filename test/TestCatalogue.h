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
//
//
//------------------------------------------------------------------------

class TestCatalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void TestTous();
  // Mode d'emploi :
  //    Quand appelée, realise tout le test de catalogue
  // Contrat :
  //


//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    static void testAfficher();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio nafficher de catalogue
  // Contrat :
    static void testRechercheParcours1();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio recherche de parcours1 de catalogue
  // Contrat :
    static void testRechercheParcours2();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio recherche de parcours1 de catalogue
  // Contrat :
  //
    static void testAjouterTrajet();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonction d'ajout de traj de catalogue
  // Contrat :
  //




//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestCatalogue>

#endif // TESTCATALOGUE_H
