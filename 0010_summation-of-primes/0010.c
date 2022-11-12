#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2000000

int main(int argc, char** argv) {
    long prime_number_sum = 2;

    long candidate=3; // start with 3
    while (candidate < N) { // loop until 10001 primes have been found
        int is_prime = 1; // true

        for (int i = 3; i < sqrt(candidate)+1; i+=2) { // loop through all invalid numbers
            if (candidate%i == 0) {
                is_prime = 0; // false, abort
                break;
            }
        }

        if (is_prime == 1) {
            prime_number_sum += candidate;
        }

        candidate += 2; // skip all even numbers
    }

    printf("The sum of prime numbers blow %i is: %li .\n", N, prime_number_sum);

    return EXIT_SUCCESS;
}