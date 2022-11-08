#include <stdio.h>
#include <stdlib.h>

#define NUM 600851475143 


int main(int argc, char** argv) {
    long largest_prime_div, current_number, number_history=1;
    current_number = NUM;
    for (long cand = 1; cand < NUM/2 + 1; ++cand) {
        if (current_number%cand == 0) {
            largest_prime_div = cand;
            current_number /= cand;
            number_history *=cand;
            
            printf("Largest Prime Diff: %li\n", largest_prime_div);
            
            if (number_history == NUM) {
                printf("Largest Prime has been found: %li\n", largest_prime_div);
                break;
            }
        }
    }

   return EXIT_SUCCESS;
}