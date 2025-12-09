/*************************************************************************
                           TestTrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TestTrajetCompose> (fichier TestTrajetCompose.h) ----------------
#if ! defined ( TESTTRAJETCOMPOSE_H )
#define TESTTRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TestTrajetCompose>
// Test la classe <TrajetCompose>. Les tests choisis sont ceux considérés comme
// important. Il peut manquer quelques cas limites.
//
//
//------------------------------------------------------------------------

class TestTrajetCompose
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void TestTous();
    // Appelle tous les test de <TestTrajetCompose>


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

static void testOperateurEgal();

static void testCopie();

static void testAffiche();

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TestTrajetCompose>

#endif // TESTTRAJETCOMPOSE_H
