/*************************************************************************
                           Calculateur d'itinéraires dans le cadre des TP C++ de 3IF à l'INSA de LYON
                             -------------------
    début                : 18/11/2025
    copyright            : (C) 2025 par Perrine Blouin-Lauvergne et Hugo Berthet-Rambaud
    e-mail               : perrine.blouin-lauvergne@insa-lyon.fr, brhugo@proton.me
*************************************************************************/

#include "Trajet.h"
#include <iostream>
using namespace std;
#include <cstring>

#include "Catalogue.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

// nombre mximal de caractères dans les chaines qui sont des noms de villes ou de moyen de transport
const int NB_CHAR_MAX_VILLE = 100;


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
    cout << "(4) Sauvegarder le catalogue" << endl;
    cout << "(5) Charger à la suite à partir d'un autre catalogue" << endl;
    cout << "(6) Quitter le logiciel" << endl;
}


void afficherModeInteractionFichier() {
    cout << "Quels sont vos critères ?" << endl;
    cout << "(0) Sans critère" << endl;
    cout << "(1) Selon le type de trajets" << endl;
    cout << "(2) Selon la ville de départ" << endl;
    cout << "(3) Selon la ville d'arrivée" << endl;
    cout << "(4) Selon une sélection (un intervalle) de trajet" << endl;
    cout << "(5) Abandonner" << endl;
}


void demanderAjoutTrajet(Catalogue & c)
// Algorithme
// On demande à 'utilisateur diverses actions qui pas à pas permettent de construire
// un trajet. Au moment de quitter, on regarde si les informations entrées sufficent
// à définir un trajet et on le crée. Sinon, on le mentionne à l'utilisateur
{
    bool doitContinuer = true;
    unsigned int nb_villes = 0;
    unsigned int taille_tableau_trajets = 10;
    char * moyen = nullptr;
    char ** villes = new char*[taille_tableau_trajets];
    char * ville_tmp = nullptr;
    TrajetSimple * trajetsSimples = nullptr;
    while (doitContinuer) {
        cout << "Actuellement " << nb_villes << " villes ajoutées" << endl;
        cout << "(0) Ajouter une ville" << endl;
        cout << "(1) Définir le moyen de transport" << endl;
        cout << "(2) Enregistre le trajet définition/Sortie" << endl;
        char choix;
        cin >> choix;
        cout << endl;
        // on gère chacun des cas
        switch (choix) {
            case '0':
                // ajout d'une ville
                cout << "Nom de la ville ?" << endl;
                ville_tmp = new char[NB_CHAR_MAX_VILLE];
                cin >> ville_tmp;
                if (nb_villes < taille_tableau_trajets) {
                    // copie du nom de la ville dans une variable de la bonne taille
                    villes[nb_villes] = new char[strlen(ville_tmp) + 1];
                    strcpy(villes[nb_villes], ville_tmp);
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
                nb_villes+=1;
                delete[] ville_tmp;
                break;
            case '1':
                // Définition du moyen de transport
                moyen = new char[NB_CHAR_MAX_VILLE];
                cout << "Nom du moyen de transport ?" << endl;
                cin >> moyen;
                break;
            case '2':
                if (nb_villes <2) {
                    cout << "Il faut au moins 2 villes pour créer un trajet !" <<endl,
                    cout << "Le trajet n'est pas enregistré, veuillez réessayer." << endl;
                } else if (!moyen) {
                    cout << "Vous devez préciser un moyen de transport !" << endl;
                    cout << "Le trajet n'est pas enregistré, veuillez réessayer." << endl;
                } else if (nb_villes == 2) {
                    // on crée le trajet simple
                    TrajetSimple *trS = new TrajetSimple(villes[0], villes[1], moyen);
                    c.AjouterTrajet(trS);
                    delete trS;
                    // puis on supprime la liste de ville dont on n'a plus besoin
                    for (unsigned int i = 0; i < nb_villes; i++) {
                        delete[] villes[i];
                    }
                    delete[] villes;
                    delete[] moyen;
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
                    delete trC;
                    // puis on supprme la liste de villes dont on n'a plus besoin
                    for (unsigned int i = 0; i < nb_villes; i++) {
                        delete[] villes[i];
                    }
                    delete[] villes;
                    delete[] trajetsSimples;
                    delete[] moyen;
                    doitContinuer = false;
                }
                break;
            default:
                cout << "Mauvaise entrée, veuillez recommencer" << endl;
                cout << endl;
                break;
        }
    }
}

void demanderRechercheBasique( const Catalogue & cata)
{
    char buffer[NB_CHAR_MAX_VILLE];
    int len;

    cout << "Entrez le nom de la ville de départ : " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];
    strcpy(villeA, buffer);

    cout << "Entrez le nom de la ville d'arrivée: " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeB = new char[len + 1];
    strcpy(villeB, buffer);

    cata.RechercheParcours1(villeA, villeB);
    delete[] villeA;
    delete[] villeB;
    cout << endl;
}


