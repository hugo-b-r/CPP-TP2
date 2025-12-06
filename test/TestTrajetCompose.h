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
//
//
//------------------------------------------------------------------------

class TestTrajetCompose
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
