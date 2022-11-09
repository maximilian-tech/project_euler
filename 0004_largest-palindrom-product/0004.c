#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM 3

void strrev(char *s, char *r) {
    int count = 0;
    int begin = 0, end = 0;

    while (s[count] != '\0')
      count++;

   end = count - 1;

   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }

   r[begin] = '\0';
}

int main(int argc, char** argv) {
   
    
    int MAX = pow(10,NUM) - 1;
    int largest_palindrom = 0;
    for (int a = MAX; a > 0; --a) {
        for (int b = MAX; b > 0; --b) {
            int tmp = a * b;
            char tmp_string[NUM*2+1];
            sprintf(tmp_string, "%d", tmp);
            char tmp_string_rev[NUM*2+1];
            //strcpy(tmp_string_rev, tmp_string);
            strrev(tmp_string, tmp_string_rev);
            //printf("%s and rev: %s\n", tmp_string, tmp_string_rev);
            if ((strcmp(tmp_string, tmp_string_rev) == 0) \
                 && (tmp > largest_palindrom)) {
                largest_palindrom = tmp;
                
            }
        }   
    }
    printf("Largest is a Palindrom of the product of %i digit numbers: %i\n", NUM, largest_palindrom);

   return EXIT_SUCCESS;
}