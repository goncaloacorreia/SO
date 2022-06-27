#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


void main(void){

int f=fork();

if (f == 0) {

 

  printf(" A \n ");

  fork();

  printf(" B \n");



} else {

  printf("C\n");

}

  fork();

  printf(" D\n ");

}

 
