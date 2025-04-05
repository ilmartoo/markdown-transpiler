#include <stdio.h>
#include <stdlib.h>

#define ITER 10000
#define N 10000

void main(void) {
    // Declaración
	int i, j;
    float a, b, c, d, k, x, y, z, t;
    float *A;
	float tmp1, tmp2, tmp3, tmp4;
	
	// Reserva de memoria
	A = (float *)malloc(sizeof(float) * N);

	// Precarga
	// A[0] = k = x = y = z = t = i = j = 2.1;
	
	// Codigo sin optimizar
    for (j = 0; j < ITER; j++)
        for (i = 0; i < N; i++) {
            a = x * y * z * t * A[i];
            b = x * z * t;
            c = y * t * A[i];
            d = k * A[i] - x * z;
            A[i] = (z * x * A[i]) + (y * t) + A[i];
        }
}