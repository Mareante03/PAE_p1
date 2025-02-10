#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#define GIB_SIZE (1024L * 1024L * 1024L)

float distance(float* X,float* Y,size_t numelms){
    double cumsum=0;
    float var=0;
    for(size_t i = 0; i < numelms; i++){
        var = X[i]-Y[i];
        cumsum+=var*var;
    }
    //111855208.448896
    printf("\nMojonazo=%lf\n",cumsum);
    return (float) sqrt((double) cumsum);

}


int main(int argc, char** argv){

    srand(25);

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

//datos float, array de 2.5gb por defecto

    size_t num_elements = (size_t) (N * GIB_SIZE) / sizeof(float);

    float *arrX = malloc(num_elements * sizeof(float));
    float *arrY = malloc(num_elements * sizeof(float));

    if(arrX <= 0 || arrY <= 0){
        printf("*EXTREMELY LOUD INCORRECT BUZZER*\npum explotó\n");
        exit(1);
    }

    for(size_t i = 0; i < num_elements; i++){
        arrX[i] = rand()/(float) RAND_MAX;
        arrY[i] = rand()/(float) RAND_MAX;
    }

    printf("\n%zu\n",num_elements);

    //num_elements-=1;
    float d = distance(arrX, arrY, num_elements);

    printf("\nResultado distancia.c = %f\n", d);

    free(arrX);
    free(arrY);

}
