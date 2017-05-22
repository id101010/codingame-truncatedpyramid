/*
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include<stdbool.h>
#include<unistd.h>

typedef struct pyr_s {
    int n_first_row;
    int n_height;
    char character;
} pyr_t;

void debugprint(pyr_t *p)
{
    printf("g=%d,h=%d\n", p->n_first_row, p->n_height);
    return;
}

void print_truncated_pyramid(pyr_t *p)
{
    for(int i=(p->n_height); i>=0; i--) { // for each row
        for(int j=0; j<(p->n_first_row-2*i); j++) { // print n elements
            printf("*");
        }
        printf("\n");
    }
}

void print_truncated_pyr(pyr_t *pyramid, int n)
{
    int t=0;

    pyramid->n_first_row = n/2; // Calculate first row

    // find number of rows
    for(int i=0; i<n; i++) {
        t = (n/2 - 2*i); // Calculate each layer, starting with n/2

        if(t <= 0 || t == 1) { // break if the layer gets negative or the top is reached
            pyramid->n_height = i;
            break;
        }
        //printf("%d: %d\n", i, t);
    }

    //debugprint(pyramid);
    print_truncated_pyramid(pyramid);
}

int main(int argc, char **argv)
{
    int n=0;
    pyr_t pyramid; // Pyramid data type
    pyramid.character = '*'; // Set character to build the pyramid with

    scanf("%d", &n); // Read number of characters to print

    print_truncated_pyr(&pyramid,n);  // Build the truncated pyramid

    return 0;
}