void demanderRechercheComplexe( const Catalogue & cata)
{
    char buffer[NB_CHAR_MAX_VILLE];
    int len;

    cout << "Entrez le nom de la ville de départ : " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeA = new char[len + 1];
    strcpy(villeA, buffer);


    cout << "Entrez le nom de la ville d'arrivée: " << endl;
    cin >> buffer;
    len = strlen(buffer);
    char * villeB = new char[len + 1];
    strcpy(villeB, buffer);

    cata.RechercheParcoursAvecComposition(villeA, villeB);
    delete[] villeA;
    delete[] villeB;
    cout << endl;
}

void demanderSauvegardeOuChargeSelonTypeTrajet(Catalogue& cata, string& chemin, bool chargement)
{
    bool doitContinuer = true;
    while (doitContinuer)  {
        cout << "Quel type de trajet ?" << endl;
        cout << "(0) TrajetSimple" << endl;
        cout << "(1)  TrajetCompose" << endl;
        int choix;
        cin >> choix;
        switch (choix)
        {
            case 0:
                if (chargement)
                    cata.ChargerTypeTrajet(chemin, TypeTrajet::SIMPLE);
                else
                    cata.SauvergarderTypeTrajet(chemin, TypeTrajet::SIMPLE);
                doitContinuer = false;
                break;
            case 1:
                if (chargement)
                    cata.ChargerTypeTrajet(chemin, TypeTrajet::COMPOSE);
                else
                    cata.SauvergarderTypeTrajet(chemin, TypeTrajet::COMPOSE);
                doitContinuer = false;
                break;
            default:
                cout << "Erreur de choix, le catalogue ne sera pas sauvegardé" << endl;
        }
    }
}

void demanderSauvegardeOuChargeSelonVille(Catalogue& cata, string& chemin, bool villeEstCelleDeDepart, bool chargement)
{
    string ville;
    if (villeEstCelleDeDepart)
        cout << "Quelle est la ville de départ qui servira de selecteur ?" << endl;
    else
        cout << "Quelle est la ville d'arrivée qui servira de selecteur ?" << endl;
    cin >> ville;
    if (chargement)
        cata.ChargerVilleDepartOuArrivee(chemin, ville, villeEstCelleDeDepart);
    else
        cata.SauvergarderVilleDepartOuArrivee(chemin, ville, villeEstCelleDeDepart);
}


void demanderSauvegardeOuChargeSelonSelection(Catalogue& cata, string& chemin, bool chargement)
{
    bool doitContinuer = true;
    while (doitContinuer)
    {
        int debut = 0, fin = 0;
        cout << "Quel est l'indice de début ?" << endl;
        cin >> debut;
        cout << "Quel est l'indice de fin ?" << endl;
        cin >> fin;

        if (fin <= debut)
        {
            cout << "l'indice de fin doit être inférieur à celui du début ! Recommencez" << endl;
        } else {
            doitContinuer = false;
            if (chargement)
                cata.ChargerSelonSelection(chemin, debut, fin);
            else
                cata.SauvergarderSelonSelection(chemin, debut, fin);
        }
    }
}



void demanderSauvegardeOuCharge(Catalogue& cata, bool chargement)
{

    // Nom et chemin du fichier vers lequel on sauvegarde
    if (chargement)
        cout << "Depuis quel fichier voulezz-vous charger ?";
    else
        cout << "Vers quel fichier voulez-vous sauvegarder ?";
    cout <<  "(chemin complet et extension de fichier, attention, il n'y a pas de vérification !)" << endl;

    string chemin = "";
    cin >> chemin;

    bool doitContinuer = true;
    while (doitContinuer)
    {
        // Mode de sauvegarde
        afficherModeInteractionFichier();
        int choix;
        cin >> choix;
        cout << endl;
        switch (choix) {
            // pas de critère
            case 0:
                cata.Sauvergarder(chemin);
                doitContinuer = false;
                break;
            // selon le type de trajet
            case 1:
                // Affichage du catalogue
                demanderSauvegardeOuChargeSelonTypeTrajet(cata, chemin, chargement);
                doitContinuer = false;
                break;
            // Selon la ville de départ
            case 2:
                demanderSauvegardeOuChargeSelonVille(cata, chemin, true, chargement);
                doitContinuer = false;
                break;
            // selon la ville d'arrivée
            case 3:

                demanderSauvegardeOuChargeSelonVille(cata, chemin, false, chargement);
                doitContinuer = false;
                break;
            // selon une sélection de trajets
            case 4:
                demanderSauvegardeOuChargeSelonSelection(cata, chemin, chargement);
                doitContinuer = false;
                break;
            case 5:
                cout << "Abandon" << endl;
                doitContinuer = false;
                break;
            default:
                cout << "vous n'avez pas entré le bon choix, veuillez recommencer" << endl;
                break;
        }
    }
}

int main() {

    bool doitContinuer = true;
    int choix;

    Catalogue cata;
    while (doitContinuer) {
        AfficherMenu(false);
        cin >> choix;
        cout << endl;
        switch (choix) {
            case 0:
                // ajout d'un trajet au catalogue
                demanderAjoutTrajet(cata);
                break;
            case 1:
                // Affichage du catalogue
                cata.Afficher();
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
                // Recherche de parcours imbriqués
                demanderSauvegardeOuCharge(cata, false);
                break;
            case 5:
                // Recherche de parcours imbriqués
                demanderSauvegardeOuCharge(cata, true);
                break;
            case 6:
                // quitter le logiciel
                doitContinuer = false;
                break;
        }
    }

    return 0;
}
