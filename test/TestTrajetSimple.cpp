/*************************************************************************
                           TestTrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TestTrajetSimple> (fichier TestTrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "TestTrajetSimple.h"

#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TestTrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TestTrajetSimple::TestTous()
{

}

//------------------------------------------------- Surcharge d'opérateurs
TestTrajetSimple & TestTrajetSimple::operator = ( const TestTrajetSimple & unTestTrajetSimple )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TestTrajetSimple::TestTrajetSimple ( const TestTrajetSimple & unTestTrajetSimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TestTrajetSimple>" << endl;
#endif
} //----- Fin de TestTrajetSimple (constructeur de copie)


TestTrajetSimple::TestTrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TestTrajetSimple>" << endl;
#endif
} //----- Fin de TestTrajetSimple


TestTrajetSimple::~TestTrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TestTrajetSimple>" << endl;
#endif
} //----- Fin de ~TestTrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

