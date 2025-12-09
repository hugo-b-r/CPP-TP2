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
#include <cstring>

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
// Test la construction d'un TrajetSimple
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
// Test de plusieurs appels pour l'affichage
{
    Test::TestHeader("Afficher non-crash", "TrajetSimple");
    cout << "de Nice à Marseille en bus" << endl;
    cout << "de Lyon à Grenoble en moto" << endl;
    cout << "de Nice à Marseille en bus" << endl;
    Test::etAffiche();

    TrajetSimple t1("Nice", "Marseille", "bus");
    TrajetSimple t2("Lyon", "Grenoble", "moto");

    // on appelle plusieurs fois pour s'assurer qu'il n'y a pas d'effet de bord
    t1.Afficher();
    t2.Afficher();
    t1.Afficher();
}

void TestTrajetSimple::TestIndependanceChar()
// Teste si les chaines originales modifiées n'affectent pas la valeur de l'objets
{
    Test::TestHeader("Indépendance des char", "TrajetSimple");

    cout << "de Lille à Bruxelles en voiture" << endl;

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
// Vérifie que VilleDepart() et VilleArrivee() retournent les bonnes chaînes
{
    Test::TestHeader("Ville_Depart/Arrivee retournent les bonnes chaines", "TrajetSimple");
    cout << "VilleDepart()   --> c'est bon" << endl;
    cout << "VilleArrivee()   --> c'est bon" << endl;
    Test::etAffiche();

    TrajetSimple ts("A", "B", "bus");
    if (strcmp(ts.VilleDepart(), "A") == 0){
      cout << "VilleDepart()   --> c'est bon" << endl;
    } else{
      cout << "VilleDepart()   -->  erreur, rend: \""<< ts.VilleDepart() << "\" au lieu de \"A\" " << endl;
    }
    if (strcmp(ts.VilleArrivee(), "B") == 0){
      cout << "VilleArrivee()   --> c'est bon" << endl;
    } else {
      cout << "VilleArrivee()   -->  erreur, rend: \""<< ts.VilleArrivee() << "\" au lieu de \"B\" " << endl;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
