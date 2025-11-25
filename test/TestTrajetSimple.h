/*************************************************************************
                           TestTrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TestTrajetSimple> (fichier TestTrajetSimple.h) ----------------
#if ! defined ( TESTTRAJETSIMPLE_H )
#define TESTTRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TestTrajetSimple>
//
//
//------------------------------------------------------------------------

class TestTrajetSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    static void TestTous();

//------------------------------------------------- Surcharge d'opérateurs
    TestTrajetSimple & operator = ( const TestTrajetSimple & unTestTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TestTrajetSimple ( const TestTrajetSimple & unTestTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TestTrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TestTrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestTrajetSimple>

#endif // TESTTRAJETSIMPLE_H

