//
// Created by Vicen on 06/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_fichier_dossier.h"
void append_fichier(char* infos)
{
    FILE *file = fopen("../informations_personnes.txt","a");
    if(file == NULL){
        printf("Le fichier d'annuaire n'a pas pu etre ouvert");
    }
    else{
        if(ferror(file)){
            printf("L'annuaire n'a pas pu etre editer");
        }
        else {
            fprintf(file, "%s\n", infos);
            fclose(file);
        }
    }
}

char* see_fichier(){
    FILE *file = fopen("../informations_personnes.txt","r");
    char c;
    int taille=0;
    while ((c = fgetc(file)) != EOF) {  // Lire chaque caractère jusqu'à la fin du fichier
        taille+=1;
    }
    char *contenu = (char*)malloc((taille + 1) * sizeof(char));
    int indice=0;
    rewind(file);
    while ((c = fgetc(file)) != EOF) {  // Lire chaque caractère jusqu'à la fin du fichier
        contenu[indice]=c;
        indice++;
    }
    contenu[indice]='\0';
    fclose(file);  // Fermer le fichier
    return contenu;
}