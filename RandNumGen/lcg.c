#include <math.h>

/**
* The formula used to generate the psudeorandom numbers.
**/
int lcg( int seed, int mod ) {
  return (2 * seed + 3) % mod;
}
