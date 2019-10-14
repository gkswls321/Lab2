#include <stdio.h>
#include <dlfcn.h>


int main()
{
	void *handle;	
	int (*Add)(int x, int y), 
	    (*Sub)(int x, int y), 
            (*Mul)(int x, int y), 
            (*Div)(int x, int y);

	char *error;

	hanlde = dlopen ("./lib/libtest.so", RTLD_LAZY);
	

	if (!handle) {
		fputs(dlerror(), stderr);
		exit(1);
	}
	
	Add = dlsym(handle, "Add");
	if((error = dlerror()) != NULL) {
		fprint(stderr, "%s", error);
			exit(1);
			}


	
	Sub = dlsym(handle, "Sub");
	if((error = dlerror()) != NULL) {
		fprint(stderr, "%s", error);
			exit(1);
			}

	
	Mul = dlsym(handle, "Mul");
	if((error = dlerror()) != NULL) {
		fprint(stderr, "%s", error);
			exit(1);
			}

	
	Div = dlsym(handle, "Div");
	if((error = dlerror()) != NULL) {
		fprint(stderr, "%s", error);
			exit(1);
	}

	printf("정수값을 입력하세요 : ");
	scanf("%d %d", &x, &y);
	printf("덧셈 : %d + %d = %d\n", x, y, (*Add)(x, y));
	printf("뺄셈 : %d - %d = %d\n", x, y, (*Sub)(x, y));
	printf("곱셈 : %d * %d = %d\n", x, y, (*Mul)(x, y));
	printf("나눗셈 : %d / %d = %d\n", x, y, (*Div)(x, y));
	dlclose(handle);

}
