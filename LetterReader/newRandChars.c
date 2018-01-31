#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "letterRead.h"

void newRandChars(double *percent, int chars) {
  int newLetters[26] = {0};
  double randPercent[26];
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
}
