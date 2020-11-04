#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){

	clock_t begin = clock();
	int sum=0;
	
	for(int i=0; i<1e9; i++){
		sum +=i;
	}

	clock_t end = clock();

	 printf("difference is %f\n", (double) (end-begin)/CLOCKS_PER_SEC);

	return EXIT_SUCCESS;
}
