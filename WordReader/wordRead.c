#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int randWord(double *percent, int numWords ){
  double sum = 0.0;
  double randomWord = (double)rand() / (double)RAND_MAX;
  for (int i = 0; i < numWords; i++) {
    if (randomWord >= sum && randomWord <= sum + percent[i]) {
      return i;
    }
    else {
      sum += percent[i];
    }
  }
}

int main( int argc, char** argv ) {
  srand(time(NULL));
  char *line = NULL;
  char x[1024];//string array
  int num = 0;

  FILE * inputStream = fopen( "bee.txt", "r" );

  while (fscanf(inputStream, " %s", x) == 1) {
    //puts(x);
    num++;
  }

  //printf("%d\n", num);

  fclose( inputStream );

  FILE * inputStream2 = fopen( "bee.txt", "r" );

  char *y[num];//array of words
  char *singleWords[num];
  int uniqueWords = 0;

  for (int i = 0; i < num; i++) {
    //wordNumber[i] = 0;
    if (fscanf(inputStream2, " %s", x) != 1) {
      break;
    }
    //puts(x);
    for (int j=0; x[j]; j++){
      x[j] = tolower(x[j]);
    }
    y[i] = strdup(x);
    //wordNumber[i]++;
  }

  fclose( inputStream2 );

  for (int i = 1; i < num; i++) {
    for (int j = 0; j < i; j++) {
      if (strcmp(y[j], y[i]) == 0) {
        break;
      }
      if (j == i - 1) {
        singleWords[uniqueWords] = strdup(y[i]);
        uniqueWords++;
      }
    }
  }

  int wordNumber[uniqueWords];
  double percent[uniqueWords];

  for (int i = 0; i < uniqueWords; i++){
    wordNumber[i] = 0;
    for (int j = 0; j < num; j++) {
      if (strcmp(y[j], singleWords[i]) == 0) {
        wordNumber[i]++;
      }
    }
  }

  for (int i = 0; i < uniqueWords; i++) {
    percent[i] = (double)wordNumber[i]/(double)num;
    printf("%s : %d   %f\n", singleWords[i], wordNumber[i], percent[i]);
  }

  printf("Unique words: %d\n", uniqueWords);

  printf("Numebr of words: %d\n", num);

  for (int i = 0; i < uniqueWords; i++) {
    int newWord = randWord(percent, uniqueWords);
    //printf("%d\n", newWord);
    printf("%s ", singleWords[newWord]);
  }


  printf("\n");



  free( line );



  return 0;

  }
