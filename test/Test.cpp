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
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Test.h"
#include "TestCatalogue.h"
#include "TestTrajetCompose.h"
#include "TestTrajetSimple.h"

//------------------------------------------------------------- Constantes

#ifdef COLORS
const char * debutBleu = "\033[34m";
const char * debutJaune = "\033[33m";
const char * finCouleur = "\033[0m";
#else
const char * debutBleu = "";
const char * debutJaune = "";
const char * finCouleur = "";
#endif
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Test::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Test::TestTous()
{
    TestCatalogue::TestTous();
    TestTrajetSimple::TestTous();
    TestTrajetCompose::TestTous();
}


void Test::TestHeader(const char * nomTest, const char * nomClasse) {
    cout << debutBleu <<"--- TEST " << nomTest <<" de " << nomClasse <<" ---\033[0m" << endl;
    cout << debutJaune <<"     est censé afficher :" << finCouleur << endl;
}


void Test::etAffiche() {
    cout << debutJaune <<"     et affiche :" << finCouleur << endl;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
