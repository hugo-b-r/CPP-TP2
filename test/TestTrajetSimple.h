/*************************************************************************
                           TestTrajetSimple  -  description
                           /  -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
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
    static void TestTous();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    static void TestCreation();

    static void TestOperateurEgal();

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestTrajetSimple>

#endif // TESTTRAJETSIMPLE_H
