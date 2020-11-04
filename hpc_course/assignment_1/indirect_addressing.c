#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_ITERATIONS 1000
#define DIMENSION 1000000
/*------------------------------------------------------------------------------------
The program creates 3 vectors vectors x,y,p, where p is an indexing vector. 
Then we add the a multiple of x by the scalar a to the vector y.

-------------------------------------------------------------------------------------*/

int main(void){

    int *y = (int*) malloc(DIMENSION * sizeof(int));
    int *x = (int*) malloc(DIMENSION * sizeof(int));
    int *p = (int*) malloc(DIMENSION * sizeof(int));

    int a=5;


    /*-----------------------------
          Linear Initialization
    -------------------------------*/
    for(int i=0; i<DIMENSION; i++){
        p[i] = i;
    }

    /*-----------------------------
                Benchmarking
    -------------------------------*/
    clock_t linear_begin = clock(); //Measure the cpu time on the process
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {
        for(int i=0; i<DIMENSION; i++){
            int k = p[i];
            y[k] += a * x[k];
        }
    }
    clock_t linear_end = clock();


    /*-----------------------------
          Jump Initialization
    -------------------------------*/
    int size_jump=1000;
    for(int i=0, j=0; i<size_jump; i++){
        for(int k=i; k<DIMENSION; k += size_jump, j++){
            p[k]= j;
        }
    }

    /*-----------------------------
                Benchmarking
    -------------------------------*/
    clock_t jump_begin = clock(); //Measure the cpu time on the process
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {
        for(int i=0; i<DIMENSION; i++){
            int k = p[i];
            y[k] += a * x[k];
        }
    }
    clock_t jump_end = clock();


    /*-----------------------------
                Results
    -------------------------------*/
    //linear initialization
    double total_time_linear_in_sec =  ((double)(linear_end-linear_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_linear          =  total_time_linear_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of linear initialization is %f miliseconds\n", avg_time_linear*1000.0);

    //jump initialization
    double total_time_jump_in_sec =  ((double)(jump_end-jump_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_jump          =  total_time_jump_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of jump initialization is %f miliseconds\n", avg_time_jump*1000.0);
    
    printf("%d, %d\n", x[56], y[11]);
    
    free(y);
    free(x);
    free(p);

    return EXIT_SUCCESS;
}