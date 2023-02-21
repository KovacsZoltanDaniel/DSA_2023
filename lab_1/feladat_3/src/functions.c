//
// Created by Dani on 2023. 02. 14..
//

#include "../headers/functions.h"

float minimum(float x1, float x2, float x3) {
    if(x1<x2 && x1<x3)
        return x1;
    else if(x2<x3)
        return x2;
    else
        return x3;

}
