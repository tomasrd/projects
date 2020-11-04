#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_ITERATIONS 200000
#define DIMENSION 30000
/*------------------------------------------------------------------------------------
The program creates 3 complex vectors a,b,c, by creating their respective real and
imaginary components, and then multiplying b and c and saves the result in a.

This version of the program divides the code into two source files:
1. main_file_alone.c
2. mul_cpx_file.c
-------------------------------------------------------------------------------------*/


void mul_cpx (double *a_re, double *a_im, double *b_re, double *b_im, double *c_re, double *c_im);

int main(void) {

    double a_real[DIMENSION]; 
    double a_imaginary[DIMENSION];

    double b_real[DIMENSION];
    double b_imaginary[DIMENSION];
    double c_real[DIMENSION];
    double c_imaginary[DIMENSION];


    /*-------------------------
            Initializing
    --------------------------*/
    //generate random doubles to initialize the vectors
    srand(time(NULL)); //use current time as seed for the random number
    for(size_t i=0; i<DIMENSION; i++){
        b_real[i]       = (double) rand() / (double) rand();
        b_imaginary[i]  = (double) rand() / (double) rand();
        c_real[i]       = (double) rand() / (double) rand();
        c_imaginary[i]  = (double) rand() / (double) rand();
    }


    /*-------------------------
            Warm up the cpu
    --------------------------*/
    for( int iter=0; iter< 50; iter++) {
        for(int i = 0; i < DIMENSION; i++){
            mul_cpx(&a_real[i], &a_imaginary[i] , &b_real[i], &b_imaginary[i], &c_real[i], &c_imaginary[i]);
        }
    }



    /*-------------------------
            Benchmarking
    --------------------------*/
    clock_t begin = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {

        for(int i = 0; i < DIMENSION; i++){
            mul_cpx(&a_real[i], &a_imaginary[i] , &b_real[i], &b_imaginary[i], &c_real[i], &c_imaginary[i]);
        }
    }
    clock_t end = clock(); //stop the clock
    
    
    /*-------------------------
            Results
    --------------------------*/
    //calculate average time for the process
    double total_time_in_sec = ((double)(end-begin)) / (double)CLOCKS_PER_SEC;
    double avg_time          = total_time_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single loop is %f miliseconds\n", avg_time*1000.0);

    printf("%f\n", a_real[0]);

    return EXIT_SUCCESS;
}
