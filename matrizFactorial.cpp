#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct timespec start, stop;
int i, j, k;
char *n,*m, *t; 

unsigned long long factorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
	
int main(int argc, char **argv) {
	
	long MAX_RANDOM = strtol(argv[2], &m, 10);
	long MAX_SIZE = strtol(argv[1], &n, 10);
	int sentido = strtol(argv[3], &t, 10); // 0 filas   -    x columnas 
	
	int mat[(int)MAX_SIZE][(int)MAX_SIZE];
	int res[(int)(MAX_SIZE*MAX_SIZE)];
	
	srand(time(NULL));
	for(i = 0; i < (int)MAX_SIZE; i++) {
		for(j = 0; j < (int)MAX_SIZE; j++) {
			mat[i][j] = rand() % (int)MAX_RANDOM;
		}
	}
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);		// inicia contador de tiempo
	if(sentido == 0) {
		int res_i = 0;
		for(i = 0; i < (int)MAX_SIZE; i++) {
			for(j = 0; j < (int)MAX_SIZE; j++) {
				res[res_i] = factorial(mat[i][j]);
				res_i++;
			}
		}
	} else {
		int res_i = 0;
		for(i = 0; i < (int)MAX_SIZE; i++) {
			for(j = 0; j < (int)MAX_SIZE; j++) {
				res[res_i] = factorial(mat[j][i]);
				res_i++;
			}
		}
	}
	
		
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&stop);		// termina el contador
	double tiempo = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / 1.0e9;
	
	printf("%.10f", tiempo);
   return 0;
}
