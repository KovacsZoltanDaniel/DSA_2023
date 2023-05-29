//
// Created by Dani on 2023. 05. 28..
//

#ifndef INFO_A_CATALOG_H
#define INFO_A_CATALOG_H
#include "movie.h"
#include <stdbool.h>

Node *insert1(Node *node, Movie key);
Node *insert2(Node *node, Movie key);
void printMovies(Node *root);
void ujFilm(Node *root1, Node *root2, Movie key);
Node *leghosszabb(Node *node);
Node *keres(Node *root, char *cim);
Node *delete(Node *root, char *cim);
Node *minValueNode(Node *node);


#endif //INFO_A_CATALOG_H
