#include <stdio.h>
#include <stdlib.h>
#define my_assert(expression) do{ \
 if (expression!=1) {\
 printf("%s: %s:%d: %s: Assertion \'%s\' failed.\n", __FILE__, __FILE__, __LINE__, __func__, #expression); \
 abort(); } }while(0)

void value(int num)
{
	{my_assert( ((num>=0) && (num<100)) );}
	printf("value: num=%d\n", num);
}

int main(int argc, char *argv[]){
	int num;

	if(argc<2){
		fprintf(stderr, "Usage: assert_test aNumber\n (0 <= aNumber <= )\n");
	exit(1);
	}

	num = atoi(argv[1]);
	value(num);
}
