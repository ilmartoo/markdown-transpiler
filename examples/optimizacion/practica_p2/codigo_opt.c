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
	
	// Codigo optimizado
    for (j = 0; j < ITER; j++)
        for (i = 0; i < N; i++) {
            tmp1 = x * z;
            tmp2 = A[i];
            tmp3 = y * t;
            tmp4 = tmp1 * tmp2;
            a = tmp3 * tmp4;
            b = tmp1 * t;
            c = tmp3 * tmp2;
            d = k * tmp2 - tmp1;
            A[i] = tmp4 + tmp3 + tmp2;
        }
}