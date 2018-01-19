#include <math.h>

/**
* The formula used to generate the psudeorandom numbers.
* \param seed The start of generating the numbers
* \param mod The modulus in the formula
**/
int lcg( int seed, int mod ) {
  return (2 * seed + 3) % mod;
}
