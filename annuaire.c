//
// Created by theo on 11/8/24.
//

#include "annuaire.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Creer_Enregistrement(cell_annuaire_t *annuaire) {
    personne_t *new_contact = malloc(sizeof(personne_t));

    printf("Entrez votre nom de famille: ");
    scanf(" %s", new_contact->lastname);

    printf("Entrez votre prenom: ");
    scanf(" %s", new_contact->firstname);

    printf("Entrez votre numero de telephone: ");
    scanf(" %s", new_contact->phone);

    printf("Entrez votre email: ");
    scanf(" %s", new_contact->email);

    if(annuaire->personne == NULL)
        annuaire->personne = new_contact;
    else {
        cell_annuaire_t *new = malloc(sizeof(cell_annuaire_t ));
        new->personne = new_contact;
        new->next = annuaire;
        annuaire = new;
    }
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

void Affiche_Repertoire(cell_annuaire_t *annuaire) {
    list_annuaire_t* index = malloc(sizeof(list_annuaire_t ));
    index->head = annuaire;
    int i = 1;
    if(index->head->personne == NULL){
        printf("L'annuaire est vide !");
    }
    else {
        while (index->head != NULL) {
            printf("Contact %d:\n", i);
            To_String(index->head->personne);
            i++;
            index->head = index->head->next;
        }
    }
}
void Recherche(cell_annuaire_t *annuaire) {
    char name[40];
    cell_annuaire_t *index = annuaire;
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

void Remove_first(cell_annuaire_t **annuaire) {
    cell_annuaire_t *new_head = (*annuaire)->next;
    free(*annuaire);
    *annuaire = new_head;
}

void Supprimer(cell_annuaire_t **annuaire) {
    char name[40];
    cell_annuaire_t *index = *annuaire;

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
        cell_annuaire_t *to_free = index->next;
        index->next = index->next->next;
        free(to_free);
    }
}