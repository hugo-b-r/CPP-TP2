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
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestTrajetSimple.h"
#include "TrajetSimple.h"
#include "Test.h"



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
    TestCreation();
    TestOperateurEgal();
}

void TestTrajetSimple::TestCreation()
{
    Test::TestHeader("Afficher", "TrajetSimple");
    cout << "de Paris à Brest en pédalo"<< endl;
    Test::etAffiche();
    TrajetSimple *s = new TrajetSimple("Paris", "Brest", "pédalo");
    s->Afficher();
    delete s;
}

void TestTrajetSimple::TestOperateurEgal()
{
    Test::TestHeader("Operateur =", "TrajetSimple");
    cout << "de Paris à Brest en pédalo"<< endl;
    Test::etAffiche();
    TrajetSimple *s =new TrajetSimple("Paris", "Brest", "pédalo");
    TrajetSimple s2 = *s;
    delete s;
    s2.Afficher();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
