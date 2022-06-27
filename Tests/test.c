#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

  struct process{
      int PID;
      int t_inicio;
      int burst[25];
      int index_b;
      int io[25];
      int index_io;
  };

void fcfs(struct process p1, struct process p2, struct process p3, struct process p4, struct process p5, struct process p6, struct process p7, struct process p8, struct process p9, struct process p10){
  
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
  int finishedp1 = 0;
  int finishedp2 = 0;
  int finishedp3 = 0;
  int finishedp4 = 0;

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

  for(int clock = 0; clock <= 60; clock++){
    if(clock < 10){
      printf("\n%d  | ", clock);
      printf("READY ");
    } else {
      printf("\n%d | ", clock);
      printf("READY ");
    }
    if(p1.t_inicio <= clock && run != p1.PID && blocked[0] != p1.PID && blocked[1] != p1.PID && finishedp1 == 0 && count >= 1){
      
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
    if(p2.t_inicio <= clock && run != p2.PID && blocked[0] != p2.PID && blocked[1] != p2.PID && finishedp2 == 0){
      
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
    if(p3.t_inicio <= clock && run != p3.PID && blocked[0] != p3.PID && blocked[1] != p3.PID && finishedp3 == 0){
      
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
    if(p4.t_inicio <= clock && run != p4.PID && blocked[0] != p4.PID && blocked[1] != p4.PID && finishedp4 == 0){
      
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
      }                     
      if(p1counterb == p1.burst[p1x]){
        p1counterb = -1;
        p1x ++;
        if(p1x >= p1.index_b){
          finishedp1 = 1;
        }
        if(finishedp1 == 0){
          if(blocked[0] == 0){
            blocked[0] = p1.PID;
          } else{
              blocked[1] = p1.PID;
            }
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
        p2x ++;
        if(p2x >= p2.index_b){
          finishedp2 = 1;
        }
        if(finishedp2 == 0){
          if(blocked[0] == 0){
            blocked[0] = p2.PID;
          } else{
              blocked[1] = p2.PID;
            }
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
        p3x ++;
        if(p3x >= p3.index_b){
          finishedp3 = 1;
        }
        if(finishedp3 == 0){
          if(blocked[0] == 0){
            blocked[0] = p3.PID;
          } else{
              blocked[1] = p3.PID;
            }
        }  
        run = ready[0];
      } 
    }

    if(run == p4.PID && finishedp4 == 0){
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
        p4x ++;
        if(p4x >= p4.index_b){
          finishedp4 = 1;
        }
        if(finishedp4 == 0){
          if(blocked[0] == 0){
            blocked[0] = p4.PID;
          } else{
              blocked[1] = p4.PID;
            }
        }  
        run = ready[0];
      } 
    }

    printf("BLOCKED ");
    
    if (blocked[0] == p1.PID || blocked[1] == p1.PID){
      if(p1counterio == -1){ 
        p1counterio ++;
      }
      else{
       printf("%d ", p1.PID);
       p1counterio ++;
      }
      if(p1counterio == p1.io[p1y]){
        p1counterio = -1;
        p1y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }

    if (blocked[0] == p2.PID || blocked[1] == p2.PID){
      if(p2counterio == -1){ 
        p2counterio ++;
      }
      else if(p2counterio != p2.io[p2y]){
       printf("%d ", p2.PID);
       p2counterio ++;
      }
      if(p2counterio == p2.io[p2y]){
        p2counterio = -1;
        p2y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }

    if (blocked[0] == p3.PID || blocked[1] == p3.PID){
      if(p3counterio == -1){ 
        p3counterio ++;
      }
      else{
       printf("%d ", p3.PID);
       p3counterio ++;
      }
      if(p3counterio == p3.io[p3y]){
        p3counterio = -1;
        p3y++;
        blocked[0] = blocked[1];
        blocked[1] = 0;
      }
    }

    if (blocked[0] == p4.PID || blocked[1] == p4.PID){
      if(p4counterio == -1){ 
        p4counterio ++;
      }
      else{
       printf("%d ", p4.PID);
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
  struct process p5;
  struct process p6;
  struct process p7;
  struct process p8;
  struct process p9;
  struct process p10;

  p1.index_b = 0;
  p2.index_b = 0;
  p3.index_b = 0;
  p4.index_b = 0;
  p1.index_io = 0;
  p2.index_io = 0;
  p3.index_io = 0;
  p4.index_io = 0;

          
  FILE *p = fopen("input1.txt","r");

  int aux = 0;
  int b_index = 0;
  int io_index = 0;
    
  fscanf(p, "%d", &p1.PID);
  
  fscanf(p, "%d", &p1.t_inicio);
 
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
   
    if(aux >= 100){
      break;
    } else{
      p1.burst[b_index] = aux;
      p1.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
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
  
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p2.burst[b_index] = aux;
      p2.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
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
  
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p3.burst[b_index] = aux;
      p3.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
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
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p4.burst[b_index] = aux;
      p4.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p4.io[io_index] = aux;
        p4.index_io ++;
        io_index ++;
      }
    }
  }

  p5.PID = aux;

  fscanf(p, "%d", &p5.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p5.burst[b_index] = aux;
      p5.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p5.io[io_index] = aux;
        p5.index_io ++;
        io_index ++;
      }
    }
  }

    p6.PID = aux;

  fscanf(p, "%d", &p6.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p6.burst[b_index] = aux;
      p6.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p6.io[io_index] = aux;
        p6.index_io ++;
        io_index ++;
      }
    }
  }

    p7.PID = aux;

  fscanf(p, "%d", &p7.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p7.burst[b_index] = aux;
      p7.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p7.io[io_index] = aux;
        p7.index_io ++;
        io_index ++;
      }
    }
  }

    p8.PID = aux;

  fscanf(p, "%d", &p8.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p8.burst[b_index] = aux;
      p8.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p8.io[io_index] = aux;
        p8.index_io ++;
        io_index ++;
      }
    }
  }

  p9.PID = aux;

  fscanf(p, "%d", &p9.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p9.burst[b_index] = aux;
      p9.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p9.io[io_index] = aux;
        p9.index_io ++;
        io_index ++;
      }
    }
  }

  p10.PID = aux;

  fscanf(p, "%d", &p10.t_inicio);
 
  
  aux = 0;
  b_index = 0;
  io_index = 0;
  
  while(aux <= 100){
    fscanf(p, "%d", &aux);
    
    if(aux >= 100){
      break;
    } else{
      p10.burst[b_index] = aux;
      p10.index_b ++;
      b_index ++;
      int state = fscanf(p, "%d", &aux);
      if(aux >= 100 || state == EOF){
        break;
      }else{
        p10.io[io_index] = aux;
        p10.index_io ++;
        io_index ++;
      }
    }
  }
  
  
  fclose(p);
  
  fcfs(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);

  printf("%d", p6.PID);
  
}