#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BENCHMARK_ITERATIONS 5000
#define DIMENSION 1000

/*------------------------------------------------------------------------------------
The program sums the rows and columns of a square matrix of size DIMENSION.

This version presents the improved column summation
-------------------------------------------------------------------------------------*/

int main(void) {
    
    double matrix[DIMENSION][DIMENSION];
    double row_sums[DIMENSION] = {0.};
    double col_sums[DIMENSION] = {0.};


    /*-------------------------
            Initializing
    --------------------------*/
    //generate random doubles to initialize the matrix
    srand(time(NULL)); //use current time as seed for the random number
    for(int i=0; i<DIMENSION; i++){
        for(int j=0; j<DIMENSION; j++){
            matrix[i][j] = (double) rand() / (double) rand();
        }
    }

    /*-------------------------
            Warm up the cpu
    --------------------------*/
    for( int iter=0; iter< 50; iter++) {
        for(int i=0; i<DIMENSION; i++){
            double sum = 0.;
            for(int j=0; j< DIMENSION; j++){
                sum += matrix[i][j];
            }
        row_sums[i] = sum;
        }
    }


    /*-------------------------
            Benchmarking
    --------------------------*/
    clock_t begin_row_sum = clock(); //start timing

    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {

        //compute sum of each row    
        for(int i=0; i<DIMENSION; i++){
            double sum = 0.;
            for(int j=0; j< DIMENSION; j++){
                sum += matrix[i][j];
            }
            row_sums[i] = sum;
        }
    }
    clock_t end_row_sum = clock(); //start timing


    clock_t begin_col_sum = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {

        //compute sum of each colum
        for(int j=0; j<DIMENSION; j++){
            double sum1 = 0;
            double sum2 = 0;
            for(int i=0; i< DIMENSION; i=i+2){
                sum1 += matrix[i][j];
                sum2 += matrix[i+1][j];
            }
            col_sums[j] = sum1 + sum2;
        }
    }
    clock_t end_col_sum = clock(); //start timing


    /*-------------------------
            Results
    --------------------------*/
    //calculate average time for row summation
    double total_time_rows_in_sec =  ((double)(end_row_sum-begin_row_sum)) / (double)CLOCKS_PER_SEC;
    double avg_time_row           = total_time_rows_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time to sum the rows is %f miliseconds\n", avg_time_row*1000.0);

    //calculate average time for column summation    
    double total_time_col_in_sec =  ((double)(end_col_sum-begin_col_sum)) / (double)CLOCKS_PER_SEC;
    double avg_time_col          = total_time_col_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time to sum the columns is %f miliseconds\n", avg_time_col*1000.0);


    printf("%f\n", matrix[19][91]);
    printf("%f\n", row_sums[20]);
    printf("%f\n", col_sums[20]);

    return EXIT_SUCCESS;

}
