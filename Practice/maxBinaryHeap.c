/* C program to build a binary heap */

#include <stdio.h>
#include <stdlib.h>
#include  <limits.h>
#define MAX 20
void maxheapify(int *, int, int);
int* buildmaxheap(int *, int);



int* buildmaxheap(int a[], int n){
    int heapsize = n;
    int j;
    for (j = n/2; j >= 0; j--) {
        maxheapify(a, j, heapsize);
    }
    return a;
}

void maxheapify(int a[], int i, int heapsize){
    int temp, largest, left, right, k;
    left = (2*i+1);
    right = ((2*i)+2);
    if (left >= heapsize){
        return; }
    else {
        if (left < (heapsize) && a[left] > a[i]) {
            largest = left;
          }
        else {
            largest = i;
        }
        if (right < (heapsize) && a[right] > a[largest]){
            largest = right;
          }
        if (largest != i) {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(a, largest, heapsize);
        }
    }

}

int main(){
  int i, t, n;
  int *a = calloc(MAX, sizeof(int));
  int *m = calloc(MAX, sizeof(int));
  printf("Enter no of elements in the array\n");
  scanf("%d", &n);
  printf("Enter the array\n");
  for (i = 0; i < n; i++) {
      a[i] = 5 + i;
      //scanf("%d", &a[i]);
    }
  m = buildmaxheap(a, n);

/*int balls[n +1];
for (int fuck = 0; fuck < n+1;fuck++){
  printf("val of fuck%d\n", m[n-fuck]);
  balls[fuck] = m[n-fuck];
}
m = balls;*/

  printf("The heap is\n");
  /*for (t = n; t >= 0; t--) {
      printf("%d\n", m[t]);
    }*/
  for (t = 0; t < n; t++) {
        printf("%d\n", m[t]);
    }
  }
