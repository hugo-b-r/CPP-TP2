/*************************************************************************
                           Calculateur d'itinéraires dans le cadre des TP C++ de 3IF à l'INSA de LYON
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

#include <iostream>
using namespace std;
#include <cstring>

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

// nombre mximal de caractères dans les chaines qui sont des noms de villes
const int NB_CHAR_MAX_VILLE = 20;

void AfficherMenu(bool afficher_menu)
// Un simple affichage qui peut facilement être répété
{
    if (afficher_menu)
        cout << "Bienvenue dans ce calculateur d'itinéraire !" << endl;
    cout << "Vous avez le choix parmis les options suivantes:" << endl;
    cout << "(0) Construction du catalogue - ajouter des trajets au catalogue " << endl;
    cout << "(1) Affichage du catalogue courant" << endl;
    cout << "(2) Recherche de parcours" << endl;
    cout << "(3) Recherche de parcours constitué de plusieurs trajets enregistrés" << endl;
    cout << "(4) Quitter le logiciel" << endl;
}


void demanderAjoutTrajet(Catalogue & c)
// Algorithme
// On demande à 'utilisateur diverses actions qui pas à pas permettent de construire
// un trajet. Au moment de quitter, on regarde si les informations entrées sufficent
// à définir un trajet et on le crée. Sinon, on le mentionne à l'utilisateur
{
    bool doitContinuer = true;
    while (doitContinuer) {
        unsigned int nb_villes = 0;
        unsigned int taille_tableau_trajets = 10;
        char * moyen = nullptr;
        char ** villes = new char*[taille_tableau_trajets];
        char * ville_tmp = nullptr;
        TrajetSimple * trajetsSimples = nullptr;


        cout << "(0) Ajouter une ville" << endl;
        cout << "(1) Définir le moyen de transport" << endl;
        cout << "(2) Enregistre le trajet définition/Sortie" << endl;
        int choix;
        cin >> choix;
        // on gère chacun des cas
        switch (choix) {
            case 0:
                // ajout d'une ville
                cout << "Nom de la ville ?" << endl;
                ville_tmp = new char[NB_CHAR_MAX_VILLE];
                cin >> ville_tmp;
                if (nb_villes < taille_tableau_trajets) {
                    villes[nb_villes] = ville_tmp;
                } else {
                    // on réalloue un tableau de taille 2*
                    taille_tableau_trajets *= 2;
                    char ** villesB = new char*[taille_tableau_trajets];
                    for (unsigned int i = 0; i < nb_villes; i++) {
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
                cin >> moyen;
                break;
            case 2:
                if (nb_villes <2) {
                    cout << "Il faut au moins 2 villes pour créer un trajet !" <<endl,
                    cout << "Le trajet n'est pas enregistré, veuillez réessayer." << endl;
                } else if (!moyen) {
                    cout << "Vous devez préciser un moyen de transport !" << endl;
                    cout << "Le trajet n'est pas enregistré, veuillez réessayer." << endl;
                } else if (nb_villes == 2) {
                    // trajet simple
                    TrajetSimple *trS = new TrajetSimple(villes[0], villes[1], moyen);
                    c.AjouterTrajet(trS);
                    delete[] villes;
                    doitContinuer = false;
                } else {
                    // On crée un trajet composé
                    trajetsSimples = new TrajetSimple[nb_villes-1];
                    for (unsigned int i = 0; i < nb_villes-1; i++) {
                        TrajetSimple trS = TrajetSimple(villes[i], villes[i+1], moyen);
                        trajetsSimples[i] = trS;
                    }
                    TrajetCompose *trC = new TrajetCompose(trajetsSimples, nb_villes-1);
                    c.AjouterTrajet(trC);
                    delete[] villes;
                    delete[] trajetsSimples;
                    doitContinuer = false;
                }

                break;
        }
    }
    cout << "Quelle est la ville de départ ?" << endl;
    char * villeA = new char[NB_CHAR_MAX_VILLE];
    cin >> villeA;

    cout << "Quelle est la ville d'arrivée ?" << endl;
    char * villeB = new char[NB_CHAR_MAX_VILLE];
    cin >> villeB;

}

void demanderAfficher(const Catalogue & cata)
{
    cata.Afficher();
}

void demanderRechercheBasique( const Catalogue & cata)
{
    char buffer[1000];
    int len;

    cout << "Entrez le nom de la ville de départ : " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];

    cout << "Entrez le nom de la ville d'arrivée: " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeB = new char[len + 1];

    cata.RechercheParcours1(villeA, villeB);
}


void demanderRechercheComplexe( const Catalogue & cata)
{
    char buffer[1000];
    int len;

    cout << "Entrez le nom de la ville de départ : " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];

    cout << "Entrez le nom de la ville d'arrivée: " << endl;
    cin >> buffer;
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
        cin >> choix;
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
