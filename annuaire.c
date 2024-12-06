//
// Created by theo on 11/8/24.
//

#include "annuaire.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Creer_Enregistrement(annuaire_t **annuaire) {
    personne_t *new_contact = malloc(sizeof(personne_t));
    char lastname[40];
    char firstname[40];
    char phone[40];
    char email[40];

    printf("Entrez votre nom de famille: ");
    scanf(" %s", lastname);
    new_contact->lastname = lastname;

    printf("Entrez votre prénom: ");
    scanf(" %s", firstname);
    new_contact->firstname = firstname;

    printf("Entrez votre numéro de téléphone: ");
    scanf(" %s", phone);
    new_contact->phone = phone;

    printf("Entrez votre email: ");
    scanf(" %s", email);
    new_contact->email = email;

    if((*annuaire)->personne == NULL)
        (*annuaire)->personne = new_contact;
    else {
        annuaire_t *new = malloc(sizeof(annuaire_t));
        new->personne = new_contact;
        new->next = *annuaire;
        *annuaire = new;
    }
}

void To_String(const personne_t *personne) {
    printf("%s %s\n"
               "Téléphone: %s\n"
               "Email: %s\n",
               personne->firstname,
               personne->lastname,
               personne->phone,
               personne->email);
}

void Affiche_Repertoire(annuaire_t *annuaire) {
    annuaire_t *index = annuaire;
    int i = 1;
    while(index != NULL) {
        printf("Contact %d:\n", i);
        To_String(index->personne);
        i++;
        index = index->next;
    }
}
void Recherche(annuaire_t *annuaire) {
    char name[40];
    annuaire_t *index = annuaire;
    char is_found = 0;

    printf("Entrez un nom: ");
    scanf(" %s", name);

    while(index != NULL) {
        if(strcmp(index->personne->lastname, name) == 0) {
            is_found = 1;
            To_String(index->personne);
            break;
        }
        index = index->next;
    }
    if(!is_found)
        printf("Contact introuvable !\n");
}

void Remove_first(annuaire_t **annuaire) {
    annuaire_t *new_head = (*annuaire)->next;
    free(*annuaire);
    *annuaire = new_head;
}

void Supprimer(annuaire_t **annuaire) {
    char name[40];
    annuaire_t *index = *annuaire;

    printf("Entrez un nom: ");
    scanf(" %s", name);

    if(strcmp(index->personne->lastname, name) == 0) {
        Remove_first(annuaire);
        return;
    }

    while(index->next != NULL &&  strcmp(index->next->personne->lastname, name) != 0)
        index = index->next;

    if (index->next == NULL)
        printf("Contact introuvable !\n");
    else if (index->next->next == NULL) {
        free(index->next);
        index->next = NULL;
    }
    else {
        annuaire_t *to_free = index->next;
        index->next = index->next->next;
        free(to_free);
    }
}