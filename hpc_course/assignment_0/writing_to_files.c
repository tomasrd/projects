#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(void){

	int arr[SIZE][SIZE];

	for(int i=0; i<SIZE; i++){
		for (int j=0; j<SIZE; j++){
			arr[i][j]= i*j;
		}
	}

	FILE *fp = fopen("files_assignment.bin", "wb");

	if (fp == NULL){
		printf("Could not open the file\n");
		return EXIT_FAILURE;
	}

	size_t wrote = fwrite(arr, sizeof(int), SIZE*SIZE, fp);
	
	// check how many elements were written
	// printf("wrote %zu elements out of %d requested\n", wrote, SIZE*SIZE);

	fclose(fp);
	

	/*------------------------------------
	 * Check the contents of the file
	 *------------------------------------

	fp = fopen("files_assignment.bin", "rb");

	if (fp == NULL){
		printf("Could not open the file\n");
		return EXIT_FAILURE;
	}

	int ar[SIZE*SIZE];
	fread(ar, sizeof(int), SIZE*SIZE, fp);

	for(int i=0; i< SIZE; i++){
		for(int j=0; j<SIZE; j++)
			printf("%d", ar[10*i +j]);
		printf("\n");
	}

	fclose(fp);

	*/

	return EXIT_SUCCESS;
}
