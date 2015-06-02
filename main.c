/* 
 * File:   main.c
 * Author: donizyo
 *
 * Created on June 2, 2015, 1:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 16777216

int
main(int argc, char** argv)
{
    char *prime;
    int i, j, k;
    float n;
    double a, b;

    n = (float) sqrt(MAX);
    prime = (char *) malloc(MAX);
    if (!prime)
        return;
    for (i = 0; i < MAX;)
        prime[i++] = 1;

    for (i = 0; i <= n; i++)
    {
        if (!prime[i])
            continue;
        k = 2 * i + 3;
        for (j = i * (2 * i + 6) + 3;
                j < MAX; j += k)
            prime[j] = 0;
    }

    k = 0;
    b = 0.0f;
    printf("Primes:\r\n");
    for (i = 0; i < n; i++)
    {
        if (!prime[i])
            continue;
        j = 2 * i + 3;
        a = (1.0 - fabs(3.0 - j / pow(2.0, floor(log2(j)) - 1.0))) *
                (1.0 - fabs(1.0 + 2.0 * (1.0 - j / pow(10.0, floor(log10(j)))) / 9.0));
        if (a > b)
        {
            b = a;
            k = j;
        }
        printf("%i(%f)\r\n", j, a);
    }
    printf("\r\n\r\nBest: %i(%f)\r\n", k, b);

    free(prime);
    prime = NULL;
    return (EXIT_SUCCESS);
}
