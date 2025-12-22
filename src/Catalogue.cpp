/*************************************************************************
                           Catalogue  -  une aggrégation de trajets dans
                           laquelle on peut chercher et ajouter des trajets et
                           afficher
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const int NB_TRAJET_DEFAUT_CATA = 10; // capacité par défaut du catalogue

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
// Affiche l'intégralité des trajets du catalogue dans l'ordre d'insertion
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Catalogue>" << endl;
#endif
    cout << "---------" << endl;
    cout << "Le catalogue comprend les trajets suivants : " << endl;
    for (int i =0; i< nbTrajets; i++){
        cout << " - ";
        trajets[i]->Afficher();
    } //----- Fin de Méthode
    cout << "---------" << endl;
}

void Catalogue::RechercheParcours1 ( const char * VilleA, const char * VilleB ) const
// Algorithme : Simple itération, si le départ et l'arrivée correspondent, alors on l'affiche
//
{
#ifdef MAP
    std::cout << "Appel à la méthode RechercheParcours1 de <Catalogue>" << std::endl;
#endif
    cout << "La recherche a trouvé les trajets suivants :" << endl;
    for (int i =0; i< nbTrajets; i++){
        if (!strcmp(trajets[i]->VilleDepart(), VilleA) && !strcmp(trajets[i]->VilleArrivee(), VilleB)){
            cout << " - ";
            trajets[i]->Afficher();
        }

    }
}

void Catalogue::RechercheParcoursAvecComposition ( const char * VilleA, const char * VilleB ) const
// Algorithme : cette fonction membre appelle seulement une autre fonction s'occupant de la récursion
// et alloue les tableaux dont elle a besoin pour fonctionner. Elle appelle avec la pile de récursion
// remplie d'un trajet pour limiter les cas dans la fonction de récursion
{
    #ifdef MAP
    std::cout << "Appel à la méthode RechercheParcoursAvecComposition de <Catalogue>" << std::endl;
    #endif
    // pour chaque indice, si le trajet est utilisé ou non par le trajet en construction
    bool * utilises = new bool[nbTrajets];
    // indices des trajets qui seront imbriqués pour faire le trajet que l'on teste
    int * ordre = new int[nbTrajets];
    // initialisation
    for (int i = 0; i < nbTrajets; i++) {
        utilises[i] = false;
        ordre[i] = -1;
    }

    // pour chaque trajet dont le départ correspond à la recherche, on lance la récursion
    cout << "La recherche a mené à ces résultats :" << endl;
    for (int i = 0; i < nbTrajets; i++) {
        if (strcmp(VilleA, trajets[i]->VilleDepart()) == 0) {
            utilises[i] = true;
            ordre[0] = i;
            RechercheParcoursAvecCompositionRecursion(VilleA, VilleB, ordre, utilises, 1);
            ordre[0] = -1;
            utilises[i] = false;
        }
    }


    delete[] ordre;
    delete[] utilises;

}

void Catalogue::RechercheParcoursAvecCompositionRecursion ( const char * VilleA, const char * VilleB, int * ordre, bool * utilises, int nbAjoutes) const
// Algorithme : Ajoute des trajets à la liste des utilises, les ajoute à ordre et si le trajet ajouté finit par VilleB, alors il affiche tout
//
{
    // si le chemin passé correspond
    if (strcmp(trajets[ordre[nbAjoutes-1]]->VilleArrivee(), VilleB) == 0) {
        cout << " - Un trajet avec correspondances a été trouvé, composé des trajets suivants :" << endl;
        for (int i = 0; i < nbAjoutes; i++) {
            cout << "   - ";
            trajets[ordre[i]]->Afficher();
        }
    // sinon si on peut encore tester d'autres trajets
    } else if (nbAjoutes < nbTrajets) {
        // si on a ajouté autant de trajets qu'il y en a et que ca ne mene pas à un trajet comme on le veut, ca ne sert à rien de continuer
        ++nbAjoutes;

        for (int i = 0; i < nbTrajets; i++) {
            // si non utilisé et ville de départ matche avec l'arrivée du chemin en construction
            if (!utilises[i] && strcmp(trajets[ordre[nbAjoutes-2]]->VilleArrivee(), trajets[i]->VilleDepart()) == 0) {

                // on fait la récursion une fois le chemin ajouté
                utilises[i] = true;
                ordre[nbAjoutes-1] = i;

                RechercheParcoursAvecCompositionRecursion(VilleA, VilleB, ordre, utilises, nbAjoutes);
                ordre[nbAjoutes-1] = -1;
                utilises[i] = false;
            }
        }
        --nbAjoutes;
    }
    // condition de sortie: on a etudie tous les trajets qui peuvent se suivre
}


void Catalogue::AjouterTrajet ( Trajet * traj )
// Ajoute un trajet au catalogue.
// Paramètre : traj - pointeur vers un trajet alloué dynamiquement (simple ou composé)
// Le tableau trajets est redimentionné quandd il faut
{
    #ifdef MAP
    std::cout << "Appel à l'ajout d'un trajet dans Catalogue" << std::endl;
    #endif

    trajets[nbTrajets] = traj->Clone();
    // si on a atteint la capacité, on réalloue une taille 2 fois plus grande
    // il y a une limite à cette solution : on ne réajuste jamais la taille du tableau
    // mais cela ne pose pas de problème car on ne supprime jamais un élément du catalogue
    if (nbTrajets == tailleTrajets) {
        tailleTrajets *= 2;
        Trajet ** newtrajets =  new Trajet*[tailleTrajets];
        // copie dans le nouveau tableau
        for (int i = 0; i < nbTrajets-1; i++) {
            newtrajets[i] = trajets[i];
        }
        delete[] trajets;
        trajets = newtrajets;
    }
    nbTrajets +=1;
}



StatutChargement Catalogue::Charger(string cheminFichier)
{
    ifstream f;
    f.open(cheminFichier, ios_base::in);
    if (!f.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutChargement::MAUVAIS_FICHIER;
    } else {
        // tant qu'on n'a pas atteint la fin du fichier
        while (f.peek() != EOF) {
            // si la ligne n'est pas vide
            if (f.peek() != '\n')
            {
                int nb = Trajet::LireNbEtapes(f);
                cout << "nb :" << nb << endl;
                if (nb == 1)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetSimple t (f, villeD, villeA);
                    AjouterTrajet(&t);
                } else if (nb > 1)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetCompose t (f, nb, villeD, villeA);
                    AjouterTrajet(&t);
                } else
                {
                    cerr << "Le fichier a un mauvais format" <<  endl;
                    return StatutChargement::MAUVAIS_FORMAT;
                }
            } else
            {
                f.get();
            }

        }
    }
    f.close();
    return StatutChargement::SUCCES;
}

StatutChargement Catalogue::ChargerTypeTrajet(string cheminFichier, TypeTrajet type)
{
    ifstream f;
    f.open(cheminFichier, ios_base::in);
    if (!f.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutChargement::MAUVAIS_FICHIER;
    } else {
        // tant qu'on n'a pas atteint la fin du fichier
        while (f.peek() != EOF) {
            if (f.peek() != '\n')
            {
                int nb = Trajet::LireNbEtapes(f);
                if (nb == 1 && type == TypeTrajet::SIMPLE)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetSimple t (f, villeD, villeA);
                    AjouterTrajet(&t);
                } else if (nb > 1 && type == TypeTrajet::COMPOSE)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetCompose t (f, nb, villeD, villeA);
                    AjouterTrajet(&t);
                } else if (nb >= 1) {
                    while (f.peek() != '\n')
                        f.get();
                } else
                {
                    cerr << "Le fichier a un mauvais format" <<  endl;
                    return StatutChargement::MAUVAIS_FORMAT;
                }
            } else
            {
                f.get();
            }

        }
    }
    f.close();
    return StatutChargement::SUCCES;
}

StatutChargement Catalogue::ChargerVilleDepartOuArrivee(string cheminFichier, string ville, bool depart)
{
    ifstream f;
    f.open(cheminFichier, ios_base::in);
    if (!f.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutChargement::MAUVAIS_FICHIER;
    } else {
        if (depart)
        {
            // tant qu'on n'a pas atteint la fin du fichier
            while (f.peek() != EOF) {
                if (f.peek() != '\n')
                {
                    int nb = Trajet::LireNbEtapes(f);
                    string villeD = Trajet::LireVilleDepart(f);
                    if (villeD == ville)
                    {
                        if (nb == 1) {
                            string villeA = Trajet::LireVilleArrivee(f);
                            TrajetSimple t (f, villeD, villeA);
                            AjouterTrajet(&t);
                        } else if (nb > 1) {
                            string villeA = Trajet::LireVilleArrivee(f);
                            TrajetCompose t (f, nb, villeD, villeA);
                            AjouterTrajet(&t);
                        } else if (nb >= 1) {
                            // saut de la ligne
                            while (f.peek() != '\n')
                                f.get();
                        } else {
                            cerr << "Le fichier a un mauvais format" <<  endl;
                            return StatutChargement::MAUVAIS_FORMAT;
                        }
                    } else {
                        // saut de la ligne
                        while (f.peek() != '\n')
                            f.get();
                    }
                } else {
                   // saut de la ligne
                    f.get();
                }
            }
        } else
        {

            // tant qu'on n'a pas atteint la fin du fichier
            while (f.peek() != EOF) {
                if (f.peek() != '\n')
                {
                    int nb = Trajet::LireNbEtapes(f);
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    if (villeA == ville)
                    {
                        if (nb == 1) {
                            TrajetSimple t (f, villeD, villeA);
                            AjouterTrajet(&t);
                        } else if (nb > 1) {
                            TrajetCompose t (f, nb, villeD, villeA);
                            AjouterTrajet(&t);
                        } else if (nb >= 1) {
                            // saut de la ligne
                            while (f.peek() != '\n')
                                f.get();
                        } else {
                            cerr << "Le fichier a un mauvais format" <<  endl;
                            return StatutChargement::MAUVAIS_FORMAT;
                        }
                    } else {
                        // saut de la ligne
                        while (f.peek() != '\n')
                            f.get();
                    }
                } else {
                   // saut de la ligne
                    f.get();
                }
            }

        }

    }
    f.close();
    return StatutChargement::SUCCES;
}

StatutChargement Catalogue::ChargerSelonSelection(string cheminFichier, int dep, int arrivee)
{
    ifstream f;
    f.open(cheminFichier, ios_base::in);
    int ligneActuelle = 0;
    if (!f.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutChargement::MAUVAIS_FICHIER;
    } else
    {
        // buffer inutile pour sauter les lignes
        while (ligneActuelle < dep)
        {
            // on va jusqu'à la fin de la ligne
            ++ligneActuelle;
            //saut de la ligne
            while (f.peek() != '\n')
                cout << f.get() << endl;
        }
        // tant qu'on n'a pas atteint la fin du fichier
        while (f.peek() != EOF && ligneActuelle < arrivee) {
            cout << ligneActuelle <<", ," << arrivee << endl;
            if (f.peek() != '\n')
            {
                int nb = Trajet::LireNbEtapes(f);
                if (nb == 1)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetSimple t (f, villeD, villeA);
                    AjouterTrajet(&t);
                    ++ligneActuelle;

                } else if (nb > 1)
                {
                    string villeD = Trajet::LireVilleDepart(f);
                    string villeA = Trajet::LireVilleArrivee(f);
                    TrajetCompose t (f, nb, villeD, villeA);
                    AjouterTrajet(&t);
                    ++ligneActuelle;

                } else if (nb >= 1)
                {
                    // saut de la ligne
                    while (f.peek() != '\n')
                        f.get();
                } else
                {
                    cerr << "Le fichier a un mauvais format" <<  endl;
                    return StatutChargement::MAUVAIS_FORMAT;
                }
            } else
            {
                f.get();
            }
        }
    }
    f.close();
    return StatutChargement::SUCCES;
}



StatutSauvegarde Catalogue::Sauvergarder(string cheminFichier)
{
    ofstream of;
    of.open(cheminFichier);
    if (!of.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutSauvegarde::MAUVAIS_FICHIER;
    } else
    {
        for (int i = 0; i < nbTrajets; i++)
        {
            trajets[i]->FormaterPourFichier(of);
        }
    }
    return StatutSauvegarde::SUCCES;
}

StatutSauvegarde Catalogue::SauvergarderTypeTrajet(string cheminFichier, TypeTrajet type)
{
    ofstream of;
    of.open(cheminFichier);
    if (!of.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutSauvegarde::MAUVAIS_FICHIER;
    } else
    {
        for (int i = 0; i < nbTrajets; i++)
        {

            if (trajets[i]->Type() == type) {
                trajets[i]->FormaterPourFichier(of);
            }
        }
    }
    return StatutSauvegarde::SUCCES;
}

StatutSauvegarde Catalogue::SauvergarderVilleDepartOuArrivee(string cheminFichier, string ville, bool depart)
{
    ofstream of;
    of.open(cheminFichier);
    if (!of.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutSauvegarde::MAUVAIS_FICHIER;
    } else
    {
        for (int i = 0; i < nbTrajets; i++)
        {
            if ((depart && strcmp(trajets[i]->VilleDepart(), ville.c_str()) == 0)
            || (!depart && strcmp(trajets[i]->VilleArrivee(), ville.c_str()) == 0)) {
                    trajets[i]->FormaterPourFichier(of);
                }
        }
    }
    return StatutSauvegarde::SUCCES;
}

StatutSauvegarde Catalogue::SauvergarderSelonSelection(string cheminFichier, int dep, int arrivee)
{
    ofstream of;
    of.open(cheminFichier);
    if (!of.is_open())
    {
        cerr << "Le fichier n'a pas pu être ouvert" <<  endl;
        return StatutSauvegarde::MAUVAIS_FICHIER;
    } else
    {
        for (int i = dep; i < arrivee; i++)
        {
            trajets[i]->FormaterPourFichier(of);
        }
    }
    return StatutSauvegarde::SUCCES;
}

//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme : simple copie en profondeur d'un Catalogue
{
    #ifdef MAP
        cout << "Appel à l'opérateur d'affectation (=) de <Catalogue>" << endl;
    #endif
    nbTrajets = unCatalogue.nbTrajets;
    tailleTrajets = unCatalogue.tailleTrajets;
    // copie en profondeus des trajets, en utilisant leur fonction membre de clonage
    trajets = new Trajet*[nbTrajets];
    for (int i = 0; i < unCatalogue.nbTrajets; i++) {
        this->trajets[i] = unCatalogue.trajets[i];
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue ) : nbTrajets(unCatalogue.nbTrajets), tailleTrajets(unCatalogue.tailleTrajets)
// Algorithme : simple copie en profondeur, en utilisant le clone de Trajets
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
    this->trajets = new Trajet*[tailleTrajets];
    for (int i = 0; i < nbTrajets; i++) {
        this->trajets[i] = unCatalogue.trajets[i]->Clone();
    }
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( ) : nbTrajets(0), tailleTrajets(NB_TRAJET_DEFAUT_CATA)
// Initialise la structure interne qui stocke des pointeurs vers les trajets
// Par défault ucun trajet n'est présent au départ
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    trajets = new Trajet*[NB_TRAJET_DEFAUT_CATA];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Suppression en profondeur
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    if (trajets) {
        for (int i = 0; i < nbTrajets; i++) {
            if (trajets[i])
                delete trajets[i];
        }
        delete[] trajets;
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
