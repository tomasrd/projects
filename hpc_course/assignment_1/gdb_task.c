#include <stdio.h>
#include <stdlib.h>

int main(void){
    int * arr = NULL;
    int sum = 0;

    for( int index = 0; index <10; index++){
        arr[index] = index;
    }

    for( int index = 0; index <10; index++){
        sum += arr[index];
    }

    free(arr);

    return EXIT_SUCCESS;
}