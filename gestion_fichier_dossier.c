//
// Created by Vicen on 06/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_fichier_dossier.h"
void append_fichier(char* infos)
{
    FILE *file = fopen("informations_personnes","a");
    fprintf(file,infos+'\n');
    fclose(file);
}