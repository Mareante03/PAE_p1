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
#include <math.h>
#include "sys/time.h"
#include "samplecode/pgmio.h"


#define K_LEN 3
#define K_SIZE K_LEN * K_LEN
#define PADDING ((K_LEN-1)/2)

typedef float pixel;

 //BLUR
 /*
pixel kernel[K_SIZE] = {  1,1, 1,
                          1, 1,1,
                          1,1, 1};
*/

/*//IDENTITY
pixel kernel[K_SIZE] = {  0,0, 0,
                          0, 1,0,
                          0,0, 0};
*/

//SHARPEN

pixel kernel[K_SIZE] = {  0,-1, 0,
                          -1,5,-1,
                          0,-1, 0};

//LAPLACE
/*pixel kernel[K_SIZE] = {  0,-1, 0,
                          -1,4,-1,
                          0,-1, 0};
*/
/*//TAM 5
pixel kernel[K_SIZE] = { 1,1,1,1,1,
                         1,1,1,1,1,
                         1,1,1,1,1,
                         1,1,1,1,1,
                         1,1,1,1,1};
*/
/*//TAM 7
pixel kernel[K_SIZE] = { 1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1,
                         1,1,1,1,1,1,1};
*/



pixel operacion(int x, int y, int w, int h, pixel*ampliada);

// Implement the exercise in a function here
void convolucion(int w, int h, pixel* matr, pixel* ampliada, pixel* res){
    int index=0;
    for(int i=0;i<(w+(PADDING*2));i++){
        ampliada[index]=0;index++;
    }

    for(int i = 0; i < h;i++){
        for(int k=0;k<PADDING;k++){//previo
            ampliada[index]=0;index++;
        }
        for(int j = 0; j < w; j++){
            ampliada[index] = matr[i*w+j];index++;
        }
        for(int k=0;k<PADDING;k++){//post
            ampliada[index]=0;index++;
        }
    }

    for(;index<(w+(PADDING*2))*(h+(PADDING*2)); index++){
        ampliada[index]=0;
    }

    for(int y = 0; y < h;y++){
        for(int x = 0; x < w; x++){
            res[(y * w) + x] = operacion(x, y, w ,h,ampliada);
        }
    }
}

pixel operacion(int x, int y, int w, int h, pixel*ampliada){
    pixel cumsum = 0;

    for(int i = 0; i < K_LEN; i++){
        for(int j = 0; j < K_LEN; j++){
            cumsum += ampliada[(y + i) * (w+2*PADDING) + x + j] * kernel[i * K_LEN + j];
        }
    }
    return cumsum;
}


// Main program
int main(int argc, char **argv){

    pixel* ampliada;
    pixel* res;
    int w, h;
    pixel* matr = loadPGM32(argv[1], &w, &h);
    ampliada = (pixel *) malloc(sizeof(pixel) * (w + PADDING*2) * (h + PADDING*2));
    res = (pixel *) malloc(sizeof(pixel) * w * h);

    // start timer
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // call the function
    convolucion(w,h,matr,ampliada,res);

    // stop timer
    gettimeofday(&end, NULL);

    savePGM32("images/resultado.pgm", res, w, h);

    double tiempofinal=(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1e-6;
    FILE *arc;
    arc= fopen("tiempo_conv2d.txt","a");
    fprintf(arc,"%f\n",tiempofinal);


    fclose(arc);
    free(res);
    free(matr);
    free(ampliada);
}
