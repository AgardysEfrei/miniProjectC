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

void reset_fichier() {
    FILE *file = fopen("../informations_personnes.txt","w");
    fclose(file);
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

annuaire_t* load_fichier(){
    char *contenu = see_fichier();
    annuaire_t *new = malloc(sizeof(annuaire_t ));
    annuaire_t **previous = malloc(sizeof(annuaire_t));
    new->personne = NULL;
    new->next = NULL;
    const char *delim="\n";
    if(contenu[0]=='\0') {
        free(contenu);
        return new;
    }
    char *token = strtok(contenu, delim);
    while(token != NULL) {
        personne_t *new_contact = malloc(sizeof(personne_t));
        strncpy(new_contact->firstname, token, strlen(token));
        new_contact->firstname[strlen(token)] = '\0';
        token = strtok(NULL, delim);
        strncpy(new_contact->lastname, token, strlen(token));
        new_contact->lastname[strlen(token)] = '\0';
        token = strtok(NULL, delim);
        strncpy(new_contact->phone, token, strlen(token));
        new_contact->phone[strlen(token)] = '\0';
        token = strtok(NULL, delim);
        strncpy(new_contact->email, token, strlen(token));
        new_contact->email[strlen(token)] = '\0';
        token = strtok(NULL, delim);
        if(new->personne == NULL) {
            new->personne=new_contact;
            new->next = NULL;
            previous=&new;
        }
        else {
            annuaire_t *new_new = malloc(sizeof(annuaire_t));
            new_new->personne=new_contact;
            new_new->next = NULL;
            (*previous)->next = new_new;
            annuaire_t *copy=new_new;
            previous = &copy;
        }
    }
    free(contenu);
    return new;
}