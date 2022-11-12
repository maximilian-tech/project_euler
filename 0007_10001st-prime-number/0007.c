#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10001

int main(int argc, char** argv) {
    int count = 1; // 2 is known and fixed
    long prime_number;

    long candidate=3; // start with 3
    while (count < N) { // loop until 10001 primes have been found
        int is_prime = 1; // true

        for (int i = 3; i < sqrt(candidate)+1; i+=2) { // loop through all invalid numbers
            if (candidate%i == 0) {
                is_prime = 0; // false, abort
                break;
            }
        }

        if (is_prime == 1) {
            prime_number = candidate;
            count++;
        }

        candidate += 2; // skip all even numbers
    }

    printf("The %i prime number is: %li\n", N, prime_number);

    return EXIT_SUCCESS;
}