#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int size=10;
	int **arr = (int**)malloc(size * sizeof(int*)); //create two dim array

	for(size_t index=0; index < size; index++)
		arr[index] = (int*)malloc(size * sizeof(int)); //create sub-arrays of size 10

	for( size_t i=0; i<size; i++){
		for (size_t j=0; j<size; j++)
			arr[i][j] = 0; //initialize each element to 0
	}

	printf("%d\n", arr[0][0]);

	for(size_t i=0; i<size; i++)
		free(arr[i]); //free each sub-array

	free(arr);

	return EXIT_SUCCESS;
}
