#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(int argc, char** argv) {
    int a, b, c;

    for (a=1; a<=N; ++a){
        for (b=1; a+b <=N; ++b) {
            for (c=1; a+b+c <= N; ++c) {
                if ((a+b+c == N) && (a*a+b*b==c*c)) {
                    goto end;
                }
            }
        }
    }
    printf("ERROR, number not found!\n");
    return EXIT_FAILURE;
    
    end: 
    printf("The product of the special pythagorean triplet is: %i*%i*%i = %i !\n", a,b,c,a*b*c );
    return EXIT_SUCCESS;
}