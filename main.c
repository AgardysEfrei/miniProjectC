#include <stdio.h>
#include <stdlib.h>

#include "annuaire.h"
#include "gestion_fichier_dossier.h"

int main() {
    char* chaine="oui";
    append_fichier(chaine);
    char* cont=see_fichier();
    printf("%s",cont);
    /*annuaire_t *annuaire = malloc(sizeof(struct annuaire));
    int fonctionnalite;
    while(1)
    {
        printf(" Que voulez vous faire ? :\n");
        printf("* Ajouter une personne (1)\n");
        printf("* Afficher le repertoire (2)\n");
        printf("* Realiser une recherche par nom (3)\n");
        printf("* Supprimer une personne par nom (4)\n");
        printf("* Quitter (5)\n");

        scanf("%d",&fonctionnalite);
        if (fonctionnalite ==1) Creer_Enregistrement(&annuaire);
        if (fonctionnalite ==2) Affiche_Repertoire(annuaire);
        if (fonctionnalite ==3) Recherche(annuaire);
        if (fonctionnalite ==4) Supprimer(&annuaire);
        if (fonctionnalite ==5) break;

        printf("\n");
        printf("\n");
    }

    printf("termine...");
    free(annuaire);*/
    return 0;
}
