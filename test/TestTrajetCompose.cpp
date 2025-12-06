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
#include "TrajetSimple.h"
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TestTrajetCompose.h"
#include "TrajetCompose.h"
#include "Test.h"

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

    testOperateurEgal();

    testCopie();

    testAffiche();
}

void TestTrajetCompose::testOperateurEgal()
{
    Test::TestHeader("Test opérateur =", "TrajetCompose");

    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Grenoble", "Paris", "Voiture");
    TrajetSimple ts3 ("Marseille", "Paris", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose t1(tab, 3);

    TrajetCompose t2 = t1;
    cout << "de Chambéry à Paris en Velo - ";
    cout << "de Grenoble à Paris en Voiture - ";
    cout << "de Marseille à Paris en Train - ";
    cout << endl;

    Test::etAffiche();
    t2.Afficher();
    delete[] tab;
}

void  TestTrajetCompose::testCopie()
{
    Test::TestHeader("Test constructeur de copie", "TrajetCompose");
    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Grenoble", "Paris", "Voiture");
    TrajetSimple ts3 ("Marseille", "Paris", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose t1(tab, 3);
    TrajetCompose t2(t1);
    delete[] tab;
    cout << "de Chambéry à Paris en Velo - ";
    cout << "de Grenoble à Paris en Voiture - ";
    cout << "de Marseille à Paris en Train - ";
    cout << endl;
    Test::etAffiche();
    t2.Afficher();
}

void TestTrajetCompose::testAffiche()
{
    Test::TestHeader("Test affichage et construction", "TrajetCompose");

    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Grenoble", "Paris", "Voiture");
    TrajetSimple ts3 ("Marseille", "Paris", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose t1(tab, 3);
    delete[] tab;
    cout << "de Chambéry à Paris en Velo - ";
    cout << "de Grenoble à Paris en Voiture - ";
    cout << "de Marseille à Paris en Train - ";
    cout << endl;


    Test::etAffiche();
    t1.Afficher();
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
