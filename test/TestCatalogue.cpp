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

#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TestCatalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Test.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TestCatalogue::TestTous()
// Algo:
{
  testAfficher();
  testRechercheParcours1();
  testRechercheParcoursAvecComposition();
  testRechercheParcoursAvecComposition2();
  testRechercheParcoursAvecComposition3();
  testRechercheParcoursAvecComposition4();
  testRechercheParcoursAvecComposition5();
  testAjouterTrajet();
  testAjouterAucunTrajet();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void TestCatalogue::testAfficher() {
    Test::TestHeader("Afficher", "Catalogue");
  cout << "de Paris à Brest en Gateau" << "\r\n";
  Catalogue C1 = Catalogue();
  TrajetSimple *traj1 = new TrajetSimple("Paris", "Brest", "Gateau");
  C1.AjouterTrajet(traj1);
  Test::etAffiche();
  C1.Afficher();
}

void TestCatalogue::testRechercheParcours1()
// Algo:
{
  Test::TestHeader("Recherche Parcours 1", "Catalogue");
  cout << "1 : de Paris à Brest en Gateau" << std::endl;
  cout << "1 : de Paris à Brest en Voiture" << std::endl;
  Catalogue C1 = Catalogue();

  TrajetSimple * traj1 = new TrajetSimple("Paris", "Brest", "Gateau");
  C1.AjouterTrajet(traj1);
  traj1 = new TrajetSimple("Chambéry", "Lyon", "Bateau");
  C1.AjouterTrajet(traj1);
  traj1 = new TrajetSimple("Paris", "Brest", "Voiture");
  C1.AjouterTrajet(traj1);
  traj1 = new TrajetSimple("Paris", "Mest", "Gateau");
  C1.AjouterTrajet(traj1);

  Test::etAffiche();
  C1.RechercheParcours1("Paris", "Brest");
}

void TestCatalogue::testRechercheParcoursAvecComposition()
// Algo:
{
    Test::TestHeader(" Recherche parcours composes", "Catalogue");
    Catalogue C1 = Catalogue();
    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Paris", "Londres", "Voiture");
    TrajetSimple ts3 ("Londres", "Marseille", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose *t1 = new TrajetCompose(tab, 3);
    delete[] tab;
    C1.AjouterTrajet(t1);

    TrajetSimple ts12 ("Marseille", "Bruxelles", "Velo");
    TrajetSimple ts22 ("Bruxelles", "Nantes", "Voiture");
    TrajetSimple ts32 ("Nantes", "Rennes", "Train");
    tab = new TrajetSimple[3];
    tab[0] = ts12;
    tab[1] = ts22;
    tab[2] = ts32;
    t1 = new TrajetCompose(tab, 3);
    delete[] tab;
    C1.AjouterTrajet(t1);

    TrajetSimple *ts13 = new TrajetSimple ("Grenoble", "Paris", "Voiture");
    C1.AjouterTrajet(ts13);
    ts13 = new TrajetSimple ("Chambéry", "Rennes", "Voiture");
    C1.AjouterTrajet(ts13);
    // ce que le test doit afficher
    cout << "Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
    cout << "de Chambéry à Paris en Velo - de Paris à Londres en Voiture - de Londres à Marseille en Train - " << endl;
    cout << "de Marseille à Bruxelles en Velo - de Bruxelles à Nantes en Voiture - de Nantes à Rennes en Train - " << endl;
    cout << "Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
    cout << "De Chambéry à Rennes en Voiture" << endl;

    Test::etAffiche();
    // ce qu'il affiche vraiment
    C1.RechercheParcoursAvecComposition("Chambéry", "Rennes");

}


void TestCatalogue::testRechercheParcoursAvecComposition2()
// Algo: test de l'ajout d'un seul trajet compose et voir s'il est trouvé
{
    Test::TestHeader(" Recherche parcours composes n°2", "Catalogue");
    Catalogue C1 = Catalogue();
    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Paris", "Londres", "Voiture");
    TrajetSimple ts3 ("Londres", "Marseille", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose *t1 = new TrajetCompose(tab, 3);
    delete[] tab;
    C1.AjouterTrajet(t1);

    // ce que le test doit afficher
    cout << "Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
    cout << "de Chambéry à Paris en Velo - de Paris à Londres en Voiture - de Londres à Marseille en Train - " << endl;

    Test::etAffiche();
    // ce qu'il affiche vraiment
    C1.RechercheParcoursAvecComposition("Chambéry", "Marseille");

}


void TestCatalogue::testRechercheParcoursAvecComposition3()
// Algo: test de l'ajout d'un seul trajet compose et voir s'il n'est pas trouvé
{
    Test::TestHeader(" Recherche parcours composes n°3", "Catalogue");
    Catalogue C1 = Catalogue();
    TrajetSimple ts1 ("Chambéry", "Paris", "Velo");
    TrajetSimple ts2 ("Paris", "Londres", "Voiture");
    TrajetSimple ts3 ("Londres", "Marseille", "Train");
    TrajetSimple *tab = new TrajetSimple[3];
    tab[0] = ts1;
    tab[1] = ts2;
    tab[2] = ts3;
    TrajetCompose *t1 = new TrajetCompose(tab, 3);
    delete[] tab;
    C1.AjouterTrajet(t1);


    Test::etAffiche();
    // ce qu'il affiche vraiment
    C1.RechercheParcoursAvecComposition("Chambéry", "Rennes");

}


void TestCatalogue::testRechercheParcoursAvecComposition4()
// Algo: test de l'ajout d'un seul trajet simple et voir s'il est bien trouvé
{
    Test::TestHeader(" Recherche parcours composes n°4", "Catalogue");
    Catalogue C1 = Catalogue();
    TrajetSimple *ts1  = new TrajetSimple ("Chambéry", "Paris", "Velo");
    C1.AjouterTrajet(ts1);

    cout << "Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
    cout << "de Chambéry à Paris en Velo" << endl;


    Test::etAffiche();
    // ce qu'il affiche vraiment
    C1.RechercheParcoursAvecComposition("Chambéry", "Paris");
}



void TestCatalogue::testRechercheParcoursAvecComposition5()
// Algo: test de l'ajout d'un seul trajet simple et voir s'il n'est pas trouvé
{
    Test::TestHeader(" Recherche parcours composes n°5", "Catalogue");
    Catalogue C1 = Catalogue();
    TrajetSimple *ts1  = new TrajetSimple ("Chambéry", "Lyon", "Velo");
    C1.AjouterTrajet(ts1);


    Test::etAffiche();
    // ce qu'il affiche vraiment
    C1.RechercheParcoursAvecComposition("Chambéry", "Paris");
}




void TestCatalogue::testAjouterTrajet()
// Algo:
{
    Test::TestHeader("Ajouter Trajet", "Catalogue");
    cout << "de Paris à Brest en Gateau" << "\r\n";
    cout << "de Chambéry à Lyon en Vélo" << "\r\n";
    cout << "de Berlin à Berlin en Canapé" << "\r\n";
    Catalogue C1 = Catalogue();
    TrajetSimple *traj1;
    traj1 = new TrajetSimple("Paris", "Brest", "Gateau");
    C1.AjouterTrajet(traj1);
    traj1 = new TrajetSimple("Chambéry", "Lyon", "Vélo");
    C1.AjouterTrajet(traj1);
    traj1 = new TrajetSimple("Berlin", "Berlin", "Canapé");
    C1.AjouterTrajet(traj1);

    Test::etAffiche();
    C1.Afficher();
}

void TestCatalogue::testAjouterAucunTrajet()
// Algo:
{
    Test::TestHeader("Aucun ajout de trajet", "Catalogue");
    Catalogue C1 = Catalogue();
    Test::etAffiche();
    C1.Afficher();
}
