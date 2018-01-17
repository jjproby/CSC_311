#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lcg( int seed, int mod ) {
  return (2 * seed + 3) % mod;
}

int main( int argc, char *argv[] ) {
  int seed = 5;
  int i;
  float num;
  int mod = 100;

  if (argc > 1) {
    seed = atoi(argv[1]);
  }

  if (argc > 2) {
    mod = atoi(argv[2]);
  }

  for (i = 0; i < 100; i++) {
    num = (float)seed/mod;
    printf("%6.2f ", num);
    seed = lcg(seed, mod);
  }

  printf("...\n");
  return 0;

}
