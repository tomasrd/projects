#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_ITERATIONS 200000
#define DIMENSION 30000

/*------------------------------------------------------------------------------------
The program creates 3 complex vectors a,b,c, by creating their respective real and
imaginary components, and then multiplying b and c and saves the result in a.

Note: Everything is done in "main".
-------------------------------------------------------------------------------------*/

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

    //generate random doubles and initialize the vectors
    srand(time(NULL)); //use current time as seed for the random number
    for(int i=0; i<DIMENSION; i++){
        b_real[i]       = (double) rand() / (double) rand();
        b_imaginary[i]  = (double) rand() / (double) rand();
        c_real[i]       = (double) rand() / (double) rand();
        c_imaginary[i]  = (double) rand() / (double) rand();
    }

    /*-------------------------
            Warm up the cpu
    --------------------------*/
    for( int iter=0; iter< 50; iter++) {
        for(int i = 0; i < 30000; i++){
            //save the result of the multiplication of b and c into a
            a_real[i]      = (b_real[i] * c_real[i]) - (b_imaginary[i] * c_imaginary[i]);
            a_imaginary[i] = (b_real[i] * c_imaginary[i]) + (b_imaginary[i] * c_real[i]);
        }
    }


    /*-------------------------
            Benchmarking
    --------------------------*/
    clock_t begin = clock(); //Measure the cpu time on the process
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {
        //the function is inlined manually
        for(int i = 0; i < DIMENSION; i++){
            //save the result of the multiplication of b and c into a
            a_real[i]      = (b_real[i] * c_real[i]) - (b_imaginary[i] * c_imaginary[i]);
            a_imaginary[i] = (b_real[i] * c_imaginary[i]) + (b_imaginary[i] * c_real[i]);
        }
    }
    clock_t end = clock();


    /*-------------------------
            Results
    --------------------------*/

    //calculate average time for the process
    double total_time_in_sec =  ((double)(end-begin)) / (double)CLOCKS_PER_SEC;
    double avg_time          = total_time_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single loop is %f miliseconds\n", avg_time*1000.0);

    //print to avoid optimization by the compiler    
    printf("%f, %f\n", a_real[50], a_imaginary[200]);

    return EXIT_SUCCESS;
}
