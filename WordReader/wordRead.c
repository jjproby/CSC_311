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
  char x[1024];
  int num = 0;

  FILE * inputStream = fopen( "bible.txt", "r" );

  numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  while (fscanf(inputStream, " %s", x) == 1) {
    //puts(x);
    num++;
  }

  fclose( inputStream );

  FILE * inputStream2 = fopen( "bible.txt", "r" );

  char *y[num];

  for (int i = 0; i < num; i++) {
    if (fscanf(inputStream2, " %s", x) != 1) {
      break;
    }
    //puts(x);
    for (int j=0; x[j]; j++){
      x[j] = tolower(x[j]);
    }
    y[i] = strdup(x);
  }

  for (int i = 0; i < num; i++) {
    printf("%s\n", y[i]);
  }

  printf("Numebr of words: %d\n", num);


/*  while( numberOfCharactersRead > 0 ) {

    numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);
    if( numberOfCharactersRead == -1 ) {
      perror( "getline" );
    } // if
    else {
      for( int i = 0; i < strlen(line); i++) {
        char c = tolower(line[i]);
        //printf("%c", line[i]);
        if( 'a' <= c && c <='z') {
          word[i] = c;
          letters[c-'a']++;
          chars++;
        }//if
      }//for
    } // else
  } // while */
  fclose( inputStream2 );

  free( line );



  return 0;

  }
