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

void push (heap_t *h, double priority, int data, double arrivalTime) {
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
    h->nodes[i].waitTime = h->nodes[i].waitTime + h->nodes[i].priority;
    h->len++;
}

void waitcalc(heap_t *h){
  for (int i = 0; i < h->len+2; i++){
  printf("i = %d  %.2lf + %.2lf\n"
    , i, h->nodes[i].waitTime, h->nodes[i - 1].priority);
    h->nodes[i].waitTime += h->nodes[i - 1].priority;
  }
}

int pop (heap_t *h) {
    int i, j, k;
    if (!h->len) {
        return 0;
    }
    int data = h->nodes[1].data;

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

    //waitcalc(h);
    h->nodes[1].waitTime += h->nodes[1].priority;
    printf("Priority: %.2lf\n", h->nodes[1].priority);
    printf("Wait Time: %.2lf\n", h->nodes[1].waitTime);
    return data;
}

int main(){
    int j;
    srand(time(NULL));

    heap_t *h = (heap_t *)calloc(2, sizeof (heap_t));
    for (j = 0; j < 5; j++) {
      node_t *t = (node_t *)calloc(2, sizeof (node_t));
      t->arrivalTime = 0;
      t->priority = (rand() % 10) + 1;
      t->data = (j+1);

      push(h, t->priority, t->data, t->arrivalTime);
    }
    for (int i = 0; i < (j - 1); i++) {
        printf("Program: %d\n\n", pop(h));
    }
    return 0;

}
