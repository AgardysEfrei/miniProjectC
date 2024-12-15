//
// Created by theo on 11/8/24.
//

#include "annuaire.h"
#include "gestion_fichier_dossier.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Creer_Enregistrement(annuaire_t *annuaire) {
    personne_t *new_contact = malloc(sizeof(personne_t));

    int nom;
    int i;
    do {
        i = 0;
        printf("Entrez votre nom de famille:");
        scanf("%s", new_contact->lastname);
        nom = 1;
        while (new_contact->lastname[i] != '\0') {
            if((new_contact->lastname[i] > 90 && new_contact->lastname[i] < 97) || new_contact->lastname[i] > 122 || new_contact->lastname[i] < 65) nom = 0;
            else if (i == 0 && new_contact->lastname[i] >= 97)new_contact->lastname[i] -= 32;
            else if (i > 0 && new_contact->lastname[i] <= 90)new_contact->lastname[i] += 32;
            i++;
        }
        fflush(stdin);
    }while(nom == 0);
    //append_fichier(new_contact->lastname);

    int prenom;
    do {
        i = 0;
        printf("Entrez votre prenom:");
        scanf("%s", new_contact->firstname);
        prenom = 1;
        while (new_contact->firstname[i] != '\0') {
            if((new_contact->firstname[i] > 90 && new_contact->firstname[i] < 97) || new_contact->firstname[i] > 122 || new_contact->firstname[i] < 65) prenom = 0;
            else if (i == 0 && new_contact->firstname[i] >= 97)new_contact->firstname[i] -= 32;
            else if (i > 0 && new_contact->firstname[i] <= 90)new_contact->firstname[i] += 32;
            i++;
        }
        fflush(stdin);
    }while(prenom == 0);
    //append_fichier(new_contact->firstname);


    int num;
    do{
        num = 1;
        i = 0;
        printf("Entrez votre numero de telephone:");
        scanf("%s", new_contact->phone);
        while(new_contact->phone[i] != '\0'){
            if(new_contact->phone[i] < 48 || new_contact->phone[i] > 57) num = 0;
            i++;
        }
        fflush(stdin);
    }while(num == 0);
    //append_fichier(new_contact->phone);

    int mail;
    do{
        mail = 0;
        i = 0;
        printf("Entrez votre email:");
        scanf("%s", new_contact->email);
        while(new_contact->email[i] != '\0'){
            if(new_contact->email[i] == 64) mail = 1;
            i++;
        }
        fflush(stdin);

    }while(mail == 0);
    //append_fichier(new_contact->email);

    if(annuaire->personne == NULL){
        annuaire->personne = new_contact;
    }
    else {
        annuaire_t * index = annuaire;
        annuaire_t *new = malloc(sizeof(annuaire_t ));
        new->personne = new_contact;
        new->next = NULL;
        while (index->next != NULL){
            index = index->next;
        }
        index->next = new;
    }
    printf("Votre contact a bien ete enregistre.\n");
}

void To_String(const personne_t *personne) {
        printf("%s %s\n"
               "Telephone: %s\n"
               "Email: %s\n",
               personne->firstname,
               personne->lastname,
               personne->phone,
               personne->email);
}

void Affiche_Repertoire(annuaire_t *annuaire) {
    annuaire_t * index = annuaire;
    int i = 1;
    if(index->personne == NULL){
        printf("L'annuaire est vide !");
    }
    else {
        while (index!= NULL) {
            printf("Contact %d:\n", i);
            To_String(index->personne);
            i++;
            index = index->next;
            printf("\n ");
        }
    }
}
void Recherche(annuaire_t *annuaire) {
    char nom[40];
    annuaire_t *index = annuaire;
    char is_found = 0;

    printf("Entrez un nom:");
    scanf("%s", nom);

    while(index != NULL) {
        if(strcmp(index->personne->lastname, nom) == 0) {
            is_found = 1;
            To_String(index->personne);
            break;
        }
        index = index->next;
    }
    if(!is_found)
        printf("Contact introuvable !\n");
}

void Supprimer(annuaire_t **annuaire) {
    char nom[40];
    annuaire_t * index = *annuaire;

    if(index == NULL){
        printf("Rien a supprimer. L'annuaire est vide.");
    }
    else {
        printf("Entrez le nom du contact a supprimer:");
        scanf("%s", nom);
        annuaire_t * prev = index;

        while (index != NULL){
            if (strcmp(index->personne->lastname, nom) == 0) {
                prev->next = index->next;
                index->next = NULL;
                free(index->personne);
                free(index);
                printf("Contact supprime.\n");
                return;
            }
            prev = index;
            index = index->next;
        }
    }
}