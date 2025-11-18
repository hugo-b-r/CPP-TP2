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
        #Trajet * trajets
        #int nbTrajets
        
        +Catalogue()
        +Catalogue(const Catalog & c)
        +~Catalogue()
        +void Afficher() - OK
        +Catalogue RechercheParcours(Ville A, Ville B)
        +void AjouterTrajet(const Trajet traj)
    }

    class Trajet {
        +virtual char * VilleDepart()
        +virtual char * VilleArrivee()
        +virtual char * MoyenDeTransport()
        +virtual void Afficher()
    }

    
    class TrajetSimple {
        #char * villeDepart
        #char * villeArrivee
        #char * moyenDeTransport

        +Trajet()
        +~Trajet()
        +void Afficher() - OK

        +virtual char * VilleDepart() - OK
        +virtual char * VilleArrivee() - OK
        +virtual char * MoyendeTransport() - OK
    }
    Trajet-->TrajetSimple
    
    class TrajetCompose {
        #TrajetSimple * trajets
        #int nbTrajets

        +TrajetCompose()
        +~TrajetCompose()
        +void Afficher() - OK
        +virtual char * VilleDepart() - OK
        +virtual char * VilleArrivee() - OK
    }
    Trajet-->TrajetCompose


```
