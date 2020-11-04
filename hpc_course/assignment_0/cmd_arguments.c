#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main( int argc, char *argv[]){

	int cmd_arg;
	int first_arg, second_arg;

	while ((cmd_arg = getopt(argc, argv, "a:b:")) != -1){
		switch(cmd_arg){
			case 'a': first_arg = atoi(optarg);
				  break;
			
			case 'b': second_arg = atoi(optarg);
				  break;

			case '?':
			default : printf("Couldn't read the option\n");

				  return EXIT_FAILURE;
		}
	}


		 printf("A is %d and B is %d\n", first_arg, second_arg);

		return EXIT_SUCCESS;
}
