#include <stdio.h>
#include <stdlib.h>
#include "samplecode/pgmio.h"


int main(int argc,char**argv){
    int vector[256];
    for(int i=0;i<256;i++){
        vector[i]=0;
    }

    int w, h;
    unsigned char* matr = loadPGMu8(argv[1], &w, &h);

    size_t n = w * h;
    for(int i = 0; i < n; i++) {
        vector[matr[i]] += 1;
    }

    printf("\n");
    for(int i = 0; i < 256; i++) {
        printf("%d, ",vector[i]);
    }
    printf("\n");

    free(matr);
}
