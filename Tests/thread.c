#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//gcc thread.c -lpthread 

void *print_message_function( void *ptr );

int n=0;

int main()
{
    pthread_t thread1, thread2;
    int x1=1; 

    int x2=2;
    pthread_create( &thread1, NULL, print_message_function, (void *) &x1 );

    pthread_create( &thread2, NULL, print_message_function, (void *) &x2 );     
    pthread_join( thread1, NULL);

    printf(" n is equal to ...%d \n", n );

    return 0;
}
void *print_message_function(void *input)
{
    int* z = (int*) input;
    int  w = *z;
    printf("w is equal to  %d ... \n", w);

    n=w;

    pthread_exit(NULL);    
}