#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main( int argc, char** argv ) {
  srand(time(NULL));
  char *line = NULL;
  size_t lengthOfBuffer = 0;
  ssize_t numberOfCharactersRead;
  int letters[26] = {0};
  int newLetters[26] = {0};
  int chars = 0;
  double percent[26] = {0};
  double randPercent[26] = {0};
  int *p;
  char x[1024];//string array
  int num = 0;


  FILE * inputStream = fopen( "frankenstein.txt", "r" );

  //numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  while (fscanf(inputStream, " %s", x) == 1) {
    //puts(x);
    num++;
  }

  fclose( inputStream );

  FILE * inputStream2 = fopen( "frankenstein.txt", "r" );

  char *y[num];//array of words
  int wordNumber[num];
  char *singleWords[num];

  for (int i = 0; i < num; i++) {
    char *z[num];
    wordNumber[i] = 0;
    if (fscanf(inputStream2, " %s", x) != 1) {
      break;
    }
    //puts(x);
    for (int j=0; x[j]; j++){
      x[j] = tolower(x[j]);
    }
    z[i] = strdup(x);
    /*for (int k = 0; k < strlen(y[i]); k++) {
      if (strcmp(y[k], z[i]) == 0) {
        wordNumber[k]++;
        continue;
      }
    }*/
    y[i] = strdup(x);
    wordNumber[i]++;
    printf("%s\n", y[i]);
  }

  fclose( inputStream2 );

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < i; j++) {
      if (strcmp(y[j], y[i]) == 0) {
        wordNumber[j]++;
      }
      else {
        singleWords[i] = strdup(y[i]);
      }
    }
  }

  /*for (int i = 0; i < num; i++) {
    printf("%s\n", y[i]);
  }*/

  /*for (int i = 0; i < num; i++) {
    /*for (int j = 0; j < i; j++) {
      if (strcmp(y[j], y[i]) == 0) {
        continue;
      }//if
    }//for
    FILE * inputStream3 = fopen( "frankenstein.txt", "r" );
    for (int j = 0; j < num; j++) {
      if (fscanf(inputStream, " %s", x) != 1) {
        break;
      }//if
      //puts(x);
      for (int k=0; x[k]; k++){
        x[k] = tolower(x[k]);
      }//for
      z[i] = strdup(x);
      if (strcmp(y[i], z[i]) == 0) {
        wordNumber[i]++;
      }//if
    }//for
    fclose( inputStream3 );
    read++;
  }//for*/

  for (int i = 0; i < num; i++) {
    printf("%s : %d \n", y[i], wordNumber[i]);
  }


  printf("Numebr of words: %d\n", num);



  free( line );



  return 0;

  }
