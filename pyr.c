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

void calc_truncated_pyramid(pyr_t *pyramid, int n)
{
    // try different top layers starting with 2
    for(int i=2; i<n; i++) {

        int tmp=n;
        // for each top layer try to subtract incrementing values until you reach 0
        for(int j=i; j<n; j++) {
            tmp-=j;
            if(tmp==0) {
                pyramid->n_first_row=j;
                pyramid->n_first_row=(j-i+1);
                return;
            }
        }
    }

    debugprint(pyramid);
}

int main(int argc, char **argv)
{
    int n=0;
    pyr_t pyramid; // Pyramid data type
    pyramid.character = '*'; // Set character to build the pyramid with

    scanf("%d", &n); // Read number of characters to print

    calc_truncated_pyramid(&pyramid,n);  // Build the truncated pyramid
    print_truncated_pyramid(&pyramid); // Print the pyramid

    return 0;
}
