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


int main(void){

  struct process p1;
  struct process p2;
  struct process p3;
  struct process p4;
  /*struct process p5;
  struct process p6;
  struct process p7;
  struct process p8;
  struct process p9;
  struct process p10;*/

  p1.index_b = 0;
  p2.index_b = 0;
  p3.index_b = 0;
  p4.index_b = 0;
  p1.index_io = 0;
  p2.index_io = 0;
  p3.index_io = 0;
  p4.index_io = 0;

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
  
  
  fclose(p);
  
  //fcfs(p1, p2, p3, p4);
  
}