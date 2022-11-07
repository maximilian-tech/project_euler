#include <stdio.h>
#include <stdlib.h>

#define N 4000000

long even_fibonacci(long maxN) {
    long fib[2] = {1,2};
    long sum = 2; // initial 2 from initialisation
    while (fib[1]+fib[0] < maxN)
    {
        long tmp = fib[0]+fib[1];
        if (tmp%2 == 0)
            sum += tmp;
        fib[0] = fib[1];
        fib[1] = tmp;
    }
    return sum;
}

int main(int argc, char** argv) {
    
    long sum = even_fibonacci(N);
    printf("The sum of even fibonacci number under %i is: %li\n", N, sum);
    return EXIT_SUCCESS;
}