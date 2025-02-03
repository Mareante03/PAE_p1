#include "stdio.h"
#include "stdlib.h"
#define GIB_SIZE (1024L * 1024L * 1024L)

void daxpy(double *arrX, double *arrY, double alpha, size_t N){
    for(size_t i = 0; i < N; i++){
        arrY[i] = alpha * arrX[i] + arrY[i];
    }
}


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
        printf("*EXTREMELY LOUD INCORRECT BUZZER*\npum explotó\n");
    }

    printf("Alfa: %f\n", alpha);

    for(int i = 0; i < num_elements; i++){
        arrX[i] = rand();
        arrY[i] = rand();
    }

    daxpy(arrX, arrY, alpha, num_elements);

    printf("random = %f\n", arrY[rand()]);

    free(arrX);
    free(arrY);
}