#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    struct timeval inicio, final, aux;
    double tiempo, overhead;

    /* Obtenemos valor de N */
    int n, iter;
    if (argc == 3) {
		n = atoi(argv[1]);
        iter = atoi(argv[2]);
    }
    else {
        perror("No se ha pasado N ni ITER como parametros!\n");
        return EXIT_FAILURE;
    }

    /* Abrimos archivo para insertar tiempos */
    FILE *outfile = NULL;
    if ((outfile = fopen("tiempos_nopt.csv", "r+")) == NULL) {
        /* Creamos el archivo si no existe */
        if ((outfile = fopen("tiempos_nopt.csv", "w")) == NULL) {
            /* No se ha podido abrir el archivo */
            perror("Error al abrir el archivo de guardado de resultados.");
            return EXIT_FAILURE;
        }

        /* Header del csv */
        fprintf(outfile, "time_%d\n", n);
    } else {
        fseek(outfile, 0, SEEK_END);
    }

    /* CÓDIGO 1 */

    // Declaración
	int i, j;
    float a, b, c, d, k, x, y, z, t;
    float *A;
	
	A = (float *)malloc(sizeof(float) * n);

	// Precarga
	A[0] = k = x = y = z = t = i = j = 2.1;

	// Medición
    gettimeofday(&aux, NULL); /* Primera medida para tener tener en cuenta el overhead */

    gettimeofday(&inicio, NULL); /* Inicio de la medida del tiempo de ejecución */

	// Codigo sin optimizar
    for (j = 0; j < iter; j++)
        for (i = 0; i < n; i++) {
            a = x * y * z * t * A[i];
            b = x * z * t;
            c = y * t * A[i];
            d = k * A[i] - x * z;
            A[i] = (z * x * A[i]) + (y * t) + A[i];
        }

    gettimeofday(&final, NULL); /* Final de la medida del tiempo de ejecución */

    overhead = (inicio.tv_sec - aux.tv_sec + (inicio.tv_usec - aux.tv_usec) / 1.e6);
    tiempo = (final.tv_sec - inicio.tv_sec + (final.tv_usec - inicio.tv_usec) / 1.e6);

    // Guardado de resultados
    fprintf(outfile, "%lf\n", tiempo - overhead);

    fclose(outfile);

    /* CÓDIGO 2 */

    /* Abrimos archivo para insertar tiempos */
    outfile = NULL;
    if ((outfile = fopen("tiempos_opt.csv", "r+")) == NULL) {
        /* Creamos el archivo si no existe */
        if ((outfile = fopen("tiempos_opt.csv", "w")) == NULL) {
            /* No se ha podido abrir el archivo */
            perror("Error al abrir el archivo de guardado de resultados.");
            return EXIT_FAILURE;
        }

        /* Header del csv */
        fprintf(outfile, "time_%d\n", n);
    } else {
        fseek(outfile, 0, SEEK_END);
    }

    // Declaración
    float tmp1, tmp2, tmp3, tmp4;
    
	// Precarga
    A[0] = k = x = y = z = t = i = j = tmp1 = tmp2 = tmp3 = tmp4 = 2.1;

    // Medición
    gettimeofday(&aux, NULL); /* Primera medida para tener tener en cuenta el overhead */

    gettimeofday(&inicio, NULL); /* Inicio de la medida del tiempo de ejecución */

	// Codigo optimizado
    for (j = 0; j < iter; j++)
        for (i = 0; i < n; i++) {
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

    gettimeofday(&final, NULL); /* Final de la medida del tiempo de ejecución */

    overhead = (inicio.tv_sec - aux.tv_sec + (inicio.tv_usec - aux.tv_usec) / 1.e6);
    tiempo = (final.tv_sec - inicio.tv_sec + (final.tv_usec - inicio.tv_usec) / 1.e6);

    // Guardado de resultados
    fprintf(outfile, "%lf\n", tiempo - overhead);

    fclose(outfile);

    // Liberado de memoria
    free(A);

    return EXIT_SUCCESS;
}