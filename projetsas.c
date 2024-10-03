
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int nbr = 10, choix, ajout, cont = 10;
typedef struct
{
    int id;
    char num[MAX];
    char prenom[MAX];
    char numerodetelephone[MAX];
    int age;
    char date[MAX];
    char statut[MAX]; //(validé, reporté, annulé, traité).
} Ajouter;
Ajouter a[MAX] = {  {1,"khalid","khalid","076487213",20,"valide","12/12/2024"},
                    {2,"Omar","lem","076487213",11,"reporte","12/1/2024"},
                    {3,"aziz","amzmiz","076487213",22,"valide","12/11/2024"},
                    {4,"khalid","lemagni","076487213",18,"traite","12/4/2025"},
                    {5,"abdo","hadoui","076487213",12,"annule","12/20/2024"},
                    {6,"hajar","intissar","076487213",36,"reporte","1/10/2024"},
                    {7,"kamal","legramme","076487213",56,"reporte","29/11/2024"},
                    {8,"aya","malki","076487213",47,"traite","1/3/2025"},
                    {9,"fatima","ouaziz","076487213",18,"valide","23/11/2024"},
                    {10,"khawla","ennair","076487213",33,"annule","20/6/2025"},
                };
void ajoute()
{
    int ajout;
    printf("antrer numbre de reservation a ajouter : ");
    scanf("%d", &ajout);
    for (int i = nbr; i < nbr + ajout; i++)
    {
        printf("Ajouter un num :");
        scanf(" %[^\n]", a[i].num);
        printf("Ajouter un prenom :");
        scanf(" %[^\n]", a[i].prenom);
        printf("Ajouter un numero de telephone :");
        scanf(" %[^\n]", a[i].numerodetelephone);
        printf("Ajouter age :");
        scanf(" %d", &a[i].age);
        printf("Ajouter un date :");
        scanf(" %[^\n]", a[i].date);
        a[i].id = ++cont;
        strcpy(a[i].statut, "valide");
    }
    nbr += ajout;
}

