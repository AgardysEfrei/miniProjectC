//
// Created by theo on 11/8/24.
//

#ifndef ANNUAIRE_H
#define ANNUAIRE_H

typedef struct personne {
    char *lastname;
    char *firstname;
    char *phone;
    char *email;
}personne_t;

typedef struct annuaire {
    personne_t *personne;
    struct annuaire *next;
}annuaire_t;

void Creer_Enregistrement(annuaire_t **annuaire);
void Affiche_Repertoire(annuaire_t *annuaire);
void Recherche(annuaire_t *annuaire);
void Supprimer(annuaire_t **annuaire);


#endif //ANNUAIRE_H
