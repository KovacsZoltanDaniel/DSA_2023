//
// Created by Dani on 2023. 05. 28..
//

#ifndef INFO_A_MOVIE_H
#define INFO_A_MOVIE_H
#include <stdio.h>
#include <stdlib.h>
#include <constant.h>
#include <string.h>

enum Mufaj {HORROR, SCIFI, AKCIO, DRAMA};
typedef struct {
    char cim[30];
    int kiadasiEv;
    int hossz;
    enum Mufaj mufaj;
}Movie;
typedef struct Node{
    Movie info;
    struct Node *left, *right;
}Node;
Node *createNewNode(Movie new_data);
void printMovie(Movie movie);
char *getMufaj(enum Mufaj mufaj);
enum Mufaj getMufajByChar(char *mufaj);
#endif //INFO_A_MOVIE_H
