/*Ejecuta una convoluci´on bidimensional sobre una imagen X con dimensiones M ×N. Esta opera
ci´on genera cada elemento de salida como una suma ponderada de ciertos elementos de la imagen X.
Los coeficientes o pesos en la suma est´an determinados por una m´ascara de entrada K, com´unmente
        llamada kernel de la convoluci´on. Los kernels suelen ser de forma cuadrada. Desarrolla la convo
        luci´on de manera que sea compatible con cualquier tama˜ no de kernel y realiza pruebas usando el
siguiente kernel de tama˜ no 3 × 3:


 0 −1  0
−1  5 −1
 0 −1  0
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "samplecode/pgmio.h"


#define K_LEN 3
#define K_SIZE K_LEN * K_LEN
#define PADDING ((K_LEN-1)/2)

typedef float pixel;

 //BLUR
pixel kernel[K_SIZE] = {  1,1, 1,
                          1, 1,1,
                          1,1, 1};


/*//IDENTITY
pixel kernel[K_SIZE] = {  0,0, 0,
                          0, 1,0,
                          0,0, 0};
*/

/*//SHARPEN
pixel kernel[K_SIZE] = {  0,-1, 0,
                          -1,5,-1,
                          0,-1, 0};
*/
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



pixel* ampliada;


pixel* res;

pixel convolucion(int x, int y, int w, int h){
    pixel cumsum = 0;

    for(int i = 0; i < K_LEN; i++){
        for(int j = 0; j < K_LEN; j++){
            cumsum += ampliada[(y + i) * (w+2*PADDING) + x + j] * kernel[i * K_LEN + j];
        }
    }



    return cumsum;

}





int main(int argc, char **argv){
    int w, h;
    //asumimos que la matriz está delimitada tal que [línea,línea,línea...]
    pixel* matr = loadPGM32(argv[1], &w, &h);
    ampliada = (pixel *) malloc(sizeof(pixel) * (w + PADDING*2) * (h + PADDING*2));
    res = (pixel *) malloc(sizeof(pixel) * w * h);

    ampliada[875] = 255;

    //Padding


/*
    int ind_ampliada=0;//indice de la matriz ampliada
    for(int j=0; j < PADDING * (w+PADDING*2); j++){//itera el ancho*lineas de padding
        ampliada[ind_ampliada]=60;//rellena con una linea de ceros
        ind_ampliada++;
    }


    savePGM32("images/outampliada1.pgm", ampliada, w+PADDING*2, h+PADDING*2);


    for(int i = 0; i < h; i++){
        for(int k = 0; k < PADDING; k++){ //Padding izquierda
            ampliada[(i + PADDING) * (w + 2 * PADDING) + k] = 0;
        }

        for (int j = 0; j < w; j++){ //Copia matriz
            ampliada[(i + PADDING) * (w + 2 * PADDING) + PADDING + j] = matr[i * w + j];
        }

        for(int k = w + PADDING; k < w + 2 * PADDING; k++){ //Padding derecha
            ampliada[(i + PADDING) * (w + 2 * PADDING) + k] = 0;
        }
    }

    savePGM32("images/outampliada2.pgm", ampliada, w+PADDING*2, h+PADDING*2);

    for(int i = (h + PADDING) * (w + 2 * PADDING); (h + 2 * PADDING) * (w + 2 * PADDING); i++){
        ampliada[i] = 0;
    }
*/


    int index=0;
    for(int i=0;i<(w+(PADDING*2));i++){
        ampliada[index]=0;index++;
    }

    savePGM32("images/outampliada1.pgm", ampliada, w+PADDING*2, h+PADDING*2);

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

    savePGM32("images/outampliada2.pgm", ampliada, w+PADDING*2, h+PADDING*2);

    for(;index<(w+(PADDING*2))*(h+(PADDING*2)); index++){
        ampliada[index]=0;
    }




    savePGM32("images/pre.pgm", ampliada, w+PADDING*2, h+PADDING*2);

    //Cálculo de la convolución para cada elemento de la matriz ampliada
    for(int y = 0; y < h;y++){
        for(int x = 0; x < w; x++){
            res[(y * w) + x] = convolucion(x, y, w ,h);
        }
    }
    savePGM32("images/pucio.pgm", ampliada, w+PADDING*2, h+PADDING*2);
    savePGM32("images/outampliada.pgm", ampliada, w+PADDING*2, h+PADDING*2);
    savePGM32("images/outprueba.pgm", res, w, h);
    printf("\nEjecucion correcta.\n");

    free(res);
    free(matr);
    free(ampliada);
}
