/*************************************************************************
                           TestTrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TestTrajetCompose> (fichier TestTrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TestTrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TestTrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TestTrajetCompose::TestTous()
{
    
}


//------------------------------------------------- Surcharge d'opérateurs
TestTrajetCompose & TestTrajetCompose::operator = ( const TestTrajetCompose & unTestTrajetCompose )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TestTrajetCompose::TestTrajetCompose ( const TestTrajetCompose & unTestTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TestTrajetCompose>" << endl;
#endif
} //----- Fin de TestTrajetCompose (constructeur de copie)


TestTrajetCompose::TestTrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TestTrajetCompose>" << endl;
#endif
} //----- Fin de TestTrajetCompose


TestTrajetCompose::~TestTrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TestTrajetCompose>" << endl;
#endif
} //----- Fin de ~TestTrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

