#include <stdio.h>
#include <stdlib.h>


#define N 20
#define OFFSET(i,j,n) ((j)+((i)*(n)))

int main(int argc, char** argv) {
    // size = 20x20
    char* str_array =   "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
                        "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
                        "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
                        "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
                        "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
                        "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
                        "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
                        "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
                        "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
                        "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
                        "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
                        "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
                        "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
                        "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
                        "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
                        "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
                        "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
                        "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
                        "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
                        "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";
    
    int* array = (int*)malloc(N*N*sizeof(int));
    char tmp_c[3];
    // conver char array to int array
    int i = 0;
    while( str_array[i] != '\0') {
        tmp_c[i%3] = str_array[i];
        if (i%3==2 ){
            array[i/3] = atoi(tmp_c);
            //printf("%i\n", array[i/3]);
        }
        i++;
    }

    int* array_wPadding = (int*)calloc((N+3)*(N+3),sizeof(int));

    // distribute data and include padding
    int pad_offset = 0;
    for(int i = 0; i < N*N; ++i){
        if( i%N==0 && i > 0) {
            pad_offset += 3;
        }
        array_wPadding[i+pad_offset] = array[i];
    }
    
    /*
    for(int i_g = 0; i_g<N+3; ++i_g) {
        for(int j_g = 0; j_g<N+3; ++j_g) {
            printf("%i ", array_wPadding[OFFSET(i_g,j_g,N+3)] );
        }
        printf("\n");
    } */

    /*
        Define stencil
        1. horizontal
        2. vertical
        3. diagonal NW-SO
        4. diagonal NO-SW
        
    */
    const int kernel_1[16]=  {1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    const int kernel_2[16]=  {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0};
    const int kernel_3[16]=  {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    const int kernel_4[16]=  {0,0,0,1, 0,0,1,0, 0,1,0,0, 1,0,0,0};

    const int* kernel[4] = {kernel_1,
                      kernel_2,
                      kernel_3,
                      kernel_4};
    
    int prod[4] = {0,0,0,0};
    
    // iterate over grid
    for(int i_g = 0; i_g<N; ++i_g) {
        for(int j_g = 0; j_g<N; ++j_g) {
            // iterate over kernel_area
            int tmp[4] = {1,1,1,1};
            for(int i_k = 0; i_k<4; ++i_k) {
                for(int j_k = 0; j_k<4; ++j_k) {   
                    // iterate over kernel
                    for(int k = 0; k<4; ++k) {
                        if (kernel[k][OFFSET(i_k,j_k,4)] > 0)
                            tmp[k] *= kernel[k][OFFSET(i_k,j_k,4)] * array_wPadding[OFFSET(i_g+i_k,j_g+j_k,N+3)];
                    }
                }
            }
            for(int k = 0; k<4; ++k) {
                prod[k] = tmp[k] > prod[k] ? tmp[k] : prod[k];
            }
        }
    }
    int largest = 0;
    for(int k = 0; k<4; ++k) {
        largest = prod[k] > largest ? prod[k] : largest;
    }
    printf("The largest product of 4 adjacent numbers within the given array is: %i\n", largest);
  
  
    free(array);
    free(array_wPadding);
    return EXIT_SUCCESS;
}