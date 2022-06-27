#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){

    FILE *p = fopen("input1.txt","r");

    int input[7];

    fscanf(p, "%ls", &input[0]);
    fscanf(p, "%ls", &input[1]);
    printf("%ls", &input[7]);

   return 0;
}