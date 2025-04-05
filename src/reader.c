#include <stdio.h>

typedef struct InputGuard
{
    FILE *file;
    char blocks[][2];
} InputGuard;
