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
            if((new_contact->lastname[i] > 'Z' && new_contact->lastname[i] < 'a') || new_contact->lastname[i] > 'z' || new_contact->lastname[i] < 'A') nom = 0;
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
            if((new_contact->firstname[i] > 'Z' && new_contact->firstname[i] < 'a') || new_contact->firstname[i] > 'z' || new_contact->firstname[i] < 'A') prenom = 0;
            else if (i == 0 && new_contact->firstname[i] >= 'a')new_contact->firstname[i] -= 32;
            else if (i > 0 && new_contact->firstname[i] <= 'Z')new_contact->firstname[i] += 32;
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
            if(new_contact->phone[i] < '0' || new_contact->phone[i] > '9') num = 0;
            i++;
        }
        fflush(stdin);
    }while(num == 0);
    //append_fichier(new_contact->phone);

    int mail;
    do{
        mail = 1;
        i = 0;
        printf("Entrez votre email:");
        scanf("%s", new_contact->email);
        while(new_contact->email[i] != '\0'){
            if(!(new_contact->email[i] == '@' || (new_contact->email[i] >= 'A' && new_contact->email[i] <= 'Z') || (new_contact->email[i] >= 'a' && new_contact->email[i] <= 'z'))) mail = 0;
            else if(new_contact->email[i] >= 'A' && new_contact->email[i] <= 'Z') new_contact->email[i] += 32;
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
    append_fichier(new_contact->firstname);
    append_fichier(new_contact->lastname);
    append_fichier(new_contact->phone);
    append_fichier(new_contact->email);
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
            printf("\nContact %d:\n", i);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Supprimer(annuaire_t **annuaire) {
    char nom[40];
    annuaire_t *index = *annuaire;
    annuaire_t *prev = NULL; // Pointer to track the previous node

    if (index == NULL) {
        printf("Rien a supprimer. L'annuaire est vide.\n");
        return;
    }

    printf("Entrez le nom du contact a supprimer: ");
    scanf("%s", nom);

    // Traverse the list to find the matching contact
    while (index != NULL) {
        if (index->personne != NULL && strcmp(index->personne->lastname, nom) == 0) {
            // Found the contact to delete
            if (prev == NULL) {
                // If deleting the head node
                *annuaire = index->next;
            } else {
                // Bypass the node in the list
                prev->next = index->next;
            }
            reset_fichier();
            for(annuaire_t *i = *annuaire; i != NULL; i = i->next) {
                append_fichier(i->personne->firstname);
                append_fichier(i->personne->lastname);
                append_fichier(i->personne->phone);
                append_fichier(i->personne->email);
            }

            // Free the node and its associated personne
            free(index->personne);
            free(index);

            printf("Contact '%s' supprime.\n", nom);
            return;
        }

        // Move to the next node
        prev = index;
        index = index->next;
    }

    // If no match is found
    printf("Contact avec le nom '%s' introuvable.\n", nom);
}
