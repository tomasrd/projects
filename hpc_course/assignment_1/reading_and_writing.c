#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_AMOUNT 104857
#define BENCHMARK_ITERATIONS 10

/*------------------------------------------------------------------------------------
The program writes and read integers into a binary file in two different wways:

1. individually
2. once, using an array
-------------------------------------------------------------------------------------*/

int main(void){


    /*---------------------------------
            Benchmarking - Writing
    -----------------------------------*/
    
    //1. write the integers individually

    FILE *fp = fopen("files_assignment.bin", "wb");
    if (fp == NULL){
		printf("Could not open the file\n");
		return EXIT_FAILURE;
    }
    
    clock_t write_indv_begin = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {
        for(int i=0; i<INT_AMOUNT; i++){
            fwrite(&i, sizeof(int), 1, fp);
            fflush(fp); //flush immediately after each write request.
        }
    }
    clock_t write_indv_end = clock(); //stop the clock
    fclose(fp);



    //2. write once, using an array
    
    // create and initialize the array of integers
    int arr[INT_AMOUNT];
    for(int i=0; i < INT_AMOUNT; i++)
        arr[i]= i;
    

    //try to open the file for writing
    fp = fopen("files_assignment.bin", "wb");
    if (fp == NULL){
		printf("Could not open the file\n");
		return EXIT_FAILURE;
    }

    clock_t write_once_begin = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) 
        fwrite(arr, sizeof(int), INT_AMOUNT, fp);
    clock_t write_once_end = clock(); //stop the clock
    fclose(fp);


    /*---------------------------------
            Benchmarking - Reading
    -----------------------------------*/


    //1. read each integer individually
    
    fp = fopen("files_assignment.bin", "rb");
	if (fp == NULL){
	    printf("Could not open the file\n");
	    return EXIT_FAILURE;
	}
	
    int read; //read an integer into the variable
    clock_t read_indv_begin = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) {
        for(int i=0; i < INT_AMOUNT; i++)
	        fread(&read, sizeof(int), 1, fp);
    }
    clock_t read_indv_end = clock(); //stop the clock
    fclose(fp);


    //2. read all at once
    
    //try to open the file
    fp = fopen("files_assignment.bin", "rb");
	if (fp == NULL){
	    printf("Could not open the file\n");
	    return EXIT_FAILURE;
	}
   
    int read_once[INT_AMOUNT]; //save the integers into the array
    clock_t read_once_begin = clock(); //start timing
    for( int iter=0; iter< BENCHMARK_ITERATIONS; iter++) 
        fread(read_once, sizeof(*read_once), INT_AMOUNT, fp);
    clock_t read_once_end = clock(); //stop the clock
    fclose(fp);


    /*-------------------------
            Results
    --------------------------*/

    //1. write individually
    double total_time_write_indv_in_sec = ((double)(write_indv_end-write_indv_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_write_indv_in_sec   = total_time_write_indv_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of writing individually is %f miliseconds\n", avg_time_write_indv_in_sec*1000.0);

    //2. write once
    double total_time_write_once_in_sec = ((double)(write_once_end-write_once_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_write_once_in_sec   = total_time_write_once_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of writing once is %f miliseconds\n", avg_time_write_once_in_sec*1000.0);

    //1. read individually
    double total_time_read_indv_in_sec = ((double)(read_indv_end-read_indv_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_read_indv_in_sec   = total_time_read_indv_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of reading individually is %f miliseconds\n", avg_time_read_indv_in_sec*1000.0);

    //2. read once
    double total_time_read_once_in_sec = ((double)(read_once_end-read_once_begin)) / (double)CLOCKS_PER_SEC;
    double avg_time_read_once_in_sec   = total_time_read_once_in_sec / (double)BENCHMARK_ITERATIONS;
    printf("Average time took for a single iteration of reading once is %f miliseconds\n", avg_time_read_once_in_sec*1000.0);

    return EXIT_SUCCESS;
}
