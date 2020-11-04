#include <stdio.h>
#include <stdlib.h>

int main(void){
	int size = 1e7;
	int arr[size];

	for ( size_t index=0; index < size; index++)
		arr[index] = 0;

	printf("%d\n", arr[0]);

	return EXIT_FAILURE;
}
