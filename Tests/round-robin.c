#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

  struct process{
      int PID;
      int t_inicio;
      int burst[25];
      int index_b;
      int io[25];
      int index_io;
  };


void roundrobin(struct process p1, struct process p2, struct process p3, struct process p4){
  
  int ready[3] = {0, 0, 0};
  int run = 0;
  int blocked[2] = {0, 0};
  int p1x = 0;
  int p1y = 0;
  int p2x = 0;
  int p2y = 0;
  int p3x = 0;
  int p3y = 0;
  int p4x = 0;
  int p4y = 0;
  int p1counterb = -1;
  int p1counterio = -1;
  int p2counterb = -1;
  int p2counterio = -1;
  int p3counterb = -1;
  int p3counterio = -1;
  int p4counterb = -1;
  int p4counterio = -1;
  /*int finishedp1;
  int finishedp2;
  int finishedp3;
  int finishedp4;*/
  int rrcounter = 0;

  for(int clock = 0; clock <= 15; clock++){
    if(clock < 10){
      printf("\n%d  | ", clock);
      printf("READY ");
    } else {
      printf("\n%d | ", clock);
      printf("READY ");
    }
    if(p1.t_inicio <= clock && run != p1.PID && blocked[0] != p1.PID && blocked[1] != p1.PID /*&& finishedp1 != 1*/){
      
      if(run == 0){
        run = p1.PID;
        p1counterb = 0;
      } else if(p1.PID != ready[0] && p1.PID != ready[1] && p1.PID != ready[2]){
         for( int readyc = 0; readyc < 3; readyc ++){
           if(ready[readyc] == 0){
            ready[readyc] = p1.PID;
            break;
           } else{
             continue;
           } 
          }
       }
    } 
    if(p2.t_inicio <= clock && run != p2.PID && blocked[0] != p2.PID && blocked[1] != p2.PID /*&& finishedp2 != 1*/){
      
      if(run == 0){
        run = p2.PID;
        p2counterb = 0;
      } else if(p2.PID != ready[0] && p2.PID != ready[1] && p2.PID != ready[2]) {
        for( int readyc = 0; readyc < 3; readyc ++){
           if(ready[readyc] == 0){
            ready[readyc] = p2.PID;
            break;
           } else{
             continue;
           } 
        } 
      } 
    }
    if(p3.t_inicio <= clock && run != p3.PID && blocked[0] != p3.PID && blocked[1] != p3.PID /*&& finishedp3 != 1*/){
      
      if(run == 0){
        run = p3.PID;
        p3counterb = 0;
      } else if(p3.PID != ready[0] && p3.PID != ready[1] && p3.PID != ready[2]){
        for( int readyc = 0; readyc < 3; readyc ++){
           if(ready[readyc] == 0){
            ready[readyc] = p3.PID;
            break;
           } else{
             continue;
           } 
        }
      } 
    } 
    if(p4.t_inicio <= clock && run != p4.PID && blocked[0] != p4.PID && blocked[1] != p4.PID /*&& finishedp4 != 1*/){
      
      if(run == 0){
        run = p4.PID;
        p4counterb = 0;
      } else if(p4.PID != ready[0] && p4.PID != ready[1] && p4.PID != ready[2]){
        for( int readyc = 0; readyc < 3; readyc ++){
           if(ready[readyc] == 0){
            ready[readyc] = p4.PID;
            break;
           } else{
             continue;
           } 
        }
      } 
    }
    
    int rspaces = 0;
    for(int i = 0; i < 3; i++){
      if(ready[i] == 0){
        continue;
      } else{
        printf("%d ", ready[i]);
        rspaces ++;
      } 
    } if(rspaces == 0){
      printf("            ");
    } else if(rspaces == 1){
      printf("        ");
    } else if(rspaces == 2){
      printf("    ");
    }
    
    printf("RUN ");
    
    if(run == p1.PID){
      if(ready[0] == p1.PID){
        ready[0] = ready[1];
        ready[1] = ready[2];
        ready[2] = 0;
      }
      if(p1counterb == -1){ 
        p1counterb ++;
      }
      else{
       printf("%d ", p1.PID);
       p1counterb ++; 
       rrcounter ++;      
      }                     
      if(p1counterb == p1.burst[p1x]){
        p1counterb = -1;
        if(blocked[0] == 0){
          blocked[0] = p1.PID;
        } else{
          blocked[1] = p1.PID;
        }  
        p1x++;
        run = ready[0];
      }
      else if(rrcounter == MAX){
        rrcounter = 0;
        if(blocked[0] == 0){
          blocked[0] = p1.PID;
        } else{
          blocked[1] = p1.PID;
        }  
        run = ready[0];
      } 
    }
    if(run == p2.PID){
      if(ready[0] == p2.PID){
        ready[0] = ready[1];
        ready[1] = ready[2];
        ready[2] = 0;
      }
      if(p2counterb == -1){ 
        p2counterb ++;
      }
      else{
       printf("%d ", p2.PID);
       p2counterb ++;
      }
      if(p2counterb == p2.burst[p2x]){
        p2counterb = -1;
        if(blocked[0] == 0){
          blocked[0] = p2.PID;
        } else{
          blocked[1] = p2.PID;
        }  
        p2x++;
        run = ready[0]; 
      }
      else if(rrcounter == MAX){
        rrcounter = 0;
        if(blocked[0] == 0){
          blocked[0] = p2.PID;
        } else{
          blocked[1] = p2.PID;
        }  
        run = ready[0];
      }     
    } 
    if(run == p3.PID){
      if(ready[0] == p3.PID){
        ready[0] = ready[1];
        ready[1] = ready[2];
        ready[2] = 0;
      }
      if(p3counterb == -1){ 
        p3counterb ++;
      }
      else{
       printf("%d ", p3.PID);
       p3counterb ++;
      }
      if(p3counterb == p3.burst[p3x]){
        p3counterb = -1;
        if(blocked[0] == 0){
          blocked[0] = p3.PID;
        } else{
          blocked[1] = p3.PID;
        }  
        p3x++;
        run = ready[0]; 
      }
      else if(rrcounter == MAX){
        rrcounter = 0;
        if(blocked[0] == 0){
          blocked[0] = p3.PID;
        } else{
          blocked[1] = p3.PID;
        }  
        run = ready[0];
      }     
    }
    if(run == p4.PID){
      if(ready[0] == p4.PID){
        ready[0] = ready[1];
        ready[1] = ready[2];
        ready[2] = 0;
      }
      if(p4counterb == -1){ 
        p4counterb ++;
      }
      else{
       printf("%d ", p4.PID);
       p4counterb ++;
      }
      if(p4counterb == p4.burst[p4x]){
        p4counterb = -1;
        if(blocked[0] == 0){
          blocked[0] = p4.PID;
        } else{
          blocked[1] = p4.PID;
        }  
        p4x++;
        run = ready[0]; 
      }
      else if(rrcounter == MAX){
        rrcounter = 0;
        if(blocked[0] == 0){
          blocked[0] = p4.PID;
        } else{
          blocked[1] = p4.PID;
        }  
        run = ready[0];
      }     
    }

    printf("BLOCKED ");
    
    if (p1.PID == blocked[0]){
      if(p1counterio == -1){ 
        p1counterio ++;
      }
      else{
       printf("%d", p1.PID);
       p1counterio ++;
      }
      if(p1counterio == p1.io[p1y]){
        p1counterio = -1;
        p1y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }
    if (p2.PID == blocked[0]){
      if(p2counterio == -1){ 
        p2counterio ++;
      }
      else if(p2counterio != p2.io[p2y]){
       printf("%d", p2.PID);
       p2counterio ++;
      }
      if(p2counterio == p2.io[p2y]){
        p2counterio = -1;
        p2y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }
    if (p3.PID == blocked[0]){
      if(p3counterio == -1){ 
        p3counterio ++;
      }
      else{
       printf("%d", p3.PID);
       p3counterio ++;
      }
      if(p3counterio == p3.io[p3y]){
        p3counterio = -1;
        p3y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }
    if (p4.PID == blocked[0]){
      if(p4counterio == -1){ 
        p4counterio ++;
      }
      else{
       printf("%d", p4.PID);
       p4counterio ++;
      }
      if(p4counterio == p4.io[p4y]){
        p4counterio = -1;
        p4y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }
    
  }
}



int main(void){

  struct process p1;
  struct process p2;
  struct process p3;
  struct process p4;

  FILE *fp = fopen("input1.txt","r");
  int count;
  char c;  
  if(fp == NULL){
    printf("Não foi possível abrir o ficheiro\n");
  }

  for (c = getc(fp); c != EOF; c = getc(fp)){ //line counter
        if (c == '\n'){
          count = count + 1;
        }
  } 
  fclose(fp);
          
  FILE *p = fopen("input1.txt","r");

  FILE *pp = fopen("input1.txt","r");

  int aux = 0;
  int b_index = 0;
  int io_index = 0;
    
  fscanf(p, "%d", &p1.PID);
  getc(pp);
  fscanf(p, "%d", &p1.t_inicio);
  getc(pp);
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    getc(pp);
    if(aux >= 100){
      break;
    } else{
      p1.burst[b_index] = aux;
      p1.index_b ++;
      b_index ++;
      fscanf(p, "%d", &aux);
      if(aux >= 100 || getc(pp) == EOF){
        break;
      }else{
        p1.io[io_index] = aux;
        p1.index_io ++;
        io_index ++;
      }
    }
  }
  
  p2.PID = aux;

  fscanf(p, "%d", &p2.t_inicio);
  getc(pp);
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    getc(pp);
    if(aux >= 100){
      break;
    } else{
      p2.burst[b_index] = aux;
      p2.index_b ++;
      b_index ++;
      fscanf(p, "%d", &aux);
      if(aux >= 100 || getc(pp) == EOF){
        break;
      }else{
        p2.io[io_index] = aux;
        p2.index_io ++;
        io_index ++;
      }
    }
  }
  
  p3.PID = aux;

  fscanf(p, "%d", &p3.t_inicio);
  getc(pp);
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    getc(pp);
    if(aux >= 100){
      break;
    } else{
      p3.burst[b_index] = aux;
      p3.index_b ++;
      b_index ++;
      fscanf(p, "%d", &aux);
      if(aux >= 100 || getc(pp) == EOF){
        break;
      }else{
        p3.io[io_index] = aux;
        p3.index_io ++;
        io_index ++;
      }
    }
  }
  
  p4.PID = aux;

  fscanf(p, "%d", &p4.t_inicio);
  getc(pp);
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    getc(pp);
    if(aux >= 100){
      break;
    } else{
      p4.burst[b_index] = aux;
      p4.index_b ++;
      b_index ++;
      fscanf(p, "%d", &aux);
      if(aux >= 100 || getc(pp) == EOF){
        break;
      }else{
        p4.io[io_index] = aux;
        p4.index_io ++;
        io_index ++;
      }
    }
  }
  
  fclose(p);
  fclose(pp);
  
  roundrobin(p1,p2,p3,p4);
}