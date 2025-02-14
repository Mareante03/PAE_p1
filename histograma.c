/**
 * @brief Template for Labs
 *
 * PAE [G4011452] Labs
 * Last update: 14/02/2025
 * Issue date:  30/01/2022
 *
 * Student name: Anxo Trillo Santamaría
 * Student name: Mateo Senín López
 *
 */

// General utilities
#include <stdio.h>
#include <stdlib.h>
#include "sys/time.h"
#include "samplecode/pgmio.h"

// Implement the exercise in a function here
void histograma(size_t n, unsigned char *matr, int* vector){
    for(int i = 0; i < n; i++) {
        vector[matr[i]] += 1;
    }
}


// Main program
int main(int argc,char**argv){

    int vector[256];
    for(int i=0;i<256;i++){
        vector[i]=0;
    }

    int w, h;
    unsigned char* matr = loadPGMu8(argv[1], &w, &h);
    size_t n = w * h;

    // start timer
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // call the function
    histograma(n,matr,vector);

    // stop timer
    gettimeofday(&end, NULL);

    printf("\n");
    for(int i = 0; i < 256; i++) {
        printf("%d, ",vector[i]);
    }
    printf("\n");


    double tiempofinal=(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1e-6;
    FILE *arc;
    arc= fopen("tiempo_histograma.txt","a");
    fprintf(arc,"%f\n",tiempofinal);


    fclose(arc);
    free(matr);
}
