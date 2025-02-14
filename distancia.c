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
#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include <math.h>
#define GIB_SIZE (1024L * 1024L * 1024L)

// Implement the exercise in a function here
float distance(float* X,float* Y,size_t numelms){
    double cumsum=0;
    float var=0;
    for(size_t i = 0; i < numelms; i++){
        var = X[i]-Y[i];
        cumsum+=var*var;
    }
    return (float) sqrt((double) cumsum);
}


int main(int argc, char** argv){

    float N = 0;
    switch(argc) {
        case 1:
            N = 2.5f;
            break;
        case 2:
            N = atof(argv[1]);
            break;
        default:
            printf("ERROR: ARGUMENTOS INSUFICIENTES");
            exit(69);
            break;
    }


    size_t num_elements = (size_t) (N * GIB_SIZE) / sizeof(float);

    float *arrX = malloc(num_elements * sizeof(float));
    float *arrY = malloc(num_elements * sizeof(float));

    if(arrX <= 0 || arrY <= 0){
        printf("*ERROR: LOS VECTORES NO SE HAN CREADO CORRECTAMENTE\n");
        exit(1);
    }

    for(size_t i = 0; i < num_elements; i++){
        arrX[i] = rand()/(float) RAND_MAX;
        arrY[i] = rand()/(float) RAND_MAX;
    }

    // start timer
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // call the function
    float d = distance(arrX, arrY, num_elements);

    // stop timer
    gettimeofday(&end, NULL);


    printf("\nAcceso para asegurar la ejecución = %f\n", d);

    double tiempofinal=(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1e-6;
    FILE *arc;
    arc= fopen("tiempo_distancia.txt","a");
    fprintf(arc,"%f\n",tiempofinal);


    fclose(arc);
    free(arrX);
    free(arrY);
}
