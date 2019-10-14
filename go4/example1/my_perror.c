#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void my_perror(const char *s){
	
	if(s==NULL)
		printf("%s\n", strerror(errno));
	else
		printf("%s: %s\n", s, strerror(errno));
	
	exit(1);
}
