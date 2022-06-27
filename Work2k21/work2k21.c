#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.c"
#define quantum 3

struct process{
    int PID;
    int t_inicio;
    int new; //esperar 1 instante em new
    int exit; //esperar 1 instante em exit
    int run[5];
    int run_limit; //limite de run[]
    int index_r; //percorrer run[]
    int blocked[5];
    int blocked_limit; //limite de blocked[]
    int index_b; //percorrer blocked[]
};

struct process p[10];

void spaces(int count){ //espaçamento entre os processos nos prints da consola
     if(count == 0){
            printf("               ");
        }else if(count == 1){
            printf("            ");
        }else if(count == 2){
            printf("         ");
        }else if(count == 3){
            printf("      ");
        }else if(count == 4){
            printf("   ");
        }
}
void vrr(struct process p[], int row, int soma){

    struct Queue* NEW = createQueue(50);
    struct Queue* READY = createQueue(50);
    struct Queue* RUN = createQueue(50);
    struct Queue* BLOCKED = createQueue(50);
    struct Queue* EXIT = createQueue(50);
    struct Queue* AUX = createQueue(50);
    struct Queue* READYAUX = createQueue(50);
    
    int index_new = 0; //print
    int index_ready = 0; //print
    int index_run = 0; //print
    int index_blocked = 0; //print
    int index_exit = 0; //print
    int index_readyaux = 0; //print
    int q; //contar o quantum
    

    
    for(int clock = 0; clock < soma; clock++){
        for(int i = 0; i < row; i++){
            if(p[i].t_inicio == clock){
                enqueue(NEW, p[i].PID);
                p[i].new = 1;
            }
            else if(p[i].new == 1){
                dequeue(NEW);
                index_new++;
                enqueue(READY,p[i].PID);
                p[i].new = 2;
                if(isEmpty(RUN)){
                    dequeue(READY);
                    index_ready++;
                    enqueue(RUN, p[i].PID);

                }
            }
        }
        
        if((isEmpty(RUN) && !isEmpty(READY)) || (isEmpty(RUN) && !isEmpty(READYAUX))){
            if(isEmpty(READYAUX)){
                int b = front(READY);
                dequeue(READY);
                index_ready++;
                enqueue(RUN, b);
                p[b-1].run[p[b-1].index_r] --; //b-1 pq PID = p[b] + 1 , p[0].run[p[0].ind_run]
                q = 1;
            } else{
                int b = front(READYAUX);
                dequeue(READYAUX);
                index_readyaux++;
                enqueue(RUN, b);
                p[b-1].run[p[b-1].index_r] --; //b-1 pq PID = p[b] + 1 , p[0].run[p[0].ind_run]
                q = 1;
            }

        } else if(!isEmpty(RUN)){
            int x = front(RUN);
            if(p[x-1].run[p[x-1].index_r] == 0 || q == quantum){
                dequeue(RUN);
                index_run++;
                if(q == quantum && p[x-1].run[p[x-1].index_r] != 0){
                    enqueue(READY, p[x-1].PID);
                } else if(p[x-1].run[p[x-1].index_r] == 0){
                    if(p[x-1].index_r == p[x-1].run_limit - 1){
                        enqueue(EXIT, p[x-1].PID);
                        //p[x-1].exit = 1;
                    }else{
                        enqueue(BLOCKED, p[x-1].PID);
                        p[x-1].index_r++;
                    }
                }
            } 
            else{
                p[x-1].run[p[x-1].index_r] --;
                q++; 
            } 
        }
 
        if(!isEmpty(BLOCKED)){
            int x = front(BLOCKED);
            if(p[x-1].blocked[p[x-1].index_b] == 0){
                dequeue(BLOCKED);
                index_blocked++;
                enqueue(READYAUX, p[x-1].PID);
                p[x-1].index_b++;
            } else{
                p[x-1].blocked[p[x-1].index_b] --;
            } 
        }
        

        if(clock < 10){
            printf("\n%d  | ", clock);
        } else{
            printf("\n%d | ", clock);
        }
        int cnt;

        printf("NEW ");
        cnt = 0;
        for(int i = index_new; i< row; i++){
            if(NEW -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",NEW -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("READY ");
        cnt = 0;
        for(int i = index_ready; i < row + 30; i++){
            if(READY -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",READY -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("RUN ");
        cnt = 0;
        for(int i = index_run; i < row + 30; i++){
            if(RUN -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",RUN -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("BLOCKED ");
        cnt = 0;
        for(int i = index_blocked; i < row + 30; i++){
            if(BLOCKED -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",BLOCKED -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        if(!isEmpty(EXIT)){
                if(p[front(EXIT)-1].exit == 0){
                    p[front(EXIT)-1].exit = 1;
                } else if(p[front(EXIT)-1].exit == 1){
                    dequeue(EXIT);
                    index_exit++;
                }
        }

        printf("READYAUX ");
        cnt = 0;
        for(int i = index_readyaux; i < row + 30; i++){
            if(READYAUX -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",READYAUX -> array[i]);
                cnt++;
            }
        }

        spaces(cnt);

        printf("EXIT ");
        cnt = 0;
        for(int i = index_exit; i < row + 30; i++){
            if(EXIT -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",EXIT -> array[i]);
                cnt++;
            }
        }
        
    }
    
}

void roundrobin(struct process p[], int row, int soma){

    struct Queue* NEW = createQueue(50);
    struct Queue* READY = createQueue(50);
    struct Queue* RUN = createQueue(50);
    struct Queue* BLOCKED = createQueue(50);
    struct Queue* EXIT = createQueue(50);
    struct Queue* AUX = createQueue(50);
    
    int index_new = 0; //print
    int index_ready = 0; //print
    int index_run = 0; //print
    int index_blocked = 0; //print
    int index_exit = 0; //print
    int q; //contar o quantum
    

    
    for(int clock = 0; clock < soma; clock++){
        for(int i = 0; i < row; i++){
            if(p[i].t_inicio == clock){
                enqueue(NEW, p[i].PID);
                p[i].new = 1;
            }
            else if(p[i].new == 1){
                dequeue(NEW);
                index_new++;
                enqueue(READY,p[i].PID);
                p[i].new = 2;
                if(isEmpty(RUN)){
                    dequeue(READY);
                    index_ready++;
                    enqueue(RUN, p[i].PID);

                }
            }
        }
        
        if(isEmpty(RUN) && !isEmpty(READY)){
            int b = front(READY);
            dequeue(READY);
            index_ready++;
            enqueue(RUN, b);
            p[b-1].run[p[b-1].index_r] --; //b-1 pq PID = p[b] + 1 , p[0].run[p[0].ind_run]
            q = 1;

        } else if(!isEmpty(RUN)){
            int x = front(RUN);
            if(p[x-1].run[p[x-1].index_r] == 0 || q == quantum){
                //blocked or exit
                dequeue(RUN);
                index_run++;
                if(q == quantum && p[x-1].run[p[x-1].index_r] != 0){
                    
                    enqueue(READY, p[x-1].PID);
                } else if(p[x-1].run[p[x-1].index_r] == 0){
                    if(p[x-1].index_r == p[x-1].run_limit - 1){
                        enqueue(EXIT, p[x-1].PID);
                        //p[x-1].exit = 1;
                    }else{
                        enqueue(BLOCKED, p[x-1].PID);
                        p[x-1].index_r++;
                    }
                }
            } 
            else{
                p[x-1].run[p[x-1].index_r] --;
                q++; 
            } 
        }
 
        if(!isEmpty(BLOCKED)){
            int x = front(BLOCKED);
            if(p[x-1].blocked[p[x-1].index_b] == 0){
                dequeue(BLOCKED);
                index_blocked++;
                enqueue(READY, p[x-1].PID);
                p[x-1].index_b++;
            } else{
                p[x-1].blocked[p[x-1].index_b] --;
            } 
        }
        

        if(clock < 10){
            printf("\n%d  | ", clock);
        } else{
            printf("\n%d | ", clock);
        }
        int cnt;

        printf("NEW ");
        cnt = 0;
        for(int i = index_new; i< row; i++){
            if(NEW -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",NEW -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("READY ");
        cnt = 0;
        for(int i = index_ready; i < row + 30; i++){
            if(READY -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",READY -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("RUN ");
        cnt = 0;
        for(int i = index_run; i < row + 30; i++){
            if(RUN -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",RUN -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        printf("BLOCKED ");
        cnt = 0;
        for(int i = index_blocked; i < row + 30; i++){
            if(BLOCKED -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",BLOCKED -> array[i]);
                cnt++;
            }
        }
        spaces(cnt);

        if(!isEmpty(EXIT)){
            if(p[front(EXIT)-1].exit == 0){
                p[front(EXIT)-1].exit = 1;
            } else if(p[front(EXIT)-1].exit == 1){
                dequeue(EXIT);
                index_exit++;
            }
        }

        printf("EXIT ");
        cnt = 0;
        for(int i = index_exit; i < row + 30; i++){
            if(EXIT -> array[i] == 0)
            {
                continue;
            }else{
                printf(" %d ",EXIT -> array[i]);
                cnt++;
            }
        }
        
    }
    
}

int main(){

    int programas[5][10] = {
    {0, 3, 1, 2, 2, 4, 1, 1, 1, 1 },
    {1, 2, 4, 2, 4, 2, 0, 0, 0, 0 },
    {3, 1, 6, 1, 6, 1, 6, 1, 0, 0 },
    {3, 6, 1, 6, 1, 6, 1, 6, 0, 0 },
    {5, 9, 1, 9, 0, 0, 0, 0, 0, 0 } 
    };

    int row = sizeof(programas) / sizeof(programas[0]);
    int column = sizeof(programas[0])/sizeof(programas[0][0]);
    int soma = 0;
    for(int i = 0; i < row; i++){
        p[i].PID = i + 1;
        p[i].run_limit = 0;
        p[i].blocked_limit = 0;
        p[i].new = 0;
        p[i].exit = 0;
        p[i].index_r = 0;
        p[i].index_b = 0;
        for(int y = 0; y < column; y++){
            if(y==0){
                p[i].t_inicio = programas[i][y];
            }
            else if(programas[i][y] == 0){
                break;
            }
            else if(y % 2 != 0){
                p[i].run[p[i].run_limit] = programas[i][y];
                p[i].run_limit ++;
                soma += programas[i][y];
            }
            else if(y % 2 == 0){
                p[i].blocked[p[i].blocked_limit] = programas[i][y];
                p[i].blocked_limit ++;
                soma+=programas[i][y];
            }
        }
    }

    int value;
    int s = 1;
    
    printf("\nPara utilizar o método de escalonamento Round Robin insira o valor 0");
    puts("\n");
    printf("Para utilizar o método de escalonamento Virtual Round Robin insira o valor 1\n");

    scanf("%d", &value);
 
    if(value == 0){
        printf("\nROUND ROBIN:");
        roundrobin(p, row, soma);
        printf("\n");
    } else if(value == 1){
        printf("\nVIRTUAL ROUND ROBIN:");
        vrr(p, row, soma);
        printf("\n");
    } else{
      printf("O valor inserido é inválido!\n");
    }
  
}
