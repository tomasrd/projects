#include <stdio.h>
#include <stdlib.h>

int main(void){

    int *arr;
    arr = (int*)malloc(10*sizeof(int)); //allocate space for 10 ints
    int sum = 0;

    for (int index = 0; index < 10; index++){
        arr[index] = index; //initialize place i to the value i
    }

    for (int index = 0; index < 10; index++){
        sum += arr[index]; //sum the values of the "array"
    }

    printf("%d\n", sum);

    free(arr);
    
    return EXIT_SUCCESS;
}