void Modifier()
{
    int index = Rechercher();
    if (index == -1)
    {
        printf("contacte pas Trouve");
        return;
    }
    printf("\nModification num: \n");
    scanf(" %[^\n]", a[index].num);
    printf("\nModification prenom: \n");
    scanf(" %[^\n]", a[index].prenom);
    printf("\nModification nobere telephone: \n");
    scanf(" %[^\n]", a[index].numerodetelephone);
    printf("\nModification age: \n");
    scanf("%d", a[index].age);
    printf("\nModification date: \n");
    scanf(" %[^\n]", a[index].date);
    int choix2;
    printf("\nModification statut \n");
    printf("1. valide\n");
    printf("2. reporte\n");
    printf("3. annule\n");
    printf("4. traite\n");
    scanf("%d", &choix2);
    switch (choix2)
    {
    case 1:
    {
        strcpy(a[index].statut, "valide");
    }
    break;
    case 2:
    {
        strcpy(a[index].statut, "reporte");
    }
    break;
    case 3:
    {
        strcpy(a[index].statut, "annule");
    }
    break;
    case 4:
    {
        strcpy(a[index].statut, "traite");
    }
    break;
    default:
        printf(" Choix Invalide");
    }
}
void Afficher()
{
    if (nbr == 0)
    {
        printf("pas de contactes dans Stock");
    }
    else
    {
        printf("===================== Afficher Le Stock ======================\n");
        for (int i = 0; i < nbr; i++)
        {
            printf("%s\n", a[i].num);
            printf("%s\n", a[i].prenom);
            printf("%s\n", a[i].numerodetelephone);
            printf("%d\n", a[i].age);
            printf("%s\n", a[i].date);
            printf("%d\n", a[i].id);
            printf("%s\n", a[i].statut);
        }
    }
}
void supprimer()
{
    int index = Rechercher();
    strcpy(a[index].num, a[index + 1].num);
    strcpy(a[index].prenom, a[index + 1].prenom);
    strcpy(a[index].numerodetelephone, a[index + 1].numerodetelephone);
    a[index].age = a[index + 1].age;
    strcpy(a[index].date, a[index + 1].date);
    a[index].id = a[index + 1].id;
    strcpy(a[index].statut, a[index + 1].statut);
    printf("contacte a ete Supprimer");
    nbr--;
}
int Rechercher()
{
    int chercher;
    int found = 0;
    printf("===================== Chercher Un contacte ======================\n");
    printf("id : ");
    scanf("%d", &chercher);
    for (int i = 0; i < nbr; i++)
    {
        if (chercher == a[i].id)
        {
            printf("---------- contacte est Trouve ----------\n");
            printf("%s\n", a[i].num);
            printf("%s\n", a[i].prenom);
            printf("%s\n", a[i].numerodetelephone);
            printf("%d\n", a[i].age);
            printf("%s\n", a[i].date);
            printf("%d\n", a[i].id);
            printf("%s\n", a[i].statut);
            found = 1;
            return i;
            break;
        }
    }
    if (!found)
        printf("contacte pas Trouve");

    return -1;
}
int Rechercherparnum()
{
    char chercher [MAX] ;
    int found = 0;
    printf("===================== Chercher Un contacte ======================\n");
    printf("num : ");
    scanf(" %[^\n]", &chercher);
    for (int i = 0; i < nbr; i++)
    {
        if (strcmp(a[i].num, chercher) == 0)
        {
            printf("---------- contacte est Trouve ----------\n");
            printf("%s\n", a[i].num);
            printf("%s\n", a[i].prenom);
            printf("%s\n", a[i].numerodetelephone);
            printf("%d\n", a[i].age);
            printf("%s\n", a[i].date);
            printf("%d\n", a[i].id);
            printf("%s\n", a[i].statut);
            found = 1;
            return i;
            break;
        }
    }
    if (!found)
        printf("contacte pas Trouve");

    return -1;
}
void statistiques()
{









}
void tri()
{









}
int main()
{
    do
    {
    mune:
        printf("\nMenu: \n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier ou supprimer une reservation\n");
        printf("3. Afficher les details d'une reservation\n");
        printf("4. Tri des reservations\n");
        printf("5. Recherche des reservations\n");
        printf("6. Statistiques\n");
        printf("7. Quitter\n");
        printf("Choix ? : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            system("cls");
            ajoute();
        }
        break;
        case 2:
        {
            system("cls");
            do
            {
                int choix1;
                printf("\nMenu: \n");
                printf("1. AModifier une reservation\n");
                printf("2. supprimer une reservation\n");
                printf("3. Menu pransepale\n");
                scanf("%d", &choix1);

                switch (choix1)
                {
                case 1:
                {
                    Modifier();
                }
                break;
                case 2:
                {
                    supprimer();
                }
                break;
                case 3:
                    goto mune;
                    break;
                default:
                    printf(" Choix Invalide");
                    break;
                }
            } while (choix < 3);
        }
        break;
        case 3:
        {
            system("cls");
            Afficher();
        }
        break;
        case 4:
        {
            system("cls");
            tri();
        }
        break;
        case 5:
        {
             system("cls");
            do
            {
                int choix3;
                printf("\nMenu: \n");
                printf("1. Rechercher par id \n");
                printf("2. Rechercher par num\n");
                printf("3. Menu pransepale\n");
                scanf("%d", &choix3);

                switch (choix3)
                {
                case 1:
                {
                   Rechercher();
                }
                break;
                case 2:
                {
                   Rechercherparnum();
                }
                break;
                case 3:
                    goto mune;
                    break;
                default:
                    printf(" Choix Invalide");
                    break;
                }
            } while (choix < 3);
        }
        break;
        case 6:
        {
            system("cls");
            statistiques();
        }
        break;
        case 7:
        {
            system("cls");
            return 1;
        }
        break;
        default:
            printf(" Choix Invalide");
            break;
        }
    } while (choix < 7);
    return 0;
}
