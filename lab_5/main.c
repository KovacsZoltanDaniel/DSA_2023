#include "stack.h"

int main() {
    char postfix[80] = "2 5 3 6 + * * 15 / 2 - 7";
    Stack verem;
    int capacity = strlen(postfix);
    createStack(capacity, &verem);
    char s[7] = " +-*/%";
    char *token;
    token = strtok(postfix," ");
    while( token != NULL){
        if(strstr(token,s)){
            
        }
        token = strtok(NULL, " ");

    }
    return 0;
}
