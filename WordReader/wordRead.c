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

  FILE * inputStream = fopen( "frankenstein.txt", "r" );

  numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  while( numberOfCharactersRead > 0 ) {

    numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);
    if( numberOfCharactersRead == -1 ) {
      perror( "getline" );
    } // if
    else {
      char word[strlen(line)];
      for( int i = 0; i < strlen(line); i++) {
        char c = tolower(line[i]);
        //printf("%c", line[i]);
        if( 'a' <= c && c <='z') {
          word[i] = c;
          letters[c-'a']++;
          chars++;
        }//if
        else {
          printf("%s\n", word);
          for (int j = 0; j < strlen(word); j++) {
            word[j] = '\0';
          }
        }
      }//for
    } // else
  } // while
  fclose( inputStream );

  free( line );

  return 0;

  }
