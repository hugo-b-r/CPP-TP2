# TP 2 - Programmation en C++ - Bases

## Conception

Premier essai de modules du projet :

```mermaid

classDiagram
    class Catalogue {
        #Trajet * trajets
        #int nbTrajets
        
        +Catalogue()
        +Catalogue(const Catalog & c)
        +~Catalogue()
        +void Afficher()
        +Catalogue RechercheParcours(Ville A, Ville B)
        +void AjouterTrajet(const Trajet traj)
    }

    class TrajetSimple {
        #char * villeDepart
        #char * villeArrivee
        #char * moyenDeTransport

        +Trajet()
        +~Trajet()
        +void Afficher()
    }

    class TrajetMultiple {
        #TrajetSimple * trajets
        #int nbTrajets

        +TrajetMultiple()
        +~TrajetMultiple()
        +void Afficher()
    }


```

et avec des tests qui peuvent au futur ressembler à :
```mermaid
classDiagram
    class Test{
        +TestTous()
    }

    class TestTrajet {
        +TestTous()
        -int testCreerTrajet()
    }
    Test -->TestTrajet
    Test --> TestCatalogue
    class TestCatalogue {
        +TestTous()
        -int testAjouterTrajet()
        -int testRechercheParcours()
    }
```


Deuxieme version de modules du projet, qui sera celle utilisée:

```mermaid

classDiagram
    class Catalogue {
        #Trajet ** trajets
        #int nbTrajets
        #int tailleTrajets
        
        +Catalogue() - OK
        +Catalogue(const Catalog & c)
        +~Catalogue() - OK
        +void Afficher() - OK
        +void RechercheParcours1(const char * VilleA, const char * VilleB) const - OK
        +void RechercheParcoursAvecComposition(const char * VilleA, const char * VilleB) const
        -void RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const;
        +void AjouterTrajet(Trajet * traj) - OK
    }

    class Trajet {
        +Trajet ( const Trajet & unTrajet )
        +Trajet ( )
        +virtual ~Trajet ( )
        +virtual char * VilleDepart()
        +virtual char * VilleArrivee()
        +virtual void Afficher()
    }

    
    class TrajetSimple {
        #char * villeDepart
        #char * villeArrivee
        #char * moyenDeTransport

        +TrajetSimple(const TrajetSimple & unTrajetSimple)
        +TrajetSimple()  OK
        +virtual ~TrajetSimple() - OK
        +virtual char * VilleDepart() - OK
        +virtual char * VilleArrivee() - OK
        +virtual char * MoyendeTransport() - OK
        +virtual void Afficher () - OK
    }
    Trajet-->TrajetSimple
    
    class TrajetCompose {
        #TrajetSimple * trajets
        #int nbTrajets

        +TrajetCompose() - OK
        +TrajetCompose ( TrajetSimple * trajetsSimples, int taille_tableau )
        +TrajetCompose ( const TrajetCompose & unTrajetCompose )
        +virtual ~TrajetCompose() - OK
        +virtual void Afficher() - OK
        +virtual char * VilleDepart() - OK
        +virtual char * VilleArrivee() - OK
    }
    Trajet-->TrajetCompose


```

## To-do 

- [ ] Corriger l'algo complexe qui doit presque fonctionner
- [ ] Correctement documenter chaque classe et fonction, commenter
Si on a le temps:
- [ ] Rajouter tests TrajetCompose
- [ ] Rajoutertests TrajetSimple
- [ ] Rajoutertests TrajetSimple
- [ ] Checker la mémoire
