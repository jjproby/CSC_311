#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main( int argc, char** argv ) {
  char *line = NULL;
  char x[1024];//string array
  int num = 0;

  FILE * inputStream = fopen( "frankenstein.txt", "r" );

  while (fscanf(inputStream, " %s", x) == 1) {
    //puts(x);
    num++;
  }

  //printf("%d\n", num);

  fclose( inputStream );

  FILE * inputStream2 = fopen( "frankenstein.txt", "r" );

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

  for (int i = 0; i < uniqueWords; i++){
    wordNumber[i] = 0;
    for (int j = 0; j < num; j++) {
      if (strcmp(y[j], singleWords[i]) == 0) {
        wordNumber[i]++;
      }
    }
  }

  for (int i = 0; i < uniqueWords; i++) {
    printf("%s : %d \n", singleWords[i], wordNumber[i]);
  }
  printf("Unique words: %d\n", uniqueWords);


  printf("Numebr of words: %d\n", num);



  free( line );



  return 0;

  }
