#include <stdio.h>
#include <stdlib.h>
#include "my_perror2.h"

int main(int argc, char *argv[]){
	FILE *f;

	if(argc<2){
		printf("Usage: perror_use2 file_name\n");
		exit(1);
	}

	if( (f=fopen(argv[1], "r")) ==NULL){
		my_perror("fopen");
		exit(1);
	}

	printf("Open a file \"%s\". \n", argv[1]);

	fclose(f);

}
