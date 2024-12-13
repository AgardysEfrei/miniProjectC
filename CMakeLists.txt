cmake_minimum_required(VERSION 3.29)
project(mini_projet_c C)

set(CMAKE_C_STANDARD 11)

add_executable(mini_projet_c main.c
        annuaire.h
        annuaire.c
        gestion_fichier_dossier.c
        gestion_fichier_dossier.h)
