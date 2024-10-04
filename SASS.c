#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la structure  reservation
struct Reservation
{
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    char statut[20];
    char reference[20];
    char date[15];
};

// stocker  reservations
struct Reservation reservations[100];
int nombreReservations = 0;

// Fonction chonge  reference
void genererReference(char ref[])
{
    sprintf(ref, "ID-%d", rand() % 1000);
}

// 1: Fonction ajouter les reservation
void ajouterReservation()
{
    struct Reservation res;

    printf("Nom: ");
    scanf("%s", res.nom);
    printf("Prenom: ");
    scanf("%s", res.prenom);
    printf("Telephone: ");
    scanf("%s", res.telephone);
    printf("Âge: ");
    scanf("%d", &res.age);
    printf("Statut (valide, reporte, annule, traite): ");
    scanf("%s", res.statut);
    printf("Date (JJ-MM-AAAA): ");
    scanf("%s", res.date);

    genererReference(res.reference); //   la reference

    // Ajouter la reservation au tableau
    reservations[nombreReservations] = res;
    nombreReservations++;

    printf("Reservation ajoute reference : %s\n", res.reference);
}

// Fonction pour afficher les details d'une reservation
void afficherReservation(char reference[])
{
    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].reference, reference) == 0)
        {
            printf("\nDetails de la reservation :\n");
            printf("Nom : %s\n", reservations[i].nom);
            printf("Prenom : %s\n", reservations[i].prenom);
            printf("Telephone : %s\n", reservations[i].telephone);
            printf("Âge : %d\n", reservations[i].age);
            printf("Statut : %s\n", reservations[i].statut);
            printf("Date : %s\n", reservations[i].date);
            printf("Reference : %s\n", reservations[i].reference);
            return;
        }
    }
    printf("Reservation introuvable.\n");
}

// 3: Fonction pour supprimer une reservation
void supprimerReservation(char reference[])
{
    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].reference, reference) == 0)
        {
            // Decaler les elements dans le tableau pour supprimer la reservation
            for (int j = i; j < nombreReservations - 1; j++)
            {
                reservations[j] = reservations[j + 1];
            }
            nombreReservations--;
            printf("Reservation supprimee.\n");
            return;
        }
    }
    printf("Reservation introuvable.\n");
}

// 2:Fonction pour modifier une reservation
void modifierReservation(char reference[])
{
    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].reference, reference) == 0)
        {
            printf("Modifier les informations :\n");
            printf("Nom: ");
            scanf("%s", reservations[i].nom);
            printf("Prenom: ");
            scanf("%s", reservations[i].prenom);
            printf("Telephone: ");
            scanf("%s", reservations[i].telephone);
            printf("age: ");
            scanf("%d", &reservations[i].age);
            printf("Statut (valide, reporte, annule, traite): ");
            scanf("%s", reservations[i].statut);
            printf("Date (JJ-MM-AAAA): ");
            scanf("%s", reservations[i].date);

            printf("Reservation modifiee.\n");
            return;
        }
    }
    printf("Reservation introuvable.\n");
}

// 4 Fonction pour afficher toutes les reservations
void afficherToutesLesReservations()
{
    for (int i = 0; i < nombreReservations; i++)
    {
        printf("\nReservation %d :\n", i + 1);
        printf("Nom : %s\n", reservations[i].nom);
        printf("Prenom : %s\n", reservations[i].prenom);
        printf("Telephone : %s\n", reservations[i].telephone);
        printf("Âge : %d\n", reservations[i].age);
        printf("Statut : %s\n", reservations[i].statut);
        printf("Date : %s\n", reservations[i].date);
        printf("Reference : %s\n", reservations[i].reference);
    }
}

// Fonction pour inserer 10 reservations par defaut
void insererReservationsParDefaut()
{
    for (int i = 0; i < 10; i++)
    {
        struct Reservation res;
        sprintf(res.nom, "Nom%d", i);
        sprintf(res.prenom, "Prenom%d", i);
        sprintf(res.telephone, "0673731912%d", i);
        res.age = 25 + i;
        strcpy(res.statut, "valide");
        sprintf(res.date, "01-10-2024");
        genererReference(res.reference);

        reservations[nombreReservations] = res;
        nombreReservations++;
    }
    printf("10 reservations par defaut inserees.\n");
}
/// function trie/
void trierReservationsParNom()
{
    struct Reservation temp;
    for (int i = 0; i < nombreReservations - 1; i++)
    {
        for (int j = i + 1; j < nombreReservations; j++)
        {
            if (strcmp(reservations[i].nom, reservations[j].nom) > 0)
            {
                temp = reservations[i];
                reservations[i] = reservations[j];
                reservations[j] = temp;
            }
        }
    }
    printf("Reservations triees par nom.\n");
}
// statisique//
void afficherStatistiques()
{
    int total = nombreReservations;
    int valides = 0, reportees = 0, annulees = 0, traitee = 0;

    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].statut, "valide") == 0)
            valides++;
        else if (strcmp(reservations[i].statut, "reporte") == 0)
            reportees++;
        else if (strcmp(reservations[i].statut, "annule") == 0)
            annulees++;
        else if (strcmp(reservations[i].statut, "traite") == 0)
            traitee++;
    }

    printf("Statistiques des reservations :\n");
    printf("Total : %d\n", total);
    printf("Validees : %d\n", valides);
    printf("Reportees : %d\n", reportees);
    printf("Annulees : %d\n", annulees);
    printf("Traitee : %d\n", traitee);
}

// Fonction pour rechercher une reservation par reference
void rechercherReservationParReference(char reference[])
{
    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].reference, reference) == 0)
        {
            afficherReservation(reference);
            return;
        }
    }
    printf("Reservation non trouvee.\n");
}
// Fonction pour rechercher une reservation par nom
void rechercherReservationParNom(char nom[])
{
    int trouve = 0;
    for (int i = 0; i < nombreReservations; i++)
    {
        if (strcmp(reservations[i].nom, nom) == 0)
        {
            afficherReservation(reservations[i].reference);
            trouve = 1;
        }
    }
    if (!trouve)
    {
        printf("Aucune reservation trouvee pour le nom : %s\n", nom);
    }
}

// Menu principal
void menu()
{
    int choix;
    char nom[50];
    char reference[20];

    do
    {
        printf("\nMenu Principal :\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher une reservation\n");
        printf("5. Afficher toutes les reservations\n");
        printf("6. Trier les reservations par nom\n");
        printf("7. Afficher les statistiques\n");
        printf("8. Rechercher une reservation par reference\n");
        printf("9. Rechercher une reservation par nom\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterReservation();
            break;
        case 2:
            printf("Entrez la reference de la reservation a modifier : ");
            scanf("%s", reference);
            modifierReservation(reference);
            break;
        case 3:
            printf("Entrez la reference de la reservation à supprimer : ");
            scanf("%s", reference);
            supprimerReservation(reference);
            break;
        case 4:
            printf("Entrez la reference de la reservation à afficher : ");
            scanf("%s", reference);
            afficherReservation(reference);
            break;
        case 5:
            afficherToutesLesReservations();
            break;
        case 6:
            trierReservationsParNom();
            break;
        case 7:
            afficherStatistiques();
            break;
        case 8:
            printf("Entrez la reference de la reservation : ");
            scanf("%s", reference);
            rechercherReservationParReference(reference);
            break;
        case 9:
            printf("Entrez le nom : ");
            scanf("%s", nom);
            rechercherReservationParNom(nom);
            break;

        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

// Fonction principale
int main()
{
    insererReservationsParDefaut();
    menu();
    return 0;
}