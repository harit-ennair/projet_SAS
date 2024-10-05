
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
    char statut[MAX];
    char date[MAX];
} Ajouter;
Ajouter a[MAX] = {
    {1, "khalid", "khalid", "076487213", 20, "valide", "12/12/2024"},
    {2, "Omar", "lem", "076487213", 11, "reporte", "12/1/2024"},
    {3, "aziz", "amzmiz", "076487213", 22, "valide", "12/11/2024"},
    {4, "khalid", "lemagni", "076487213", 18, "traite", "12/4/2025"},
    {5, "abdo", "hadoui", "076487213", 12, "annule", "12/20/2024"},
    {6, "hajar", "intissar", "076487213", 36, "reporte", "1/10/2024"},
    {7, "kamal", "legramme", "076487213", 56, "reporte", "29/11/2024"},
    {8, "aya", "malki", "076487213", 47, "traite", "1/3/2025"},
    {9, "fatima", "ouaziz", "076487213", 18, "valide", "23/11/2024"},
    {10, "khawla", "ennair", "076487213", 33, "annule", "20/6/2025"},
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
        printf("\n___________________________\n");
    }
    nbr += ajout;
}

int Rechercher()
{
    int chercher;
    int found = 0;
    printf("===================== Chercher Un reservation ======================\n");
    printf("id : ");
    scanf("%d", &chercher);
    for (int i = 0; i < nbr; i++)
    {
        if (chercher == a[i].id)
        {
            printf("---------- reservation est Trouve ----------\n");
            printf("=======================================\n");
            printf("num :%s\n", a[i].num);
            printf("prenom :%s\n", a[i].prenom);
            printf("numero de telephone :%s\n", a[i].numerodetelephone);
            printf("age :%d\n", a[i].age);
            printf("date :%s\n", a[i].date);
            printf("ID :%d\n", a[i].id);
            printf("statut :%s\n", a[i].statut);
            printf("=======================================\n");
            found = 1;
            return i;
            break;
        }
    }
    if (!found)
        printf("---------- reservation pas Trouve ----------");
    return -1;
}
int Rechercherparnum()
{
    char chercher[MAX];
    int found = 0;
    printf("===================== Chercher Un reservation ======================\n");
    printf("num : ");
    scanf(" %[^\n]", &chercher);
    for (int i = 0; i < nbr; i++)
    {
        if (strcmp(a[i].num, chercher) == 0)
        {
            printf("---------- reservation est Trouve ----------\n");
            printf("=======================================\n");
            printf("num :%s\n", a[i].num);
            printf("prenom :%s\n", a[i].prenom);
            printf("numero de telephone :%s\n", a[i].numerodetelephone);
            printf("age :%d\n", a[i].age);
            printf("date :%s\n", a[i].date);
            printf("ID :%d\n", a[i].id);
            printf("statut :%s\n", a[i].statut);
            printf("=======================================\n");
            found = 1;
            return i;
            break;
        }
    }
    if (!found)
        printf("----------reservation pas Trouve----------");

    return -1;
}
void Modifier()
{
    int index = Rechercher();
    if (index == -1)
    {
        printf("reservation pas Trouve");
        return;
    }
    printf("\nModification num: \n");
    scanf(" %[^\n]", a[index].num);
    printf("\nModification prenom: \n");
    scanf(" %[^\n]", a[index].prenom);
    printf("\nModification nobere telephone: \n");
    scanf(" %[^\n]", a[index].numerodetelephone);
    printf("\nModification age: \n");
    scanf("%d",& a[index].age);
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
        printf("Choix Invalide");
    }
}
void Afficher()
{
    if (nbr == 0)
    {
        printf("---------pas de reservation dans Stock---------");
    }
    else
    {
        printf("===================== Afficher Le Stock ======================\n");
        for (int i = 0; i < nbr; i++)
        {
            printf("=======================================\n");
            printf("num :%s\n", a[i].num);
            printf("prenom :%s\n", a[i].prenom);
            printf("numero de telephone :%s\n", a[i].numerodetelephone);
            printf("age :%d\n", a[i].age);
            printf("date :%s\n", a[i].date);
            printf("ID :%d\n", a[i].id);
            printf("statut :%s\n", a[i].statut);
            printf("=======================================\n");
        }
    }
}
void supprimer()
{
     int index = Rechercher();
    if (index == -1) {
    printf("Reservation pas Trouve\n");
    return;
    }
         for (int i = index; i < nbr - 1; i++) {
                a[i] = a[i + 1]; 
            }
            nbr--; 
    printf("--------- Reservation a ete supprime ---------\n");
}


