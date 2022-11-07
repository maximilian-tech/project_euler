#include <stdio.h>
#include <stdlib.h>

#define N 1000 

int main(int argc, char** argv) {
    long sum = 0;
    for(int i = 0; i <  N; ++i)
        if ((i%3 == 0) || (i%5 == 0))
            sum += i;        
    
    printf("The sum of multiples of 3 or 5 below %i is: %li\n", N, sum);

    return EXIT_SUCCESS;
}