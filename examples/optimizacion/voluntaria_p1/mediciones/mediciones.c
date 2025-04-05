#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Funciones auxiliares del cálculo de las matrices*/
#define Nmax 600 /* Tamaño de la matriz */

void producto(float x, float y, float *z) {
    *z = x * y;
}

int main(int argc, char *argv[]) {
    struct timeval inicio, final, aux;
    double tiempo, overhead;

    /* Variables del código a medir */
    float A[Nmax][Nmax], B[Nmax][Nmax], C[Nmax][Nmax], t, r;
    int i, j, k, n;

    /* Precarga de caché */
    i = j = k = n = t = r = 2;
    A[0][0] = B[0][0] = C[0][0] = 2.1;

    /* Abrimos archivo para insertar tiempos */
    FILE *outfile = NULL;
    if ((outfile = fopen("tiempos.csv", "r+")) == NULL) {
        /* Creamos el archivo si no existe */
        if ((outfile = fopen("tiempos.csv", "w")) == NULL) {
            /* No se ha podido abrir el archivo */
            perror("Error al abrir el archivo de guardado de resultados.");
            return EXIT_FAILURE;
        }

        /* Header del csv */
        fprintf(outfile, "time_%d\n", Nmax);
    } else {
        fseek(outfile, 0, SEEK_END);
    }

    gettimeofday(&aux, NULL); /* Primera medida para tener tener en cuenta el overhead */

    gettimeofday(&inicio, NULL); /* Inicio de la medida del tiempo de ejecución */

    /* Inicio del código a medir */
    for (i = 0; i < Nmax; i++) /* Valores de las matrices */
        for (j = 0; j < Nmax; j++) {
            A[i][j] = (i + j) / (j + 1.1);
            B[i][j] = (i - j) / (j + 2.1);
        }
    for (i = 0; i < Nmax; i++) /* Producto matricial */
        for (j = 0; j < Nmax; j++) {
            t = 0;
            for (k = 0; k < Nmax; k++) {
                producto(A[i][k], B[k][j], &r);
                t += r;
            }
            C[i][j] = t;
        }

    /* Final del código a medir */

    gettimeofday(&final, NULL); /* Final de la medida del tiempo de ejecución */

    overhead = (inicio.tv_sec - aux.tv_sec + (inicio.tv_usec - aux.tv_usec) / 1.e6);
    tiempo = (final.tv_sec - inicio.tv_sec + (final.tv_usec - inicio.tv_usec) / 1.e6);

    /* Guardado de resultados */
    fprintf(outfile, "%lf\n", tiempo - overhead);

    /* Codigo de impresión para evitar la eliminación del
     * código anterior derivado de las optimizaciones */
    printf("\n");
    for (i = 0; i < Nmax; i++) {
        for (j = 0; j < Nmax; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    /* Cerrado del archivo */
    fclose(outfile);
    return EXIT_SUCCESS;
}