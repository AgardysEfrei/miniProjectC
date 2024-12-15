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

typedef struct cell_annuaire {
    personne_t *personne;
    struct cell_annuaire *next;
}cell_annuaire_t;

void Creer_Enregistrement(cell_annuaire_t *annuaire);
void Affiche_Repertoire(cell_annuaire_t *annuaire);
void Recherche(cell_annuaire_t *annuaire);
void Supprimer(cell_annuaire_t **annuaire);


#endif //ANNUAIRE_H
