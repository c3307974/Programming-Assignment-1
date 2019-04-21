#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_LEN 300
#define ALPHABET_LEN 26
#define a_ASCII 97
#define z_ASCII 122
#define A_ASCII 65
#define Z_ASCII 90

// known frequencies for English language, 0.0855 represents for A, 0.0160 for B etc.
double known_freq[] = { 0.0855, 0.0160, 0.0316, 0.0387, 0.1210, 0.0218, 0.0209, 0.0496, 0.0733, 0.0022, 0.0081,
						0.0421, 0.0253, 0.0717, 0.0747, 0.0207, 0.0010, 0.0633, 0.0673, 0.0894, 0.0268, 0.0106, 0.0183, 0.0019,
						0.0172, 0.0011
