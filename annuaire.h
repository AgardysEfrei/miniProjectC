//
// Created by theo on 11/8/24.
//

#ifndef ANNUAIRE_H
#define ANNUAIRE_H

typedef struct personne {
    char lastname[40];
    char firstname[40];
    char phone[40];
    char email[40];
}personne_t;

typedef struct annuaire {
    personne_t *personne;
    struct annuaire *next;
}annuaire_t;

void Creer_Enregistrement(annuaire_t *annuaire);
void Affiche_Repertoire(annuaire_t *annuaire);
void Recherche(annuaire_t *annuaire);
void Supprimer(annuaire_t **annuaire);


#endif //ANNUAIRE_H
