/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Test> (fichier Test.h) ----------------
#if ! defined ( TEST_H )
#define TEST_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Test>
//  Rassemble l'appel de tous les tests de chacun des modules de test.
//
//------------------------------------------------------------------------

class Test
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void TestTous();
  // Mode d'emploi :
  //    Quand appelée, appelle tous les tests de chacun de modules
  // Contrat :
  //
  static void TestHeader(const char * nomTest, const char * nomClasse);
  // Utiliser cette fonction pour ajouter un header de test avec les bonnes couleurs
  //

  static void etAffiche();
  // Utiliser cette fonction pour ajouter en bonne couleur le texte de séparation
  // entre ce qui est attendu et ce qui est retourné par le test


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées




//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Test>

#endif // TEST_H
