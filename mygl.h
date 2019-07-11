#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void PutPixel(uint x, uint y, uint r, uint g, uint b, uint a){
    
    FBptr[4*x + 4*y*IMAGE_HEIGHT + 0] = r;
    FBptr[4*x + 4*y*IMAGE_HEIGHT + 1] = g;
    FBptr[4*x + 4*y*IMAGE_HEIGHT + 2] = b;
    FBptr[4*x + 4*y*IMAGE_HEIGHT + 3] = a;
       
}

void DrawLine(){

}

void DrawTriangle(){

}

#endif // _MYGL_H_

