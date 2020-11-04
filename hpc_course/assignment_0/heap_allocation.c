#include <stdio.h>
#include <stdlib.h>

int main(void){
	long size = 1000000000;
	int *arr = (int*)malloc(size * sizeof(int));

	for ( size_t index=0; index < size; index++)
		arr[index] = 0;
	
	printf("%d\n", arr[0]);
	
	free(arr);

	return EXIT_FAILURE;
}
