#include <stdio.h>
#include <math.h>
#include <string.h>
#include "maxBinaryHeap.c"

struct Program {
  int arrivalTime;
  int burstTime;
  int waitTime;
};

void initProg(struct Program *prog) {
  prog->arrivalTime = 20;
  return;
}

int main(){
  /*int i, t, n;
  int *a = calloc(MAX, sizeof(int));
  int *m = calloc(MAX, sizeof(int));
  printf("Enter no of elements in the array\n");
  scanf("%d", &n);
  printf("Enter the array\n");
  for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
  m = buildmaxheap(a, n);
  printf("The heap is\n");
  for (t = 0; t < n; t++) {
      printf("%d\n", m[t]);
    }*/

    struct Program program1;
    struct Program program2;
    struct Program program3;

    program1.burstTime = 25;
    program2.burstTime = 35;

    program1.arrivalTime = 0;
    program2.arrivalTime = 1;
    program3.arrivalTime =2;

    program1.waitTime=0;
    program1.waitTime=0;
    //printf("hello");

    if(program1.burstTime < program2.burstTime) {
      program2.arrivalTime = program2.arrivalTime + program1.burstTime;
      program2.waitTime = program2.waitTime + program1.burstTime;
      printf("Program 1 Arrival Time: %d, Burst Time: %d, Waiting Time: %d\n", program1.arrivalTime, program1.burstTime, program1.waitTime);
      printf("Program 2 Arrival Time: %d, Burst Time: %d, Waiting Time: %d\n", program2.arrivalTime, program2.burstTime, program2.waitTime);
    }

    initProg(&program3);
    printf(" Arrival Time : %d", program3.arrivalTime);
}
