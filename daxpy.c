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
#define GIB_SIZE (1024L * 1024L * 1024L)

// Implement the exercise in a function here
void daxpy(double *arrX, double *arrY, double alpha, size_t N){
    for(size_t i = 0; i < N; i++){
        arrY[i] = alpha * arrX[i] + arrY[i];
    }
}

// Main program
int main(int argc, char** argv){
    unsigned long N = 0;

    switch(argc) {
        case 2:
            N = 6;
            break;
        case 3:
            N = atol(argv[2]);
            break;
        default:
            printf("ERROR: ARGUMENTOS INSUFICIENTES");
            exit(69);
            break;
    }

    double alpha = atof(argv[1]);
    size_t num_elements = N * GIB_SIZE / sizeof(double);

    double *arrX = malloc(num_elements * sizeof(double));
    double *arrY = malloc(num_elements * sizeof(double));

    if(arrX <= 0 || arrY <= 0){
        printf("ERROR: LOS VECTORES NO SE HAN CREADO CORRECTAMENTE\n");
        exit(1);
    }

    for(int i = 0; i < num_elements; i++){
        arrX[i] = rand();
        arrY[i] = rand();
    }


    // start timer
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);

    // call the function
    daxpy(arrX, arrY, alpha, num_elements);

    // stop timer
    gettimeofday(&end, NULL);



    printf("Acceso para asegurar la ejecución = %f\n", arrY[rand()]);


    double tiempofinal=(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)*1e-6;
    FILE *arc;
    arc= fopen("tiempo_daxpy.txt","a");
    fprintf(arc,"%f\n",tiempofinal);


    fclose(arc);
    free(arrX);
    free(arrY);
}
