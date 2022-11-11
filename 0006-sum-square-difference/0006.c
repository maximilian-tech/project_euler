#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main(int argc, char** argv) {
    long long sum = 0, sq_sum = 0;
    long long diff = 0;
    for(int i = 1; i <=  N; ++i) {
        sum += pow(i,2);
        sq_sum += i;
    }
    sq_sum = powl(sq_sum,2);
        
    printf("the sum of the squares of the first %i natural numbers and the square of the sum is: %lli\n", N, sq_sum-sum);

    return EXIT_SUCCESS;
}