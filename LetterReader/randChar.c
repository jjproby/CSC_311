#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "letterRead.h"

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
}
