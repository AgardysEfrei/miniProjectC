#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "annuaire.h"

int main() {
    cell_annuaire_t *annuaire = malloc(sizeof(struct cell_annuaire));
    annuaire->personne = NULL;
    annuaire->next = NULL;
    int fonctionnalite;
    while(1)
    {
        printf(" Que voulez vous faire :\n");
        printf("* Ajouter une personne (1)\n");
        printf("* Afficher le repertoire (2)\n");
        printf("* Realiser une recherche par nom (3)\n");
        printf("* Supprimer une personne par nom (4)\n");
        printf("* Quitter (5)\n");

        scanf("%d",&fonctionnalite);

        if (fonctionnalite ==1){
            Creer_Enregistrement(annuaire);
            sleep(3);
        }
        if (fonctionnalite ==2){
            Affiche_Repertoire(annuaire);
            sleep(3);
        }
        if (fonctionnalite ==3){
            Recherche(annuaire);
            sleep(3);
        }
        if (fonctionnalite ==4){
            Supprimer(&annuaire);
            sleep(3);
        }
        if (fonctionnalite ==5) break;

        printf("\n");
    }

    printf("termine...");
    free(annuaire);
    return 0;
}
