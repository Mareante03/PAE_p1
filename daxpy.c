#include "stdio.h"
#include "stdlib.h"


void main(int argc, char** argv){
k

    if(argc!=3){
        exit(0);}


    switch(argc){

    int alpha = atoi(argv[1]);
    int N = atoi(argv[2]);


    size_t N = (1073741824 * 6 / sizeof(float));

    

    int *arrX=malloc((int) N*sizeof(int));
    int *arrY= malloc((int) N*sizeof(int));

    for(int i=0;i<N;i++){
        arrX[i]=rand();
        arrY[i]=rand();
    }


}