#include <stdio.h>
#include <stdlib.h>

#define N 20 

int main(int argc, char** argv) {
    long num = 1;

    for(long int cand=1;cand<__INT32_MAX__;++cand){
        int reminder=0;
        for(int i = 1; i <= N; ++i) {
            if (cand%i != 0) {
                reminder += i;
                break;
            }
        }
        if(reminder == 0) {
            printf("Found number that is evenly devisible by all numbers from 1 to %i:  %li\n", N ,cand);
            break;
        } 
                

    }
    
    return EXIT_SUCCESS;
}