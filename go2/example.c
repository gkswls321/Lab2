#include <stdio.h>
#include <stdlib.h>

void input(int **m, int first, int second);
void output(int **m, int first, int second);

int main(int args, int argv[]){
	
	int a, b;
	int first, second;
	printf("행 입력 : "); 
	scanf(" %d", &first);

	printf("열 입력 : ");
	scanf(" %d", &second); 
	int **d_Array = malloc(sizeof(int *) *first);
	int **c_Array = malloc(sizeof(int *) *first);
	int **out = malloc(sizeof(int *) *first);
		
	for(a=0; a<first; a++){
		d_Array[a]=malloc(sizeof(int) *second);
		c_Array[a]=malloc(sizeof(int) *second);
		out[a]=malloc(sizeof(int) *second);
	}

	printf("첫 번째 행렬 : \n");
	input(d_Array, first, second);
	output(d_Array, first, second);
	printf("\n\n");	
	printf("두 번째 행렬 : \n");
	input(c_Array, first, second);
	output(c_Array, first, second);
	printf("\n\n");	
	printf("두 개의 행렬의 합 : \n");
	
	for(a=0; a<first; a++){
		for(b=0; b<second; b++){
			out[a][b] = d_Array[a][b] + c_Array[a][b];
		}
	}
	
	for(a=0; a<first; a++){
		for(b=0; b<second; b++){
			printf("%.2d ", out[a][b]);
		}
		printf("\n");
	}
	
	for(a=0; a<second; a++){
		free(d_Array[a]);
		free(c_Array[a]);
		free(out[a]);
	}
	
	free(d_Array);
	free(c_Array);
	free(out);
	
	return 0;
	
}

void input(int **m, int first, int second){
	int a,b;
	for(a=0; a<first; a++){
		for(b=0; b<second; b++){
			m[a][b] = a+b;
		}
	}
}

void output(int **m, int first, int second){
	int a,b;
	for(a=0; a<first; a++){
		for(b=0; b<second; b++){
			printf("%d ", m[a][b]);
		}
		printf("\n");
	}
}
