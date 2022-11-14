#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))
#define N 500 

int main(int argc, char** argv) {
    int   num_divisors_max = 0;

    unsigned long long  triangle_number = 1;
    unsigned long long   count=2;
    while (num_divisors_max <= N) {
        
        int num_divisors = 2; // own number and 1 is always possible
        // count factors
        #pragma omp parallel for reduction(+:num_divisors) schedule(guided, 10000)
        for (unsigned long long  i = 2; i < triangle_number/2 + 1; ++i)
        {
            if (triangle_number%i==0) {
                num_divisors++;
            }
        }
        //printf("Triangle num: %i, divisors: %i\n", triangle_number, num_divisors);        
        num_divisors_max = max(num_divisors,num_divisors_max);
        triangle_number += count++;
        if (count%1000==0)
            printf("triangle:%llu, div_max=%i\n",triangle_number,num_divisors_max);
    }

    printf("The first triangle number with %i divisors is: %llu\n", N,triangle_number- --count);

    return EXIT_SUCCESS;
}