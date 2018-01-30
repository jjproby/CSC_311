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

// might want to declare some global variables

// might want to define some other functions


char randChar(double *percent) {
  double sum = 0.0;
  double randomNum = (double)rand() / (double)RAND_MAX;
  //printf("%f\n", randomNum);
  for (int i = 0; i < 26; i++) {
    if (randomNum >= sum && randomNum <= sum + percent[i]) {
      char c = 'a' + i;
      return c;
    }
    else {
      sum += percent[i];
    }
  }
  //if (randomNum)

}

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

  // uncomment next line if opening a file
  // (and replace "tale-of-two-cities.txt" with name of file
  FILE * inputStream = fopen( "frankenstein.txt", "r" );

  // replace stdin in next line with another input stream
  // if opening a file
  numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  while( numberOfCharactersRead > 0 ) {


    // replace stdin in next line with another input stream
    // if opening a file
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
      //printf( "%s\n", line );
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


  /*for(int i = 0; i < 150; i++) {
    printf("Random Char is: %c\n", randChar(percent));
  }*/

  for(int i = 0; i < chars; i++) {
    char c = randChar(percent);
    newLetters[c-'a']++;
  }

  for(int i = 0; i < 26; i++) {
    randPercent[i] = ((double)newLetters[i]/(double)chars);
  }

  for(int i = 0; i < 26; i++) {
    printf("Random Char %c = %d\n", 'a' + i, newLetters[i]);
    printf("Random Percent for Char %c = %f\n", 'a' + i, randPercent[i]);
  }

  return 0;

} // main( int, char** )
