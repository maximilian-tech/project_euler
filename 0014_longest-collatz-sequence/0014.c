#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main(int argc, char** argv) {
    int max = 0;
    unsigned long long longest = 0;
    for(int start = 1; start <  N; ++start) {
        long long unsigned n = start;
        unsigned long long tmp = 0;
        for( ;n > 1;++tmp) {
            if(n%2==0) {
                n = n/2;
            } else {
                n = 3*n + 1;
            }
            /*long long unsigned n1 = n/2;
            long long unsigned n2 = 3*n + 1;
            n = n%2==0?n1:n2;*/

        }
        #pragma omp critical
        {
        if (tmp > longest) {
            max = start;
            longest = tmp;
        }
        }
    }
    
    printf("The starting number of the longest collatz sequence under %i is: %i\n", N, max);

    return EXIT_SUCCESS;
}