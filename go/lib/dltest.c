#include <stdio.h>
#include <dlfcn.h>

int main()
{
	void *handle;
	int (*Add)(int, int), 
	    (*Sub)(int, int), 
            (*Mul)(int, int), 
            (*Div)(int, int);

	char *error;
	int a,b;
	handle=dlopen("./libtest.so",RTLD_LAZY);
	
	if(!handle) {
			fputs(dlerror(), stderr);
	}
	
	Add=dlsym(handle, "Add");
	Sub=dlsym(handle, "Sub");
	Mul=dlsym(handle, "Mul");
	Div=dlsym(handle, "Div");
	printf("정수값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	printf("%d + %d = %d\n", a, b, (*Add)(a,b));
	printf("%d - %d = %d\n", a, b, (*Sub)(a,b));
	printf("%d * %d = %d\n", a, b, (*Mul)(a,b));
	printf("%d / %d = %d\n", a, b, (*Div)(a,b));
	dlclose(handle);
}
