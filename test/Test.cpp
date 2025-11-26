/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Test> (fichier Test.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"
#include "TestCatalogue.h"
#include "TestTrajetCompose.h"
#include "TestTrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Test::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Test::TestTous() {
    TestCatalogue::TestTous();

    TestTrajetSimple::TestTous();
}


//------------------------------------------------- Surcharge d'opérateurs
Test & Test::operator = ( const Test & unTest )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Test::Test ( const Test & unTest )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Test>" << endl;
#endif
} //----- Fin de Test (constructeur de copie)


Test::Test ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Test>" << endl;
#endif
} //----- Fin de Test


Test::~Test ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Test>" << endl;
#endif
} //----- Fin de ~Test


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
