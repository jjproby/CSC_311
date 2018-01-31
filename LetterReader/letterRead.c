/**
 * This is a program to count how many times
 * each letter of the alphabet occurs in a sample
 * of text
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "letterRead.h"


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


  FILE * inputStream = fopen( "importance.txt", "r" );

  // replace stdin in next line with another input stream
  // if opening a file
  numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  while( numberOfCharactersRead > 0 ) {

    numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);
    if( numberOfCharactersRead == -1 ) {
      perror( "getline" );
    } // if
    else {

      for( int i = 0; i < strlen(line); i++) {
        char c = tolower(line[i]);
        printf("%c", line[i]);
        if( 'a' <= c && c <='z') {
          letters[c-'a']++;
          chars++;
        }//if
      }//for
    } // else
  } // while
  fclose( inputStream );

  free( line );

  // add code here to report number of times
  // that each letter of the alphabet was found
  // in the input

  for(int i = 0; i < 26; i++) {
    percent[i] = ((double)letters[i]/(double)chars);
  }

  for(int i = 0; i < 26; i++) {
    printf("%c = %d\n", 'a' + i, letters[i]);
    printf("%c = %f\n", 'a' + i, percent[i]);
  }

  printf("Total number of characters: %d\n", chars);

  newRandChars(percent, chars);

  return 0;

} // main( int, char** )
