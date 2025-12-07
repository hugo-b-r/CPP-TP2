/*************************************************************************
                           TestTrajetSimple  -  description
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
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
void TestTrajetSimple::TestTous()
{
    TestCreation();
    TestOperateurEgal();
    TestAfficherNonBords();
    TestIndependanceChar();
    TestVille();
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

void TestTrajetSimple::TestAfficherNonBords()
{
    Test::TestHeader("Afficher non-crash", "TrajetSimple");
    cout << "Affichage simple (vérification visuelle)" << endl;
    Test::etAffiche();

    TrajetSimple t1("Nice", "Marseille", "bus");
    TrajetSimple t2("Lyon", "Grenoble", "moto");

    // on appelle plusieurs fois pour s'assurer qu'il n'y a pas d'effet de bord
    t1.Afficher();
    t2.Afficher();
    t1.Afficher();
}

void TestTrajetSimple::TestIndependanceChar()
{
    Test::TestHeader("Indépendance des char", "TrajetSimple");
    cout << "Les chaînes originales modifiées après création ne doivent pas affecter l'objet" << endl;
    Test::etAffiche();

    char dep[20] = "Lille";
    char arr[20] = "Bruxelles";
    TrajetSimple *t = new TrajetSimple(dep, arr, "voiture");
    // on modifie les originaux
    strcpy(dep, "XXXX");
    strcpy(arr, "YYYY");

    // si la classe a copié les chaînes, l'affichage reste correct
    t->Afficher();
    delete t;
}

void TestTrajetSimple::TestVille()
{
    Test::TestHeader("Ville_Depart/Arrivee", "TrajetSimple");
    cout << "Vérifie que VilleDepart() et VilleArrivee() retournent les bonnes chaînes" << endl;
    Test::etAffiche();

    TrajetSimple ts("A", "B", "bus");
    if (ts.VilleDepart()=="A"){
      cout << "VilleDepart()   --> c'est bon" << endl;
    } else{
      cout << "VilleDepart()   -->  erreur, rend:"<< ts.VilleDepart() << "au lieu de 'A' " << endl;
    }
    if (ts.VilleArrivee()=="B"){
      cout << "VilleArrivee()   --> c'est bon" << endl;
    }else{
      cout << "VilleArrivee()   -->  erreur, rend:"<< ts.VilleArrivee() << "au lieu de 'B' " << endl;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
