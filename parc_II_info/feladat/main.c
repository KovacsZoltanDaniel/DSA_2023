#include "movie.h"
#include "catalog.h"

int main() {
    //feladat 1
//   Movie favorite;
    char mufaj[20];
//    printf("olvasd be a kedvenc filmed cimet, kiadasi evet, hosszat es mufajat: ");
//    scanf("%s%i%i%s",favorite.cim, &favorite.kiadasiEv, &favorite.hossz, mufaj);
//    favorite.mufaj = getMufajByChar(mufaj);
//    printMovie(favorite);
    Node *root1 =NULL, *root2 = NULL;
    if(!freopen("movie.txt", "r", stdin)){
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    for (int i = 0; i < 3; ++i) {
        Movie movie;
        scanf("%[^\n]\n%i%i%s\n", movie.cim, &movie.hossz, &movie.kiadasiEv, mufaj);
        movie.mufaj = getMufajByChar(mufaj);
        root1 = insert1(root1, movie);
        root2 = insert2(root2,movie);
    }
    freopen("CON", "r", stdin);
    printf("az elso lista: \n");
    printMovies(root1);
    printf("masodik lista: \n");
    printMovies(root2);
//    printf("olvass be egy uj film adatait:  ");
//    Movie movie;
//    scanf("%[^\n]%i%i%s",movie.cim, &movie.hossz, &movie.kiadasiEv, mufaj);
//    movie.mufaj = getMufajByChar(mufaj);
//    ujFilm(root1,root2,movie);
//    printf("\naz elso lista: \n");
//    printMovies(root1);
//    printf("\nmasodik lista: \n");
//    printMovies(root2);
    Node *node = leghosszabb(root1);
    printf("\na leghosszabb film:\n");
    printMovies(node);
    node = keres(root2,"Avatar");
    printMovies(node);
    node = delete(root2,"Avatar");
    printMovies(node);
    return 0;
}
