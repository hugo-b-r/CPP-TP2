/*************************************************************************
                           Calculateur d'itinéraires dans le cadre des TP C++ de 3IF à l'INSA de LYON
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

#include <iostream>
#include <cstring>

#include "Catalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

// nombre mximal de caractères dans les chaines qui sont des noms de villes
const int NB_CHAR_MAX_VILLE = 20; 

void AfficherMenu(bool afficher_menu)
{
    if (afficher_menu)
        std::cout << "Bienvenue dans ce calculateur d'itinéraire !" << std::endl;
    std::cout << "Vous avez le choix parmis les options suivantes:" << std::endl;
    std::cout << "(0) Construction du catalogue - ajouter des trajets au catalogue " << std::endl;
    std::cout << "(1) Affichage du catalogue courant" << std::endl;
    std::cout << "(2) Recherche de parcours" << std::endl;
    std::cout << "(3) Recherche de parcours constitué de plusieurs trajets enregistrés" << std::endl;
    std::cout << "(4) Quitter le logiciel" << std::endl;

}


void demanderAjoutTrajet(Catalogue & c)
{
    bool doitContinuer = true;
    while (doitContinuer) {
        int nb_villes = 0;
        int taille_tableau_trajets = 10;
        char * moyen = nullptr;
        char ** villes = new char*[taille_tableau_trajets];
        char * ville_tmp = nullptr;
        TrajetSimple * trajetsSimples = nullptr;
        
        
        std::cout << "(0) Ajouter une ville" << std::endl;
        std::cout << "(1) Définir le moyen de transport" << std::endl;
        std::cout << "(2) Enregistre le trajet définition/Sortie" << std::endl;
        int choix;
        std::cin >> choix;
        // on gère chacun des cas
        switch (choix) {
            case 0:
                // ajout d'une ville
                std::cout << "Nom de la ville ?" << std::endl;
                ville_tmp = new char[NB_CHAR_MAX_VILLE];
                std::cin >> ville_tmp;
                if (nb_villes < taille_tableau_trajets) {
                    villes[nb_villes] = ville_tmp;
                } else {
                    // on réalloue un tableau de taille 2*
                    taille_tableau_trajets *= 2;
                    char ** villesB = new char*[taille_tableau_trajets];
                    for (int i = 0; i < nb_villes; i++) {
                        villesB[i] = villes[i];
                    }
                    delete [] villes;
                    villes = villesB;

                }
                nb_villes++;
                delete[] ville_tmp;
                break;
            case 1:
                // Définition du moyen de transport
                moyen = new char[NB_CHAR_MAX_VILLE];
                std::cin >> moyen;
                break;
            case 2:
                if (nb_villes <2) {
                    std::cout << "Il faut au moins 2 villes pour créer un trajet !" <<std::endl,
                    std::cout << "Le trajet n'est pas enregistré, veuillez réessayer." << std::endl;
                } else if (!moyen) {
                    std::cout << "Vous devez préciser un moyen de transport !" << std::endl;
                    std::cout << "Le trajet n'est pas enregistré, veuillez réessayer." << std::endl;
                } else if (nb_villes == 2) {
                    // trajet simple
                    TrajetSimple trS(villes[0], villes[1], moyen);
                    c.AjouterTrajet(trS);
                    delete[] villes;
                    doitContinuer = false;
                } else {
                    // On crée un trajet composé
                    trajetsSimples = new TrajetSimple[nb_villes-1];
                    for (int i = 0; i < nb_villes-1; i++) {
                        TrajetSimple trS(villes[i], villes[i+1], moyen);
                        trajetsSimples[i] = trS;
                    }
                    TrajetCompose trC(trajetsSimples, nb_villes-1);
                    c.AjouterTrajet(trC);
                    delete[] villes;
                    delete[] trajetsSimples;
                    doitContinuer = false;
                }
                
                break;
        }
    }
    std::cout << "Quelle est la ville de départ ?" << std::endl;
    char * villeA = new char[NB_CHAR_MAX_VILLE];
    std::cin >> villeA;

    std::cout << "Quelle est la ville d'arrivée ?" << std::endl;
    char * villeB = new char[NB_CHAR_MAX_VILLE];
    std::cin >> villeB;

}

void demanderAfficher(const Catalogue & cata)
{
    cata.Afficher();
}

void demanderRechercheBasique( const Catalogue & cata)
{
    char buffer[1000];
    int len;

    std::cout << "Entrez le nom de la ville de départ : " << std::endl;
    std::cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];

    std::cout << "Entrez le nom de la ville d'arrivée: " << std::endl;
    std::cin >> buffer;
    len = strlen(buffer);
    char * villeB = new char[len + 1];

    cata.RechercheParcours1(villeA, villeB);
}


void demanderRechercheComplexe( const Catalogue & cata)
{
    char buffer[1000];
    int len;
    
    std::cout << "Entrez le nom de la ville de départ : " << std::endl;
    std::cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];

    std::cout << "Entrez le nom de la ville d'arrivée: " << std::endl;
    std::cin >> buffer;
    len = strlen(buffer);
    char * villeB = new char[len + 1];

    cata.RechercheParcours1(villeA, villeB);
}

int main() {

    bool doitContinuer = true;
    int choix;
    
    Catalogue cata;
    while (doitContinuer) {
        AfficherMenu(false);
        std::cin >> choix;
        switch (choix) {
            case 0:
                // ajout d'un trajet au catalogue
                demanderAjoutTrajet(cata);
                break;
            case 1:
                // Affichage du catalogue
                demanderAfficher(cata);
                break;
            case 2:
                // Recherche de parcous basique
                demanderRechercheBasique(cata);
                break;
            case 3:
                // Recherche de parcours imbriqués
                demanderRechercheComplexe(cata);
                break;
            case 4:
                // quitter le logiciel
                doitContinuer = false;
        }       break;
    }

    return 0;
}