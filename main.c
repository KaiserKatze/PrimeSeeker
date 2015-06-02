/* 
 * File:   main.c
 * Author: donizyo
 *
 * Created on June 2, 2015, 1:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX     4194305

int
main(int argc, char** argv)
{
    char *prime;
    int i, j, n;

    prime = (char *) malloc(MAX);
    if (!prime)
        return;
    n = sqrt(MAX);
    for (i = 0; i < MAX;)
    {
        prime[i++] = 0;
        if (i >= MAX)
            break;
        prime[i++] = 1;
    }

    for (i = 3; i < n; i += 2)
    {
        if (prime[i])
            for (j = i * 2; j <= n; j += i)
                prime[j] = 0;
    }

    prime[2] = 1;

    printf("Primes:\r\n");
    for (i = 2; i < n; i++)
        if (prime[i])
            printf("%i ", i);
    printf("\r\n");

    free(prime);
    prime = NULL;
    return (EXIT_SUCCESS);
}

