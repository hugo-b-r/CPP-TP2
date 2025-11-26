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
//
//
//------------------------------------------------------------------------

class Test
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static void TestTous();
  // Mode d'emploi :
  //    Quand appelée, realise tout le test de catalogue
  // Contrat :
  //
  static void TestHeader(const char * nomTest, const char * nomClasse);
  // Utiliser cette fonction pour ajouter un header de tes

  static void etAffiche();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées




//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Test>

#endif // TEST_H
