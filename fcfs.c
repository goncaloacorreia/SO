#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void fcfs(struct process p1, struct process p2, struct process p3, struct process p4){
  
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

  for(int clock = 0; clock <= 62; clock++){
    if(clock < 10){
      printf("\n%d  | ", clock);
      printf("READY ");
    } else {
      printf("\n%d | ", clock);
      printf("READY ");
    }
    if(p1.t_inicio <= clock && run != p1.PID && blocked[0] != p1.PID && blocked[1] != p1.PID && finishedp1 == 0){
      
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