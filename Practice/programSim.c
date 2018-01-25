#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//#include "heap.h"


typedef struct {
    double priority;
    int data;
    double arrivalTime;
    double waitTime;
} node_t;

typedef struct {
    node_t *nodes;
    int len;
    int size;
} heap_t;

void push (heap_t *h, double priority, int data, double arrivalTime, double waitTime) {
    if (h->len + 1 >= h->size) {
        h->size = h->size ? h->size * 2 : 4;
        h->nodes = (node_t *)realloc(h->nodes, h->size * sizeof (node_t));
    }
    int i = h->len + 1;
    int j = i / 2;
    while (i > 1 && h->nodes[j].priority > priority) {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].priority = priority;
    h->nodes[i].data = data;
    h->nodes[i].arrivalTime = arrivalTime;
    h->nodes[i].waitTime = waitTime;
    h->len++;
}

double waitcalc(heap_t *h, double waitstore){
  for (int j = 0; j < h->len; j++) {
      waitstore += h->nodes[j].priority;
  }
  for (int i = 0; i < h->len; i++){
    //  double waitstore = 0;
    h->nodes[i].waitTime = waitstore - h->nodes[i].arrivalTime;
    //double *waitT2 = &h->nodes[i].waitTime;
    //int *id = &h->nodes[i].data;
    //double *P2 = &h->nodes[i].priority;
    //printf("%lf\n", *waitT2);
    //printf("%lf\n", *P2);
    //printf("Program: %d\n\n", *id);
  }
  //printf("waitstroe: %lf\n", waitstore);
  return waitstore;
}


int pop (heap_t *h, double waittime) {
    int i, j, k;
    if (!h->len) {
        return 0;
    }
    int data = h->nodes[1].data;
    double priority2 = h->nodes[1].priority;
    double arrival = h->nodes[1].arrivalTime;
    double waitT = h->nodes[1].waitTime;

    h->nodes[1] = h->nodes[h->len];
    int priority = h->nodes[1].priority;
    h->len--;
    i = 1;
    while (1) {
        k = i;
        j = 2 * i;
        if (j <= h->len && h->nodes[j].priority < priority) {
            k = j;
        }
        if (j + 1 <= h->len && h->nodes[j + 1].priority < h->nodes[k].priority) {
            k = j + 1;
        }
        if (k == i) {
            break;
        }
        h->nodes[i] = h->nodes[k];
        i = k;
    }
    h->nodes[i] = h->nodes[h->len + 1];


    //*wait = *wait + *waitT;

    //waittime += waitcalc(h, waittime);
    waittime = waitcalc(h, waittime);

    printf("Priority: %lf\n", priority2);
    printf("Arrival Time: %lf\n", arrival);
    printf("Wait Time: %lf\n", waitT);
    printf("waittime: %lf\n", waittime);
    return data;
}

int main(){
    srand(time(NULL));
    int j;
    double waitstore = 0;
    heap_t *h = (heap_t *)calloc(2, sizeof (heap_t));
    for (j = 0; j < 5; j++) {
      node_t *t = (node_t *)calloc(2, sizeof (node_t));
      //char * d = calloc(2, sizeof (char *));
      t->arrivalTime = j;
      //printf("J=%d\n, Arrival time = %lf\n", j, t->arrivalTime);
      t->priority = (rand() % 10) + 1;
      t->waitTime = 0;
      t->data = (j+1);
      //*d = j+65;

      push(h, t->priority, t->data, t->arrivalTime, t->waitTime);

    }
    //waitcalc(h);
    /*push(h, 3, "Clear drains");
    push(h, 4, "Feed cat");
    push(h, 5, "Make tea");
    push(h, 1, "Solve RC tasks");
    push(h, 2, "Tax return");*/
    int i;
    for (i = 0; i < j; i++) {
        printf("Program: %d\n\n", pop(h, waitstore));
    }
    return 0;

}
