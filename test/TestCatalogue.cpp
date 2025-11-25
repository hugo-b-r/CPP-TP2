/*************************************************************************
                           TestCatalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TestCatalogue> (fichier TestCatalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TestCatalogue.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TestCatalogue::TestTous()
//Algo:
{
    this->testAfficher();
    this->testRechercheParcours1();
    this->testRechercheParcours2();
    this->testAjouterTrajet();

}


//------------------------------------------------- Surcharge d'opérateurs
TestCatalogue & TestCatalogue::operator = ( const TestCatalogue & unTestCatalogue )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TestCatalogue::TestCatalogue ( const TestCatalogue & unTestCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TestCatalogue>" << endl;
#endif
} //----- Fin de TestCatalogue (constructeur de copie)


TestCatalogue::TestCatalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TestCatalogue>" << endl;
#endif
} //----- Fin de TestCatalogue


TestCatalogue::~TestCatalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TestCatalogue>" << endl;
#endif
} //----- Fin de ~TestCatalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void TestCatalogue::testAfficher()
  {
    cout << "--- TEST AFFICHER de Catalogue.cpp ---" << endl;
    cout << "Test 1:" << endl;
    cout << "    est censé afficher :" << endl;
    cout << "de Paris à Brest en Gateau" << "\r\n";
    Catalogue C1 = Catalogue();
    TrajetSimple traj1 = TrajetSimple("Paris", "Brest", "Gateau");
    C1.AjouterTrajet(&traj1);
    cout << "    et affiche :" << endl;
    C1.Afficher();
  }

void TestCatalogue::testRechercheParcours1()
    //Algo:
    {
    cout << "--- TEST Recherche de Parcours 1 de Catalogue.cpp ---" << endl;
    cout << "Test 1:" << endl;
    cout << "    est censé afficher :" << endl;
    cout << "1 : de Paris à Brest en Gateau" << std::endl;
    Catalogue C1 = Catalogue();

    TrajetSimple traj1 = TrajetSimple("Paris","Brest","Gateau");
    C1.AjouterTrajet(&traj1);
    cout << "    et affiche :" << endl;
    C1.RechercheParcours1("Paris", "Brest");
    }
void TestCatalogue::testRechercheParcours2()
    //Algo:
    {}
void TestCatalogue::testAjouterTrajet()
    //Algo:
    {}
