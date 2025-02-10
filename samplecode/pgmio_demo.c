/**
 * @brief Demo for PGM input / output
 * 
 * PAE [G4011452] Labs
 * Last update: 17/01/2022
 * Issue date:  10/02/2021
 * 
 * Author: Pablo Quesada Barriuso
 *
 * This work is licensed under a Creative Commons
 * Attribution-NonCommercial-ShareAlike 4.0 International.
 * http:// https://creativecommons.org/licenses/by-nc-sa/4.0/
 * 
 * THE AUTHOR MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 */

// General utilities
#include <stdlib.h>
#include <stdio.h>
// Math functions
#include <math.h>

// The file loadPGM.h will be used for defining load and export functions
#include "pgmio.h"

int main(int argc, char *argv[])
{ 
    // check for arguments
    if (argc < 2) {
    	printf("Use %s file.pgm\n", argv[0]);
        exit(-1);
    }

    // image width x height
    int w, h;

    // Load pgm image
    unsigned char* xu8 = loadPGMu8(argv[1], &w, &h);

    // save pgm image
    savePGMu8("xu8.pgm", xu8, w, h);

    free(xu8);
    
    // Load pgm image
    float* x32 = loadPGM32(argv[1], &w, &h);

    // save pgm image
    savePGM32("x32.pgm", x32, w, h);
    
    free(x32);

    return 0;
}
