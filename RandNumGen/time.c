#include <stdio.h>
#include <time.h>

int main () {
  time_t seconds;

  seconds = time(NULL);
  printf("%ld\n", seconds%100);

  return 0;
}
