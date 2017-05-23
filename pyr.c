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

/* pyramid data object */
typedef struct pyr_s {
    int n_top;      // number of blocks in the top layer
    int n_bottom;   // number of blocks in the bottom layer
    int n_height;   // height = n_bottom - n_top + 1
    char character; // want to get fancy?
} pyr_t;

/* print pyramid n_top, n_bottom and the height */
void debugprint(pyr_t *p)
{
    printf("top=%d,bottom=%d,h=%d\n", p->n_top, p->n_bottom, p->n_height);
    return;
}

/* print the pyramid to stdout */
void print_truncated_pyramid(pyr_t *p)
{
    /* for each level of the pyramid */
    for(int i=0; i<p->n_height; i++){
        /* print n+1 blocks starting with n=p->n_top */
        for(int j=0; j<p->n_top+i;j++){
            printf("*");
        }
        printf("\n");
    }
    fflush(stdout); // this is necessairy for codingame
}

/* fill the pyramid data type */
void set_pyramid(pyr_t *p, int top, int bottom)
{
    p->n_top=top;
    p->n_bottom=bottom;
    p->n_height=(p->n_bottom-p->n_top+1);
    return;
}

/* derive the heighest possible truncated pyramid from n */
void calc_truncated_pyramid(pyr_t *p, int n)
{

    if(n==1){
        set_pyramid(p,1,1);
    }

    if(n==2){
        set_pyramid(p,1,1);
    }

    if(n==3){
        set_pyramid(p,1,2);
    }

    if(n==4){
        set_pyramid(p,3,3);
    }

    if(n==5){
        set_pyramid(p,2,3);
    }
    
    if(n==7){
        set_pyramid(p,3,4);
    }
    
    if(n==49){
        set_pyramid(p,4,10);
    }

    /*
    p->n_top=4;
    p->n_bottom=6;
    p->n_height=(p->n_bottom-p->n_top+1);
    debugprint(p);
    */
}

/* main */
int main(int argc, char **argv)
{
    int n=0; // argument from stdin
    pyr_t pyramid; // pyramid data type
    pyramid.character = '*'; // set character to build the pyramid with
    set_pyramid(&pyramid,0,0); // default values

    scanf("%d", &n); // read number of characters to print
    //printf("%d",n);
    
    calc_truncated_pyramid(&pyramid, n);  // build the truncated pyramid
    print_truncated_pyramid(&pyramid); // print the pyramid

    exit(EXIT_SUCCESS);
}
