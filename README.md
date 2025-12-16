# TP 2 - Programmation en C++ - Bases

## Conception

Premier essai de modules du projet :


et avec des tests qui peuvent au futur ressembler à :
```mermaid
classDiagram
    class Test{
        +static void TestTous()
        +static void TestHeader(const char * nomTest, const char * nomClasse)
        +static void etAffiche()
    }
    Test --> TestCatalogue
    Test --> TestTrajetSimple
    Test --> TestTrajetCompose
    class TestCatalogue {
        +static void TestTous()
        #static void testAjouterTrajet()
        #static void testRechercheParcours()
        #static void testAfficher()
        #static void testRechercheParcours1()
        #static void testRechercheParcoursAvecComposition()
        #static void testRechercheParcoursAvecComposition2()
        #static void testRechercheParcoursAvecComposition3()
        #static void testRechercheParcoursAvecComposition4()
        #static void testRechercheParcoursAvecComposition5()
        #static void testAjouterTrajet()
        #static void testAjouterAucunTrajet()
    }
    class TestTrajetCompose {
        +static void TestTous()
        #static void testOperateurEgal()
        #static void testCopie()
        #static void testAffiche()
    }
    class TestTrajetSimple {
        +static void TestTous()
        #static void TestCreation()
        #static void TestOperateurEgal()
        #static void TestAfficherNonBords()
        #static void TestIndependanceChar()
        #static void TestVille()
    }
```


Deuxieme version de modules du projet, qui sera celle utilisée:

```mermaid

classDiagram
    class Trajet {
        +Trajet ( const Trajet & unTrajet )
        +Trajet ( )
        +virtual ~Trajet ( )
        +virtual char * VilleDepart()
        +virtual char * VilleArrivee()
        +virtual void Afficher()
        +virtual Trajet * Clone()
        +virtual ofstream FormaterPourFichier()
    }

    
    class TrajetSimple {
        #char * villeDepart
        #char * villeArrivee
        #char * moyenDeTransport

        +TrajetSimple(const TrajetSimple & unTrajetSimple)
        +TrajetSimple()
        +TrajetSimple( ifstream chaineFormatteeFichier )
        +virtual ~TrajetSimple()
        +virtual char * VilleDepart()
        +virtual char * VilleArrivee()
        +virtual char * MoyendeTransport()
        +virtual void Afficher ()
        +virtual Trajet * Clone()
        +ofstream FormaterPourFichier()
    }
    Trajet-->TrajetSimple
    
    class TrajetCompose {
        #TrajetSimple * trajets
        #int nbTrajets

        +TrajetCompose()
        +TrajetCompose ( TrajetSimple * trajetsSimples, int taille_tableau )
        +TrajetCompose ( const TrajetCompose & unTrajetCompose )
        +TrajetCompose ( ifstream chaineFormatteeFichier, int taille_tableau )
        +virtual ~TrajetCompose()
        +virtual void Afficher()
        +virtual char * VilleDepart()
        +virtual char * VilleArrivee()
        +virtual Trajet * Clone()
        +ofstream FormaterPourFichier()
    }
    Trajet-->TrajetCompose



```

```mermaid
classDiagram
    class Catalogue {
        #Trajet ** trajets
        #int nbTrajets
        #int tailleTrajets
        
        +Catalogue()
        +Catalogue(const Catalog & c)
        +~Catalogue()
        +void Afficher()
        +void RechercheParcours1(const char * VilleA, const char * VilleB) const
        +void RechercheParcoursAvecComposition(const char * VilleA, const char * VilleB) const
        -void RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const;
        +void AjouterTrajet(Trajet * traj)
        +void Charger(string cheminFichier)
        +void Sauvegarder(string cheminFichier)
    }

```
