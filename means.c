#include <stdio.h>
#include "means.h"

int main(int argc, double argv[]) {

  double x = 3;
  double y = 4;

  printf("The arithmetic mean of %6.2f and %6.2f = %6.2f\n", x, y, arithmeticMean(x,y) );
  printf("The harmonic mean of %6.2f and %6.2f = %6.2f\n", x, y, harmonicMean(x,y) );
  printf("The geometric mean of %6.2f and %6.2f = %6.2f\n", x, y, geometricMean(x,y) );
}
