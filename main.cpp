#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

void gen_permutations(char *laststring, char *insert, FILE * file);

char original[] = "123456789";
unsigned int length;

int main() {
    char start[2];

    FILE *myfile = fopen("nineFactorial.txt", "w");

    strncpy(start, original, 1);
    start[1] = '\0';
    length = strlen(original);
    gen_permutations(start, &original[1], myfile);
    fclose(myfile);
    return (0);
}


void gen_permutations(char * str, char * insert);

void gen_permutations(char *laststring, char *insert, FILE * file) {
    char newstring[30];
    int i, len;


    len = strlen(laststring);

    for (i = 0; i <= len; i++) {
        strncpy(newstring, laststring, i);
        newstring[i] = *insert;
        newstring[i + 1] = '\0';
        strcat(newstring, &laststring[i]);

        if (strlen(newstring) == length) {
            // printf("%s ", newstring);
            fprintf(file,"%s\n", newstring);

        } else
            gen_permutations(newstring, &original[len + 1], file);
    }
}
