//
// Created by Dani on 2023. 05. 28..
//

#include "movie.h"

Node *createNewNode(Movie new_data) {
    Node * new_node = malloc(sizeof(Node));
    if(!new_node){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    new_node->info = new_data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

char *getMufaj(enum Mufaj mufaj) {
    switch (mufaj) {
        case DRAMA : {
            return "DRAMA";
            break;
        }
        case AKCIO : {
            return "AKCIO";
            break;
        }case HORROR : {
            return "HORROR";
            break;
        }case SCIFI : {
            return "SCIFI";
            break;
        }
        default:{
            return "ERROR";
        }
    }
}

enum Mufaj getMufajByChar(char *mufaj) {
    for (int i = 0; i < 4; ++i) {
        if(strcmp(getMufaj(i), mufaj) == 0){
            return i;
        }
    }
    return 0;
}

void printMovie(Movie movie) {
    printf("Cim: %s\n", movie.cim);
    printf("Kiadasi ev: %i\n", movie.kiadasiEv);
    printf("Hossza: %i\n", movie.hossz);
    printf("Mufaj: %s\n", getMufaj(movie.mufaj));
    printf("\n");
}
