/*************************************************************************
                           TestCatalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TestCatalogue> (fichier
//TestCatalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <cstring>
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TestCatalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TestCatalogue::TestTous()
// Algo:
{
  TestCatalogue::testAfficher();
  TestCatalogue::testRechercheParcours1();
  TestCatalogue::testRechercheParcours2();
  TestCatalogue::testAjouterTrajet();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void TestCatalogue::testAfficher() {
  cout << "--- TEST AFFICHER de Catalogue.cpp ---" << endl;
  cout << "Test 1:" << endl;
  cout << "    est censé afficher :" << endl;
  cout << "de Paris à Brest en Gateau" << "\r\n";
  Catalogue C1 = Catalogue();
  TrajetSimple *traj1 = new TrajetSimple("Paris", "Brest", "Gateau");
  C1.AjouterTrajet(traj1);
  cout << "    et affiche :" << endl;
  C1.Afficher();
  cout << "--------------------------------------" << endl;
}

void TestCatalogue::testRechercheParcours1()
// Algo:
{
  cout << "--- TEST Recherche de Parcours 1 de Catalogue.cpp ---" << endl;
  cout << "Test 1:" << endl;
  cout << "    est censé afficher :" << endl;
  cout << "1 : de Paris à Brest en Gateau" << std::endl;
  Catalogue C1 = Catalogue();

  TrajetSimple * traj1 = new TrajetSimple("Paris", "Brest", "Gateau");
  C1.AjouterTrajet(traj1);
  cout << "    et affiche :" << endl;
  C1.RechercheParcours1("Paris", "Brest");
}
void TestCatalogue::testRechercheParcours2()
// Algo:
{}
void TestCatalogue::testAjouterTrajet()
// Algo:
{}
