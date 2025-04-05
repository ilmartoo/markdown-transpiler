#define N 70000000

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

double* res;
int main(int argc, char* argv[]) {
    int i;
    double x;
    res = (double *)malloc(sizeof(double) * N);

    struct timeval inicio, final, aux;
    double tiempo, overhead;

    /* Abrimos archivo para insertar tiempos */
    FILE* outfile = NULL;
    if ((outfile = fopen("tiempos.csv", "r+")) == NULL) {
        /* Creamos el archivo si no existe */
        if ((outfile = fopen("tiempos.csv", "w")) == NULL) {
            /* No se ha podido abrir el archivo */
            perror("Error al abrir el archivo de guardado de resultados.");
            return EXIT_FAILURE;
        }

        /* Header del csv */
        fprintf(outfile, "real_time_%d\n", N);
    } else {
        fseek(outfile, 0, SEEK_END);
    }

    /* Precarga de cache */
    i = 2;
    x = res[0] = 2.1;

    gettimeofday(&aux, NULL); /* Primera medida para tener tener en cuenta el overhead */

    gettimeofday(&inicio, NULL); /* Inicio de la medida del tiempo de ejecución */

    /* Inicio del código a medir */

    for (i = 0; i < N; i++)
        res[i] = 0.0004 * i;
    for (i = 0; i < N; i++) {
        x = res[i];
        if (x < 10.0e6)
            x = x * x + 0.0004;
        else
            x = x - 900;
        res[i] += x;
    }

    /* Final del código a medir */

    gettimeofday(&final, NULL); /* Final de la medida del tiempo de ejecución */

    overhead = (inicio.tv_sec - aux.tv_sec + (inicio.tv_usec - aux.tv_usec) / 1.e6);
    tiempo = (final.tv_sec - inicio.tv_sec + (final.tv_usec - inicio.tv_usec) / 1.e6);

    printf("resultado= %e ", res[N - 1]);

    /* Guardado de resultados */
    fprintf(outfile, "%lf\n", tiempo - overhead);

    /* Liberación de memoria*/
    free(res);

    return EXIT_SUCCESS;
}