void statistiques()
{
    do
    {
        int choix4;
        printf("\nStatistiques \n");
        printf("1. moyenne d'age des patients\n");
        printf("2. patients par tranche d'age\n");
        printf("3. Statistiques par statut\n");
        scanf("%d", &choix4);

        switch (choix4)
        {
        case 1:
        {
            if (nbr == 0)
            {
                printf("Aucun patient enregistre.\n");
                return;
            }
            int somme = 0;
            for (int i = 0; i < nbr; i++)
            {
                somme += a[i].age;
            }
            float moyenne = somme / nbr;
            printf("La moyenne d'age des patients est : %.2f ans\n", moyenne);
        }
        break;
        case 2:
        {
            if (nbr == 0)
            {
                printf("Aucun patient enregistre.\n");
                return;
            }
            int tra1 = 0, tra2 = 0, tra3 = 0;

            for (int i = 0; i < nbr; i++)
            {
                if (a[i].age <= 18)
                {
                    tra1++;
                    printf("===================minere====================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("==============================================\n");
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (a[i].age <= 35 && a[i].age > 18)
                {
                    tra2++;
                    printf("=====================june==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("==============================================\n");
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (a[i].age > 35)
                {
                    tra3++;
                    printf("=====================majere==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("==============================================\n");
                }
            }
            printf("Nombre de patients par tranche d'age :\n");
            printf("0-18 ans : %d\n", tra1);
            printf("19-35 ans : %d\n", tra2);
            printf("36 ans et plus : %d\n", tra3);
        }
        break;
        case 3:
            if (nbr == 0)
            {
                printf("Aucun patient enregistré.\n");
                return;
            }
            int valide = 0, reporte = 0, annule = 0, traite = 0;
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "valide") == 0)
                {
                    valide++;
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "reporte") == 0)
                {
                    reporte++;
                }
            }

            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "annule") == 0)
                {
                    annule++;
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "traite") == 0)
                {
                    traite++;
                }
            }

            printf("Statistiques par statut :\n");
            printf("Valide : %d\n", valide);
            printf("Reporte : %d\n", reporte);
            printf("Annule : %d\n", annule);
            printf("Traite : %d\n", traite);
            break;
        default:
            printf(" Choix Invalide");
            break;
        }
    } while (choix < 3);
}
void tri()
{
    do
    {

        int choix1;
        printf("\nTri des reservations \n");
        printf("1. tri par num\n");
        printf("2. tri par statut\n");
        scanf("%d", &choix1);

        switch (choix1)
        {
        case 1:
        {
                  for(int i=0 ; i<nbr ; i++){
                     for(int j=0 ; j<nbr-1-i ; j++){
                            if(strcasecmp (a[j].num,a[j+1].num)>0){
                                Ajouter cang = a[j];
                                     a[j] =  a[j+1];
                                   a[j+1] =  cang;
                            }
                        }
                    }
       for(int i=0 ; i<nbr ; i++){
                                    printf("=======================================\n");
                                    printf("num :%s\n", a[i].num);
                                    printf("prenom :%s\n", a[i].prenom);
                                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                                    printf("age :%d\n", a[i].age);
                                    printf("date :%s\n", a[i].date);
                                    printf("ID :%d\n", a[i].id);
                                    printf("statut :%s\n", a[i].statut);
                                    printf("=======================================\n");
        }
        }
        break;
        case 2:
        {

            if (nbr == 0)
            {
                printf("Aucun patient enregistré.\n");
                return;
            }
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "valide") == 0)
                {
                    printf("=====================valide==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("=============================================\n");
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "reporte") == 0)
                {
                    printf("=====================reportre==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("=============================================\n");
                }
            }

            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "annule") == 0)
                {

                    printf("=====================annule==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("=============================================\n");
                }
            }
            for (int i = 0; i < nbr; i++)
            {
                if (strcmp(a[i].statut, "traite") == 0)
                {
                    printf("=====================traite==================\n");
                    printf("num :%s\n", a[i].num);
                    printf("prenom :%s\n", a[i].prenom);
                    printf("numero de telephone :%s\n", a[i].numerodetelephone);
                    printf("age :%d\n", a[i].age);
                    printf("date :%s\n", a[i].date);
                    printf("ID :%d\n", a[i].id);
                    printf("statut :%s\n", a[i].statut);
                    printf("=============================================\n");
                }
            }
        }
        break;

        default:
            printf(" Choix Invalide");
            break;
        }
    } while (choix < 3);
}
int main()
{
    do
    {
    mune:

        printf("\n============= Menu de reservation ==============: \n");
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
                printf("\nModifier ou supprimer une réservation \n");
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
                    system("cls");
                    Rechercher();
                }
                break;
                case 2:
                {
                    system("cls");
                    Rechercherparnum();
                }
                break;
                case 3:
                    system("cls");
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

            return 0;
        }
        break;
        default:
            printf(" Choix Invalide");
            break;
        }
    } while (choix != 7);
    return 0;
}
