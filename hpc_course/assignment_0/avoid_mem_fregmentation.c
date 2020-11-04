#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int size=10;
	int *arr_entries = (int*)malloc(size *size * sizeof(int)); //allocate memory for 100 integers 
	int **arr = (int**)malloc(size *size * sizeof(int*)); //allocate memory for 10 integer pointers

	for( size_t i=0, j=0; i<size; i++, j+=size){
			arr[i] = arr_entries + j;  //each arr[i] points to 10 integers arr[0]-> 0, arr[1]->10,...
	}


	for(size_t i=0; i<size; i++)
		for(size_t j=0; j<size; j++)
			arr[i][j] = 0;

	printf("%d\n", arr[0][0]);

	free(arr);
	free(arr_entries);

	return EXIT_SUCCESS;
}
