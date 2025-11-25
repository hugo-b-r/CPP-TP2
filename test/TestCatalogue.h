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
    void TestTous();
  // Mode d'emploi :
  //    Quand appelée, realise tout le test de catalogue
  // Contrat :
  //


//------------------------------------------------- Surcharge d'opérateurs
    TestCatalogue & operator = ( const TestCatalogue & unTestCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TestCatalogue ( const TestCatalogue & unTestCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TestCatalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TestCatalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void testAfficher();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio nafficher de catalogue
  // Contrat :
    void testRechercheParcours1();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio recherche de parcours1 de catalogue
  // Contrat :
    void testRechercheParcours2();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonctio recherche de parcours1 de catalogue
  // Contrat :
  //
    void testAjouterTrajet();
  // Mode d'emploi :
  //    Quand appelée, affiche des tests de la fonction d'ajout de traj de catalogue
  // Contrat :
  //




//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestCatalogue>

#endif // TESTCATALOGUE_H

